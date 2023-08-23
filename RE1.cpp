#include <bits/stdc++.h>
using namespace ::std;
int cnt = 0;
void rec()
{
    if (cnt == 3)
        return;
    cout << cnt << endl;
    cnt++;
    rec();
}

int main()
{
    rec();
    return 0;
}