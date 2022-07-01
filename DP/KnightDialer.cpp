class Solution {
public:
     int possible_matrix[10][3]= {{4,6},{8,6},{9,7},{4,8},{3,9,0},{},{1,7,0},{2,6},{3,1},{2,4}}; //0 can land on 4/6, 1 can land on 8/6...
     int number_of_jumps[10]= {2,2,2,2,3,0,3,2,2,2}; //total number of possibilities.
    int sum=0; //ans will be sum of last row of dp table.
    int MOD= 1e9+7;
    int knightDialer(int n) 
    {
        unsigned int dp[n+1][10];
        for(int i=0;i<10;i++)
        {
            dp[0][i]=0;
            dp[1][i]=1; //if n=1, there is only one way in which landing can happen on all numbers.
            if(n>1)
            {
            dp[2][i]=number_of_jumps[i]; //if n=2 (for two steps), landing can be done in number_of_jumps ways.
            }
        }
		for(int i=3;i<=n;i++)
		{
			dp[i][5]=0;
		}
        for(int i=3;i<=n;i++)
        {
          for(int j=0;j<10;j++)
          {
			dp[i][j]=0;
              for(int k=0;k<number_of_jumps[j];k++)
              {
                  //dp[i-1][possible_matrix[j][k]]%=MOD;
                  dp[i][j]+=dp[i-1][possible_matrix[j][k]]%MOD;
              }
          }
        }
	
        for(int i=0;i<10;i++)
        {
            sum+=dp[n][i]%MOD;
        }
        return sum;
        
        
    }
};
