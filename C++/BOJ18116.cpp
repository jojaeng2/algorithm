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
#define NUM 230000
#define INF 2000000000
#define MOD 1000000007
#define LOG 22
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, ll> pil;
typedef pair<pii, int> piii;
typedef pair<piii, int> piiii;
typedef pair<ll, ll> pll;
int n, par[1000010], psum[1000010];

int find(int start) {
	if(start == par[start]) return start;
	return par[start] = find(par[start]);
}

void uni(int x, int y) {
	x = find(x);
	y = find(y);
	if(x == y) return;
	if(x < y) {
		psum[x] += psum[y];
		par[y] = x;
	}
	else {
		psum[y] += psum[x];
		par[x] = y;
	}
}

void init() {
	cin >> n;
	for(int i=0; i<1000010; i++) par[i] = i, psum[i] = 1;
	while(n--) {
		char x;
		cin >> x;
		if(x == 'I') {
			int y, z;
			cin >> y >> z;
			uni(y, z);
		}
		if(x == 'Q') {
			int y;
			cin >> y;
			cout << psum[find(y)] << '\n';
		}
	}

}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}