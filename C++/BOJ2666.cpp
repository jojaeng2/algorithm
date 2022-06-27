#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, DP[21][21][21], start_x, start_y, answer = 1e9;
vector<int> v;

void print() {
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) answer = min(answer, DP[m][i][j]);
    cout << answer << '\n';
}

void dynamic() {
    for(int k=0; k<v.size(); k++) {
        int next = v[k];
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                DP[k+1][next][j] = min(DP[k+1][next][j], DP[k][i][j] + abs(i-next));
                DP[k+1][i][next] = min(DP[k+1][i][next], DP[k][i][j] + abs(j-next));
            }
        }
    }
}

void init() {
    memset(DP, 1e6, sizeof(DP));
    cin >> n;
    cin >> start_x >> start_y >> m;
    for(int i=0; i<m; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    DP[0][start_x][start_y] = 0;
}

int main() {
    init();
    dynamic();
    print();
}