class Solution {
public:
    
    
    // Time complexity -> number of state x avg transition cost
    // which is O(m*n*m*n) = O(m^2 x n^2) 
    // Space complexity -> O(m^2 x n)
    
    vector<vector<int>> cost;
    int m,n,target;
    vector<int> houses;
    const int inf = 1e9;
    
    // state - index, previous color, neighbourhood number
    int dp[101][21][101];
    
    
    int rec(int level,int prev,int stage){
        // we have made choices for all houses
        if(level == m){
            // if number of neighbourhood is same as target we are done
            if(stage == target) return 0;
            return inf;
        }
        
        if(dp[level][prev][stage] != -1) return dp[level][prev][stage];
        
        int ans = inf;
        
        // if its 0 then we have choice to take color from 1 to n
        if(houses[level] == 0){
        for(int choice=1;choice<=n;choice++){
            // if current choice of color is same as previous then neighbourhood doesnt change
            if(choice == prev){
                ans = min(ans,cost[level][choice-1]+rec(level+1,choice,stage));
            }
            // otherwise it increases by 1
            else{
                ans = min(ans,cost[level][choice-1]+rec(level+1,choice,stage+1));
            }
        }
        }
        // if its already painted we dont have to pay any cost
        else{
            if(prev == houses[level]) ans = min(ans,rec(level+1,prev,stage));
            else ans = min(ans,rec(level+1,houses[level],stage+1));
        }
        return dp[level][prev][stage] = ans;
    }
    
    int minCost(vector<int>& _houses, vector<vector<int>>& _cost, int _m, int _n, int _target) {
        cost = _cost;
        m = _m;
        n = _n;
        houses = _houses;
        target = _target;
        memset(dp,-1,sizeof(dp));
        // if its not possible to achieve target, it will return inf
        if(rec(0,0,0) == inf) return -1;
        return rec(0,0,0);
    }
};