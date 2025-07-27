class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int len = s.length();

        int total = 0;
        for(int i=0; i<len; i++){
            if(i+1 < len){
                if(s[i] == 'I' && s[i+1] == 'V') total += 4, i++;
                else if(s[i] == 'I' && s[i+1] == 'X') total += 9, i++;
                else if(s[i] == 'X' && s[i+1] == 'L') total += 40, i++;
                else if(s[i] == 'X' && s[i+1] == 'C') total += 90, i++;
                else if(s[i] == 'C' && s[i+1] == 'D') total += 400, i++;
                else if(s[i] == 'C' && s[i+1] == 'M') total += 900, i++;
                else total += m[s[i]];
            }
            else{
                total += m[s[i]];
            }
        }

        return total;
    }
};
