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
#define NUM 1000010
#define INF 2000000000
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
int maxi = 0, s=-1, e, psum[2*NUM], n, as, ae;
vector<int> v;
vector<pii> in; 

void init() {
	memset(psum, 0, sizeof(psum));
	cin >> n;
	for(int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		in.push_back({x, y});
		v.push_back(x);
		v.push_back(y-1);
	}
	sort(v.begin(), v.end());
	for(int i=0; i<in.size(); i++) {
		int l = lower_bound(v.begin(), v.end(), in[i].X) - v.begin();
		int r = lower_bound(v.begin(), v.end(), in[i].Y) - v.begin();
		psum[l]++;
		psum[r]--;
	}
	for(int i=1; i<v.size(); i++) psum[i] += psum[i-1];
	for(int i=0; i<v.size(); i++) {
		cout << i << ' ' << v[i] << " " << psum[i] << " " << psum[i-1] << " " << maxi << " " << s << " " << e << endl;
		if(psum[i] <= maxi) {
			if(s == -1 || psum[i] == maxi) continue;
			if(psum[i] < maxi) { 
				e = v[i-1]+1;
				as = s, ae = 
				s = -1;
			}
		}
		else {
			maxi = psum[i];
			s = v[i];
		}
	}
	cout << maxi << endl;
	cout << s << ' ' << e << endl;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}