class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();

        auto coor = [&](int x) {

            int r = (x - 1) / n;
            int c = (x - 1) % n;
            if (r % 2 == 1) c = n - 1 - c;

            return make_pair(n - 1 - r, c);
        };

        vector<int> dist(n * n + 1, -1);
        queue<int> q;
        q.push(1);
        dist[1] = 0;

        while (!q.empty()) {

            int curr = q.front();
            q.pop();

            for (int i = 1; i <= 6; ++i) {

                int next = curr + i;
                if (next > n * n) continue;

                auto [r, c] = coor(next);
                if (board[r][c] != -1)  // follow snake or ladder
                    next = board[r][c];

                if(next == n*n)
                    return dist[curr] + 1 ;

                if (dist[next] == -1) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
        }

        return dist[n * n]; // or -1 
    }
};
