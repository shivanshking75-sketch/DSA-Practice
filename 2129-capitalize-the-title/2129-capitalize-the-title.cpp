#include <sstream>
#include <cctype>

class Solution {
public:
    string capitalizeTitle(string title) {
        stringstream ss(title);
        string temp, result = "";
        
        while (ss >> temp) {
            // First, convert every character in the temp to lowercase
            for (char &c : temp) {
                c = tolower(c);
            }
            
            // If length is greater than 2, capitalize the first letter
            if (temp.length() > 2) {
            temp[0] = toupper(temp[0]);
            }
            
            // Append the word to the result with a space
            if (!result.empty() ) 
            {
                result =result + " ";
            }
            result =result + temp;
               // or use below line...
           // result += (result.empty() ? "" : " ") + temp;
        }
        
        return result;
    }
};