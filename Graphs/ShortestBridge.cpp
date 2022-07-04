class Solution {
public:
    //apply a dfs to find one full island. Then apply bfs to find the shortest distance to the other island.
    queue <pair<int,int>> q;
    void dfs(int i,int j,vector<vector<int>>& grid)
    {
        q.push(make_pair(i,j));
        grid[i][j]=-1;
        if(i<grid.size()-1 && grid[i+1][j]==1)
        {
            dfs(i+1,j,grid);
        }
        if(j<grid[i].size()-1 && grid[i][j+1]==1)
        {
            dfs(i,j+1,grid);
        }
        if(i>0 && grid[i-1][j]==1)
        {
            dfs(i-1,j,grid);
        }
        if(j>0 && grid[i][j-1]==1)
        {
            dfs(i,j-1,grid);
        }
        return;
    }
    int f=0;
    int shortestBridge(vector<vector<int>>& grid) 
    {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(i,j,grid);
                    f=1;
                    break;
                }
            }
            if(f)
            {
                break;
            }
        }
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            
            if(i<grid.size()-1 && grid[i+1][j]==0)
            {
                grid[i+1][j]=grid[i][j]-1;
                q.push(make_pair(i+1,j));
            }
            else if(i<grid.size()-1 && grid[i+1][j]==1)
            {
               break; 
            }
            if(j<grid[i].size()-1 && grid[i][j+1]==0)
            {
                 grid[i][j+1]=grid[i][j]-1;
                 q.push(make_pair(i,j+1));
            }
            else if(j<grid[i].size()-1 && grid[i][j+1]==1)
            {
               break; 
            }
            
             if(i>0 && grid[i-1][j]==0)
            {
                grid[i-1][j]=grid[i][j]-1;
                q.push(make_pair(i-1,j));
            }
            else if(i>0 && grid[i-1][j]==1)
            {
               break; 
            }
             if(j>0 && grid[i][j-1]==0)
            {
                grid[i][j-1]=grid[i][j]-1;
                q.push(make_pair(i,j-1));
            }
            else if(j>0 && grid[i][j-1]==1)
            {
               break; 
            }
            q.pop();
        }
        return (-grid[q.front().first][q.front().second])-1;
        
        
    }
};
