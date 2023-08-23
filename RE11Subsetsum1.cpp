//***********************************ASHUTOSH KUMAR***********************************//
/*
कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥

Karmanye vadhikaraste Ma Phaleshu Kadachana,
Ma Karmaphalaheturbhurma Te Sangostvakarmani,

The meaning of the verse is :—
You have the right to work only but never to its fruits.
Let not the fruits of action be your motive, nor let your attachment be to
inaction
*/
#include <bits/stdc++.h>
using namespace ::std;
class Solution {
    private:
    void subset(int index,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans)
    {
        ans.push_back(temp);
        int n=nums.size();
        for(int i=index;i<n;i++)
        {
            if(i!=index&&nums[i]==nums[i-1])
            {
                continue;
            }
            temp.push_back(nums[i]); 
            subset(i+1,nums,temp,ans);    
            temp.pop_back(); 
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        subset(0,nums,temp,ans);
        return ans;
    }
};