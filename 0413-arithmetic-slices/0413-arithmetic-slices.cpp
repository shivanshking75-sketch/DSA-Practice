class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 0;

        int cnt = 0;
        int seq = 0;
        int seqdiff = nums[0] - nums[1];

        for (int i = 1; i < n; i++) {
            int diff = nums[i-1] - nums[i];
            if (diff == seqdiff && i - seq >= 2) cnt += (i - seq - 1);
            if (diff != seqdiff) {
                seq = i - 1;
                seqdiff = diff;
            }
        }
        return cnt;
    }
};