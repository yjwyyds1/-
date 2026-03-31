//https://atcoder.jp/contests/abc449/tasks/abc449_d
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
//
ll f(ll l1,ll r1,ll l2,ll r2){
    ll L=max(l1,l2);
    ll R=min(r1,r2);
    if(L>R)return 0;
    else return R-L+1;
}
ll g(ll l,ll r){
    if(l>r)return 0;
    else{
        int len=r-l+1;
        if(len%2==0)return len/2;
        else return (l%2==0?1:0)+len/2;
    }
}
void solve(){
    ll l,r,d,u;
    cin>>l>>r>>d>>u;
    // for(int i=l;i<=r;i++){
    //     int p=0;
    //     for(int j=d;j<=u;j++){
    //         if(max(abs(i),abs(j))%2==0){
    //             p++;
    //         }
    //     }
    //     cout<<i<<" "<<p<<'\n';
    // }
    ll ans=0;
    for(int i=l;i<=r;i++){
        ll x=abs(i);
        ll res=0;
        if(x%2==0){
            res+=f(-x,x,d,u);
        }
        res+=g(d,min(u,-(x+1)));
        res+=g(max(d,x+1),u);
        // if(x&1){
        //     if(d<0){
        //         res+=g(x+1,-d);
        //         res+=g(x+1,u);
        //     }else{
        //         res+=g(max(x+1,d),u);
        //     }
        // }else{
        //     res+=f(-x,x,d,u);
        //     res+=g(d,-x-1);
        //     res+=g(x+1,u);
        // }
        // cout<<i<<" "<<res<<'\n';
        ans+=res;
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
