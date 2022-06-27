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
#define NUM 1010
#define INF 1000000000
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
int n;
ll answer = 0;
bool visit[100010];
priority_queue<int> pq;

void init() {
	memset(visit, false, sizeof(visit));
	cin >> n;
	for(int i=0; i<n; i++) {
		int x;
		cin >> x;
		pq.push(-x);
	}
	for(int i=1; i<=n; i++) {
		while(!pq.empty()) {
			int top = -pq.top();
			pq.pop();
			if(top < i) continue;
			else {
				answer += (ll)(top-i);
				break;
			}		
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