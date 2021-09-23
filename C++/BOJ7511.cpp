#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, par[1000010], k, q, cnt=0;

int find(int s) {
	if(s == par[s]) return s;
	return par[s] = find(par[s]);
}

void uni(int x, int y) {
	int nx = find(x), ny = find(y);
	if(nx < ny) par[ny] = nx;
	else if(nx > ny) par[nx] = ny;
}

void init() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while(true) {
		cnt++;
		if(cnt > t) break;
		cin >> n;
		for(int i=0; i<=n; i++) par[i] = i;
		cin >> k;
		for(int i=0; i<k; i++) {
			int x, y;
			cin >> x >> y;
			uni(x, y);
		}
		cin >> q;
		cout << "Scenario " << cnt << ":\n";
		for(int i=0; i<q; i++) {
			int x, y;
			cin >> x >> y;
			if(find(x) == find(y)) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		cout << '\n';
	}
}

int main() {
	init();
}