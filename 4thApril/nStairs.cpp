#include<iostream>
using namespace std;

// For k=3
// int nStairs(int n){
//     if(n==0){
//         return 1;
//     }
//     if(n<0){
//         return 0;
//     }
//     return nStairs(n-1)+nStairs(n-2)+nStairs(n-3);
// }

//General Function
int nStairs(int n,int k){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }

    int ans=0;
    for(int i=1;i<=k;i++){
        ans+=nStairs(n-i,k);
    }

    return ans;
}


int main(){
    int n;
    int k;
    cout<<"Enter the value of n: ";
    cin>>n;

    cout<<"Enter the value of k: ";
    cin>>k;

    cout<<"The number of ways to reach the nth stair with k max steps at a time is: "<<nStairs(n,k)<<endl;


    return 0;
}