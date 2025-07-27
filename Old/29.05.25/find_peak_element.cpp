// https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ans = bsa(nums, 0, nums.size()-1);

        cout << ans << endl;

        return ans;
    }

    int bsa(vector<int>& nums, int l, int r){
        while(l <= r){
            int mid = (l+r)/2;

            if(nums.size() == 1){
                return l;
            }

            if(mid == 0){
                if(nums[mid] > nums[mid+1]) return mid;
                else l = mid + 1;
            }
            else if(mid == r){
                if(nums[mid] > nums[mid-1]) return mid;
                else r = mid - 1;
            }
            else if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }
            else if(nums[mid] > nums[mid-1]){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        return -1;
    }
};