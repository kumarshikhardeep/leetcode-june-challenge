class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols,0));
        dp[rows-1][cols-1] = dungeon[rows-1][cols-1] > 0 ? 1 : abs(dungeon[rows-1][cols-1]) + 1;
        for(int i = rows-2; i>=0; i--){
            dp[i][cols-1] = max(dp[i+1][cols-1] - dungeon[i][cols-1], 1);
        }
        for(int i = cols-2; i>=0; i--){
            dp[rows-1][i] = max(dp[rows-1][i+1] - dungeon[rows-1][i], 1);
        }
        for(int i=rows-2; i>=0; i--){
            for(int j=cols-2; j>=0; j--){
                int minExit = min(dp[i+1][j], dp[i][j+1]);
                dp[i][j] = max(minExit - dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }
};
