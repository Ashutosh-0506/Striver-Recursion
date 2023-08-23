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
void summ(int i,int sum)
{
    
    if(i<1)
    {
        cout<<sum<<endl;
        return;
    }
    else
    {
        summ(i-1,sum+i);//Paramiterised Way
    }

}
int main()
{
    int sum=0;
    int n;
    cin>>n;
    summ(n,sum);
    return 0;
}