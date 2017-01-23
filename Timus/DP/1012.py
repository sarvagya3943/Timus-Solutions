import sys
sys.setrecursionlimit(1800)
n = int(raw_input())
k = int(raw_input())
dp = [[-1 for x in xrange(15)]for y in xrange(2000)]
for i in xrange(1,n+1) :
    if(i==1) :
        dp[i][k] = k - 1
    elif(i==2) :
        dp[i][k] = k * (k-1)
    else :
        dp[i][k] = (k-1) * (dp[i-1][k] + dp[i-2][k])
print dp[n][k]
