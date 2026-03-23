//https://atcoder.jp/contests/abc450/tasks/abc450_e
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

// 由斐波那契应该想到记忆化搜索递归的
// 然后用前缀和优化一下 因为L R的 范围最多才1e18 所以只用处理到 len[88]
// 因为后面继续递归的字符串的前面这些部分不会再改变了 



ll ca[N][26],cb[N][26];
ll sum[100][26];
ll len[100];
ll dfs(int k,ll l,ll r,int c){
    // cout<<k<<" "<<l<<" "<<r<<" "<<c<<'\n';
    if(k==1){
        return ca[r][c]-ca[l-1][c];
    }
    if(k==2){
        return cb[r][c]-cb[l-1][c];
    }
    if(r==len[k]&&l==1){
        return sum[k][c];
    }
    ll mid=len[k-1];
    if(r<=mid){
        return dfs(k-1,l,r,c);
    }else if(l>mid){
        return dfs(k-2,l-mid,r-mid,c);
    }else{
        return dfs(k-1,l,mid,c)+dfs(k-2,1,r-mid,c);
    }
}
void solve(){
    string a,b;
    cin>>a>>b;
    a='1'+a;
    b='1'+b;
    for(int i=1;i<a.size();i++){
        for(int j=0;j<26;j++){
            if(a[i]-'a'==j){
                ca[i][j]=ca[i-1][j]+1;
            }else{
                ca[i][j]=ca[i-1][j];
            }
        }
    }
    for(int i=1;i<b.size();i++){
        for(int j=0;j<26;j++){
            if(b[i]-'a'==j){
                cb[i][j]=cb[i-1][j]+1;
            }else{
                cb[i][j]=cb[i-1][j];
            }
        }
    }
    for(int i=0;i<26;i++){
        sum[1][i]=ca[a.size()-1][i];
        sum[2][i]=cb[b.size()-1][i];
    }
    len[1]=a.size()-1;
    len[2]=b.size()-1;
    int cnt=2;
    while(1){
        cnt++;
        len[cnt]=len[cnt-1]+len[cnt-2];
        for(int i=0;i<26;i++){
            sum[cnt][i]=sum[cnt-1][i]+sum[cnt-2][i];
        }
        if(len[cnt]>1e18){
            break;
        }
    }
    // for(int i=1;i<a.size();i++){
    //     for(int j=0;j<26;j++){
    //         cout<<ca[i][j]<<" ";
    //     }cout<<'\n';
    // }
    // for(int i=1;i<b.size();i++){
    //     for(int j=0;j<26;j++){
    //         cout<<cb[i][j]<<" ";
    //     }cout<<'\n';
    // }

    // for(int i=1;i<100;i++){
    //     for(int j=0;j<26;j++){
    //         cout<<sum[i][j]<<" ";
    //     }cout<<'\n';
    // }
    // for(int i=1;i<100;i++){
    //     cout<<len[i]<<'\n';
    // }
    int q;cin>>q;
    for(int i=1;i<=q;i++){
        ll l,r;
        char c;
        cin>>l>>r>>c;
        cout<<dfs(cnt,l,r,c-'a')<<'\n';
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

