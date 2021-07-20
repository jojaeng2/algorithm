#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, r, graph[101][101], odd = 0, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}, dir, answer = 0;
bool visit[101][101] = {false};

void print() {
    cout << answer << '\n';
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(visit[i][j]) cout << 'F' << " ";
            else cout << 'S' << " ";
        }
        cout << '\n';
    }
}

void swing(int x, int y, char z) {
    if(z == 'E') dir = 0;
    if(z == 'W') dir = 1;
    if(z == 'S') dir = 2;
    if(z == 'N') dir = 3;
    int now = graph[x][y] - 1;
    answer++;
    visit[x][y] = true;
    while(true) {
        x += dx[dir], y += dy[dir];
        if(now == 0 || x < 1 || y < 1 || x > n || y > m) break;
        now--;
        if(!visit[x][y]) {
            answer++;
            visit[x][y] = true;
            now = max(now, graph[x][y]-1);
        }
    }
}


void init() {
    cin >> n >> m >> r;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin >> graph[i][j];
    for(int i=1; i<=2*r; i++) {
        odd++;
        int x, y;
        char z;
        if(odd % 2 == 1) {
            cin >> x >> y >> z;
            swing(x, y, z);
        }
        else {
            cin >> x >> y;
            visit[x][y] = false;
        }   
    }
}

int main() {
    init();
    print();
}