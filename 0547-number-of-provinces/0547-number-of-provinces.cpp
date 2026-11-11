class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        queue<int> queue;
        unordered_set<int> visited;
        int res = 0;

        for (int c = 0; c < isConnected.size(); c++) {
            if (visited.count(c) != 0) continue;

            queue.push(c);
            visited.insert(c);
            res++;

            while (!queue.empty()) {
                int curr = queue.front();
                queue.pop();
                for (int i = 0; i<isConnected[curr].size(); i++) {
                    if (visited.count(i) == 0 && isConnected[curr][i]) {
                        queue.push(i);
                        visited.insert(i);
                    }
                }
            }
        }

        return res;
    }
};