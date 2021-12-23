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
typedef pair<pll, ll> plll;
ll psum[NUM], n, t;
ll mini = 0, as, ae;

void init() {
	memset(psum, 0, sizeof(psum));
	cin >> n >> t;
	for(int i=0; i<n; i++) {
		int x;
		cin >> x;
		for(int j=0; j<x; j++) {
			int x, y;
			cin >> x >> y;
			psum[x]++;
			psum[y]--;
		}
	}
	for(int i=1; i<NUM; i++) psum[i] += psum[i-1]; 
	for(int i=1; i<NUM; i++) psum[i] += psum[i-1];
	mini = psum[t-1];
	as = 0, ae = t;
	for(int i=1; i<NUM-t; i++) {
		ll res = psum[i+t-1] - psum[i-1];
		if(res > mini) {
			mini = res;
			as = i;
			ae = i+t;
		}
	}
	cout << as << " " << ae << '\n';
}		

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}