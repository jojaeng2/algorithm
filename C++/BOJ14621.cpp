#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct road{
	int length, top, bot;
};

int n, m, visit[1001], cnt = 0;
char school[1001];
vector<road> graph;

void answer() {
	int ans = 0;
	for(int i=1; i<=n; i++) {
		if(visit[i] == i) ans++;
	}
	if(ans == 1) cout << cnt << '\n';
	else cout << -1 << '\n';
}

int find(int start) {
	if(start == visit[start]) return start;
	return visit[start] = find(visit[start]);
}

bool uni(int x, int y) {
	int xx = find(x), yy = find(y);
	if(xx == yy) return false;
	else if(xx < yy) visit[yy] = xx;
	else visit[xx] = yy;
	return true;
}

void imp() {
	for(int i=0; i<graph.size(); i++) {
		int length = graph[i].length, x = graph[i].top, y = graph[i].bot;
		if(uni(x, y)) cnt += length;
	}
}

bool compare(road a, road b) {
	return a.length < b.length;
}

void init() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> school[i];
		visit[i] = i;
	}

	for(int i=0; i<m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		road r;
		r.length = c, r.top = a, r.bot = b;
		if(school[a] != school[b]) graph.push_back(r);
	}
	sort(graph.begin(), graph.end(), compare);
}

int main() {
	init();
	imp();
	answer();
}