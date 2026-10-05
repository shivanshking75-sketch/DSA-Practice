static const int _ = [](){ios_base::sync_with_stdio(false);cin.tie(NULL);return 0;}();

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while (left < right) {
            left >>= 1; right >>= 1; shift++;
        }
        return left << shift;
    }
};