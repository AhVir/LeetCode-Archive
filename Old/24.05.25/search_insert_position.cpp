// https://leetcode.com/problems/search-insert-position/description/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();

        int ans = binarySearch(nums, target, 0, len-1);

        cout << ans << endl;

        return ans;
    }

    int binarySearch(vector<int>& nums, int target, int l, int r){
        if(l > r) return l;

        int mid = (l+r)/2;
        int val = nums[mid];

        if(val == target) return mid;
        if(val > target) return binarySearch(nums, target, l, mid-1);
        
        return binarySearch(nums, target, mid+1, r);
    }
};