#include <iostream>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<pair<ll, int>, int> ppli;
ll answer = 0;
int n, parent[100001];
vector<pli> xx, yy, zz;
vector<ppli> conn;

int find(int start) {
    if(start == parent[start]) return start;
    return parent[start] = find(parent[start]);
}

bool uni(int x, int y) {
    int xx = find(x), yy = find(y);
    if(xx == yy) return false;
    parent[yy] = xx;
    return true; 
}

void connect() {
    for(int i=0; i<conn.size(); i++) {
        ll dist = conn[i].X.X, a = conn[i].X.Y, b = conn[i].Y;
        if(uni(a, b)) answer += dist;
    }
}

void sorting() {
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());
    sort(zz.begin(), zz.end());
    for(int i=0; i<=n; i++) parent[i] = i;
    for(int i=1; i<n; i++) {
        conn.push_back({{xx[i].X - xx[i-1].X, xx[i].Y}, xx[i-1].Y});
        conn.push_back({{yy[i].X - yy[i-1].X, yy[i].Y}, yy[i-1].Y});
        conn.push_back({{zz[i].X - zz[i-1].X, zz[i].Y}, zz[i-1].Y});
    }
    sort(conn.begin(), conn.end());
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        xx.push_back({x, i});
        yy.push_back({y, i});
        zz.push_back({z, i});
    }
}

int main() {
    init();
    sorting();
    connect();
    cout << answer << '\n';
}