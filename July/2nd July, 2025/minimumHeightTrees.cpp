// Leetcode question 310

// A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

// Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

// Return a list of all MHTs' root labels. You can return the answer in any order.

// The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> inDegree(n, 0);
        vector<int> answer;
        if(n == 0) return answer;
        if(n == 1) return {0};
        for(auto it : edges) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
            inDegree[it[0]]++;
            inDegree[it[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(inDegree[i] == 1) q.push(i);
        }
        while(!q.empty()) {
            answer.clear();
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                answer.push_back(node);
                for(auto it : graph[node]) {
                    inDegree[it]--;
                    if(inDegree[it] == 1) q.push(it);
                }
            }
        }
        return answer;
    }
};