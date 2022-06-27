#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct horse {
    int x, y, dir, idx;
};
int dx[5] = {0, 0, 0, -1, 1}, dy[5] = {0, 1, -1, 0, 0};
int n, k, color[15][15], cnt = 0;
vector<int> graph[15][15];
vector<horse> v;

void print() {
    if(cnt >= 1000) cnt = -1;
    cout << cnt << '\n';
}

void red(horse h) {
    int x = h.x, y = h.y, dir = h.dir, idx = h.idx;
    int nx = x + dx[dir], ny = y + dy[dir];
    int length = graph[x][y].size() - idx;
    while(length != 0) {
        int now = graph[x][y].back();
        graph[x][y].pop_back();
        v[now].x = nx, v[now].y = ny, v[now].idx = graph[nx][ny].size();
        graph[nx][ny].push_back(now);
        length--;
    }
}

void white(horse h) {
    int x = h.x, y = h.y, dir = h.dir, idx = h.idx;
    int nx = x + dx[dir], ny = y + dy[dir];
    stack<int> stak;
    int length = graph[x][y].size() - idx;
    while(length != 0) {
        stak.push(graph[x][y].back());
        graph[x][y].pop_back();
        length--;
    }
    while(!stak.empty()) {
        int now = stak.top();
        stak.pop();
        v[now].x = nx, v[now].y = ny, v[now].idx = graph[nx][ny].size();
        graph[nx][ny].push_back(now);
    }
}

void blue(horse h, int num) {
    int x = h.x, y = h.y, dir = h.dir, idx = h.idx, new_dir;
    if(h.dir == 1) new_dir = 2;
    else if(h.dir == 2) new_dir = 1;
    else if(h.dir == 3) new_dir = 4;
    else if(h.dir == 4) new_dir = 3;
    
    v[num].dir = new_dir;
    h.dir = new_dir;
    int nx = x + dx[new_dir], ny = y + dy[new_dir];
    if(nx<1 || ny<1 || nx>n || ny>n) return;
    else {
        if(color[nx][ny] == 0) white(h);
        else if(color[nx][ny] == 1) red(h);
        else return;
    }
}

bool check() {
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) {
        if(graph[i][j].size() >= 4) return true; 
    }
    return false;
}

void solve() {
    while(cnt<1001) {
        cnt++;
        for(int i=0; i<v.size(); i++) {
            horse h = v[i];
            int nx = h.x + dx[h.dir], ny = h.y + dy[h.dir];
            if(nx<1 || ny<1 || nx>n || ny>n) blue(h, i);
            else {
                if(color[nx][ny] == 0) white(h);
                else if(color[nx][ny] == 1) red(h);
                else blue(h, i);
            }
            if(check()) return;
        }
    }
}

void init() {
    cin >> n >> k;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin >> color[i][j];
    for(int i=0; i<k; i++) {
        horse h;
        cin >> h.x >> h.y >> h.dir;
        h.idx = graph[h.x][h.y].size();
        v.push_back(h);
        graph[h.x][h.y].push_back(i);
    }
}

int main() {
    init();
    if(check()) cout << 0 << '\n';
    else solve();
    print();
}