#include<iostream>
using namespace std;

void TowerofHanoi(int n, string fromRod, string toRod, string auxRod){
    // Base Case: When there are no discs left to move
    if(n==0){
        return;
    }

    // 1. Ask recursion to move n-1 discs from the source to the helper tower.
    TowerofHanoi(n-1, fromRod,auxRod,toRod);
    // 2. Move the nth disc from the source to the destination
    cout<<"Move the disk "<<n<<" from "<<fromRod<<" to "<<toRod<<endl;
    // 3. Ask recursion to n-1 discs from the helper to the destination
    TowerofHanoi(n-1,auxRod,toRod,fromRod);
}

int main(){
    TowerofHanoi(3,"A","C","B");
    return 0;
}