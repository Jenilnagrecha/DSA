#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
string ls(string s1,string s2, int m,int n)
{
    int t[m+1][n+1];
    string v;
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
            t[i][j] =max(t[i][j-1],t[i-1][j]);
          }
          
       }
       
    }
    int i=m, j=n;
    while (i<=0 && j<=0)
    {
        if (s1[i] == s2[j])
        {
            v.push_back(s1[i]);
        }

        else if(t[i-1][j-1] == max(t[i-1][j],max(t[i][j-1],t[i-1][j-1])))
        {
            i=i-1;
            j=j-1;
        }
        
         else if (t[i-1][j] == max(t[i-1][j],max(t[i][j-1],t[i-1][j-1])))
        {
            i=i-1;
            j=j;
        }
        else
        {
            i=i;
            j=j-1;
        }
        
        
    }
    reverse(v.begin(),v.end());
    return v;
}
int main()
{
ios_base::sync_with_stdio(false); cin.tie(NULL);
string s1,s2;
cin>>s1>>s2;
cout<<ls(s1,s2,s1.size(),s2.size());
    return 0;
}