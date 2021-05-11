#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, k, cnt = 0;
int same[51], zero[51];
vector<string> v;

int main() {
	memset(same, 0, sizeof(same));
	memset(zero, 0, sizeof(zero));

	cin >> n >> m;
	for(int i=0;i<n;i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	cin >> k;

	for(int i=0;i<n;i++) {
		string s = v[i];

		for(int j=0;j<n;j++) {
			if(s == v[j]) same[i]++;
		}

		for(int j=0;j<m;j++) {
			if(s[j] == '0') zero[i]++;
		}
	}
	
	for(int i=0;i<n;i++) {
		if(zero[i]<=k && zero[i]%2 == k%2) cnt = max(cnt,same[i]);
	}
	cout << cnt << '\n';
}