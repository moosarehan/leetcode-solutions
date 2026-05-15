class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dk;
        int windowsize=k;
        if(nums.size()==1)
        {
            ans.push_back(nums[0]);
            return ans;
            
        }
        for(int i=0;i<k;i++){

        if(dk.empty())
            {
                dk.push_back(i);
            }
            else
            {
          while(!dk.empty()&&nums[i]>=nums[dk.back()])
            {
            dk.pop_back();
            }
                dk.push_back(i);

            }
         
        }
        ans.push_back(nums[dk.front()]);
        for(int i=k;i<nums.size();i++){
           int index=i-windowsize;
           if(dk.front()==index)
           {
              if(!dk.empty())
              {
                dk.pop_front();
              }
           }
           while(!dk.empty()&&nums[i]>nums[dk.back()])
           {
            dk.pop_back();
           }
           dk.push_back(i);
          ans.push_back(nums[dk.front()]);

        }
        return ans;

    }
};