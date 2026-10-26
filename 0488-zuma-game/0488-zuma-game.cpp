class Solution {
private:
    unordered_map<string, int> memo;

    bool isGoodPlace(const string& board, int pos, char ball) {
        if (pos > 0 && board[pos - 1] == ball) {
            return true;
        }
        if (pos > 0 && pos < board.length() && board[pos - 1] == board[pos]) {
            return true;
        }
        return false;
    }

    string collapse(string board) {
        int i = 0;
        while (i < board.length()) {
            int j = i;
            while (j < board.length() && board[i] == board[j]) {
                j++;
            }
            if (j - i >= 3) {
                return collapse(board.substr(0, i) + board.substr(j));
            } else {
                i = j;
            }
        }
        return board;
    }

    int dfs(string board, string hand) {
        if (board.empty()) return 0;
        if (hand.empty()) return -1;

        string key = board + "#" + hand;
        if (memo.count(key)) {
            return memo[key];
        }

        int minSteps = INT_MAX;

        for (int i = 0; i < hand.length(); i++) {
            if (i > 0 && hand[i] == hand[i - 1]) {
                continue;
            }

            char ball = hand[i];
            string nextHand = hand.substr(0, i) + hand.substr(i + 1);

            for (int j = 0; j <= board.length(); j++) {
                if (!isGoodPlace(board, j, ball)) {
                    continue;
                }

                string insertedBoard = board.substr(0, j) + ball + board.substr(j);
                string collapsedBoard = collapse(insertedBoard);

                int subSteps = dfs(collapsedBoard, nextHand);
                if (subSteps != -1) {
                    minSteps = min(minSteps, subSteps + 1);
                }
            }
        }

        int result = (minSteps == INT_MAX) ? -1 : minSteps;
        memo[key] = result;
        return result;
    }

public:
    int findMinStep(string board, string hand) {
        sort(hand.begin(), hand.end());
        memo.clear();
        return dfs(board, hand);
    }
};