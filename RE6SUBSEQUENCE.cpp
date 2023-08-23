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
void subsequence(int n,int arr[],vector<int>&temp,int index)
{
    if(index>=n)
    {
        for (int i=0;i<temp.size();i++)
        {
            cout<<temp[i]<<" ";
        }
        cout<<endl;
        return;
    }
    else
    {   //Pick
        temp.push_back(arr[index]);
        subsequence(n,arr,temp,index+1);
        //Not Pick
        temp.pop_back();
        subsequence(n,arr,temp,index+1);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    vector<int>temp;
    cout<<"The subsequence of the array is:-"<<endl;
    subsequence(n,arr,temp,0);
    
    return 0;
}