// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // int cal = bs(nums, target);
        // cout << cal << endl;

        // return cal;

        int minIdx = bs(nums);
        cout << "minIdx: " << minIdx << endl;

        if(minIdx == 0){
            return bsTarget(nums, target, minIdx, nums.size()-1);
        }
        else{
            int ans1 = bsTarget(nums, target, minIdx, nums.size()-1);
            int ans2 = bsTarget(nums, target, 0, minIdx-1);

            if(ans1 != -1) return ans1;
            else if(ans2 != -1) return ans2;
            else return -1;
        }
    }


    int bsTarget(vector<int>& nums, int target, int l, int r){
        // int l = 0, r = nums.size()-1;

        while(l <= r){
            int mid = (l+r)/2;

            if(nums[mid] == target) return mid;
            else if(nums[mid] > target){
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return -1;
    }

    int bs(vector<int>& nums){
        int l = 0, r = nums.size()-1;

        while(l < r){
            int mid = l + (r-l)/2;
            int val = nums[mid];

            if(val > nums[r]){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }

        return l;
    }
};