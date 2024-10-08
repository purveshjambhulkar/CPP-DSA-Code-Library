// TABULATION WITH OPTIMIZATION
class Solution {
public:
    int solve(vector<int>& cost, int n) {
        int prev1 = cost[1];
        int prev2 = cost[0];
        

        for (int i = 2; i < n; i++) {
            int ans = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = ans;
        }

        return min(prev1, prev2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solve(cost, n);
    }
};

// APPROACH 2 - TABULATION --- best solution

// class Solution {
// public:
//     int solve(vector<int>& cost,  int n) {
//         vector<int> dp(n+1);
//         dp[0] = cost[0];
//         dp[1] = cost[1];

//         for(int i = 2; i < n ;i++){
//             dp[i] = cost[i] + min(dp[i-1] , dp[i-2]);
//         }

//         return min(dp[n-1] , dp[n-2]);

//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         return solve(cost , n);
//     }
// };

// APPROACH 1 - TOP DOWN - RECURSION + MEMOIZATION

// class Solution {
// public:
//     int solve(vector<int>& cost, vector<int>& dp, int n) {
//         // base case
//         if (n == 0) {
//             return cost[0];
//         }
//         if (n == 1) {
//             return cost[1];
//         }
//         // dp check
//         if (dp[n] != -1) {
//             return dp[n];
//         }
//         // recursive call
//         dp[n] = cost[n] + min(solve(cost, dp, n-1), solve(cost, dp, n-2));
//         return dp[n];
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         vector<int> dp(n+1, -1);
//         int ans = min(solve(cost, dp, n-1), solve(cost, dp, n-2));
//         return ans;
//     }
// };