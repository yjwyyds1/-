#https://www.luogu.com.cn/problem/P12173
s=input()
s='1'+s
t=["lqb","lbq","qlb","qbl","blq","bql"]
dp = [0] * len(s)
dp[0]=0
for i in range(1,len(s)):
    dp[i]=max(dp[i-1],dp[i])
    for j in range(0,6):
        if(i>=3):
            p=s[i-2]+s[i-1]+s[i]
            # print(p)
            if(p==t[j]):
                dp[i]=max(dp[i],dp[i-3]+1)
# for i in range(0,len(s)):
#     print(dp[i])
print(dp[len(s)-1])
