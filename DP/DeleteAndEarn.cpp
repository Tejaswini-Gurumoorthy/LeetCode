class Solution {
public:
    int N=20000;
    int deleteAndEarn(vector<int>& nums) 
    {
        vector<int> cnt(N,0); //maintaining cnt array to store number of times each element occurs.
        sort(nums.begin(),nums.end()); 
        for(int i=0;i<nums.size();i++)
        {
                ++cnt[nums[i]]; //filling cnt array
        }
        auto end_iter= unique(nums.begin(),nums.end()); //removing duplicates
        nums.resize(distance(nums.begin(),end_iter));
        
        int e1= cnt[nums[0]]*nums[0]; //e1= total points we can get with the first number.
        int curr= cnt[nums[1]]*nums[1]; //total points we can get with the current number
        int e2=0;
        if(nums[1]==nums[0]+1) //if 2nd number if (1+ 1st number)
        {
            e2= max(e1,curr); 
        }
        else
        {
            e2=e1;
        }
        for(int i=2;i<nums.size();i++)
        {
            int temp;
            curr= nums[i]*cnt[nums[i]];
            if(nums[i]==nums[i-1]+1)
            {
               temp=max(e2,e1+curr);
            }
            else
            {
                temp=e2+curr;
            }
            e1=e2; //e1 is always nums[i-2]'s max points
            e2=temp; //e2 is always nums[i-1]'s max points
        }
        
        return e2;
    }
};
