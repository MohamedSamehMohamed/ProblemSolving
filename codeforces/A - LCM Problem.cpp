// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int l, r;
    cin >> l >> r;
    if (l+l <= r)
      cout << l <<" " << l+l <<"\n";
    else
      cout << "-1 -1\n";
  }
}
