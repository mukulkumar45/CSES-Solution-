#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x;
    int y;
};

void bfs(queue<pair<Point,int>>& q,vector<vector<int>>& dist,vector<vector<char>>& arr) {
    int n = arr.size();
    int m = arr[0].size();
    int dr[4] = {0,0,-1,1};
    int dc[4] = {-1,1,0,0};
    while(!q.empty()) {
        auto fr = q.front();
        q.pop();
        auto curr = fr.first;
        int dis = fr.second;

        dist[curr.x][curr.y] = dis;

        for(int i = 0;i<4;i++) {
            int nrow = curr.x + dr[i];
            int ncol = curr.y + dc[i];

            if(nrow >= 0 and nrow < n and ncol >=0 and ncol < m and arr[nrow][ncol] != '#') {
                if(dist[nrow][ncol] > dis + 1) {
                    dist[nrow][ncol] = dis + 1;
                    q.push({{nrow,ncol}, dis + 1});
                }
            }
        }
    }
}

void newBfs(queue<pair<pair<Point,int>,string>>& q,vector<vector<int>>& dist,vector<vector<int>>& d,vector<vector<char>>& arr) {
    int n = arr.size();
    int m = arr[0].size();

    int dr[4] = {0,0,-1,1};
    int dc[4] = {-1,1,0,0};

    while(!q.empty()) {
        auto fr = q.front();
        q.pop();
        auto curr = fr.first.first;
        int dis = fr.first.second;

        string path = fr.second;

        d[curr.x][curr.y] = dis;

        for(int i = 0;i<4;i++) {
            int nrow = curr.x + dr[i];
            int ncol = curr.y + dc[i];

            if(nrow >=0 and nrow < n and ncol >= 0 and ncol < m and arr[nrow][ncol] != '#' and dist[nrow][ncol] > dis + 1) {

                if((nrow == 0 or nrow == n-1 or ncol == 0 or ncol == m-1) and (path.size() >= 1)) {

                    if(nrow == 0) {
                        path += 'U';
                    }
                    else if(nrow == n-1) path += 'D';
                    else if(ncol == 0) path += 'L';
                    else if(ncol == m-1) path += 'R';
                    cout << "YES" << endl;
                    cout << path.size() << endl;
                    for(char ch : path) {
                        cout << ch;
                    }
                    cout << endl;
                    return;
                }

                if(d[nrow][ncol] > dis + 1) {
                    char ch = '#';
                    d[nrow][ncol] = dis + 1;
                    if(i == 0) ch = 'L';
                    else if(i == 1) ch = 'R';
                    else if(i == 2) ch = 'U';
                    else if(i == 3) ch = 'D';

                    q.push({{{nrow,ncol},dis + 1},path + ch});
                }
            } 
        }

    }
    cout << "NO" << endl;
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<char>> arr(n,vector<char>(m));
    queue<pair<Point,int>> q;
    queue<pair<pair<Point,int>,string>> qe;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'M') {
                q.push({{i,j},0});
            }
            if(arr[i][j] == 'A') {
                qe.push({{{i,j},0},""});
            }
        }
    }

    vector<vector<int>> dist(n,vector<int>(m,1e8));
    bfs(q,dist,arr);

    vector<vector<int>> d(n,vector<int>(m,1e8));
    newBfs(qe,dist,d,arr);
}
