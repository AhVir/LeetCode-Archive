// https://leetcode.com/problems/valid-perfect-square/

#define int2 long long

class Solution {
public:
    bool isPerfectSquare(int2 num) {
        int2 r = num/2;
        cout << "r: " << r << endl;
        if(num == 1) r = 1;
        cout << "r: " << r << endl;

        int2 ans = bs(num, 1, r);
        cout << ans << endl;

        // return ans;
        if(ans == -1) return false;
        return true;
    }

    int2 bs(int num, int2 l, int2 r){
        if(l > r) return -1;

        int2 mid = (l+r)/2;

        if(mid*mid == num) return mid;
        if(mid*mid  > num) return bs(num, l, mid-1);
        return bs(num, mid+1, r);
    }
};