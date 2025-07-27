class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256];
        for(int i=0; i<256; i++) freq[i] = -1;

        int cnt = 0;
        int l = 0, r = 0;
        int tempCnt = 0;

        int len = s.length();
        // cout << len << endl;

        while(r<len){
            char ch = s[r];
            int val = (int)ch;
            cout << val << endl;

            if(freq[val] != -1 && freq[val] >= l){
                cnt = max(cnt, tempCnt);
                l = freq[val] + 1;
                tempCnt = r-l+1;
                freq[val] = r;
                r++;
            }
            else{
                tempCnt++;
                freq[val] = r;
                r++;
            }
        }

        cnt = max(tempCnt, cnt);

        return cnt;
    }
};