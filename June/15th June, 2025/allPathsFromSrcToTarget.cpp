// Leetcode question no 797

/*
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).
*/

class Solution {
private:
    void solve(vector<vector<int>>& answer, vector<int>& path, vector<vector<int>>& graph, int n, int node) {
        if(node == n-1) {
            answer.push_back(path);
            return ;
        }
        if(node >= n) return ;
        for(int i : graph[node]) {
            path.push_back(i);
            solve(answer, path, graph, n, i);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> answer;
        vector<int> path;
        path.push_back(0);
        solve(answer, path, graph, n, 0);
        return answer;
    }
};