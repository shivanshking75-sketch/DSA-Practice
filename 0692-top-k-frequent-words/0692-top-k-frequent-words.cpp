class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto it : words) {
            mp[it]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        for(auto it : mp) {
            pq.push({-it.second, it.first});
        }

        vector<string> ans;
        while(k > 0) {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};