#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    while(n) {
        int temp = n;
        int maxi = INT_MIN;
        while(temp) {
            int t = temp % 10;
            maxi = max(maxi,t);
            temp = temp / 10;
        }

        n = n - maxi;
        ans++;
    }

    cout << ans << endl;
}