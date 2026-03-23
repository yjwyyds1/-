//https://codeforces.com/contest/1644/problem/D
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
using PIII=pair<int,pair<int,int>>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e4+10;
const int M=2e6+10;
// const int mod = 1000000007;
const int mod = 998244353;
//随机化
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> Tp(1, 100);
// cout<<fixed<<setprecision(10);

// 想错了 正着考虑很不好做 一直在想怎么维护之前被覆盖的操作
// 因为每一个位置的颜色取决于最后一次操作 所以倒着记录 然后就是 
// 如果当前操作的行列都以及被之后的覆盖过了vx[x[i]]&&vy[y[i]] 就不管
// 最那个的就是 当时一直在想如果全部的行/列 被操作完了之前的列/行就要重新维护了
// 实际上 全部的行/列 被操作完了 就不会再变了 最多应该就是k^min(n,m)
// 再操作也不会有新的位置被行列操作
void solve(){
    ll n,m,k,q;
    cin>>n>>m>>k>>q;
    vector<int> x(q+1),y(q+1);
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    int cx=0,cy=0;
    ll ans=1;
    vector<int> vx(n+1,0),vy(m+1,0);
    for(int i=q;i>=1;i--){
        if(vx[x[i]]&&vy[y[i]])continue;
        if(cx==n||cy==m)break;
        ans=(ans*k)%mod;
        if(!vx[x[i]])cx++;
        if(!vy[y[i]])cy++;
        vx[x[i]]=vy[y[i]]=1;
    }
    cout<<ans<<'\n';
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
