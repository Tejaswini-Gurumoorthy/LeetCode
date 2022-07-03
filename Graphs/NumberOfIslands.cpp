class Solution {
public:
            
    int numIslands(vector<vector<char>>& grid) 
    {
        //apply dfs from any 1.
        //change the traversed 1s as 2.
        //count number of times dfs was called.
        
        unsigned int cnt=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1' )
                {
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
    
    void dfs(int i,int j,vector<vector<char>>& grid)
    {
        grid[i][j]=2; 
        
        if(j!=grid[i].size()-1 && grid[i][j+1]=='1' )
        {
            dfs(i,j+1,grid);
        }
        if(i!=grid.size()-1 && grid[i+1][j]=='1' )
        {
            dfs(i+1,j,grid);
        }
        if(j!=0 && grid[i][j-1]=='1')
        {
             dfs(i,j-1,grid);
        }
        if(i!=0 && grid[i-1][j]=='1')
        {
            dfs(i-1,j,grid);
        }
        return;
    }
};
