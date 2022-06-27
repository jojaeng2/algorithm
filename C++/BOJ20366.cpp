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
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
int n;
ll answer = INF;
bool visit[610];
vector<ll> v;

void init() {
	memset(visit, false, sizeof(visit));
	cin >> n;
	for(int i=0; i<n; i++) {
		ll x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for(int i=0; i<n; i++) {
		visit[i] = true;
		for(int j=i+1; j<n; j++) {
			visit[j] = true;
			int l = 0, r = n-1;
			while(l<r) {
				if(visit[l]) l++;
				else if(visit[r]) r--;
				else {
					ll first = v[i] + v[j], second = v[l] + v[r];
					answer = min(answer, abs(first-second));
					if(second > first) r--;
					else l++;
				}
			}
			visit[j] = false;
		}
		visit[i] = false;
	}
	cout << answer << '\n';
}	

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}