#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n;
vector<string> v;

bool compare(string a, string b) {
	string aa = a+b, bb = b+a;
	cout << aa << " " << bb << '\n';
	return aa > bb;
}

void init() {
	cin >> n;
	for(int i=0; i<n; i++) {
		string x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end(), compare);
	string s = "";
	for(int i=0; i<v.size(); i++) s += v[i];
	if(s[0] == '0') cout << 0 << '\n';
	else cout << s << '\n';
}

int main() {
	init();
}