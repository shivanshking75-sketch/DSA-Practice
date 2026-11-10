class Solution {
public:
    vector<int> rank;
    vector<int> parent;

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void un(int x, int y) {
        int par_x = find(x);
        int par_y = find(y);

        if (par_x != par_y) {
            if (rank[par_x] > rank[par_y])
                parent[par_y] = par_x;

            else if (rank[par_x] < rank[par_y])
                parent[par_x] = par_y;

            else {
                parent[par_y] = par_x;
                rank[par_x]++;
            }
        }
    }

    bool possibleBipartition(
        int n, vector<vector<int>>& dislikes
    ) {
        rank.resize(n + 1, 1);
        parent.resize(n + 1);

        vector<int> enemy(n + 1, -1);

        for (int i = 0; i < n + 1; i++)
            parent[i] = i;

        for (auto& it : dislikes) {
            if (enemy[it[0]] == -1)
                enemy[it[0]] = it[1];
            else
                un(enemy[it[0]], it[1]);

            if (enemy[it[1]] == -1)
                enemy[it[1]] = it[0];
            else
                un(enemy[it[1]], it[0]);
        }

        for (auto& it : dislikes) {
            int pa = find(it[0]);
            int pb = find(it[1]);

            if (pa == pb)
                return false;
        }

        return true;
    }
};