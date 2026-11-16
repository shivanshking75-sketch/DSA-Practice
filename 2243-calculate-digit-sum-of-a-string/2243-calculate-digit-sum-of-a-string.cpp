class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            int count = 0;
            int sum = 0;
            string group = "";
            
            for (char ch : s) {
                count++;
                sum += ch - '0';
                
                if (count == k) {
                    group += to_string(sum);
                    count = 0;
                    sum = 0;
                }
            }
            
            if (count > 0) {
                group += to_string(sum);
            }
            
            s = group;
        }
        
        return s;
    }
};