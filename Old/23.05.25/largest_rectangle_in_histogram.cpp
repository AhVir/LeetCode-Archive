// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        stack<pair<int, int>> st;

        st.push({heights[0], 0});

        int maxArea = 0;
        for(int i=1; i<len; i++){
            int val = heights[i];

            // pair<int, int> topPair = st.top();
            int index = i;
            while(!st.empty() && st.top().first > val){
                pair<int, int> topPair = st.top();
                int tempVal = topPair.first;
                int tempIndex = topPair.second;
                st.pop();
                int tempArea = tempVal * (i-tempIndex);
                maxArea = max(maxArea, tempArea);

                index = topPair.second;
            }

            st.push({val, index});
        }

        while(!st.empty()){
            pair<int, int> temp = st.top(); 
            int tempArea = temp.first * (len - temp.second);

            maxArea = max(maxArea, tempArea);

            st.pop();
        }


        cout << maxArea << endl;
        
        return maxArea;
    }
};