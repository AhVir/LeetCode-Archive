// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = bs_firstOccur(nums, target);
        int last = bs_lastOccur(nums, target);


        cout << first << endl;
        cout << last << endl;

        vector<int> ans;
        ans.push_back(first);
        ans.push_back(last);

        return ans;
    }


    int bs_firstOccur(vector<int>&nums, int target){
        int len = nums.size();
        int l = 0, r = len-1;

        int ans = -1;
        while(l <= r){
            int mid = (l+r)/2;

            if(nums[mid] == target){
                ans = mid;
                r = mid - 1;
            }
            else if(nums[mid] > target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }

    int bs_lastOccur(vector<int>&nums, int target){
        int len = nums.size();
        int l = 0, r = len-1;

        int ans = -1;
        while(l <= r){
            int mid = (l+r)/2;

            if(nums[mid] == target){
                ans = mid;
                // r = mid - 1;
                l = mid + 1;
            }
            else if(nums[mid] > target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }
};