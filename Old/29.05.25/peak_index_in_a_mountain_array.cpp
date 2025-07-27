// https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int val = bsa(arr, 0, arr.size()-1);
        cout << val << endl;

        return val;
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