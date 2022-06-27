#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <cstring>
#define X first
#define Y second
#define NUM 1010
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
int n, answer = 0, arr[1000010];
set<int> s;

void init() {
	memset(arr, 0, sizeof(arr));
	cin >> n;
	for(int i=1; i<=n; i++) {
		int x;
		cin >> x;
		if(!arr[x+1]) {
			answer++;
			arr[x]++;
		}
		else {
			arr[x+1]--;
			arr[x]++;
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