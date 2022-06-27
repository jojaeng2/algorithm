#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>
#include <set>
#define X first
#define Y second
#define NUM 100010
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii,int> piii;
typedef long long ll;
int n, m, s, e, par[NUM], mini = 0, answer = 0;
vector<piii> v;

bool compare(piii a, piii b) {
	return a.Y > b.Y;
}

int find(int start) {
	if(start == par[start]) return start;
	return par[start] = find(par[start]);
}

bool uni(int x, int y) {
	int xx = find(x);
	int yy = find(y);
	if(xx == yy) return false;
	if(yy < xx) par[xx] = yy;
	else par[yy] = xx;
	return true;
}

void init() {
	for(int i=0; i<NUM; i++) par[i] = i;
	cin >> n >> m >> s >> e;
	for(int i=0; i<m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		v.push_back({{x, y}, d});
	}
	sort(v.begin(), v.end(), compare);
	for(int i=0; i<v.size(); i++) {
		int x = v[i].X.X, y = v[i].X.Y, d = v[i].Y;
		if(uni(x, y)) {
			mini = d;
			if(find(par[s]) == find(par[e])) {
				answer = mini;
				break;
			}
		}
	}
	cout << answer << '\n';

}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}