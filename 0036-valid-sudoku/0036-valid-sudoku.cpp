class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                char ch = board[i][j];
                board[i][j]='.';
                for(int k=0;k<9;k++){
                    if(board[i][k]==ch){
                        board[i][j]=ch;
                        return false;
                    }
                }
                for(int k=0;k<9;k++){
                    if(board[k][j]==ch){
                        board[i][j]=ch;
                        return false;
                    }
                }
                int sRow = i-i%3;
                int sCol = j-j%3;
                for(int a=0;a<3;a++){
                    for(int b=0;b<3;b++){
                        if(board[a+sRow][b+sCol]==ch){
                            board[i][j]=ch;
                            return false;
                        }
                        
                    }
                }

            }
        }
        return true;
    }
};