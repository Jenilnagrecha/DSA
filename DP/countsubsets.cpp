#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
int subsetsum(vector<int> ar,int sum, int n)
{
       vector<vector<int>> t(n+1,vector<int>(sum+1));
      for (int i = 0; i < n+1; i++)
      {
       t[i][0] = 1;
      }
      for (int i = 1; i < sum+1; i++)
      {
       t[0][i] = 0;
      }
 
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < sum+1; j++)
        {
            
           if (j < ar[i-1])
            {
                t[i][j] = t[i-1][j];
            }
            else
            {
                t[i][j] = ( t[i-1][j-ar[i-1]] + t[i-1][j] );
            }
            
        }
        
    }
 return t[n][sum];
  


   
    
}
int main()
{
ios_base::sync_with_stdio(false); cin.tie(NULL);
int n;
cin>>n;
int sum;
cin>>sum;
vector<int> ar(n);

for (int i = 0; i < n; i++)
{
   cin>>ar[i];
}

cout<< subsetsum(ar,sum,n);
    return 0;
}