// https://leetcode.com/problems/koko-eating-bananas/

# define int2 long long

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxVal = *max_element(piles.begin(), piles.end());

        cout << "maxVal: " << maxVal << endl;

        int l = 1, r = maxVal;

        int ans = INT_MAX;
        while(l <= r){
            int mid = (l+r)/2;

            long long cal = helper(piles, mid);
            if(cal <= h){
                ans = min(ans, mid);
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }

    long long helper(vector<int>& piles, int k){
        int n = piles.size();
        long long cnt = 0;
        for(int i = 0; i<n; i++){
            // if(piles[i] <= k) cnt++;
            // else{
            //     cnt += ceil(piles[i]*1.0/k);
            // }
            cnt += ((piles[i]+k-1)/k);
        }

        return cnt;
    }
};