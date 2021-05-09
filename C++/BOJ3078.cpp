#include <iostream>
#include <string>
using namespace std;
int n, k, window[300001];
long long cnt, num[21];


int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(num,num+21,0);
	cin >> n >> k;
	for(int i=1;i<=n;i++) {
		string s;
		cin >> s;
		window[i] = s.size();
	}
	for(int i=1;i<=k+1;i++) {
		num[window[i]]++;
	}
	cnt = num[window[1]]-1;
	for(int i=2;i<=n;i++) {
		if(i+k<=n) {
			num[window[i+k]]++;
		}
		num[window[i-1]]--;
		cnt += num[window[i]] - 1;
	}
	cout << cnt << '\n';
}
