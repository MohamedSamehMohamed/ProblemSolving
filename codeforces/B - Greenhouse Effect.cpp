// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
int n, m;
const int N = 5001;
int dp[N][N];
int a[N];
int rem[N][N];
int solve(int i = 0, int last = 1)
{
  if (i == n || last == m+1 )return 0;
  int &ret = dp[i][last];
  if (~ret)return ret ;
  ret = 1e9 ;
  if (a[i] < last)return ret = solve(i+1,last);
  if (rem[i][last] - (a[i] == last) == 0 ) return ret = solve(i+(a[i]==last),last+1);
  if (a[i] == last)return ret = solve(i+1, last);
  // a[i] > last
  ret = min(rem[i][last] + solve(i, last + 1),1+solve(i+1, last));
  return ret ;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    double t;
    memset(dp, -1, sizeof dp);
    for (int i =0; i < n ;i++)
    {
      cin >> a[i] >> t;
    }
    rem[n-1][a[n-1]]=1;
    for (int i = n-2 ;i >= 0 ;i--)
    {
      rem[i][a[i]]++;
      for (int j = 1 ; j <= m ;j++)
        rem[i][j]+=rem[i+1][j];
    }
    cout << solve() <<"\n";
}
