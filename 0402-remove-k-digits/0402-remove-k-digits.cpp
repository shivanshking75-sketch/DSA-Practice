class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        for(char ch : num) {
            while(ans.size() && ans.back() > ch && k) {
                k--; ans.pop_back();
            }
            if(ans.size() + ch - '0') ans.push_back(ch);
        }
        while(k-- && ans.size()) ans.pop_back();
        return ans.size() ? ans : "0";
    }
};