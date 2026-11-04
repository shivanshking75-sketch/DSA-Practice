class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int i;
        for(i=0; i<A.size(); i++)
        {
            if(A[i]==i)     
                continue;
            else if(A[i] == i-1)
                    continue;
            else if(A[i] == i+1)
                    continue;
                else
                    return false;
        }
       return true;       
    }
};