//https://codeforces.com/contest/1418/problem/D
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

// 读错题目意思了草 
// 感觉还是挺好想的 最后是两堆肯定优于只剩一堆
// 在这个增删的过程中维护 相邻点间的最大距离 以及点集的最大 最小 点的位置
// 用set 跟 multiset  然后 用rebegin要保证那个multiset不为空
// 不然会RE
set<int> s;
multiset<int> d;
void add(int x){
    auto idx=s.lower_bound(x);
    int L=-1,R=-1;
    if(idx!=s.end()){
        R=*idx;
        d.insert(R-x);
    }
    if(idx!=s.begin()){
        L=*(--idx);
        d.insert(x-L);
    }
    if(L!=-1&&R!=-1){
        d.erase(d.find(R-L));
    }
    s.insert(x);
    return ;
}
void del(int x){
    s.erase(x);//先删再找位置
    auto idx=s.lower_bound(x);
    int L=-1,R=-1;
    if(idx!=s.end()){
        R=*idx;
        d.erase(d.find(R-x));
    }
    if(idx!=s.begin()){
        L=*(--idx);
        d.erase(d.find(x-L));
    }
    if(L!=-1&&R!=-1){
        d.insert(R-L);
    }
    
    return ;
}
void solve(){
    int n,q;
    cin>>n>>q;
    d.insert(0);//不如先加一个进去 用rbegin() d为空的时候会RE！
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        add(x);
    }
    cout<<*s.rbegin()-*s.begin()-*d.rbegin()<<'\n';
    for(int i=1;i<=q;i++){
        int op,x;cin>>op>>x;
        if(op){
            add(x);
        }else{
            del(x);
        }
        if(s.size()<=2){
            cout<<0<<'\n';
        }else{
            cout<<*s.rbegin()-*s.begin()-*d.rbegin()<<'\n';
        }
    }
    
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
