#include<iostream>
#include<climits>
using namespace std;

int maxWater(vector<int>&v){
    int n=v.size();
    int left=0;
    int right=n-1;
    int maxarea=INT_MIN;
    while(left<right){
        int width=right-left;
        int min_height=min(v[left],v[right]);
        int area=width*min_height;
        if(area>maxarea){
            maxarea=area;
        }

        if(v[left]<v[right]){
            left++;
        }
        else{
            right--;
        }

    }
    return maxarea;
}

int main(){
    vector<int>v={1,8,6,2,5,4,8,3,7};
    cout<<maxWater(v)<<endl;



    return 0;
}