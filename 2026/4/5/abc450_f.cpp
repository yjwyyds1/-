//https://atcoder.jp/contests/abc450/tasks/abc450_f
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


// 相比于只有区间加 这个的pushdown下传跟计算有变化
// m=m*mul
// a=a*mul+x
// sum=sum*mul+len*x
struct Tree{
    int l,r;
    ll sum;
    ll a,m;
}tr[N<<2];
int a[N];
void f(struct Tree&d,ll mul,ll x){
    d.m=(d.m*mul)%mod;
    d.a=((d.a*mul)%mod+x)%mod;
    d.sum=((d.sum*mul)%mod+((d.r-d.l+1)*x)%mod)%mod;
}
void pushdown(int p){
    f(tr[p<<1],tr[p].m,tr[p].a);
    f(tr[p<<1|1],tr[p].m,tr[p].a);
    tr[p].m=1,tr[p].a=0;
}
void pushup(int p){
    tr[p].sum=(tr[p<<1].sum+tr[p<<1|1].sum)%mod;
}
void build(int p,int l,int r){
    tr[p].l=l;
    tr[p].r=r;
    tr[p].m=1,tr[p].a=0;
    if(l==r){    
        tr[p].sum=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    pushup(p);
}
void updata(int p,int l,int r,ll mul,ll x){
    if(r<tr[p].l||tr[p].r<l){
        return ;
    }
    if(l<=tr[p].l&&tr[p].r<=r){
        f(tr[p],mul,x);
        return ;
    }
    pushdown(p);
    updata(p<<1,l,r,mul,x);
    updata(p<<1|1,l,r,mul,x);
    pushup(p);
}
ll query(int p,int l,int r){
    if(r<tr[p].l||tr[p].r<l){
        return 0;
    }
    if(l<=tr[p].l&&tr[p].r<=r){
        return tr[p].sum;
    }
    pushdown(p);
    ll res=0;
    res+=query(p<<1,l,r);
    res%=mod;
    res+=query(p<<1|1,l,r);
    res%=mod;
    return res;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> a(m);
    for(int i=0;i<m;i++){
        cin>>a[i].first>>a[i].second;
    }
    build(1,1,n);
    updata(1,1,1,1,1);
    sort(a.begin(),a.end());
    for(int i=0;i<m;i++){
        int l=a[i].first,r=a[i].second;
        if(r+1<=n)updata(1,r+1,n,2,0);
        ll res=query(1,l,r)%mod;
        updata(1,r,r,1,res);
    }
    cout<<query(1,n,n)<<'\n';
    // int n,q,t;
    // cin>>n>>q>>t;
    // for(int i=1;i<=n;i++){
    //     cin>>a[i];
    // }
    // build(1,1,n);
    // for(int i=1;i<=q;i++){
    //     int op,l,r;
    //     cin>>op>>l>>r;
    //     if(op==1){
    //         ll k;cin>>k;
    //         updata(1,l,r,k,0);
    //     }else if(op==2){
    //         ll k;cin>>k;
    //         updata(1,l,r,1,k);
    //     }else{
    //         cout<<query(1,l,r)<<'\n';
    //     }
    // }
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
