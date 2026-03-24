#include<iostream>
using namespace std;

void Subsequences(string str,string curr){
    // Base Case: If we have iterated over the entire string, return.
    if(str==""){
        cout<<curr<<'\n';
        return;
    }
    // 1. Don't include the first character in the current subsequence.
    Subsequences(str.substr(1),curr);
    // 2. Include the first character in the current subsequence.
    Subsequences(str.substr(1),curr+str[0]);
}

int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    Subsequences(s,"");
    return 0;
}