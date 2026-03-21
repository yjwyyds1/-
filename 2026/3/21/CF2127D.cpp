//https://codeforces.com/contest/2127/problem/D
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
//带补集的并查集（染色并查集 / 二分图并查集） 来判断和统计图的“两侧”
//不能是图特别是不能有环，必须可以分成两边，所以满足的条件的形态一定是树
//最后可能的结构就是一条链上面每一个点挂叶子节点，所连的节点度大于等于2的个数最多只有2个
//然后在不同的对岸可以上下交换，所以初始就是2
//再就是因为是一条链左右也可以换，只要两边最少都有2个以上，这个想的时候感觉想复杂了
//哎哎哎
struct dsu{
    int n;
    vector<int> f;
    void init(int _){
        n=_;
        f.resize(n+1);
        for(int i=1;i<=n;i++)f[i]=i;
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
        f[x]=y;
    }
};
ll fct[N];
void init(){
    fct[0]=1;
    for(int i=1;i<=200000;i++){
        fct[i]=(fct[i-1]*i)%mod;
    }
}
void solve(){
    int n,m;cin>>n>>m;
    dsu d;d.init(2*n+1);
    vector<vector<int>>e(n+1);
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        d.merge(x,y+n);
        d.merge(y,x+n);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    if(n<=m){
        cout<<0<<'\n';
    }
    else{
        int ans=2;
        int a=0,b=0;
        for(int i=1;i<=n;i++){
            a+=d.find(i)==d.find(1);
            b+=d.find(i)==d.find(n+1);
            int y=0;
            for(auto v:e[i]){
                if(e[v].size()==1)y++;
            }
            if(e[i].size()-y>2)ans=0;
            ans=(ans*fct[y])%mod;
        }
        if(a!=1&&b!=1)ans=(ans*2)%mod;
        cout<<ans<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
