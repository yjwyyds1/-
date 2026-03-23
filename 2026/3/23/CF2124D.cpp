//https://codeforces.com/contest/2124/problem/D
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



// 能想到最后保留下来的是前k-1小的数 但是不知道怎么让它能是按子序列顺序成回文
// 然后对于刚好等于a[k-1]的数的保留也不好处理 一直想从中间怎么划分一下 但是感觉思路不是很好
// 题解的双指针贪心 优先保留严格小于a[k-1] 的构成回文 
// 然后加入恰好等于a[k-1]的数进去来最大化回文的长度 只要最长的长度大于等于k-1就ok 
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<int> b=a,c;
    sort(a.begin()+1,a.end());
    for(int i=1;i<=n;i++){
        if(b[i]>a[k-1]){
            continue;
        }else{
            c.push_back(b[i]);
        }
    }
    int len=0;
    vector<int> l,r;
    for(int L=0,R=c.size()-1;L<=R;){
        if(c[L]==c[R]){
            if(L==R){
                len++;
            }else{
                len+=2;
            } 
            L++;
            R--;
        }else{
            if(c[L]<a[k-1]&&c[R]<a[k-1]){
                cout<<"NO"<<'\n';
                return ;
            }else if(c[L]<a[k-1]&&c[R]==a[k-1]){
                R--;
            }else if(c[L]==a[k-1]&&c[R]<a[k-1]){
                L++;
            }
        }
    }
    if(len>=k-1){
        cout<<"YES"<<'\n';
    }else{
        cout<<"NO"<<'\n';
    }
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
