#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct conn {
    int s, e, d;
};
int n, m, k, par[1001];
vector<conn> v;
vector<int> ans;

void print() {
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}

int find(int start) {
    if(start == par[start]) return start;
    return par[start] = find(par[start]);
}

bool uni(int x, int y) {
    int xx = find(x), yy = find(y);
    if(xx == yy) return false;
    if(xx < yy) par[yy] = xx;
    else par[xx] = yy;
    return true;
}

void kruscal(int idx) {
    int cnt = 0, chk = 0;
    for(int i=idx; i<v.size(); i++) {
        conn co = v[i];
        if(uni(co.s, co.e)) cnt += co.d;
        else continue;
    }
    for(int i=1; i<=n; i++) {
        if(par[i] == i) chk++;
    }
    if(chk == 1) ans.push_back(cnt);
    else ans.push_back(0);
}
bool compare(conn a, conn b) {
    return a.d < b.d;
}

void init() {
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i=1; i<=m; i++) {
        conn co;
        cin >> co.s >> co.e;
        co.d = i;
        v.push_back(co);
    }
    sort(v.begin(), v.end(), compare);
    for(int i=0; i<k; i++) {
        for(int j=1; j<=n; j++) par[j] = j;
        kruscal(i);
    }
}

int main() {
    init();
    print();
}