//https://codeforces.com/contest/2096/problem/C
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
using PIII=pair<int,pair<int,int>>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=2e5+10;
const int M=2e6+10;
// const int mod = 1000000007;
const int mod = 998244353;
//随机化
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> Tp(1, 100);
// cout<<fixed<<setprecision(10);



// 关键想到可以把行列分开考虑，要观察发现到他们不会相互影响
// 那么如果只考虑行列分别美好，那么合并之后整个矩阵就美好了
// 然后就是正常的转移讨论了
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> a(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    vector<ll> c(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    vector<vector<ll>> dp1(n+1,vector<ll>(2,1e18));
    dp1[1][1]=b[1];
    dp1[1][0]=0;
    for(int j=2;j<=n;j++){
        int c1=1,c2=1,c3=1;
        for(int i=1;i<=n;i++){
            if(a[i][j]==a[i][j-1]){
                c1=0;
            }else if(a[i][j]+1==a[i][j-1]){
                c2=0;
            }else if(a[i][j]==a[i][j-1]+1){
                c3=0;
            }
        }
        if(c1){
            dp1[j][1]=min(dp1[j-1][1]+b[j],dp1[j][1]);
            dp1[j][0]=min(dp1[j-1][0],dp1[j][0]);
        }
        if(c2){
            dp1[j][1]=min(dp1[j-1][0]+b[j],dp1[j][1]);
        }
        if(c3){
            dp1[j][0]=min(dp1[j-1][1],dp1[j][0]);
        }
    }
    // cout<<dp1[n][0]<<" "<<dp1[n][1]<<'\n';
    ll r1=min(dp1[n][1],dp1[n][0]);
    vector<vector<ll>> dp2(n+1,vector<ll>(2,1e18));
    dp2[1][1]=c[1];
    dp2[1][0]=0;
    for(int i=2;i<=n;i++){
        int c1=1,c2=1,c3=1;
        for(int j=1;j<=n;j++){
            if(a[i-1][j]==a[i][j]){
                c1=0;
            }else if(a[i-1][j]==a[i][j]+1){
                c2=0;
            }else if(a[i-1][j]+1==a[i][j]){
                c3=0;
            }
        }
        if(c1){
            dp2[i][1]=min(dp2[i-1][1]+c[i],dp2[i][1]);
            dp2[i][0]=min(dp2[i-1][0],dp2[i][0]);
        }
        if(c2){
            dp2[i][1]=min(dp2[i-1][0]+c[i],dp2[i][1]);
        }
        if(c3){
            dp2[i][0]=min(dp2[i-1][1],dp2[i][0]);
        }
    }
    // cout<<dp2[n][0]<<" "<<dp2[n][1]<<'\n';
    ll r2=min(dp2[n][0],dp2[n][1]);
    if(r1==1e18||r2==1e18)cout<<-1<<'\n';
    else cout<<r1+r2<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}

// 00 c1
// 11
// 01 c2
// 10 c3
