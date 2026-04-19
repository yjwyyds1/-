//https://codeforces.com/gym/104639/problem/D
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
const int mod = 1000000007;
// const int mod = 998244353;
//随机化
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> Tp(1, 100);
// cout<<fixed<<setprecision(10);
//并查集算一下 简单签到题目
struct dsu{
    int n;
    vector<int> f,sz;
    void init(int _){
        n=_;
        f.resize(n+1);
        sz.resize(n+1);
        for(int i=1;i<=n;i++)f[i]=i,sz[i]=1;
    }
    int find(int x){
        if(x==f[x])return f[x];
        else {
            f[x]=find(f[x]);
            return f[x];
        }
    }
    void merge(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return ;
        if(sz[x]>sz[y]){
            swap(x,y);
        }
        f[x]=y;
        sz[y]+=sz[x];
        return ;
    }
};
void solve(){
    int n,m;
    cin>>n>>m;
    dsu d;d.init(n);
    vector<int> u(m+1),v(m+1);
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i];
        d.merge(u[i],v[i]);
    }
    map<int,int> f;
    vector<ll> c;
    for(int i=1;i<=n;i++){
        if(d.find(i)==i)f[i]=0;
    }
    for(int i=1;i<=m;i++){
        f[d.find(u[i])]++;
    }
    ll ans=0;
    for(auto [x,b]:f){
        // cout<<x<<" "<<b<<'\n';
        ll k=d.sz[x];
        k=(k*(k-1))/2;
        c.push_back(d.sz[x]);
        ans+=k-b;
    }
    sort(c.begin(),c.end());
    if(ans==0){
        ans=c[0]*c[1];
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
