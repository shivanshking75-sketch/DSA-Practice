class Solution {
public:
    bool canAliceWin(int n) {
        return 0x61f03F807FC00 >> n & 1;
    }
};