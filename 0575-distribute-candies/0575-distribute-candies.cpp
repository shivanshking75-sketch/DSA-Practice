class Solution {
public:
    int distributeCandies(vector<int>& c) {
        int count=1;

        sort(c.begin(),c.end());
        for(int i=0;i<c.size()-1;i++){
            if(c[i]!=c[i+1]){
                count++;
            }
        }
        
        int n=c.size()/2;
        int ans=count;
        ans=min(ans,n);
        return ans;
    }
};