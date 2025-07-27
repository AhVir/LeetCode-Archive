// https://leetcode.com/problems/longest-valid-parentheses/?envType=problem-list-v2&envId=string
// -> Approach: stack of indices

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        stack<int> st;
        st.push(-1);

        int cnt = 0, temp = 0;
        for(int i=0; i<len; i++){
            char ch = s[i];

            if(ch == '('){
                st.push(i);
            }
            else if(ch == ')'){
                st.pop();

                if(st.empty() == false){
                    int temp = i - st.top();
                    cnt = max(temp, cnt);
                }
                else{
                    st.push(i);
                }
            }
        }

        cout << cnt << endl;
        
        return cnt;
    }
};