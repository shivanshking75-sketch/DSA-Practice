class Solution {
public:
    void DFS(int i, int j, vector<vector<char>>& board, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return;
        }
        if (board[i][j] == 'M') {
            return;
        }
        if (board[i][j] != 'E') {
            return;
        }
        int temp = 0;
        for (int k = -1; k <= 1; k++) {
            for (int l = -1; l <= 1; l++) {
                if (i + k < 0 || i + k >= n || j + l < 0 || j + l >= m) {
                    continue;
                } else if (board[i + k][j + l] == 'M') {
                    temp++;
                }
            }
        }
        if (temp == 0) {
            board[i][j] = 'B';
            DFS(i + 1, j, board, n, m);
            DFS(i - 1, j, board, n, m);
            DFS(i, j + 1, board, n, m);
            DFS(i, j - 1, board, n, m);
            DFS(i + 1, j + 1, board, n, m);
            DFS(i + 1, j - 1, board, n, m);
            DFS(i - 1, j + 1, board, n, m);
            DFS(i - 1, j - 1, board, n, m);
        } else {
            board[i][j] = '0' + temp;
        }
    }

        vector<vector<char>> updateBoard(vector<vector<char>> & board,
                                         vector<int> & click) {
            int n = board.size();
            int m = board[0].size();
            int a = click[0];
            int b = click[1];
            if (board[a][b] == 'M') {
                board[a][b] = 'X';
                return board;
            } else {
                DFS(a, b, board, n, m);
            }
            return board;
        }
    };