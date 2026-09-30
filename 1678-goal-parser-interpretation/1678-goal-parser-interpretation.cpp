class Solution {
public:
    string interpret(string command) {
        int n=command.size();
        string ans;
        for(int i=0;i<n;i++)
        {
            if(command[i]=='G' )

            {
                ans.push_back('G');
            }
            else if(command[i]=='('&&command[i+1]==')')
            {
                ans.push_back('o');
                i++;
            }
            else
            {
                ans+="al";
                i=i+3;
                
            }

        }
        return ans;
        
        
    }
};