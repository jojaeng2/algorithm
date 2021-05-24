#include <iostream>
#include <queue>
#include <cstring>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
int n, k, par[100001], visit[2001][2001], answer = 0;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
queue<pii> q_bfs, q_uni;

int find(int start) {
    if(start == par[start]) return start;
    return par[start] = find(par[start]);
}

void uni(int a, int b) {
    int aa = find(a), bb = find(b);
    if(bb < aa) par[aa] = bb;
    else par[bb] = aa;
}

void bfs() {
    while(!q_bfs.empty()) {
        int x = q_bfs.front().X, y = q_bfs.front().Y, now = visit[x][y];
        q_bfs.pop();
        for(int i=0; i<4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(1>nx || nx>n || 1>ny || ny>n || visit[nx][ny] == now) continue;
            int next = visit[nx][ny];
            if(next == 0) {
                visit[nx][ny] = now;
                q_uni.push(make_pair(nx, ny));
            }
            else uni(now, next);
        }
    }
}

bool go_uni(){
    while(!q_uni.empty()){
        int x = q_uni.front().X, y = q_uni.front().Y, now = visit[x][y];
        q_uni.pop();
        q_bfs.push(make_pair(x, y));
        for(int i=0; i<4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(1>nx || nx>n || 1>ny || ny>n || visit[nx][ny] == now || visit[nx][ny] == 0) continue;
            int next = visit[nx][ny];
            uni(now, next);
        }
    }
    int cnt = 0;
    for(int i=1; i<=k; i++) {
        if(par[i] == i) cnt++;
        if(cnt>1) return false;
    }
    return true;
}

void letsgo() {
    while(true) {
        if(go_uni()) break;
        bfs();
        answer++;
    }
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    memset(visit, 0, sizeof(visit));
    for(int i=0; i<=k; i++) par[i] = i;

    for(int i=1; i<=k; i++) {
        int x, y;
        cin >> x >> y;
        visit[x][y] = i;
        q_uni.push(make_pair(x, y));
    }
}

int main() {
    init();
    letsgo();
    cout << answer << '\n';
}