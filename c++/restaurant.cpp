
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n, m;
  cin >> n >> m;
  vector<ll> d(n);
  rep(i,n-1) {
    ll a;
    cin >> a;
    d[i+1] = d[i] + a;
  }
  vector<vector<ll>> dp(n+1,vector<ll>(n+1)), b(n,vector<ll>(m));
  rep(i,n) rep(j,m) cin >> b[i][j];
  rep(i,m) {
    vector<ll> v;
    rep(j,n) v.push_back(b[j][i]);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int sz = v.size();
    rep(j,n) b[j][i] = lower_bound(v.begin(),v.end(),b[j][i]) - v.begin();
    vector<vector<int>> pos(sz);
    rep(j,n) pos[b[j][i]].push_back(j);
    set<int> st;
    st.insert(n); st.insert(-1);
    for(int k = sz-1; k >= 0; k--) {
      for(auto x : pos[k]) {
        st.insert(x);
        int l, r;
        auto itr = st.upper_bound(x);
        r = (*itr)-1;
        itr = st.lower_bound(x);
        itr--;
        l = (*itr)+1;
        dp[l][x] += v[k];
        dp[x+1][x] -= v[k];
        dp[l][r+1] -= v[k];
        dp[x+1][r+1] += v[k];
      }
    }
  }
  rep(i,n) for(int j = 1; j < n; j++) dp[i][j] += dp[i][j-1];
  rep(j,n) for(int i = 1; i < n; i++) dp[i][j] += dp[i-1][j];
  ll ans = 0;
  rep(i,n) for(int j = i; j < n; j++) ans = max(ans,dp[i][j]-d[j]+d[i]);
  cout << ans << endl;
  return 0;
}
