#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>
#define X first
#define Y second
#define NUM 1000010
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int n;
vector<int> v;
deque<int> dq;
void init() {
	cin >> n;
	for(int i=0; i<n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	reverse(v.begin(), v.end());
	for(int i=0; i<v.size(); i++) {
		if(v[i] == 1) dq.push_front(i+1);
		if(v[i] == 3) dq.push_back(i+1);
		if(v[i] == 2) {
			int b = dq.front();
			dq.pop_front();
			dq.push_front(i+1);
			dq.push_front(b);
		}
	}
	for(int i=0; i<dq.size(); i++) {
		cout << dq[i] << ' ';
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}