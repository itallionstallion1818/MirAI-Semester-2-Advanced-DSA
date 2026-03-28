#include<iostream>
using namespace std;

void permute(string s, int i, int n){
    if(i==n-1){
        cout<<s<<endl;
        return; 
    }

    for(int idx=i;idx<n;idx++){
        swap(s[i],s[idx]);
        permute(s,i+1,n);
        swap(s[i],s[idx]);
    }
}

int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    permute(s,0,s.length());

    return 0;
}