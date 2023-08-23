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
void f(int n, int arr[], vector<int> temp, int index, int sum, int target)
{
    if (index >= n)
    {
        if (sum == target)
        {
            for (int i = 0; i < temp.size(); i++)
            {
                cout << temp[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    else
    {
        temp.push_back(arr[index]);
        sum += arr[index];
        f(n, arr, temp, index + 1, sum, target);
        temp.pop_back();
        sum -= arr[index];
        f(n, arr, temp, index + 1, sum, target);
    }
}
int main()
{
    int n;
    cout << "Enter number of elements" << endl;
    cin >> n;
    int t;
    cout << "Enter Target" << endl;
    cin >> t;
    int arr[n];
    cout << "Enter Elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> temp;
    cout << "Desired Elements are:" << endl;
    f(n, arr, temp, 0, 0, t);

    return 0;
}