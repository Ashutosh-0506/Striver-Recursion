#include <bits/stdc++.h>
using namespace ::std;
void print(int n,int i)
{
    if (i<1)
    {
        cout << endl;
        return;
    }
    else
    {
        cout << i << " ";
        print(n,i-1);
    }
}
int main()
{
    int n;
    cin >> n;
    cout << "**************************************************************************" << endl;
    print(n,n);//Without taking a second variable i we can aslo do the same old int i=n ans then input print(n,i); but this is way more cooler!
    return 0;
}