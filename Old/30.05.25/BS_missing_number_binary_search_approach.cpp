// https://leetcode.com/problems/missing-number/description/?envType=problem-list-v2&envId=binary-search

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int l = 0, r = nums.size() - 1;

        while(l <= r){
            int mid = (l+r)/2;

            if(nums[mid] > mid) r = mid - 1;
            else l = mid + 1;
        }

        return l;
    }
};