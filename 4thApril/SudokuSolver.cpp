#include<iostream>
using namespace std;

bool isSafe(int mat[][9],int i,int j,int n,int number){
    for(int k=0;k<n;k++){
        if(mat[i][k]==number || mat[k][j]==number){
            return false;
        }
    }

        n=sqrt(n);
        int si=(i/n)*n;
        int sj=(j/n)*n;
        for(int i=si;i<n;i++){
            for(int j=sj;j<n;j++){
                if(mat[i][j]==number){
                    return false;
                }
            }
        }
    return true;
}


bool sudokusolver(int mat[][9],int i,int j,int n){
    if(i==n){
        //Print the solution



        return true;
    }


    if(j==n){
        return sudokusolver(mat,i+1,0,n);
    }

    if(mat[i][j]!=0){
        return sudokusolver(mat,i,j+1,n);
    }

    // Trying to place numbers, row-wise
    for(int number=1;number<=9;number++){
        if(isSafe(mat,i,j,n,number)){
            mat[i][j]=number;
            bool solutionexists=sudokusolver(mat,i,j+1,n);
            if(solutionexists){
                return true;
            }
            mat[i][j]=0;
        }
    }
    return false;
}


int main(){


    return 0;
}
