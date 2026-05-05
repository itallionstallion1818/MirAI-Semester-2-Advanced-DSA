#include<iostream>
using namespace std;

int partition(vector<int>&v,int left,int right){
    // Select the last element as the pivot
    int pivot= v[right];
    
    // Create partitions such that 
    // 1st partition has elements < pivot
    // 2nd partition has elements > pivot
    int i=left-1;
    for(int j=left;j<=right;j++){
        if(v[j]<pivot){
            i++;
            swap(v[i],v[j]);
        }
    }

    // Putting the pivot element in it's right position
    swap(v[i+1],v[right]);
    // Returning the index where we need to divide
    return i+1;

}


void Quicksort(vector<int>&v,int left,int right){
    if(left<right){
        //Calculating the partition index where we need to divide
        int pi=partition(v,left,right);
        //Calling quicksort recursively on the left part
        Quicksort(v,left,pi-1);
        //Calling quicksort recursively on the right part
        Quicksort(v,pi+1,right);
    }
}

int main(){
    vector<int> v = {10, 7, 8, 9, 1, 5};
    int n = v.size();
	
  	// Calling quicksort for the vector vec
    Quicksort(v, 0, n - 1);

    for (auto i : v) {
        cout << i << " ";
    }
    return 0;

}