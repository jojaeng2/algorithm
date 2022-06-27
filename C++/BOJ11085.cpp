#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define X first
#define Y second
#define NUM 1010
using namespace std;
struct st {
	int x, y, d;
};
typedef pair<int, int> pii;
typedef long long ll;
int n, m, s, e, par[NUM], answer = 50010;
vector<st> v;

bool compare(st a, st b) {
	return a.d > b.d;
}

int find(int start) {
	if(start == par[start]) return start;
	return par[start] = find(par[start]);
}

void uni(int x, int y) {
	int nx = find(x), ny = find(y);
	if(nx > ny) par[nx] = ny;
	else if(nx < ny) par[ny] = nx;
}

void init() {
	cin >> n >> m >> s >> e;
	for(int i=0; i<=n; i++) par[i] = i;
	for(int i=0; i<m; i++) {
		st s;
		cin >> s.x >> s.y >> s.d;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), compare);
	for(int i=0; i<v.size(); i++) {
		int x = v[i].x, y = v[i].y, d = v[i].d;
		uni(x, y);
		answer = min(answer, d);
		if(find(par[s]) == find(par[e])) break;
	}
	cout << answer << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
