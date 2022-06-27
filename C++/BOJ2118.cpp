#include <bits/stdc++.h>
#define X first
#define Y second
#define NUM 100
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
int n;
ll l, r, sum, answer = 0, nums[50010];

void init() {
	memset(nums, 0, sizeof(nums));
	cin >> n;
	for(int i=1; i<=n; i++) {
		ll x;
		cin >> x;
		nums[i] = nums[i-1] + x;
	}

	for(int i=1; i<=n; i++) {
		l = i, r = n;
		while(l <= r) {
			ll mid = (l+r)/2;
			ll A = nums[mid] - nums[i-1], B = nums[n] - A;
			if(A < B) l = mid+1;
			else r = mid-1;
			answer = max(answer, min(A, B));
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