#include<iostream>
using namespace std;

int fibonacci(int n){
    
    // Base Case
    if(n==0 || n==1){
        return n;
    }
    // Asking the recursion to return the values
    return fibonacci(n-1)+fibonacci(n-2);
    
}

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    for(int i=0;i<=n;i++){
        cout<<"The fibonacci number is: "<<fibonacci(i)<<endl;  
    }
    
    return 0;
}