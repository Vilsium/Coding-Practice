// Leetcode question 743

/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        for(auto it : times) {
            graph[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        vector<int> distance(n+1, INT_MAX);
        distance[k] = 0;
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int time = it.first;
            for(auto i : graph[node]) {
                int adjNode = i.first;
                int edgeWt = i.second;
                if(time + edgeWt < distance[adjNode]) {
                    distance[adjNode] = time+edgeWt;
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }
        int maxElem = *max_element(distance.begin()+1, distance.end());
        return (maxElem == INT_MAX) ? -1 : maxElem;
    }
};