// Backtracking
#include <bits/stdc++.h>
using namespace ::std;
void print(int n, int i)
{
    if (i < 1)
    {
        cout << endl;
        return;
    }
    else
    {
        print(n,i-1);
        cout<<i<<" ";
    }
}
int main()
{
    int n;
    cin >> n;
    cout << "****************************************************************************" << endl;
    print(n, n);

    return 0;
}
