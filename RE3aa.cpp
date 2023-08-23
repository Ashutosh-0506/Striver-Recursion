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
void summ(long long n,long long i,long long sum)
{
    
    if(i>n)
    {
        cout<<sum<<endl;
        return;
    }
    else
    {
        sum+=i;
        summ(n,i+1,sum);
    }

}
int main()
{
    long long sum=0;
    long long n,i=1;
    cin>>n;
    summ(n,i,sum);
    return 0;
}