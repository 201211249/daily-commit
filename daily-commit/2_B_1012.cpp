#include<bits/stdc++.h>
using namespace std;
int adj[50][50], visited[50][50], n, m, ret,t,k, y,x;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1, 0,-1 };
vector<int> result;
void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m || adj[ny][nx]==0)continue;
		if (visited[ny][nx])continue;
		dfs(ny, nx);
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m >> k;
		for (int j = 0; j < k; j++) {
			cin >> y >> x;
			adj[y][x] = 1;
		}
		for (int l = 0; l < n; l++) {
			for (int u = 0; u < m; u++) {
				if (visited[l][u] == 0 && adj[l][u] == 1) {
					dfs(l, u);
					ret++;
				}
			}
		}
		result.push_back(ret);
		ret = 0; 
		memset(visited, 0, sizeof(visited));
		memset(adj, 0, sizeof(adj));
	}
	for (int i : result) cout << i << "\n";
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int m, n, k, y, x, ret, ny, nx, t;
int a[51][51];
bool visited[51][51];
void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (a[ny][nx] == 1 && !visited[ny][nx]) {
            dfs(ny, nx);
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--) {
        fill(&a[0][0], &a[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        ret = 0;
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            a[y][x] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j);
                    ret++;
                }
            }
        }
        cout << ret << "\n";
    }
    return 0;
}
