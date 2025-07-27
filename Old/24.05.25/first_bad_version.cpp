// https://leetcode.com/problems/first-bad-version/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// #define int2 long long

class Solution {
public:
    int firstBadVersion(int n) {
        int ans = bs(n, 1, n);
        cout << ans << endl;

        return ans;
    }

    int bs(int n, int l, int r){
        int ans = -1;
        while(l <= r){
            // int2 mid = (l+r)/2;
            int mid = l + (r-l)/2;
            bool res = isBadVersion(mid);

            if(res){
                // cout << "trigger" << endl;
                ans = mid;
                r = mid - 1;
            }
            else if(!res){
                l = mid + 1;
                // cout << "trigger" << endl;
            }
        }

        return ans;
    }
};