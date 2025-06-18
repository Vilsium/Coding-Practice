// Geeks for geeks practice

/*
Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge between the nodes u and v having w edge weight.
You have to find the shortest distance of all the vertices from the source vertex src, and return an array of integers where the ith element denotes the shortest distance between ith node and source vertex src.

Note: The Graph is connected and doesn't contain any negative weight edge.
*/

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int, int>>> graph(V);
        for(auto it : edges) {
            graph[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> distance(V, 1e9);
        distance[src] = 0;
        minHeap.push({0, src});
        while(!minHeap.empty()) {
            int node = minHeap.top().second;
            int distFromSrc = minHeap.top().first;
            minHeap.pop();
            for(auto it : graph[node]) {
                int adjNode = it.first;
                int edgeWt = it.second;
                if(distFromSrc + edgeWt < distance[adjNode]) {
                    distance[adjNode] = distFromSrc + edgeWt;
                    minHeap.push({distance[adjNode], adjNode});
                }
            }
        }
        return distance;
    }
};