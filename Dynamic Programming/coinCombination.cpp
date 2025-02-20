#include <bits/stdc++.h>
using namespace std;
#define ll long long

int mod = 1e9 + 7;
vector<ll> dp;

int solve(ll n,ll target,vector<ll>& arr) {
    dp[0] = 1;
    for(int i = 1;i<=target;i++) {
        for(int j = 0;j<n;j++) {
            if(arr[j] > i) continue;
            dp[i] = (dp[i] + dp[i - arr[j]]) % mod;
        }
    }
    return dp[target];
}

int main() {
    ll n,target;
    cin >> n >> target;

    vector<ll> arr(n);
    for(int i = 0;i<n;i++) {
        cin >> arr[i];
    }
    dp.resize(target + 1,0);

    cout << solve(n,target,arr) << endl;
}