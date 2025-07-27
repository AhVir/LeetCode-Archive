https://leetcode.com/problems/find-closest-node-to-given-two-nodes/description/

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        for(int i=0; i<edges.size(); i++) cout << i << " -> " << edges[i] << endl;

        vector<int> distNode1(edges.size(), -1);
        vector<int> distNode2(edges.size(), -1);

        bfs(edges, node1, distNode1);
        bfs(edges, node2, distNode2);

        // cout <<"node1: " << endl;
        // for(int x=0; x<distNode1.size(); x++){
        //     cout << x << " -> " << distNode1[x] << endl;
        // }

        // cout <<"node2: " << endl;
        // for(int x=0; x<distNode2.size(); x++){
        //     cout << x << " -> " << distNode2[x] << endl;
        // }

        vector<int>ansNodes(edges.size(), -1);
        vector<int>ansDist(edges.size(), -1);

        for(int i=0; i<edges.size(); i++){
            if(distNode1[i] != -1 && distNode2[i] != -1){
                ansDist[i] = max(distNode1[i], distNode2[i]);
                ansNodes[i] = i;
            }
        }

        int ansVal = INT_MAX;
        int ansNode = -1;

        for(int i=0; i<edges.size(); i++){
            if(ansDist[i] != -1 && ansDist[i] < ansVal){
                ansVal = ansDist[i];
                ansNode = ansNodes[i];
                // ansNode = i;
            }
        }

        return ansNode;
    }

    void bfs(vector<int>& edges, int start, vector<int>& dist){
        queue<pair<int, int>> q;
        q.push({start, 0});
        dist[start] = 0;

        while(!q.empty()){
            auto tempNode = q.front();
            int val = tempNode.second;
            int node = tempNode.first;
            q.pop();

            int nei = edges[node];
            if(nei != -1 && dist[nei] == -1){
                dist[nei] = val + 1;
                q.push({nei, val+1});
            }
        }
    }
};