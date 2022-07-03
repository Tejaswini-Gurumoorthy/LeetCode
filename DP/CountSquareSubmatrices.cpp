class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) 
    {
        //create a 2d array, where in each position, it will hold the number of square matrices ending at that point.
        //for this, do -> 1+ min(top left,top, left)
        //for answer, add all the elements of the created array.
        
        int dp[matrix.size()][matrix[0].size()];
        int sum=0;
        //vector<int> temp;
        for(int i=0;i<matrix[0].size();i++)
        {
            dp[0][i]=matrix[0][i];
        }
        for(int i=0;i<matrix.size();i++)
        {
            dp[i][0]=matrix[i][0];
        }
        
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=1;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==1)
                {
                    //temp.push_back(dp[i][j-1]);
                    //temp.push_back(dp[i-1][j-1]);
                    //temp.push_back(dp[i-1][j]);
                    //sort(temp.begin(),temp.end());
                    //dp[i][j]=1+temp[0];
                    //temp.clear();
                    int temp=min(dp[i][j-1],dp[i-1][j-1]);
                    dp[i][j]=1+min(temp,dp[i-1][j]);
                    temp=0;
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                sum+=dp[i][j];
            }
        }
        return sum;
        
    }
};
