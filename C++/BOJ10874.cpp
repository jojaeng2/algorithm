#include <bits/stdc++.h>
#define X first
#define Y second
#define NUM 300010
#define INF 1e18
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
int n, ans[11];
vector<int> v;

void init() {
	cin >> n;
	for(int i=1; i<=5; i++) {
		ans[i] = i;
	}
	ans[6] = 1, ans[7] = 2, ans[8] = 3, ans[9] = 4, ans[10] = 5;
	for(int i=1; i<=n; i++) {
		bool flag = false;
		for(int j=1; j<=10; j++) {
			int x;
			cin >> x;
			if(x != ans[j]) flag = true;
		}
		if(!flag) v.push_back(i);
	}
	for(int vv : v) {
		cout << vv << '\n';
	}
}		

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}