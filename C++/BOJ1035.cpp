#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef pair<pair<int, int>, int> piii;
typedef pair<int, int> pii;
int graph[6][6], dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}, psum=0, answer = 1e9, star = 0;
vector<pii> v, pos;
bool graph_visit[6][6], visit[6][6];

bool bfs() {
    memset(visit, false, sizeof(visit));
    queue<pii> q;
    q.push(make_pair(pos[0].first, pos[0].second));
    visit[pos[0].first][pos[0].second] = true;
    int cnt = 1;
    while(!q.empty()) {
        int x = q.front().X, y = q.front().Y;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx<0 || ny<0 || nx>4 || ny>4 || visit[nx][ny] || graph[nx][ny] == 0) continue;
            visit[nx][ny] = true;
            cnt++;
            q.push(make_pair(nx, ny));
        }
    }
    return star == cnt;
}

void dfs(int cnt) {
    if(cnt == star) {
        if(bfs()) {
            int now = 0;
            for(int i=0; i<v.size(); i++) now += abs(v[i].first - pos[i].first) + abs(v[i].second - pos[i].second);
            answer = min(now, answer);
        }
        return;
    }
    for(int i=0; i<5; i++) for(int j=0; j<5; j++) {
        if(graph_visit[i][j]) continue;
        graph_visit[i][j] = true;
        graph[i][j] = cnt+1;
        pos.push_back(make_pair(i, j));
        dfs(cnt+1);
        pos.pop_back();
        graph[i][j] = 0;
        graph_visit[i][j] = false;
    }
}

void init() {
    for(int i=0; i<5; i++) {
        string s;
        cin >> s;
        for(int j=0; j<5; j++) {
            if(s[j] == '*') {
                star++;
                v.push_back(make_pair(i, j));
            }
        }
    }
    dfs(0);
    cout << answer << '\n';
}

int main() {
    init();
}