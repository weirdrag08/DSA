class Solution {
public:

    bool safe(int row, int col, vector<vector<char> > &board){
        //check column
        for(int i = 0; i < row; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        //check 1st diag(\)
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        //check 2nd diag(/)
        for(int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        //All safe
        return true;
    }

    void formBoard(int row, int queens, int &res, vector<vector<char> > &board){
        if(row >= board.size()){
            if(queens == 0){
                res += 1;
            }
            return;
        }
        //level = each row
        //option = each column 
        for(int col = 0; col < board.size(); col++){
            if(safe(row, col, board)){
                board[row][col] = 'Q';
                formBoard(row + 1, queens - 1, res, board);
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<char> > board(n, vector<char>(n, '.'));
        int res = 0;
        formBoard(0, n, res, board);
        return res;
    }
};
