// Geeks for Geeks problem

/*
Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length E, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.
*/

// User function Template for C++
class Solution {
  private:
    void topoSort(vector<vector<pair<int, int>>>& graph, stack<int>& stk, vector<bool>& visited, int node) {
        visited[node] = true;
        for(auto it : graph[node]) {
            if(!visited[it.first]) topoSort(graph, stk, visited, it.first);
        }
        stk.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> graph(V);
        for(auto it : edges) {
            graph[it[0]].push_back({it[1], it[2]});
        }
        vector<bool> visited(V, false);
        stack<int> stk;
        for(int i = 0; i < V; i++) {
            if(!visited[i]) topoSort(graph, stk, visited, i);
        }
        vector<int> distance(V, 1e9);
        distance[0] = 0;
        while(!stk.empty()) {
            int node = stk.top();
            stk.pop();
            for(auto it : graph[node]) {
                distance[it.first] = min(distance[it.first], distance[node]+it.second);
            }
        }
        for(int i = 0; i < V; i++) {
            if(distance[i] == 1e9) distance[i] = -1;
        }
        return distance;
    }
};
