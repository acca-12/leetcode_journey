class Solution:
    def climbStairs(self, n: int) -> int:
        ## recurrence relation dp[i]  = #ways can climb to ith = dp[i-1] + dp[i-2]

        dp = [0] * n

        dp[0] = 1

        if(n > 1):
            dp[1] = 2
        else:
            return 1
    
        for i in range(2, n):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[-1]
