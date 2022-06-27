#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#define X first
#define Y second
#define NUM 1010
#define INF 1e15
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
int n, answer = 0;
vector<pii> v;
bool out(pii a, pii b) {
	return a.X > b.X;
}

bool in(pii a, pii b) {
	return a.Y < b.Y;
}

void init() {
	cin >> n;
	for(int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}
	sort(v.begin(), v.end(), out);
	answer = v[0].X;
	sort(v.begin(), v.end(), in);
	answer -= v[0].Y;
	answer = max(answer, 0);
	cout << answer << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}