#include<iostream>
using namespace std;

bool check7(int * arr,int n){
    // If the array has been traversed then 7 is not present.
    if(n==0){
        return false;
    }
    // Check if last element is 7.
    if(arr[n-1]==7){
        return true;
    }
    // Recursive check for the remaining array.
    return check7(arr,n-1);
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the element: ";
        cin>>arr[i];
    }
    if(check7(arr,n)){
        cout<<"7 is present in the array.\n";
    }
    else{
        cout<<"7 is not present in the array.\n"; 
    }

    return 0;
}