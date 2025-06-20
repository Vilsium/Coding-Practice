// Leetcode question 2642

/*
There is a directed weighted graph that consists of n nodes numbered from 0 to n - 1. The edges of the graph are initially represented by the given array edges where edges[i] = [fromi, toi, edgeCosti] meaning that there is an edge from fromi to toi with the cost edgeCosti.

Implement the Graph class:

Graph(int n, int[][] edges) initializes the object with n nodes and the given edges.
addEdge(int[] edge) adds an edge to the list of edges where edge = [from, to, edgeCost]. It is guaranteed that there is no edge between the two nodes before adding this one.
int shortestPath(int node1, int node2) returns the minimum cost of a path from node1 to node2. If no path exists, return -1. The cost of a path is the sum of the costs of the edges in the path.
*/

class Graph {
private:
    int n;
    vector<vector<pair<int, int>>> graph;
    
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        graph.resize(n);
        for(auto it : edges) {
            graph[it[0]].push_back({it[1], it[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> distance(n, INT_MAX);
        distance[node1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, node1});
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int dist = it.first;
            int node = it.second;
            for(auto i : graph[node]) {
                int adjNode = i.first;
                int edgeWt = i.second;
                if(edgeWt + dist < distance[adjNode]) {
                    distance[adjNode] = dist + edgeWt;
                    pq.push({distance[adjNode], adjNode});   
                }
            }
        }
        return (distance[node2] == INT_MAX) ? -1 : distance[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */