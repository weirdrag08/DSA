class Solution {
public:

    bool safe(int row, int col, vector<vector<char> > &board){
        int n = board.size();
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
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        //All safe
        return true;
    }

    void fillBoard(int row, int queens, vector<vector<char> > &board, vector<vector<string> > &res){
        int n = board.size();
        if(row >= n){
            //All queens placed, solution formed
            if(queens == 0){
                vector<string> sol;
                for(int i = 0; i < n; i++){
                    string r = "";
                    for(int j = 0; j < n; j++){
                        r += (board[i][j] == 'Q' ? 'Q' : '.');
                    }
                    sol.push_back(r);
                }
                res.emplace_back(sol);
            }
            return;
        }
        //level = each row
        //option = each column
        for(int i = 0; i < board.size(); i++){
            if(safe(row, i, board)){
                board[row][i] = 'Q';
                fillBoard(row + 1, queens - 1, board, res);
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char> > board(n, vector<char>(n, '.'));
        vector<vector<string> > res;
        fillBoard(0, n, board, res);
        return res;
    }
};
