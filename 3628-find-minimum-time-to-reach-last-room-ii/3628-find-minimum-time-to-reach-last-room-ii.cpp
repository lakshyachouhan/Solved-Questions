#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {

        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<ll>> dist(n, vector<ll>(m, LLONG_MAX));
        dist[0][0] = 0;
        
        // (time, i, j)
        using T = tuple<ll,int,int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, 0, 0});
        
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        
        while (!pq.empty()) {
            auto [t, i, j] = pq.top(); 
            pq.pop();
            if (t > dist[i][j]) continue;
            if (i == n-1 && j == m-1) 
                return (int)t;
            
            for (auto &d : dirs) {
                int x = i + d[0], y = j + d[1];
                if (x < 0 || x >= n || y < 0 || y >= m) continue;
                
                // move cost alternates: (i+j)%2==0?1:2
                ll moveCost = ((i + j) % 2) + 1;
                // earliest arrival after moving
                ll arrival = t + moveCost;
                // wait if moveTime[x][y] is later
                ll cand = max<ll>(arrival, moveTime[x][y] + moveCost);
                
                if (cand < dist[x][y]) {
                    dist[x][y] = cand;
                    pq.push({cand, x, y});
                }
            }
        }
        
        return -1;
    }
};
