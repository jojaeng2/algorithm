#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}, ans = 0;
char graph[26];
pii idx[26];
bool visit[6][6];
vector<pii> v;

bool bfs() {
    queue<pii> q;
    bool par[6][6] = {false};
    int node = 0;
    for(int i=1; i<=5; i++) {
        for(int j=1; j<=5; j++) {
            if(visit[i][j] && !par[i][j]) {
                node++;
                q.push(make_pair(i, j));
                par[i][j] = true;
                while(!q.empty()) {
                    int x = q.front().X, y = q.front().Y;
                    q.pop();
                    for(int k=0; k<4; k++) {
                        int nx = x + dx[k], ny = y + dy[k];
                        if(1>nx || nx>5 || 1>ny || ny>5) continue;
                        if(!par[nx][ny] && visit[nx][ny]) {
                            par[nx][ny] = true;
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }
    }
    if(node == 1) return true;
    else return false;
}

void dfs(int x, int S, int Y){
    if(Y >= 4) return;
    if(S+Y == 7) {
        if(bfs()) ans++;
        return;
    }
    for(int i=x; i<26; i++) {
        int nx = idx[i].first, ny = idx[i].second;
        if(visit[nx][ny]) continue;
        visit[nx][ny] = true;
        if(graph[i] == 'S') dfs(i+1, S+1, Y);
        else dfs(i+1, S, Y+1);
        visit[nx][ny] = false;
    }
}

void init() {
    for(int i=1; i<=5; i++) {
        string s;
        cin >> s;
        for(int j=0; j<5; j++) {
            graph[5*(i-1)+j+1] = s[j];
            idx[5*(i-1)+j+1].first = i, idx[5*(i-1)+j+1].second = j+1;
        }
    }
}

int main() {
    init();
    dfs(1, 0, 0);
    cout << ans << '\n';
}