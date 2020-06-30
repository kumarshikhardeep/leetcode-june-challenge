class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (const auto& coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
        
        // int cols = amount+1;
        // int rows = coins.size();
        // int arr[rows][cols];
        // for(int i=0; i<rows; i++){
        //     arr[i][0] = 1;
        // }
        // for(int i=0; i<cols; i++){
        //     arr[0][i] = 1;
        // }
        // for(int i=1;i<rows; i++){
        //     for(int j=1; j<cols; j++){
        //         if(j>= coins[i]){
        //             arr[i][j] = arr[i-1][j] + arr[i][j-coins[i]];
        //         }
        //         else{
        //             arr[i][j] = arr[i-1][j];
        //         }
        //     }
        // }
    //     return arr[rows-1][cols-1];
    }
};
