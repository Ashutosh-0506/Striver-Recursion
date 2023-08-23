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
#include<bits/stdc++.h>
using namespace::std;
class Solution
{
    bool isSafe(bool graph[101][101], int m, int n, vector<int> &color, int node, int col)
    {
        for (int i = 0; i < n; i++)
        {
            if (node != i && graph[i][node] == 1 && color[i] == col)
            {
                return false;
            }
        }
        return true;
    }

private:
    bool solve(bool graph[101][101], vector<int> &color, int m, int n, int node)
    {
        if (node == n)
        {
            return true;
        }
        for (int i = 1; i <= m; i++)
        {
            if (isSafe(graph, m, n, color, node, i))
            {
                color[node] = i;
                if (solve(graph, color, m, n, node + 1))
                {
                    return true;
                }
                color[node] = 0;
            }
        }
        return false;
    }

public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n)
    {
        vector<int> color(n, 0);
        int node = 0;
        if (solve(graph, color, m, n, node))
        {
            return true;
        }
        return false;
    }
};