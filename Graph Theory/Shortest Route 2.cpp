#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n,m,q;
    cin >> n >> m >> q;
    
    vector<vector<ll>> dist(n+1,vector<ll>(n+1,1e12));
    for(int i = 0;i<m;i++) {
        ll a,b,w;
        cin >> a>> b >> w;
        if(w < dist[a][b]) {
            dist[a][b] = w;
            dist[b][a] = w;
        }
    }

    for(int k = 1;k<=n;k++) {
        for(int i = 1;i<=n;i++) {
            for(int j = i + 1;j<=n;j++) {
                ll new_min = dist[i][k] + dist[k][j];
                if(new_min < dist[i][j]) {
                    dist[i][j] = dist[j][i] = new_min;
                }
            }
        }
    }

    for(int i = 0;i<q;i++) {
        int a,b;
        cin >> a >> b;
        if(a == b) {
            cout << 0 << endl;
        }
        else if(dist[a][b] == 1e12) {
            cout << -1 << endl;
        }
        else {
            cout << dist[a][b] << endl;
        }
    }
}
