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
class Solution
{
private:
    void solve(vector<string> &v, vector<vector<string>> &ans, vector<int> &left, vector<int> &upDiag, vector<int> &downDiag, int n, int col)
    {
        if (col == n)
        {
            ans.push_back(v);
        }
        for (int row = 0; row < n; row++)
        {
            if ((left[row] == 0) && (upDiag[n + col - row - 1] == 0) && (downDiag[row + col] == 0))
            {
                v[row][col] = 'Q';
                left[row] = 1;
                upDiag[n + col - row - 1] = 1;
                downDiag[row + col] = 1;
                solve(v, ans, left, upDiag, downDiag, n, col + 1);
                v[row][col] = '.';
                left[row] = 0;
                upDiag[n + col - row - 1] = 0;
                downDiag[row + col] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> v(n);
        string st(n, '.');
        for (int i = 0; i < n; i++)
        {
            v[i] = st;
        }
        vector<vector<string>> ans;
        vector<int> left(n, 0);
        vector<int> upDiag(2 * n - 1, 0);
        vector<int> downDiag(2 * n - 1, 0);
        int col = 0;
        solve(v, ans, left, upDiag, downDiag, n, col);
        return ans;
    }
};