#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
bool subsetsum(vector<int> ar,int sum, int n)
{
       vector<vector<int>> t(n+1,vector<int>(sum+1));
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
 return t[n][sum];
}
int sum(vector<int> v)
{
    int sm=0;
    for (int i = 0; i < v.size(); i++)
    {
       sm+=v[i];
    }
    if (sm%2 == 0)
    {
        if (subsetsum(v,sm/2,v.size()))
        {
           cout<<"Yes";
        }
        else
        {
            cout<<"No";
        }
        return 0;
    }
    cout<<"NO";
    return 0;
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

 sum(v);
 
    return 0;
}