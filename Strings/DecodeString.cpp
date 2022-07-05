class Solution {
public:
    string decodeString(string s) 
    {
        stack <char> st;
        int i=0;
        while(s[i]!='\0')
        {
            if(s[i]!=']')
            {
                st.push(s[i]);
            }
            else
            {
                string temp; //to store characters inside a []
                while(st.top()!='[')
                {
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                reverse(temp.begin(),temp.end());
                string n;
                while((!st.empty()) && (st.top()>='0' && st.top()<='9' ))
                {
                    n+=st.top();
                    st.pop();
                }
                //n+='\0';
                reverse(n.begin(),n.end());
                int num=0;
                for(int x=0;x<n.size();x++)
                {
                    num= (num*10) + (n[x]-'0');
                }
                for(int k=0;k<num;k++)
                {
                    for(int l=0;l<temp.size();l++)
                    {
                        st.push(temp[l]);
                    }
                }
            }
            i++;
        }
        string ans;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
