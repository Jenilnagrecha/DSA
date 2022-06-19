#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
int knapsack(vector<int> wt,vector<int> val,int W, int n)
{
    vector<vector<int>> t(n+1,vector<int>(W+1));

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < W+1; j++)
        {
            if(i ==0|| j== 0)
            {
               t[i][j] =0;
            }
            else if (W < wt[i-1])
            {
                t[i][j] = t[i-1][j];
            }
            else
            {
                t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]],t[i][j] = t[i-1][j] );
            }
            
        }
        
    }
    return t[n][W];
    
}
int main()
{
ios_base::sync_with_stdio(false); cin.tie(NULL);
int n;
cin>>n;
int w;
cin>>w;
vector<int> wt(n);
vector<int> val(n);
for (int i = 0; i < n; i++)
{
   cin>>val[i];
}
for (int i = 0; i < n; i++)
{
   cin>>wt[i];
}
cout<< knapsack(wt,val,w,n)<<endl;
    return 0;
}