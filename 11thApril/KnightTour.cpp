#include<iostream>
#include<vector>
using namespace std;

// Possible moves for a Knight in L-shape
int dx[8]={2,1,-2,-1,2,1,-2,-1};
int dy[8]={1,2,1,2,-1,-2,-1,-2};

// Check if the move is within board boundaries and the cell is unvisited
bool isSafe(int x,int y,int n,vector<vector<int>>&board){
    return (x>=0 && x<n && y>=0 && y<n && board[x][y]==-1);
}

// Recursive function to solve Knight's Tour using Backtracking
bool KnightTravel(int x, int y,int step,int n, vector<vector<int>>&board){
    // Base Case: If all cells are visited, return true
    if(step==(n*n)){
        return true;
    }

    // Try all 8 possible moves from the current position
    for(int i=0;i<8;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(isSafe(nx,ny,n,board)){
            board[nx][ny]=step; // Mark the cell with the current step number
            if(KnightTravel(nx,ny,step+1,n,board)){
                return true;
            }
            board[nx][ny]=-1; // Backtrack: Unmark the cell if the path doesn't lead to a solution
        }
    }
    return false;
}

// Initializes the board and starts the recursion
vector<vector<int>> KnightTour(int n){
    // Initialize board with -1 (representing unvisited)
    vector<vector<int>> board(n,vector<int>(n,-1));
    board[0][0]=0; // Starting position
    
    if(KnightTravel(0,0,1,n,board)){
        return board;
    }
    return {{-1}}; // Return error indicator if no tour exists
}

int main(){
    int n = 5; // Example with 5x5 board (Note: 3x3 is impossible)
    vector<vector<int>>result=KnightTour(n);
    
    for(const auto& row:result){
        for(int val:row){
            cout<<val<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}