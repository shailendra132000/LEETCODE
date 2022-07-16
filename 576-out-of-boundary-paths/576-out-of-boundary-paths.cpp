class Solution {
public:
    int mod = pow(10, 9) + 7;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int dp[51][51][51];
    
    int ff(int m, int n, int N, int i, int j) {
        if (i >= m || j >= n || i < 0 || j < 0) return 1;
        if (N <= 0) return 0;
        if (dp[i][j][N] != -1) return dp[i][j][N];

        int totalPaths = 0;
        
        for (int k=0; k<4; k++) {
            totalPaths += ff(m, n, N - 1, i + dx[k], j + dy[k]) % mod;
            totalPaths %= mod;
        }
        
        return dp[i][j][N] = totalPaths % mod;
    }
     
    int findPaths(int m, int n, int N, int i, int j) {
        memset(dp, -1, sizeof dp);
        return ff(m, n, N, i, j);
    }
};