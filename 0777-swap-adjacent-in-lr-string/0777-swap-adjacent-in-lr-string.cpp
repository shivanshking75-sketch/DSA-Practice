class Solution {
public:
    bool canTransform(string start, string result) {
        int i = 0;
        int j = 0;
        int n = start.length();

        while (i < n || j < n) {
            while (i < n && start[i] == 'X') {
                i++;
            }

            while (j < n && result[j] == 'X') {
                j++;
            }

            if (i == n || j == n) {
                return i == n && j == n;
            }

            char a = start[i];
            char b = result[j];

            if (a != b) {
                return false;
            }

            if (a == 'L' && i < j) {
                return false;
            }

            if (a == 'R' && i > j) {
                return false;
            }

            i++;
            j++;
        }

        return true;
    }
};