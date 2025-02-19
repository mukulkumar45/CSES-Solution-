#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
    ll weight;
    int currNode;
    int coupoun;
};

struct myComparator {
    bool operator()(const node& a1,const node& a2) {
        return a1.weight > a2.weight;
    }
};

int main() {
    int n,m;
    cin >> n >> m;

    vector<vector<pair<ll,ll>>> adj(n + 1);
    for(int i = 0;i<m;i++) {
        ll a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c}); // from -> {to,weight}
    } 

    vector<vector<ll>> dist(2,vector<ll>(n+1, LONG_LONG_MAX));
    priority_queue<node, vector<node>, myComparator> pq;

    dist[0][0] = dist[1][0] = 0;
    pq.push({0,1,1});

    while(!pq.empty()) {
        auto fr = pq.top();
        pq.pop();
        ll currWeight = fr.weight;
        int curr = fr.currNode;
        int coupoun = fr.coupoun;

        if(dist[!coupoun][curr] < currWeight) {
            continue;
        }

        for(auto ne : adj[curr]) {
            int v = ne.first;
            ll w = ne.second;

            if(coupoun) {
                if(dist[0][v] > currWeight + w) {
                    dist[0][v] = currWeight + w;
                    pq.push({currWeight+w,v,1});
                }
                if(dist[1][v] > currWeight + w / 2) {
                    dist[1][v] = currWeight + w / 2;
                    pq.push({currWeight + w/2,v,0});
                }
            }

            else{
                if(dist[1][v] > currWeight + w) {
                    dist[1][v] = currWeight + w;
                    pq.push({currWeight + w,v,0});
                }
            }
        }
    }

    cout << min(dist[0][n],dist[1][n]);

}
