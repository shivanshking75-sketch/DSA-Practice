#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int func(vector<int>& weights, int capacity) {
        int n = weights.size();
        int days = 1;
        int load = 0;
        for(int i = 0; i < n; i++) {
            if(weights[i] + load > capacity) {
                days = days + 1;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        
        int ans = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int no_of_day = func(weights, mid); // Pass weights and mid capacity
            
            if(no_of_day <= days) {
                ans = mid;         // Try finding a smaller capacity on the left
                high = mid - 1;
            } else {
                low = mid + 1;     // Capacity too small, need a bigger one on the right
            }
        }
        return ans;
    }
};