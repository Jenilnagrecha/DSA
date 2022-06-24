#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
int ls(string s1,string s2, int m,int n)
{
    int t[m+1][n+1];
    for (int i = 0; i < m+1; i++)
    {
       for (int j = 0; j < n+1; j++)
       {
          if (i == 0|| j == 0)
          {
             t[i][j]=0;
          }
          
          else if (s1[i-1] == s2[j-1])
          {
             t[i][j] = 1+t[i-1][j-1];
          }
          else
          {
            t[i][j] =0;
          }
          
       }
       
    }
    sort(t,t+((m+1)*(n+1)));
    return t[0][0];
}
int main()
{
ios_base::sync_with_stdio(false); cin.tie(NULL);
string s1,s2;
cin>>s1>>s2;
cout<<ls(s1,s2,s1.size(),s2.size());
    return 0;
}