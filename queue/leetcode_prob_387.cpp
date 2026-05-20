class Solution {
public:
    int firstUniqChar(string s) {
        queue<char>q;
        vector<int>counter(26,0);
        for(int i=0;i<s.length();i++)
        {
        
              q.push(s[i]);
             counter[q.back()-'a']++;
        }
        int i=0;
        while(!q.empty())
        {
            if(counter[q.front()-'a']>1)
            {
                   q.pop();
            }
            else
            {
                return i;
            }
           i++;
        }
        if(q.empty())
        return -1;
        return 0;
    }
};