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
const double PI = acos(-1);
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    int n;
    scanf("%d", &n);
    n *= 2;
    double r = (1.0/2)*(1.0/tan(PI/n));
    double R = r * (1.0/ cos(PI/n));
    r *= 2;
    R *= 2;
    if (r > R)swap(r, R);
    printf("%.9f\n", r);  
  }
}
