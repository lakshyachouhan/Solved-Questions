class Solution {
public:
    int bfs(vector<vector<int>>& bombs, int index) {

        // map<pair<int,int>,bool> vis; 
        // vis[{srcX,srcY}] = true ;  // not work for two same bomb
        int srcX = bombs[index][0], srcY = bombs[index][1], rad = bombs[index][2];
        queue<int> q;
        int ans = 1;
        vector<int> vis(bombs.size(), 0);
        vis[index] = true;
        q.push(index);

        while (!q.empty()) {
            int currIndex = q.front();
            q.pop();
            int currX = bombs[currIndex][0], currY = bombs[currIndex][1];
            long long currRad = bombs[currIndex][2];

            for (int i = 0; i < bombs.size(); i++) {
                if (vis[i]) continue;
                int newX = bombs[i][0], newY = bombs[i][1];
                long long xDist = abs(newX - currX), yDist = abs(newY - currY);

                if (xDist * xDist + yDist * yDist <= currRad * currRad) {
                    vis[i] = true;
                    q.push(i);
                    ans++;
                }
            }
        }

        return ans;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int ans = 0;
        for (int i = 0; i < bombs.size(); i++) {
            int curr = bfs(bombs, i);
            ans = max(ans, curr);
        }
        return ans;
    }
};
