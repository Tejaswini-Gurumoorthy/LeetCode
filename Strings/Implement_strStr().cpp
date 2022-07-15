class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int i=0,start=-1;
        while(i<haystack.size())
        {
            int k=i;
            start=i;
            int j=0;
            while(haystack[k]==needle[j] && j<needle.size())
            {
                if(j==needle.size()-1)
                {
                    return start;
                }
                j++;
                k++;
            }
            i++;
         }
        return -1;
    }
};
