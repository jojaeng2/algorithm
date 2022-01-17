#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

int graph[510][510], cnt = 0, n, m, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
bool visit[4][510][510] = {false};

void dfs(int x, int y, int dir) {
    cnt++;
    visit[dir][x][y] = true;
    int curr = graph[x][y];
    if(curr == 0) {
        if(dir == 0 && !visit[dir][(x+1)%n][y]) dfs((x+1)%n, y, dir);
        if(dir == 1 && !visit[dir][(x == 0 ? n : x)-1][y]) dfs((x == 0 ? n : x)-1, y, dir);
        if(dir == 2 && !visit[dir][x][(y+1)%m]) dfs(x, (y+1)%m, dir);
        if(dir == 3 && !visit[dir][x][(y == 0 ? m : y)-1]) dfs(x, (y == 0 ? m : y)-1, dir);
    }
    else if(curr == 1) {
        if(dir == 0 && !visit[2][x][(y+1)%m]) dfs(x, (y+1)%m, 2);  
        if(dir == 1 && !visit[3][x][(y == 0 ? m : y)-1]) dfs(x, (y == 0 ? m : y)-1, 3); 
        if(dir == 2 && !visit[1][(x == 0 ? n : x)-1][y]) dfs((x == 0 ? n : x)-1, y, 1);
        if(dir == 3 && !visit[0][(x+1)%n][y]) dfs((x+1)%n, y, 0);
    }
    else if(curr == 2) {
        if(dir == 0 && !visit[3][x][(y == 0 ? m : y)-1]) dfs(x, (y == 0 ? m : y)-1, 3);
        if(dir == 1 && !visit[2][x][(y+1)%m]) dfs(x, (y+1)%m, 2);
        if(dir == 2 && !visit[0][(x+1)%n][y]) dfs((x+1)%n, y, 0);
        if(dir == 3 && !visit[1][(x == 0 ? n : x)-1][y]) dfs((x == 0 ? n : x)-1, y, 1);
    }
}

vector<int> solution(vector<string> grid) {
    n = grid.size(), m = grid[0].size();
    memset(graph, 0, sizeof(graph));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            char dir = grid[i][j];
            if(dir == 'S') continue;
            else if(dir == 'L') graph[i][j] = 1;
            else if(dir == 'R') graph[i][j] = 2;
        }
    }
    vector<int> answer;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int k=0; k<4; k++) {
                if(visit[k][i][j]) continue;
                cnt = 0;
                dfs(i, j, k);
                answer.push_back(cnt);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}