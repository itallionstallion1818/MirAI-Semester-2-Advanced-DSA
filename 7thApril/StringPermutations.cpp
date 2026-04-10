#include<iostream>
#include<vector>
using namespace std;

void recurPermute(int index,string &s,vector<string>&res){
    //Base case
    if(index==s.size()){
        res.push_back(s);
        return;
    }

    // Iterating through the string
    for(int i=index;i<s.size();i++){
        swap(s[i],s[index]);
        recurPermute(index+1,s,res);
        swap(s[i],s[index]);
    }
    return;
}

vector<string> findPermutations(string &s){
    vector<string> res;
    recurPermute(0,s,res);

    sort(res.begin(),res.end());
    return res;
}

int main(){
    string s="ABC";
    vector<string>result=findPermutations(s);
    for(string s:result){
        cout<<s<<endl;

    }

    return 0;
}