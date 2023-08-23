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
vector<vector<int>> subsequencessum(int n, int arr[], vector<int> temp, vector<vector<int>> val, int index)
{
    if (index >= n)
    {
        vector<int> ans;
        for (int i = 0; i < temp.size(); i++)
        {
            ans.push_back(temp[i]);
        }
        val.push_back(ans);
    }
    else
    {
        temp.push_back(arr[index]);
        subsequencessum(n, arr, temp, val, index + 1);
        temp.pop_back();
        subsequencessum(n, arr, temp, val, index + 1);
    }
}
int main()
{
    int n, target;
    cout << "Enter number of elements" << endl;
    cin >> n;
    cout << "Enter Target" << endl;
    cin >> target;
    int arr[n];
    cout << "Enter Elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> temp;
    vector<vector<int>> fin;
    fin = subsequencessum(n, arr, temp, fin, 0);
    for (int i = 0; i < fin.size(); i++)
    {
        int m = fin[i].size();
        for (int j = 0; j < m; j++)
        {
            int sum = 0;
            sum = fin[i][j] + sum;
            if (sum != target)
            {
                for (int k = 0; k < m; k++)
                {
                    cout << fin[i][k] << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}