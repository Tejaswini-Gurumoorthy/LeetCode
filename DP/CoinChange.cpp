class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        sort(coins.begin(),coins.end());
        unsigned int dp[coins.size()+1][amount+1];
        unsigned int inf=INT_MAX;
        
        for(int i=0;i<=amount;i++)
        {
            dp[0][i]=inf;
        }
        
        for(int i=0;i<=coins.size();i++)
        {
            dp[i][0]=0;
        }
        
        for(int i=1;i<=coins.size();i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(j<coins[i-1])
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                dp[i][j]=min((1+dp[i][j-coins[i-1]]),dp[i-1][j]);
                }
            }
        }
        if(dp[coins.size()][amount]>=inf)
        {
            return -1;
        }
        else
        {
            return dp[coins.size()][amount];
        }
        
        
    }
};
