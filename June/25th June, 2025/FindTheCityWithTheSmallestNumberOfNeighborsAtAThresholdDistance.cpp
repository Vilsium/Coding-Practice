// Leetcode question 1334

/*
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.
*/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> cost(n, vector<int> (n, INT_MAX));
        for(int i = 0; i < n; i++) {
            cost[i][i] = 0;
        }
        for(auto it : edges) {
            cost[it[0]][it[1]] = it[2];
            cost[it[1]][it[0]] = it[2]; 
        }
        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(cost[i][via] == INT_MAX || cost[via][j] == INT_MAX) continue;
                    cost[i][j] = min(cost[i][j], cost[i][via] + cost[via][j]);
                }
            }
        }
        int cityCount = n;
        int cityNo = -1;
        for(int city = 0; city < n; city++) {
            int count = 0;
            for(int adjCity = 0; adjCity < n; adjCity++) {
                if(cost[city][adjCity] <= distanceThreshold) count++;
            }
            if(count <= cityCount) {
                cityCount = count;
                cityNo = city;
            }
        }
        return cityNo;
    }
};