class Solution {
public:
    
    int memo[110][110];

    int recursive(int c, int k, string ring, string key, int ringLen, int keyLen){
        if(k == keyLen) return 0;

        if(memo[c][k] != -1) return memo[c][k];

        int ans = 1111; // infinite
        for(int i=0; i<ringLen; i++){
            if(key[k] == ring[i]){

                int minLen = min(abs(i-c), ringLen - abs(i-c));
                int tempAns = 1 + minLen + recursive(i, k+1, ring, key, ringLen, keyLen);
                ans = min(ans, tempAns);
            }
        }

        memo[c][k] = ans;

        return ans;
    }

    int findRotateSteps(string ring, string key) {
        for(int i=0; i<110; i++){
            for(int j=0; j<110; j++){
                memo[i][j] = -1;
            }
        }
        int val = recursive(0, 0, ring, key, ring.length(), key.length());

        cout << val << endl;

        return val;
    }
};