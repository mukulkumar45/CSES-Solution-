#include <bits/stdc++.h>
using namespace std;
int dr[4] = {0,0,-1,1};
int dc[4] = {-1,1,0,0};

void dfs(int row,int col,vector<vector<char>>& arr,vector<vector<int>>& vis,int n,int m) {
    vis[row][col] = 1;

    for(int i = 0; i < 4;i++) {
        int nrow = row + dr[i];
        int ncol = col + dc[i];

        if(nrow >= 0 and nrow < n and ncol >=0 and ncol < m and !vis[nrow][ncol] and arr[nrow][ncol] == '.') {
            dfs(nrow,ncol,arr,vis,n,m);
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;

    vector<vector<char>> arr(n,vector<char>(m));
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            cin >> arr[i][j];
            if(arr[i][j] == '#') {
                vis[i][j] = 1;
            }
        }
    }

    int count = 0;
    

    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            if(arr[i][j] == '.' and !vis[i][j]) {
                count++;
                dfs(i,j,arr,vis,n,m);
            }
        }
    }

    cout << count << endl;
}