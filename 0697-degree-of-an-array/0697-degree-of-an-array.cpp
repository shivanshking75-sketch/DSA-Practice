class Solution {
public:
    int findShortestSubArray(vector<int>& nums) 
    {
        unordered_map <int, int> freq;

        for(int x : nums)
            freq[x]++;
        
        int maxCount = 0;
        for(const auto& [val, count] : freq)
            maxCount = max(maxCount, count);
        
        int ans = nums.size();
        for(const auto& [val, count] : freq)
        {
            if(count == maxCount)                  
            {
                int l = 0, r = nums.size() - 1;
                while(nums[l] != val) l++;         
                while(nums[r] != val) r--;        
                ans = min(ans, r - l + 1);
            }
        }
        return ans;   
    }
};