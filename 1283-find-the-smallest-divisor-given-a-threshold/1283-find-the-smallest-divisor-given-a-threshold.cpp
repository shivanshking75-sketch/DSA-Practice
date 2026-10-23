#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumbyd(vector<int> &nums, int div) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            sum = sum + ceil((double)(nums[i]) / (double)(div));
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        
        while(low <= high) {
            // Fixed parenthesis: (high - low) / 2
            int mid = low + (high - low) / 2;
            
            if(sumbyd(nums, mid) <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};