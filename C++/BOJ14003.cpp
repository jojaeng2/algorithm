#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
ll number[1000001], idx[1000001];
vector<ll> v_number, v_idx, ans;

void dfs(int now) {
	ans.push_back(number[now]);
	if(idx[now] == 0) return;
	dfs(idx[now]);
}

void print() {
	int last = v_idx.back();
	cout << v_idx.size()-1 << '\n';
	dfs(last);
	for(int i=ans.size()-1;i>=0; i--) {
		cout << ans[i] << " ";
	}
	cout << '\n';
}

void longest() {
	v_number.push_back(-1000000001);
	v_idx.push_back(0);
	for(int i=1; i<=n; i++) {
		ll next = number[i];
		if(next > v_number.back()) {
			v_number.push_back(next);
			idx[i] = v_idx.back();
			v_idx.push_back(i);
		}
		else {
			int new_idx = lower_bound(v_number.begin(), v_number.end(), next) - v_number.begin();
			v_number[new_idx] = next;
			if(new_idx == 0) idx[i] = 0;
			else {
				idx[i] = v_idx[new_idx-1];
				v_idx[new_idx] = i;
			}
		}
	}
}

void init() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> number[i];
		idx[i] = i;
	}
}

int main() {
	init();
	longest();
	print();
}