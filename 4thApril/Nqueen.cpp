#include<iostream>
using namespace std;


//Checking if we can place the queen
bool isSafe(int board[][10],int r,int c,int n){
    //1.Check the Upper Column
    for(int i=0;i<r;i++){
        if(board[i][c]==1){
            return false;
        }
    }
    
    //2.Check the Upper Left Diagonal
    int i=r;
    int j=c;
    while(i>=0 && j>=0){
        if(board[i][j]==1){
            return false;
        }
        i--;
        j--;
    }

    //3.Check the Upper Right Diagonal
    i=r;
    j=c;
    while(i>=0 && j<n){
        if(board[i][j]==1){
            return false;
        }
        i--;
        j++;
    }

    // After checking all the scenarios, return true
    return true;
}

bool NQueen(int board[][10],int r,int c,int n){
    if(r==n){
        // Print the solution
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1){
                    cout<<"Q"<<"   ";
                }
                else{
                    cout<<"_"<<"   ";
                }
            }
            cout<<endl;
        }
        return true;
    }



    //Recursive case

    //For the current row, try placing a queen at each column
    for(int c=0;c<n;c++){
        // Check if it is safe to place the queen
        if(isSafe(board,r,c,n)){
            board[r][c]=1;
            //If solution exists after placing the queen return true;
            bool solutionexists=NQueen(board,r+1,c,n);
            if(solutionexists){
                return true;
            }
            // If the solution does not exist, then backtrack and unplace the queen
            board[r][c]=0;
        }
    }
    // After checking the whole row, if no solution is found, return false;
    return false;

}



int main(){
    int board[][10]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    int n=4;
    NQueen(board,0,0,4);
    
}