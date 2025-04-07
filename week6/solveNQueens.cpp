class Solution {
    public:
        vector<vector<string>> solveNQueens(int n) {
            vector<int> board(n, -1);
            vector<vector<string>> res;
            helper(board, res, 0);
            return res;
        }
        // how to put in row? (havent put down yet)
        void helper(vector<int>& board, vector<vector<string>>& res, int row) {
            const int N = board.size();
            if (row == N) {
                vector<string> path(N, string(N, '.'));
                for (int i = 0; i < N; i++) {
                    path[i][board[i]] = 'Q';
                }
                res.push_back(path);
            } else {
                for (int col = 0; col < N; col++) {
                    board[row] = col;
                    if (isValid(board, row, col)) {
                        helper(board, res, row + 1);
                    }
                    board[row] = -1;
                }
            }
        }
        // have put down in (row, col), alright?
        bool isValid(vector<int>& board, int row, int col) {
            for (int prow = 0; prow < row; prow ++) {
                int pcol = board[prow];
                if (pcol == col || abs(prow - row) == abs(pcol - col)) {
                    return false;
                }
            }
            return true;
        }
    };
    