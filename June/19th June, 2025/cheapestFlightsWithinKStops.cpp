// Leetcode question 787

/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto it : flights) {
            graph[it[0]].push_back({it[1], it[2]});
        }
        // {stops, {node, dist}}
        queue<pair<int, pair<int, int>>> q;
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;
        q.push({0, {src, 0}});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int stop = it.first;
            int node = it.second.first;
            int dist = it.second.second;
            if(stop > k) continue;
            for(auto i : graph[node]) {
                int adjNode = i.first;
                int edgeWt = i.second;
                if(dist + edgeWt < distance[adjNode] && stop <= k) {
                    distance[adjNode] = dist + edgeWt;
                    q.push({stop+1, {adjNode, distance[adjNode]}});
                }
            }
        }
        return (distance[dst] == INT_MAX) ? -1 : distance[dst];
    }
};