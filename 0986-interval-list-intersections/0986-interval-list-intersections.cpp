class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& fl, vector<vector<int>>& sl) {
        int n=fl.size(),m=sl.size();
        int i=0,j=0;
        vector<vector<int>> ans;
        while(i<n && j<m){
            if(fl[i][1]<sl[j][0]) i++;
            else if(sl[j][1]<fl[i][0]) j++;
            else {
                ans.push_back({max(fl[i][0],sl[j][0]),min(fl[i][1],sl[j][1])});
                if(fl[i][1]<=sl[j][1]) i++;
                else j++;
            }
        }
        return ans;
    }
};