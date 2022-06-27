#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <cmath>
#include <deque>
#include <list>
#define X first
#define Y second
#define NUM 1010
#define INF 1000000000
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
int n, par[51], psum = 0;
vector<piii> v;

bool compare(piii a, piii b) {
	return a.Y < b.Y;
}

int find(int start) {
	if(start == par[start]) return start;
	return par[start] = find(par[start]);
}

bool uni(int x, int y) {
	int xx = find(x), yy = find(y);
	if(xx == yy) return false;
	if(yy < xx) par[xx] = yy;
	else par[yy] = xx;
	return true;
}

void init() {
	cin >> n;
	for(int i=0; i<=n; i++) par[i] = i;
	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		for(int j=0; j<s.size(); j++) {
			if(s[j] == '0') continue;
			if(s[j]>='a' && s[j]<='z') {
				v.push_back({{i, j}, (s[j]-'a')+1});
				psum += (s[j]-'a')+1;
			}
			if('A'<=s[j] && s[j]<='Z') {
				v.push_back({{i, j}, (s[j]-'A')+27});
				psum += (s[j]-'A')+27;
			}
		}
	}
	sort(v.begin(), v.end(), compare);
	for(int i=0; i<v.size(); i++) {
		int x = v[i].X.X, y = v[i].X.Y, cost = v[i].Y;
		if(uni(x, y)) psum -= cost;
	}
	int cnt = 0;
	for(int i=0; i<n; i++) {
		if(par[i] == i) cnt++;
	}
	if(cnt > 1) cout << -1 << '\n';
	else cout << psum << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}