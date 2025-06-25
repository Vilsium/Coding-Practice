// Leetcode question 1976

/*
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.
*/

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        using LL = long long;
        vector<vector<pair<int, int>>> graph(n);
        for(auto it : roads) {
            graph[it[0]].push_back({it[1], it[2]});
            graph[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> pq;
        vector<LL> distance(n, LLONG_MAX);
        vector<int> ways(n, 0);
        int MOD = 1000000007;
        distance[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            long long dist = it.first;
            int node = it.second;
            for(auto i : graph[node]) {
                int adjNode = i.first;
                long long edgeWt = i.second;
                if(dist + edgeWt < distance[adjNode]) {
                    distance[adjNode] = dist + edgeWt;
                    ways[adjNode] = ways[node];
                    pq.push({distance[adjNode], adjNode});
                } else if(dist + edgeWt == distance[adjNode]) ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
            }
        }
        return ways[n-1] % MOD;
    }
};