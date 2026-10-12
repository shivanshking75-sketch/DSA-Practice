class Solution {
public:

        void merge(vector<pair<int,int>>&arr,int left,int mid, int right,vector<int>&counts){
            int n1=mid-left+1;
            int n2=right-mid;
            vector<pair<int,int>>l(n1),r(n2);
            for(int i=0;i<n1;i++){
                l[i]=arr[left+i];
            }
            for(int j=0;j<n2;j++){
                r[j]=arr[mid+1+j];
            }
            int i=0,j=0;
            int k=left;
            int rightCount=0;
            
            while(i<n1 && j<n2){
                if(l[i].first<=r[j].first){
                    counts[l[i].second]+=rightCount;
                    arr[k]=l[i];
                    i++;        
                }
                else{
                    arr[k]=r[j];
                    rightCount++;
                    j++;
                }
                k++;
            }
            while(i<n1){
                arr[k]=l[i];
                counts[l[i].second]+=rightCount;
                i++;
                k++;
            }
            while(j<n2){
                arr[k]=r[j];
                j++;
                k++;
            }
        }
        
        void mergesort(vector<pair<int,int>>&arr,int left,int right,vector<int>&counts){
            if(left>=right){
                return;
            }
            int mid=left+(right-left)/2;
            mergesort(arr,left,mid,counts);
            mergesort(arr,mid+1,right,counts);
            merge(arr,left,mid,right,counts);
        }

    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        vector<int>counts(n,0);
         mergesort(arr,0,n-1,counts);
        return counts;
    }
};