class DSU{
    public:
    vector<int>sze,parent;
    DSU(int n){
        sze.assign(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(sze[ulp_u]<sze[ulp_v]){
            sze[ulp_v]+=sze[ulp_u];
            parent[ulp_u]=ulp_v;
        }
        else{
            sze[ulp_u]+=sze[ulp_v];
            parent[ulp_v]=ulp_u;
        }
        return;
    }
};
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        DSU dsu=DSU(n);
        for(int i=0;i<n;i++){
            dsu.unionBySize(i,nums[i]);
            maxi=max(maxi,dsu.sze[dsu.findUPar(i)]);
        }
        return maxi;
    }
};