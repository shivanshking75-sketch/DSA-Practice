class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int l,k;
        int total = 0;
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[i].size(); ++j)
            {
                if(board[i][j] == 'R') 
                {
                    l = i - 1;
                    k = j;
                    while(l >= 0)
                    {
                        if(board[l][j] == 'p') {total++; break;}
                        else if(board[l][j] != '.') break;
                        l--;
                    }
                    l = i + 1;
                    while(l <= 7)
                    {
                        if(board[l][j] == 'p') {total++; break;}
                        else if(board[l][j] != '.') break;
                        l++;
                    }
                    k = j - 1;
                    while(k >= 0)
                    {
                        if(board[i][k] == 'p') {total++; break;}
                        else if(board[i][k] != '.') break;
                        k--;
                    }
                    k = j + 1;
                    while(k < 8)
                    {
                        if(board[i][k] == 'p') {total++; break;}
                        else if(board[i][k] != '.') break;
                        k++;
                    }
                    break;
                    return total;
                }
            }
        }
        return total;
    }
};