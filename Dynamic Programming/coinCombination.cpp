#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e9 + 7;

int main() {
    ll n, target;
    cin >> n >> target;

    vector<ll> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> t(n + 1, vector<int>(target + 1, 0));

    for(int i = 0; i <= n; i++) {
        t[i][0] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= target; j++) {
            if(arr[i - 1] <= j) {
                t[i][j] = (t[i][j - arr[i - 1]] + t[i - 1][j]) % mod;
            } else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    cout << t[n][target] << endl;
    return 0;
}
