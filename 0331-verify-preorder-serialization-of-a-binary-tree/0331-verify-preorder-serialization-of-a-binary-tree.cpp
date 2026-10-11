class Solution {
public:
    bool isValidSerialization(string s) {
        int n = s.size();
        stack<int> st;
        int i = 0;

        while (i < n) {

            if (s[i] == '#' && !st.empty() && st.top() == -1) {
                st.pop();                 

                if (st.empty()) return false;

                st.pop();                 
            }
            else {
                int k = 0;

                
                if (s[i] == '#') {
                    k = -1;
                    i += 2;              
                }
                else {
        
                    while (i < n && s[i] != ',') {
                        k = k * 10 + (s[i] - '0');
                        i++;
                    }
                    i++;                  
                }

                st.push(k);
            }
        }

        return (st.size() == 1 && st.top() == -1);
    }
};