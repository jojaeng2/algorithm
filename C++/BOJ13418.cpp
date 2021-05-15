#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct roads {
	int length, x, y;
};

int n, m, mini = 0, maxi = 0, visit[1001];
vector<roads> val;

bool val_minus(roads a, roads b) {
	return a.length > b.length;
}

bool val_plus(roads a, roads b) {
	return a.length < b.length;
}

void print() {
	cout << maxi*maxi - mini*mini << '\n';
}

int find(int start) {
	if(start == visit[start]) return start;
	return visit[start] = find(visit[start]);
}

bool uni(int a, int b) {
	int aa = find(a), bb = find(b);
	if(aa == bb) return false;
	if(aa < bb) visit[bb] = aa;
	else visit[aa] = bb;
	return true;
}

void visit_reset() {
	for(int i=0; i<=n; i++) visit[i] = i;
}

void kruscal(int& now) {
	for(int i=0; i<val.size(); i++) {
		int x = val[i].x, y = val[i].y, length = val[i].length;
		if(uni(x, y)) now += length;
	}
}

void init() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for(int i=0; i<m+1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		roads road;
		if(c == 0) c = 1;
		else c = 0;
		road.x = a, road.y = b, road.length = c;
		val.push_back(road);
	}
	visit_reset();
	sort(val.begin(), val.end(), val_plus);
	kruscal(mini);
	visit_reset();
	sort(val.begin(), val.end(), val_minus);
	kruscal(maxi);
}

int main() {
	init();
	print();
}