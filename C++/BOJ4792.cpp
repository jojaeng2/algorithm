#include <bits/stdc++.h>
#define X first
#define Y second
#define NUM 1010
#define INF 1e9
#define MINF 0x7f7f7f7f
#define MOD 1000000007
#define LOG 22
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
int n, m, k, par[NUM], mini, maxi;
vector<piii> adj1, adj2;

bool compare(piii a, piii b) {
    return a.Y < b.Y;
}

int find(int curr) {
    if(par[curr] == curr) return curr;
    return par[curr] = find(par[curr]);
}

void init() {
    while(true) {
        cin >> n >> m >> k;
        if(!n && !m && !k) break;
        adj1.clear(), adj2.clear();
        mini = 0, maxi = 0;

        for(int i=0; i<NUM; i++) par[i] = i;
        for(int i=0; i<m; i++) {
            char x;
            int y, z;
            cin >> x >> y >> z;
            if(x == 'B') {
                adj1.push_back({{y, z}, 1});
                adj2.push_back({{y, z}, 0});
            }
            else {
                adj1.push_back({{y, z}, 0});
                adj2.push_back({{y, z}, 1});
            }
        }
        sort(adj1.begin(), adj1.end(), compare);
        sort(adj2.begin(), adj2.end(), compare);
        for(auto edge : adj1) {
            int x = find(edge.X.X), y = find(edge.X.Y);
            if(x == y) continue;
            if(x < y) par[y] = x;
            else par[x] = y;
            if(edge.Y) mini++;
        }
        for(int i=0; i<NUM; i++) par[i] = i;

        for(auto edge : adj2) {
            int x = find(edge.X.X), y = find(edge.X.Y);
            if(x == y) continue;
            if(x < y) par[y] = x;
            else par[x] = y;
            if(!edge.Y) maxi++;
        }
        if(mini <= k && k <= maxi) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}																		

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}