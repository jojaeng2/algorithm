#include <bits/stdc++.h>
#define X first
#define Y second
#define NUM 100010
#define INF 1e9
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
vector<int> v, d;
int t;

bool div(ll x) {
	for(ll i = 1; i*i <=x; i++) {
		if(x % i == 0) {
			if((i + x/i) % 3 == 0) return true;
		}
	}
	return false;
}

void init() {
	cin >> t;
	ll n;
	while(t--) {
		cin >> n;
		if(div(n)) cout << "TAK" << '\n';
		else cout << "NIE" << '\n';
	}

}		

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}