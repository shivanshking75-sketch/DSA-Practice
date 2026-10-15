class Solution {
public:


    bool allocationispossible(
        vector<int>& nums, int barrier, int k) {

        int allocated = 1;
        int pages = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {

      
            if(nums[i] > barrier)
                return false;

            if(pages + nums[i] > barrier) {
                allocated++;
                pages = nums[i];
            }
            else {
                pages += nums[i];
            }
        }

        if(allocated > k)
            return false;

        return true;
    }

    int splitArray(vector<int>& nums, int k) {

        int n = nums.size();

        if(k > n)
            return -1;

        int low = *max_element(
            nums.begin(), nums.end());

        int high = accumulate(
            nums.begin(), nums.end(), 0);

        int ans = -1;

    
        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(allocationispossible(nums, mid, k)) {

                ans = mid;

                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};