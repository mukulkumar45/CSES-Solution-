#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int target = 0;
    vector<int> arr(n);
    for(int i = 0;i<n;i++) {
        cin >> arr[i];
        target += arr[i];
    }

    vector<vector<bool>> t(n+1,vector<bool>(target+1,false));

    for(int i = 0;i<=n;i++) {
        t[i][0] = true;
    }

    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=target;j++) {
            if(arr[i-1] <= j) {
                t[i][j] = t[i - 1][j] || t[i - 1][j - arr[i-1]];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    vector<int> ans;
    for(int j = 1;j<=target;j++) {
        if(t[n][j]) {
            ans.push_back(j);
        }
    }

    cout << ans.size() << endl;
    for(int i : ans) cout << i << " ";
    cout << endl;
}