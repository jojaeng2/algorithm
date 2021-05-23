#include <iostream>
#include <algorithm>
using namespace std;
int n, graph[21][21], answer = 0;

void maxi() {
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) answer = max(answer, graph[i][j]);
}

void row(int direction) {
    if(direction == 0) {
        for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) {
            if(graph[i][j] == 0) {
                for(int k=i+1; k<=n; k++) {
                    if(graph[k][j] != 0) {
                        graph[i][j] = graph[k][j];
                        graph[k][j] = 0;
                        break;
                    }
                }
            }
            for(int k=i+1; k<=n; k++) {
                if(graph[k][j] != 0) {
                    if(graph[i][j] == graph[k][j]) {
                        graph[i][j] *= 2;
                        graph[k][j] = 0;
                    }
                    break;
                }
            }
        }   
    }
    else if(direction == 2) {
        for(int i=n; i>=1; i--) for(int j=n; j>=1; j--) {
            if(graph[i][j] == 0) {
                for(int k=i-1; k>=1; k--) {
                    if(graph[k][j] != 0) {
                        graph[i][j] = graph[k][j];
                        graph[k][j] = 0;
                        break;
                    }
                }
            }
            for(int k=i-1; k>=1; k--) {
                if(graph[k][j] != 0) {
                    if(graph[i][j] == graph[k][j]) {
                        graph[i][j] *= 2;
                        graph[k][j] = 0;
                    }
                    break;
                }
            }
        }   
    }
}

void column(int direction) {
     if(direction == 1) {
        for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) {
            if(graph[i][j] == 0) {
                for(int k=j+1; k<=n; k++) {
                    if(graph[i][k] != 0) {
                        graph[i][j] = graph[i][k];
                        graph[i][k] = 0;
                        break;
                    }
                }
            }
            for(int k=j+1; k<=n; k++) {
                if(graph[i][k] != 0) {
                    if(graph[i][j] == graph[i][k]) {
                        graph[i][j] *= 2;
                        graph[i][k] = 0;
                    }
                    break;
                }
            }
        }   
    }
    else {
        for(int i=n; i>=1; i--) for(int j=n; j>=1; j--) {
            if(graph[i][j] == 0) {
                for(int k=j-1; k>=1; k--) {
                    if(graph[i][k] != 0) {
                        graph[i][j] = graph[i][k];
                        graph[i][k] = 0;
                        break;
                    }
                }
            }
            for(int k=j-1; k>=1; k--) {
                if(graph[i][k] != 0) {
                    if(graph[i][j] == graph[i][k]) {
                        graph[i][j] *= 2;
                        graph[i][k] = 0;
                    }
                    break;
                }
            }
        }   
    }
}
void dfs(int cnt) {
    int cpy_map[21][21];
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cpy_map[i][j] = graph[i][j];
    if(cnt == 5) {
        maxi();
        return;
    }
    for(int i=0; i<4; i++) {
        if(i == 0 || i == 2) row(i);
        else column(i);
        dfs(cnt+1);
        for(int j=1; j<=n; j++) for(int k=1; k<=n; k++) graph[j][k] = cpy_map[j][k];
    }
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin >> graph[i][j];
}

int main() {
    init();
    dfs(0);
    cout << answer << '\n';
}