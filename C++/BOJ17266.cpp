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
#define NUM 100010
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
int n, t, maxi = 0, l = 1, r = 100000, ans;
vector<int> v;

void init() {
	cin >> n >> t;
	for(int i=0; i<t; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	while(l<=r) {
		int mid = (l+r)/2, maxi = 0;
		bool flag = false;
		for(auto next : v) {
			int left = next - mid, right = next + mid;
			if(left > maxi) {
				flag = true;
				break;
			} 
			else maxi = right;
		}
		if(flag || maxi < n) l = mid+1;
		else {
			r = mid-1;
			ans = mid;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}