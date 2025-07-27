// https://leetcode.com/problems/snakes-and-ladders/

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int len = board[0].size();

        // reversing the board
        reverse(board.begin(), board.end());
        // for(auto& row:board){
        //     reverse(row.begin(), row.end());
        // }

        // cout << len << endl;
        vector<int> visited(len*len+1, -1);

        queue<pair<int, int>> q;
        q.push({1, 0});
        visited[1] = 0;

        while(!q.empty()){
            auto temp = q.front();
            int pos = temp.first;
            int mv = temp.second;
            q.pop();

            for(int i=1; i<=6; i++){
                int nextPos = pos + i;
                auto cord = cordination(nextPos, len);
                if(board[cord.first][cord.second] != -1) nextPos = board[cord.first][cord.second];
                if(nextPos == len*len) return mv+1;

                if(visited[nextPos] == -1){
                    visited[nextPos] = mv + 1;
                    q.push({nextPos, mv+1});
                }
            }
        }

        return -1;
    }

    pair<int, int> cordination(int val, int len){
        int r = (val-1)/len;
        int c = (val-1)%len;

        if(r%2 == 1){
            c = len - 1 - c;
        }

        return {r, c};
    }
};