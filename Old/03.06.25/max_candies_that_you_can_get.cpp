// https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/

class Solution {
public:

    int dfs(int box, vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, unordered_set<int>& visited, unordered_set<int>& foundBoxes){
        if(visited.count(box)){
            return 0;
        }

        if(status[box] == 0){
            foundBoxes.insert(box);
            return 0;
        }

        visited.insert(box);
        int candiesCollect = candies[box];

        for(int &insideBox:containedBoxes[box]){
            candiesCollect += dfs(insideBox, status, candies, keys, containedBoxes, visited, foundBoxes);
        }

        for(int &boxKey:keys[box]){
            status[boxKey] = 1;
            if(foundBoxes.count(boxKey)){
                candiesCollect += dfs(boxKey, status, candies, keys, containedBoxes, visited, foundBoxes);
            }
        }

        return candiesCollect;
    }

    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int candy = 0;

        unordered_set<int> visited;
        unordered_set<int> foundBoxes;

        for(int &box : initialBoxes){
            candy += dfs(box, status, candies, keys, containedBoxes, visited, foundBoxes);
        }

        return candy;
    }
};