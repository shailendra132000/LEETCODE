class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        // edge case - empty columns or rows
        if (!grid.size() || !grid[0].size()) return 0;
        int x = grid[0].size() - 1, y = grid.size() - 1, qLen = 1;
        // edge cases - destination or starting point blocked
        if (grid[y][x] || grid[0][0]) return 0;
        // annoyingly necessarily cloned grid here
        long dp[y + 1][x + 1];
        for (int _y = 0; _y <= y; _y++) {
            for (int _x = 0; _x <= x; _x++) dp[_y][_x] = grid[_y][_x];
        }
        queue<pair<int, int>> nextLayer;
        nextLayer.push({x, y});
        dp[y][x] = -1;
        while (qLen) {
            for (int i = 0; i < qLen; i++ ) {
                x = nextLayer.front().first;
                y = nextLayer.front().second;
                // removing the used cell
                nextLayer.pop();
                // checking the cell on left of the current one
                if (x > 0 && dp[y][x - 1] < 1) {
                    if (dp[y][x - 1] == 0) nextLayer.push({x - 1, y});
                    dp[y][x - 1] += dp[y][x];
                }
                // checking the cell on top of the current one
                if (y > 0 && dp[y - 1][x] < 1) {
                    nextLayer.push({x, y - 1});
                    dp[y - 1][x] += dp[y][x];
                }
            }
            // preparing for the next run
            qLen = nextLayer.size();
        }
        return -dp[0][0];
    }
};