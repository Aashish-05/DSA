class Solution {
public:
bool isSafe(int row,int col,vector<string>&board,int n){
    // left row check    
    for(int j=0;j<col;j++){
        if(board[row][j]=='Q') return false;
    }
    int dupRow=row;
    int dupCol=col;
    // upper-left diagonal
    while(row>=0 && col>=0){
        if(board[row][col]=='Q') return false;
        col--;
        row--;
    }
    row = dupRow;
    col=dupCol;
    // lower-left diagonal
    while(row<n && col>=0){
        if(board[row][col]=='Q') return false;
        row++;
        col--;
    }
    return true;
}
void solve(int col,int n,vector<string>&board,vector<vector<string>>&ans){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            solve(col+1,n,board,ans);
            board[row][col]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        solve(0,n,board,ans);
        return ans;
    }
};