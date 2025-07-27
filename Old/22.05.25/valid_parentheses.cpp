// https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        stack<char> st;

        for(int i=0; i<len; i++){
            char ch = s[i];

            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                if(st.empty()) return false;

                if(ch == ')'){
                    if(st.top() == '(') st.pop();
                    else return false;
                }
                else if(ch == '}'){
                    if(st.top() == '{') st.pop();
                    else return false;
                }
                else if(ch == ']'){
                    if(st.top() == '[') st.pop();
                    else return false;
                }
            }
        }

        if(!st.empty()) return false;
        
        
        return true;
    }
};