#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <cstring>
#define NUM 200010
using namespace std;
typedef pair<int, int> pii;
int n, m, conn[NUM], par[NUM];
stack<pii> stak;
stack<string> ans;

int find(int s) {
    if(s == par[s]) return s;
    return par[s] = find(par[s]);
}

void uni(int x, int y) {
    int xx = find(x), yy = find(y);
    if(xx < yy) par[yy] = xx;
    else par[xx] = yy;
}

void init() {
    memset(conn, 0, sizeof(conn));
    cin >> n >> m;
    for(int i=0; i<=n; i++) par[i] = i;
    for(int i=2; i<=n; i++) {
        int x;
        cin >> x;
        conn[i] = x;
    }
    for(int i=0; i<m+n-1; i++) {
        int x, y, z;
        cin >> x;
        if(x == 1) {
            cin >> y >> z;
            stak.push(make_pair(y, z));
        }
        else {
            cin >> y;
            stak.push(make_pair(0, y));
        }
    }
    while(!stak.empty()) {
        int y = stak.top().first, z = stak.top().second;
        stak.pop();
        if(y == 0) {
            uni(z, conn[z]);
        }
        else {
            if(find(par[y]) == find(par[z])) ans.push("YES");
            else ans.push("NO");
        }
    }
    while(!ans.empty()) {
        cout << ans.top() << '\n';
        ans.pop();
    }
}

int main() {
    init();
}