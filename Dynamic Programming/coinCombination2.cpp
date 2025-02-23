#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> t(n + 1, vector<int>(target + 1));

    for (int i = 0; i <= n; i++) {
        t[i][0] = 0;
    }
    for (int j = 1; j <= target; j++) {
        t[0][j] = INT_MAX - 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (arr[i - 1] <= j) {
                t[i][j] = min((1 + t[i][j - arr[i - 1]]) % mod, t[i - 1][j] % mod);
            } else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    if (t[n][target] == INT_MAX - 1) {
        cout << -1 << endl;
    } else {
        cout << t[n][target] << endl;
    }

    return 0;
}
