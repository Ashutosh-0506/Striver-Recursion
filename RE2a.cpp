#include <bits/stdc++.h>
using namespace ::std;
void print(string st,int i,int n)
{
    if (i>n)
        return;
    cout << st << endl;
    print(st,i+1,n);
}
int main()
{
    string st;
    cin >> st;
    int i=1,n;
    cin>>n;
    cout<<"**************************************************************************"<<endl;
    print(st,i,n);
    return 0;
}