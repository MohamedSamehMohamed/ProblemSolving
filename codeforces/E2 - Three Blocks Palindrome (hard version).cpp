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
int t ;
const int M = 2e5 + 9; 
int a[M]; 
int frq[203]; 
int n;
int pre[M][203]; 
vector<int> adj[203]; 
int Sum (int l , int r , int val)
{
    if (l > r)return 0; 
    int ans = pre[r][val]; 
    if (l >= 0 )ans -= pre[l][val]; 
    return ans ; 
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t ;
    while (t--)
    {
        cin >> n ;
        memset(frq, 0, sizeof frq); 
        for (int i =0 ; i < 203 ;i++)
        adj[i].clear(); 
        for (int i =0 ; i < n ;i++)
        {
            for (int j=0; j < 203 ;j++)
            pre[i][j] =0; 
        }
        int ans =0 ; 
        for (int i =0 ; i < n ;i++)
        {
            cin >> a[i];
            adj[ a[i] ].pb(i); 
            pre[ i ][ a[i] ]++; 
            frq[ a[i] ]++;
            if (i)
            {
                for (int j =0 ; j < 203 ;j++)
                {
                    pre[i][j] += pre[i-1][j]; 
                }
            }
        }
        for (int i =0 ; i < 203 ;i++)ans = max (frq[i] , ans ); 
        for (int i=1 ; i <= 200 ;i++)
        {
            if ( SZ(adj[i]) == 0  )continue ;
            for (int l = 0 , r = SZ(adj[i])-1 ; l < r ;l++,r--)
            {
                int cur = (l+1)*2 ; 
                int mx = 0;
               // cout << cur <<" ";
                for (int k = 1;  k <= 200 ;k++)
                {
                    if (k == i )continue ; 
                    mx = max (mx , Sum( adj[i][l]  , adj[i][r]-1 , k)); 
                }
                //cout << mx <<"\n"; 
                ans = max (ans , cur + mx ); 
            }
        }
        cout << ans <<"\n"; 
    }
}
