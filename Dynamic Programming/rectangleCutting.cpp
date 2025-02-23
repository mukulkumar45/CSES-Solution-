#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b;
    cin >> a >> b;

    vector<vector<int>> t(a+1,vector<int>(b+1,1e9));
    for(int i = 0;i<=a;i++) {
        for(int j = 0;j<=b;j++) {
            if(i == j) {
                t[i][j] = 0;
            }
            else{
                for(int k = 1;k < j;k++) {
                    t[i][j] = min(t[i][j],t[i][k] + t[i][j - k] + 1);
                }

                for(int k = 1;k<i;k++) {
                    t[i][j] = min(t[i][j],t[k][j] + t[i - k][j] + 1);
                }
            }
        }
    }

    cout << t[a][b] << endl;
}