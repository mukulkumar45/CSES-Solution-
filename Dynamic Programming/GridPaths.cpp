#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int solve(int row,int col,vector<vector<char>>& arr,vector<vector<int>>& dp,int n) {
    if(row >= n or col >= n) return 0;
    if(row == n-1 and col == n-1) return 1;

    if(dp[row][col] != -1) return dp[row][col];

    int right = 0,down = 0;
    if(row + 1 < n and arr[row+1][col] != '*') {
        down = solve(row + 1,col,arr,dp,n);
    }
    if(col + 1 < n and arr[row][col +1] != '*') {
        right = solve(row,col + 1,arr,dp,n);
    }

    return dp[row][col] = (right + down) % mod;
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> arr(n,vector<char>(n));
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dp(n,vector<int>(n,-1));

    if(arr[0][0] == '*') {
        cout << 0 << endl;
    }
    else {
        cout << solve(0,0,arr,dp,n) << endl;
    }
}