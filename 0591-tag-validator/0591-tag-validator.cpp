class Solution {
public:
    bool isValidTag(string &s){
        if(s.size() < 1 || s.size() > 9) return false;

        for(int i=0; i<s.size(); i++){
            if(!isupper(s[i])) return false;
        }
        return true;
    }
    bool isValid(string code) {
        int n = code.size();
        stack<string>st;
        for(int i=0; i<n; i++){
            // there should be atleast one tag from the begining
            if(i > 0 && st.empty()){
                return false;
            }

            // handle CDATA section
            if(code.substr(i, 9) == "<![CDATA["){
                int pos = code.find("]]>", i + 9);
                if(pos == -1) return false;
                //skip the content part and CDATA clsoing
                i = pos + 2;
            }

            // check closing
            else if(code.substr(i, 2) == "</"){
                int endTagPos = code.find('>', i + 2);
                if(endTagPos == -1) return false;

                // extract tag name
                string tag = code.substr(i+2, endTagPos - (i+2));

                // validate end tag
                if(st.empty() || !isValidTag(tag) || st.top() != tag){
                    return false;
                }

                st.pop();
                i = endTagPos;
            }

            // handle opening tag
            else if(code[i] == '<'){
                int startTagPos = code.find('>', i + 1);
                if(startTagPos == -1) return false;

                // extract tag name
                string tag = code.substr(i+1, startTagPos - (i+1));

                if(!isValidTag(tag)){
                    return false;
                }
                st.push(tag);
                i = startTagPos;
            }
        }
        return st.empty();
    }
};