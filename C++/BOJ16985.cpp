#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define X first
#define Y second
using namespace std;
struct blocks {
    int x, y, z, cnt;
};
typedef pair<int, int> pii;
int maze[5][5][5], c_maze[5][5][5], answer = 1e9, visit[5][5][5], r_maze[5][4][5][5];
int dx[6] = {-1, 1, 0, 0, 0, 0}, dy[6] = {0, 0, -1, 1, 0, 0}, dz[6] = {0, 0, 0, 0, -1, 1};
bool selec[5], cube[5][4];
vector<pii> v;

void bfs(int a, int b) {
    if(c_maze[0][a][b] == 0) return;
    memset(visit, -1, sizeof(visit));
    visit[0][a][b] = 0;
    queue<blocks> q;
    blocks block;
    block.x = a, block.y = b, block.z = 0, block.cnt = 1;
    q.push(block);
    while(!q.empty()) {
        int x = q.front().x, y = q.front().y, z = q.front().z, cnt = q.front().cnt;
        q.pop();
        for(int i=0; i<6; i++) {
            int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
            if(nx<0 || nx>4 || ny<0 || ny>4 || nz<0 || nz>4) continue;
            if(c_maze[nz][nx][ny] == 0 || visit[nz][nx][ny] != -1) continue;
            visit[nz][nx][ny] = cnt;
            blocks block;
            block.x = nx, block.y = ny, block.z = nz, block.cnt = cnt+1;
            q.push(block);
        }
    }
    int ex = abs(4-a), ey = abs(4-b);
    
    if(visit[4][ex][ey] == -1) return;
    answer = min(answer, visit[4][ex][ey]);
}


void deep_copy() {
    for(int k=0; k<5; k++) {
        int now = v[k].X, r = v[k].Y;
        for(int i=0; i<5; i++) for(int j=0; j<5; j++) c_maze[k][i][j] = r_maze[now][r][i][j];
    }
}
void dfs(int cnt) {
    if(cnt == 5) {
        deep_copy();
        bfs(0, 0), bfs(0, 4), bfs(4, 0), bfs(4, 4);
        return;
    }
    for(int i=0; i<5; i++) {
        if(selec[i]) continue;
        selec[i] = true;
        for(int j=0; j<4; j++) {
            if(cube[i][j]) continue;
            cube[i][j] = true;
            v.push_back(make_pair(i, j));
            dfs(cnt+1);
            v.pop_back();
            cube[i][j] = false;
        }
        selec[i] = false;
    }
}

void make_rotation() {
    for(int k=0; k<5; k++) {
        for(int r=0; r<4; r++) {
            for(int i=0; i<5; i++) {
                for(int j=0; j<5; j++) {
                    if(r == 0) r_maze[k][0][i][j] = maze[k][i][j];
                    else r_maze[k][r][j][5-i-1] = r_maze[k][r-1][i][j];
                }
            }
        }
    }

}

void init() {
    for(int k=0; k<5; k++) {
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                cin >> maze[k][i][j];
            }
        }
    }
    make_rotation();
}

int main() {
    init();
    dfs(0);
    if(answer == 1e9) answer = -1;
    cout << answer << '\n';
}