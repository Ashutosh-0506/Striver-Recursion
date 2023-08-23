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
    void selector(int index, int target, vector<int> &candidates, vector<int> &temp, map<vector<int>,int> &ans)
    {
        if (index == candidates.size())
        {
            if (target == 0)
            {
                ans[temp]++;
            }
            return;
        }
        else
        {
            if (candidates[index] <= target)
            {
                temp.push_back(candidates[index]);
                selector(index+1, target - candidates[index], candidates, temp, ans);
                temp.pop_back();
            }
            selector(index + 1, target, candidates, temp, ans);
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<vector<int>,int>ans;
        vector<vector<int>>fin;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        selector(0, target, candidates, temp, ans);
        for(auto i:ans)
        {
            fin.push_back(i.first);
        }
        return fin;
    }
};
int main()
{

    return 0;
}