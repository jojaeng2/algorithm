#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
map<char, bool> m;
vector<string> v;
int n,k, ans = 0;

void solve() {
	int cnt = 0;
	for(int i=0;i<v.size();i++) {
		bool flag = false;
		string now = v[i];
		for(int j=4;j<now.size()-3;j++) {
			if(!m[now[j]]) {
				flag = true;
				break;
			}
		}
		if(!flag) cnt++;
	}
	ans = max(ans, cnt);
}

void dfs(int cnt, char alpha) {
	if(cnt == k) {
		solve();
		return;
	}
	while(alpha<'z') {
		alpha++;
		if(m[alpha]) continue;
		m[alpha] = true;
		dfs(cnt+1, alpha);
		m[alpha] = false;
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for(int i=0;i<n;i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	char ch = 'a';
	for(int i=0;i<26;i++){
		m.insert(pair<char,bool>(ch,false));
		ch++;
	}
	m['a'] = true, m['c'] = true, m['t'] = true, m['i']= true, m['n'] = true;

	if(k>=5) {
		k -= 5;
		dfs(0, 'a');
	}
	cout << ans << '\n';
}