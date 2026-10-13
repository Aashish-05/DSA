class Solution {
public:
 bool isValid(char ch ,int row,int col,vector<vector<char>>&board){
    for(int i=0;i<9;i++){
        if(board[i][col]==ch) return false;
    }
    for(int j=0;j<9;j++){
        if(board[row][j]==ch) return false;
    }
    int sRow = row-row%3;
    int sCol = col-col%3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i+sRow][j+sCol]==ch) return false;
        }
    }
    return true;
 }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char ch = '1';ch<='9';ch++){
                        if(isValid(ch,i,j,board)){
                            board[i][j]=ch;
                            if(solve(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};