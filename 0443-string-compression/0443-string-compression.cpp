class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if (n == 1)
            return 1;

        int p = 1;
        int count = 1;

        for (int i = 1; i < n; i++) {
            if (chars[i] != chars[i - 1]) {
                if (count > 1) {
                    string str = to_string(count);
                    for (char ch : str) {
                        chars[p] = ch;
                        p++;
                    }
                }
                chars[p] = chars[i];
                p++;
                count = 1;
            } else
                count++;
        }

        // After the loop ends, append the count for the last group if greater than 1.
        if (count > 1) {
            string str = to_string(count);
            for (char ch : str) {
                chars[p] = ch;
                p++;
            }
        }

        return p;
    }
};