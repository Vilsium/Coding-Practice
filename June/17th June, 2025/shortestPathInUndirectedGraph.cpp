// Geeks for geeks question

/*
You are given an adjacency list, adj of Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.
*/

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n = adj.size();
        queue<pair<int, int>> q;
        q.push({src, 0});
        vector<int> distance(n, 1e9);
        distance[src] = 0;
        while(!q.empty()) {
            int node = q.front().first;
            int distFromSrc = q.front().second;
            q.pop();
            for(int i : adj[node]) {
                if(distFromSrc+1 < distance[i]) {
                    distance[i] = distFromSrc+1;
                    q.push({i, distFromSrc+1});
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(distance[i] == 1e9) distance[i] = -1;
        }
        return distance;
    }
};