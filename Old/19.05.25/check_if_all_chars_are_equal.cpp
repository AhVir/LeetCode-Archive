// https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/description/?envType=problem-list-v2&envId=string

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int freq[26] = {0};
        string str = s;
        int len = str.length();

        // cout << str << endl;
        // cout << len << endl;

        for(int i=0; i<len; i++){
            // cout << str[i] << endl;
            // cout << str[i]-'a' << endl;
            int ch = str[i] - 'a';
            // cout << "ch: " << str[i] << "-> " << ch << endl;
            // cout << ch << endl;
            freq[ch]++;
        }

        // for(int i=0; i<26; i++) printf("%d ", freq[i]);
        // cout << endl;

        int cnt = freq[str[0]-'a'];
        // cout << cnt << endl;
        if(len == 1) return true;

        for(int i=0; i<26; i++){
            if(freq[i] != 0 && freq[i] != cnt){
                // cout << freq[i] << endl;
                return false;
            }
        }

        return true;
    }
};