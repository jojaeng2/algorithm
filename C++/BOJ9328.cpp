#include <bits/stdc++.h>
#define X first
#define Y second
#define NUM 100010
#define INF 1e9
#define MINF 0x7f7f7f7f
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
typedef pair<pll, ll> plll;
int n, m, t;
bool build[NUM], inq[NUM];
vector<int> products[NUM];
queue<pii> q;

void init() {
	memset(build, false, sizeof(build));
	memset(inq, false, sizeof(inq));
	cin >> n >> m >> t;
	for(int i=0; i<m; i++) {
		int x;
		cin >> x;
		build[x] = true;
	}
	for(int i=1; i<=n; i++) {
		int x;
		cin >> x;
		for(int j=0; j<x; j++) {
			int y;
			cin >> y;
			if(build[i]) {
				if(inq[y]) continue;
				inq[y] = true;
				q.push({y, 1});
			}
		}
	}

}		

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}