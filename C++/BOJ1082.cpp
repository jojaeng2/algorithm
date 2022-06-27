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
#define X first
#define Y second
#define NUM 100010
#define INF 1e15
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
int n, num[11], m;
string answer = "";
priority_queue<pii> o, z, pq;

void init() {
	memset(num, 0, sizeof(num));
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> num[i];
		z.push({-num[i], i});
		pq.push({i, num[i]});
		if(i != 0) o.push({-num[i], i});
	}
	cin >> m;
	if(!o.empty()) {
		int cost = -o.top().X, now = o.top().Y;
		if(m-cost >= 0) {
			answer += now+'0';
			m -= cost;
		}
		while(true) {
			int cost = -z.top().X, now = z.top().Y;
			if(m-cost>=0) {
				answer += (now + '0');
				m -= cost;
			}
			else break;
		}
	}
	if(answer.size() == 0) answer = "0";
	else {
		while(!pq.empty()) {
			int cost = pq.top().Y, now = pq.top().X;
			pq.pop();
			for(int i=0; i<answer.size(); i++) {
				if((now+'0') >= answer[i] && m+num[answer[i]-'0']-cost >= 0) {
					m += (num[answer[i]-'0']-cost);
					answer[i] = now+'0';
				}
			}
		}	
	}
	if(answer[0] == '0') answer = "0";
	cout << answer << '\n';
	
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}