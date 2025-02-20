#include <bits/stdc++.h>
using namespace std;

int solve(string str1,string str2) {
    vector<vector<int>> dp(str1.length() + 1,vector<int>(str2.length() + 1));

    for(int i = 0;i<=str1.length();i++) {
        dp[i][0] = i;
    }
    for(int j = 0;j<=str2.length();j++) {
        dp[0][j] = j;
    }

    for(int i = 1;i<=str1.length();i++) {
        for(int j = 1;j<=str2.length();j++) {
            if(str1[i-1] == str2[j - 1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min({
                    dp[i-1][j] + 1,
                    dp[i][j-1] + 1,
                    dp[i-1][j-1] + 1
                });
            }
        }
    }

    return dp[str1.length()][str2.length()];
}

int main() {
    string str1,str2;
    cin >> str1 >> str2;

    cout << solve(str1,str2) << endl;
}