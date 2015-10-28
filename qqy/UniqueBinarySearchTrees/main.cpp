class Solution {
public:
    int numTrees(int n) {
        int *dp = new int[n+1];
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            int st = 0;
            for(int j=1;j <= i-2;j++){
                st += dp[j]*dp[i-1-j];
            }
            dp[i] = 2*dp[i-1] + st;
        }
        return dp[n];
    }
}; 
