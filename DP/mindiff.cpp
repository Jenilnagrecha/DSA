#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
int subsetsum(vector<int> ar, int n)
{
    int sum =0;
    for (int i = 0; i < n; i++)
    {
      sum+=ar[i];
    }
    
       vector<vector<bool>> t(n+1,vector<bool>(sum+1));
      for (int i = 0; i < n+1; i++)
      {
       t[i][0] = true;
      }
      for (int i = 1; i < sum+1; i++)
      {
       t[0][i] = false;
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
                t[i][j] = ( t[i-1][j-ar[i-1]] || t[i-1][j] );
            }
            
        }
        
    }
    int mn =INT_MAX;
    for (int i = 0; i < sum/2+1; i++)
    {
        if (t[n][i])
        {
            mn=min(mn,sum-2*i);
        }
        
      
    }
    

 return mn;
    
}
int main()
{
ios_base::sync_with_stdio(false); cin.tie(NULL);
int n;
cin>>n;
vector<int> v(n);
for (int i = 0; i < n; i++)
{
   cin>>v[i];
}
cout<<subsetsum(v,n);
    return 0;
}