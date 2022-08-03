#include <bits/stdc++.h>
#define MINF 0x7f7f7f7f
#define INF 1000000000000
#define MOD 10000
#define NUM 200010
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
int N, M, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}, sx, sy, ex, ey;
int graph[510][510], visited[3][510][510];
queue<piii> q;
bool flag = false;

void init() {
    memset(visited, -1, sizeof(visited));
    
    // X -> 방문할 수있는가?
    // . -> visited[.] 주변 확인 -> N-1 2개 이상 or N이상 이으면 YES
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        string str;
        cin >> str;
        for(int j=0; j<M; j++) {
            if(str[j] == '.') graph[i][j] = 0;
            else graph[i][j] = 1;
        }
    }
    cin >> sx >> sy >> ex >> ey;
    sx--, sy--, ex--, ey--;
    visited[1][sx][sy] = 0;
    q.push({{sx, sy}, 1});

    while(!q.empty()) {
        auto curr = q.front();
        int x = curr.X.X, y = curr.X.Y, status = curr.Y;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = x+ dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(graph[nx][ny] == 0) {
                visited[1][nx][ny] = visited[status][nx][ny] + 1;
                graph[nx][ny] = 1;
                q.push({{nx, ny}, 1});
            }
            else {
                if(visited[2][nx][ny] != -1) continue;
                visited[2][nx][ny] = visited[status][x][y] + 1;
            }
        }
    }

    int num = visited[2][ex][ey];
    if(num != -1) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main() {   
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
}