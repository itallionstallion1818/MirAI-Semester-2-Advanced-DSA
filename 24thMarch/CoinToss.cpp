#include<iostream>
using namespace std;

void CoinToss(int n,string curr){
    // Base Case: If no coins are left to toss, return.
    if(n==0){
        cout<<curr<<'\n';
        return;
    }
    // 1.Suppose first coin toss lands a head.
    CoinToss(n-1,curr+"H");
    // 2.Suppose first coin toss lands a tail.
    CoinToss(n-1,curr+"T");
}

int main(){
    CoinToss(3,"");


    return 0;
}