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
    bool isSafe(int row,int col,vector<string>&v)
    {
        int n=v.size();
        int duprow=row;
        int dupcol=col;
        while(row>=0&&col>=0)
        {
            if(v[row][col]=='Q')
            {
                return false;
            }
            row--;
            col--;
        }
        row=duprow;
        col=dupcol;
        while(col>=0)
        {
             if(v[row][col]=='Q')
            {
                return false;
            }
            col--;
        }
        row=duprow;
        col=dupcol;
        while(row<n&&col>=0)
        {
            if(v[row][col]=='Q')
            {
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    void solve(vector<vector<string>>&ans, vector<string>&v,int col)
    {   
        int n=v.size();
        if(col==n)
        {
            ans.push_back(v);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,v))
            {
                v[row][col]='Q';
                solve(ans,v,col+1);
                v[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>>ans;
        vector<string>v(n);
        string st(n,'.');
        for(int i=0;i<n;i++)
        {
            v[i]=st;
        }   
        solve(ans,v,0);
        return ans;
    }
};