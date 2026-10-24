#include<bits/stdc++.h>
using namespace std;
long long sumofb(vector<int> &piles , int hour){
    int n =piles.size();
    long long  sum=0;
    for(int i = 0; i<n ; i++)
    {
        sum +=  ceil((double)(piles[i])/(double)hour);
    }
    return sum;

}
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<=high)
        {
            long long mid = low+(high-low)/2;
            if(sumofb(piles,mid)<=h)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return low;
        
    }
};