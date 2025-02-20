#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
vector<int> dp;

int solve(int curr,int target) {
    if(curr == target) {
        return 1;
    }
    if(curr > target) return 0;
    if(dp[curr] != -1) return dp[curr];

    int ans = 0;

    for(int i = 1;i<=6;i++) {
        ans = (ans + solve(curr + i , target)) % mod;
    }

    return dp[curr] =  ans % mod;
}

int main() {
    int n;
    cin >> n;

    dp.resize(n+1,-1);
    cout << solve(0,n) << endl;
}