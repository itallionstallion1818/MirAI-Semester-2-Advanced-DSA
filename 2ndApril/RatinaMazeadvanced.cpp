#include<iostream>
using namespace std;

void printsolution(int soln[][10],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<soln[i][j]<<" ";
        }
        cout<<endl;
    }

}

bool ratinamaze(char maze[][5],int n,int i,int j,int soln[][10]){
    if(i==n-1 && j==n-1){
        soln[i][j]=1;
        //Print the solution
        printsolution(soln,n);
        // Fool the recursion to print all possible outcomes.
        return true;
    }

    soln[i][j]=1;
    if(j+1<n && maze[i][j+1]!='X' && soln[i][j+1]!=1){
        bool solutionfromright=ratinamaze(maze,n,i,j+1,soln);
        if(solutionfromright){
            return true;
        }
    }
    if(i+1<n && maze[i+1][j]!='X' && soln[i+1][j]!=1){
        bool solutionfromdown=ratinamaze(maze,n,i+1,j,soln);
        if(solutionfromdown){
            return true;
        }
    }
    if(i-1>=0 && maze[i-1][j]!='X' && soln[i-1][j]!=1){
        bool solutionfromup=ratinamaze(maze,n,i-1,j,soln);
        if(solutionfromup){
            return true;
        }
    }

    if(j-1>=0 && maze[i][j-1]!='X' && soln[i][j-1]!=1){
        bool solutionfromleft=ratinamaze(maze,n,i,j-1,soln);
        if(solutionfromleft){
            return true;
        }
    }


    // Backtracking and re-setting the path as '0'
    soln[i][j]=0;
    return false;
}

int main(){

    int n=4;
    char maze[5][5];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
        }
    }
    cout<<endl;
    int soln[10][10]={0};
    ratinamaze(maze,4,0,0,soln);
    return 0;
}