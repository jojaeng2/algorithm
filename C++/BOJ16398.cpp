#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define X first
#define Y second
using namespace std;
typedef long long ll;
struct planet {
    ll dist;
    int s, e;
};
int n, par[1001];
ll answer = 0;
vector<planet> graph;

int find(int s) {
    if(s == par[s]) return par[s];
    return par[s] = find(par[s]);
}

bool uni(int x, int y) {
    int xx = find(x), yy = find(y);
    if(xx == yy) return false;
    if(xx<yy) par[yy] = xx;
    else par[xx] = yy;
    return true;
}

void mst() {
    for(int i=0; i<graph.size(); i++) {
        int s = graph[i].s, e = graph[i].e;
        ll d = graph[i].dist;
        if(uni(s, e)) answer += d;
    }
    cout << answer << '\n';
}

bool compare(planet a, planet b) {
    return a.dist < b.dist;
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1; i<1001; i++) par[i] = i;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            ll d;
            cin >> d;
            if(i == j) continue;
            planet p;
            p.dist = d, p.s = i, p.e = j;
            graph.push_back(p);
        }
    }
    sort(graph.begin(), graph.end(), compare);
}

int main() {
    init();
    mst();
}