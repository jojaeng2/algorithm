#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,number[40001];
vector<int> v;

int main(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> number[i];
	v.push_back(0);
	for(int i=1;i<=n;i++){
		if(v.back()<number[i]) v.push_back(number[i]);
		else {
			int idx = lower_bound(v.begin(), v.end(), number[i]) - v.begin();
			v[idx] = number[i];
		}
	}
	cout << v.size()-1 << '\n';
}