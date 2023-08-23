#include <bits/stdc++.h>
using namespace ::std;
void print(int n,int i)
{
    if (i>n)
    {
        cout << endl;
        return;
    }
    else
    {
        cout << i << " ";
        print(n,i+1);
    }
}
int main()
{
    int n;
    cin >> n;
    int i=1;
    cout << "**************************************************************************" << endl;
    print(n,i);
    return 0;
}