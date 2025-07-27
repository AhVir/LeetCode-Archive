class Solution {
public:
    long long nCr(int n, int r) {
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n - r) r = n - r;
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res *= (n - r + i);
            res /= i;
        }
        return res;
    }

    long long distributeCandies(int n, int limit) {
        long long total = nCr(n + 2, 2);
        long long part1 = (n >= (limit + 1)) ? nCr(n - (limit + 1) + 2, 2) : 0;
        long long part2 = (n >= 2 * (limit + 1)) ? nCr(n - 2 * (limit + 1) + 2, 2) : 0;
        long long part3 = (n >= 3 * (limit + 1)) ? nCr(n - 3 * (limit + 1) + 2, 2) : 0;

        long long ans = total - 3 * part1 + 3 * part2 - part3;
        return ans;
    }
};