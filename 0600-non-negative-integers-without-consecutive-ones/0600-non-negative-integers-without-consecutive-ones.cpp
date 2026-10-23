class Solution {
public:
    string bin(int n) {
        string s;
        while (n) {
            int d = n % 2;
            n /= 2;
            s.push_back('0' + d);
        }
        reverse(s.begin(), s.end());
        return s;
    }

    int t[30][2][2]; //since 10^9 comes in 29 bits
    int solve(string s, int i, bool tight, bool prev) {

        if (i >= s.size())
            return 1;

        if (t[i][tight][prev] != -1)
            return t[i][tight][prev];

        int lb = 0;
        int ub = (tight == 1) ? s[i] - '0' : 1;

        int res = 0;
        for (int dig = lb; dig <= ub; dig++) {

            if (prev && dig == 1)
                continue;

            res += solve(s, i + 1, (tight && dig == ub), (dig == 1));
        }
        return t[i][tight][prev] = res;
    }

    int findIntegers(int n) {
        memset(t, -1, sizeof(t));

        string s = bin(n);
        return solve(s, 0, 1, 0);
    }
};