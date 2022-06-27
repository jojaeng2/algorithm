#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
int n;
vector<int> v;

bool eratos(int number) {
	if(number/10 == 0) {
		if(number==2 || number==3 || number==5 || number==7) return true;
		else return false;
	}
	for(int i=2;i<sqrt(number)+1;i++) {
		if(number % i == 0) return false;
	} 
	return true;
}

bool drom(string s) {
	for(int i=0;i<(s.size()/2)+1;i++) {
		if(s[i] != s[s.size()-(i+1)]) return false;
	}
	return true;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i=n;i<=1500000;i++) {
		string s = to_string(i);
		if(eratos(i) && drom(s)) {
			v.push_back(i);
		}
	}
	for(int i=0;i<v.size();i++) {
		if(v[i]>=n) {
			cout << v[i] << '\n';
			break;
		}
	}
}