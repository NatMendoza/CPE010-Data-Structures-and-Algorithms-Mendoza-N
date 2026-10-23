#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int memo[100];

// Memoization 
int getMinStepsMemo(int n) {
    if (n == 1) return 0; 
    if (memo[n] != -1) return memo[n]; 
    
    int r = 1 + getMinStepsMemo(n - 1); 
    if (n % 2 == 0) r = min(r, 1 + getMinStepsMemo(n / 2)); 
    if (n % 3 == 0) r = min(r, 1 + getMinStepsMemo(n / 3)); 
    
    memo[n] = r; 
    return r;
}  

// Bottom-Up DP Approach
int getMinStepsBottomUp(int n) {
    if (n == 1) return 0;
    int dp[n + 1];
    dp[1] = 0; // trivial case[cite: 10]
    
    for (int i = 2; i <= n; i++) {
        dp[i] = 1 + dp[i - 1];
        if (i % 2 == 0) dp[i] = min(dp[i], 1 + dp[i / 2]);
        if (i % 3 == 0) dp[i] = min(dp[i], 1 + dp[i / 3]);
    }
    return dp[n];
}

int main() {
    int n;
    cout << "Enter a number (100 Maximum): ";
    cin >> n;

    // For Memoization
    memset(memo, -1, sizeof(memo));
    cout << "Minimum steps to reach 1 (Memoization): " << getMinStepsMemo(n) << endl; 

    // For Bottom-Up DP
    cout << "Minimum steps to reach 1 (Bottom-Up): " << getMinStepsBottomUp(n) << endl; 

    return 0;
}
