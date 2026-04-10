#include<iostream>
#include<vector>
using namespace std;

void PrintPaths(int arr[][10],vector<int>&current,vector<vector<int>>&result,int n,int r,int c){
    if(r==(n-1)&&c==(n-1)){
        current.push_back(arr[r][c]);
        result.push_back(current);
        current.pop_back();
        return;

    }

    if(r<0 || r>=n || c<0 || c>=n){
        return;
    }

    current.push_back(arr[r][c]);

    if(r+1<n){
        PrintPaths(arr,current,result,n,r+1,c);
    }
    if(c+1<n){
        PrintPaths(arr,current,result,n,r,c+1);
    }

    current.pop_back();
}

int main(){
    int arr[10][10]={{1,2},{3,4}};
    vector<int>current;
    vector<vector<int>>result;
    PrintPaths(arr,current,result,2,0,0);
    for(const auto& row:result){
        for(int val:row){
            cout<<val<<" ";
        }
        cout<<endl;
        
    }

    return 0;
}