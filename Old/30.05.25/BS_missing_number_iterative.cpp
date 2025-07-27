// https://leetcode.com/problems/missing-number/description/?envType=problem-list-v2&envId=binary-search

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int arr[10005];
        for(int i=0; i<10005; i++) arr[i] = 0;
        for(int x:nums) arr[x]++;

        for(int i=0; i<10005; i++){
            if(arr[i] == 0) return i;
        }

        return -1;
    }
};