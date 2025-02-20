#include <bits/stdc++.h>
using namespace std;
#define ll long long

int mod = 1e9 + 7;
vector<ll> dp;

int solve(ll n,ll target,vector<ll>& arr) {
    dp[0] = 0;
    for(int i = 1;i<=target;i++) {
        for(int j = 0;j<n;j++) {
            if(arr[j] > i or dp[i - arr[j]] == 1e9) continue;
            dp[i] = min(dp[i],dp[i - arr[j]] + 1);
        }
    }
    if(dp[target] == 1e9) return -1;
    return dp[target];
}

int main() {
    ll n,target;
    cin >> n >> target;

    vector<ll> arr(n);
    for(int i = 0;i<n;i++) {
        cin >> arr[i];
    }
    dp.resize(target + 1,1e9);

    cout << solve(n,target,arr) << endl;
}