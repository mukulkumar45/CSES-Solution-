#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,total;
    cin >> n >> total;

    vector<int> price(n);
    vector<int> pages(n);
    for(int i = 0;i<n;i++) {
        cin >> price[i];
    }
    for(int i = 0;i<n;i++) {
        cin >> pages[i];
    }

    int t[n+1][total + 1];
    
    for(int i = 0;i<=n;i++) t[i][0] = 0;
    for(int j = 0;j<=total;j++) t[0][j] = 0;

    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=total;j++) {
            if(price[i - 1] <= j) {
                t[i][j] = max(pages[i - 1] + t[i-1][j - price[i - 1]], t[i-1][j]);
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    cout << t[n][total] << endl;

}