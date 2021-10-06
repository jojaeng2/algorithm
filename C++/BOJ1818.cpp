#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define X first
#define Y second
#define NUM 200010
#define MOD 1000000007
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int n;
vector<int> v;

void init() {
	cin >> n;
	v.push_back(-1);
	for(int i=1; i<=n; i++) {
		int x;
		cin >> x;
		if(v.back() < x) v.push_back(x);
		else {
			int idx = lower_bound(v.begin(), v.end(), x) - v.begin();
			v[idx] = x;
		}
	}
	cout << n-v.size()+1 << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
