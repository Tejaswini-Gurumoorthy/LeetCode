class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n=height.size();
        int left[n],right[n];
        left[0]=0;
        right[n-1]=0;
        int sum=0;
        for(int i=1;i<n;i++)
        {
            left[i]=max(left[i-1],height[i-1]);
        }
        for(int i=n-2;i>=0;i--)
        {
            right[i]=max(right[i+1],height[i+1]);
        }
        for(int i=0;i<n;i++)
        {
            if(left[i]==0 || right[i]==0)
            {
                continue;
            }
            else
            {
                if(min(left[i],right[i])>height[i])
                {
                    sum+=min(left[i],right[i])-height[i];
                }
            }
        }
        return sum;
    }
};
