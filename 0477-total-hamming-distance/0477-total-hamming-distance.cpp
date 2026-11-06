class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0;
        int n= nums.size();
        for(int bit =0 ; bit<31;bit++){
            int ones =0;
            for(int x : nums){
                if((x >> bit)&1){
                    ones++;
                }
            }
            total += ones * (n-ones);
        }
        return total;
        
    }
};