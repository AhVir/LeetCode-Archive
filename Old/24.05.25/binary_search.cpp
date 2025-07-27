// https://leetcode.com/problems/binary-search/description/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();

        int ans = binarySearch(nums, target, 0, len-1, len);

        cout << ans << endl;

        return ans;
    }

    int binarySearch(vector<int>& nums, int target, int l, int r, int len){
        int mid = (l+r)/2;

        if(l>r) return -1;

        if(nums[mid] == target) return mid;
        else if(nums[mid] > target){
            return binarySearch(nums, target, l, mid-1, len);
        }
        
        return binarySearch(nums, target, mid+1, r, len);
    }
};