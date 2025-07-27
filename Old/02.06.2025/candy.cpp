// https://leetcode.com/problems/candy/

// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int len = ratings.size();
//         vector<int> candies(len, 1);

//         for(int i=0; i<len; i++){
//             if(i == 0){
//                 if(ratings[i] > ratings[i+1]) candies[i] = candies[i+1] + 1;
//             }
//             else if(i == len-1){
//                 if(ratings[i] > ratings[i-1]) candies[i] = candies[i-1] + 1;
//             }
//             else{
//                 if(ratings[i] > ratings[i-1] && ratings[i+1]){
//                     int val = max(candies[i-1], candies[i+1]);
//                     candies[i] = val + 1;
//                 }
//                 else if(ratings[i] > ratings[i-1]) candies[i] = candies[i-1] + 1;
//                 else if(ratings[i] > ratings[i+1]) candies[i] = candies[i+1] + 1;
//             }
//         }

//         for(int i=len-1; i>=0; i--){
//             if(i == 0){
//                 if(ratings[i] > ratings[i+1]) candies[i] = candies[i+1] + 1;
//             }
//             else if(i == len-1){
//                 if(ratings[i] > ratings[i-1]) candies[i] = candies[i-1] + 1;
//             }
//             else{
//                 if(ratings[i] > ratings[i-1] && ratings[i] > ratings[i+1]){
//                     int val = max(candies[i-1], candies[i+1]);
//                     candies[i] = val + 1;
//                 }
//                 else if(ratings[i] > ratings[i-1]) candies[i] = candies[i-1] + 1;
//                 else if(ratings[i] > ratings[i+1]) candies[i] = candies[i+1] + 1;
//             }
//         }

//         int res = accumulate(candies.begin(), candies.end(), 0);

//         cout << res << endl;

//         return res;
//     }
// };


class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        if (len == 0) return 0;  
        if (len == 1) return 1;  

        vector<int> candies(len, 1);

        for (int i = 1; i < len; i++) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }

        for (int i = len - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
};
