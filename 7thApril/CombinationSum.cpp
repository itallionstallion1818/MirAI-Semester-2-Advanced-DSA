#include<iostream>
#include<vector>
using namespace std;


void combinationsum(vector<int>&candidates,vector<int>&current_combination,vector<vector<int>>&result,int start_index,int target){
    if(target==0){
        result.push_back(current_combination);
        return;
    }

    for(int i=start_index;i<candidates.size();i++){
        if(candidates[i]<=target){
            current_combination.push_back(candidates[i]);
            combinationsum(candidates,current_combination,result,i,target-candidates[i]);
            current_combination.pop_back();
        }
    }
}


int main(){
    vector<vector<int>> result;
    vector<int>current_combination;
    vector<int>candidates={2,3,4,7};

    combinationsum(candidates,current_combination,result,0,8);
    for(const auto& row:result){
        for(int val:row){
            cout<<val<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}