class Solution {
public:
    int dp[3001][1005];
    int mod=1e9+7;
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(startPos,endPos,k);
    }
    int solve(int s,int e,int k){
        if(k==0) return s==e;
        if(dp[s+1000][k]!=-1) return dp[s+1000][k];
        int l=solve(s+1,e,k-1)%mod;
        int r=solve(s-1,e,k-1)%mod;
        return dp[s+1000][k]=(l+r)%mod;
    }
};
