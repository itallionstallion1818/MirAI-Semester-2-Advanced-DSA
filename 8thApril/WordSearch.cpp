#include<iostream>
using namespace std;

bool search(vector<vector<char>>&board,string &word,int index,int r,int c){

    if(index==word.size()){
        return true;
    }
    //1.Check the boundary conditions
    //2.Check the constraints
    if(r<0 || r>=board.size() || c<0 || c>=board[0].size() || board[r][c]!=word[index]){
        return false;
    }
    char temp=board[r][c];
    board[r][c]='*';
    bool wordfound=search(board,word,index+1,r-1,c) || //UP
                   search(board,word,index+1,r+1,c) || //DOWN
                   search(board,word,index+1,r,c+1) || //RIGHT
                   search(board,word,index+1,r,c-1); //LEFT
    board[r][c]=temp;
    return wordfound;
}


bool exist(vector<vector<char>>&board,string word){
    int rows=board.size();
    int cols=board[0].size();

    for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++){
            if(board[r][c]==word[0] && search(board,word,0,r,c)){
                return true;
            }
        }
    }
    return false;
}


int main(){
    string word="AAACCED";
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    if(exist(board,word)){
        cout<<"TRUE";
    }
    else{
        cout<<"FALSE";
    }

    return 0;
}