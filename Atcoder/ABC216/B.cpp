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
#define NUM 100
#define INF 1000000
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
int n;
bool flag = false;
string f[1010], se[1010];

void init() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> f[i] >> se[i];
	}
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(f[i] == f[j] && se[i] == se[j]) flag = true;
		}
	}

	if(flag) cout << "Yes" << '\n';
	else cout << "No" << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}