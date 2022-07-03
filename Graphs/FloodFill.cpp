class Solution {
public:
    //similar to the number of islands problem
    void dfs(int i,int j,vector<vector<int>>& image,int color,int prev)
        {
                if(prev!=color)
                {
                image[i][j]=color;
                }
                else
                {
                    image[i][j]=-1;
                }
                if(i!=image.size()-1 && image[i+1][j]==prev)
                {
                    dfs(i+1,j,image,color,prev);
                }
                
                if(j!=image[i].size()-1 && image[i][j+1]==prev)
                {
                    dfs(i,j+1,image,color,prev);
                }
            
                if(i!=0 && image[i-1][j]==prev)
                {
                    dfs(i-1,j,image,color,prev);
                }
            
                if(j!=0 && image[i][j-1]==prev)
                {
                    dfs(i,j-1,image,color,prev);
                }
            return;
            }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int prev = image[sr][sc];
        
        dfs(sr,sc,image,color,prev);
        for(int i=0;i<image.size();i++)
        {
            for(int j=0;j<image[i].size();j++)
            {
                if(image[i][j]==-1)
                {
                    image[i][j]=color;
                }
            }
        }
        return image;
        
    }
};
