#https://www.luogu.com.cn/problem/P12174
n=eval(input())
ans=0
a=[0 for _ in range(n+1)]
for i in range(1,n+1):
    j=i
    while j<=n:
        a[j]=a[j]+1
        j=j+i
    # for j in range(i,n+1,i):
    #     a[j]=a[i]+1
f=[0 for _ in range(n+1)]
for i in range(1,n+1):
    f[i]=f[i-1]+a[i]
ans=0
for i in range(1,n+1):
    ans=ans+a[i]*f[n-i]
print(ans)
