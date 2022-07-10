class Solution 
{
    struct node
    {
        int no;
        int freq;
        node(int a,int b)
        {
            no=a;
            freq=b;
        }
    };
    struct cmp
    {
        bool operator()(node const& a, node const& b)
        {
            return a.freq<b.freq;
        }
    };
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {  
       //storing frequency of all elements in a map.
        unordered_map<int,int> m;
        for(int ele: nums)
        {
            m[ele]++;
        }
        
        //building heap for these value,frequency pairs.
        priority_queue<node,vector<node>,cmp>heap; //vector <node> for maintaining heap as an array.
        for(auto it:m)
        {
            heap.push(node(it.first,it.second)); //make node and push into heap
        }
        vector <int> ans; //for top k elements
        
        while(k--)
        {
            node temp= heap.top();
            heap.pop();
            ans.push_back(temp.no);
        }
        return ans;
    }
};
