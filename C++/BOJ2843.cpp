#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
#define X first
#define Y second
#define NUM 300010
using namespace std;
typedef pair<int, int> pii;
int n, m, par[NUM], dat[NUM];
stack<pii> query;
vector<int> answer;
bool visit[NUM] = {false};

int find(int s) {
    if(s == par[s] || par[s] == -1) return par[s];
    return par[s] = find(par[s]);
}

void uni(int x, int y) {
    int ny = find(y);
    if(x == ny) par[ny] = -1;
    else par[x] = ny;
}

void solve() {
    while(!query.empty()) {
        int x = query.top().X, y = query.top().Y;
        query.pop();
        if(x == 1) answer.push_back(find(y));
        else uni(y, dat[y]);
    }
    for(int i=answer.size()-1; i>=0; i--) {
        if(answer[i] == -1) cout << "CIKLUS" << '\n';
        else cout << answer[i] << '\n';
    }
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0; i<NUM; i++) par[i] = i;
    cin >> n;
    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;   
        dat[i] = x;
    }
    cin >> m;
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        query.push(make_pair(x, y));
        if(x == 2) visit[y] = true;
    }
    for(int i=1; i<=n; i++) {
        if(visit[i] || dat[i] == 0) continue;
        uni(i, dat[i]);
    }
    solve();
}

int main() {
    init();
}