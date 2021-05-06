#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> v;

int main(){
	v.push_back(-1000000001);
	cin >> n;
	for(int i=0;i<n;i++){
		int num;
		cin >> num;
		if(num>v.back()) v.push_back(num);
		else {
			int index = lower_bound(v.begin(), v.end(), num) - v.begin();
			v[index] = num;
		}
	}
	cout << endl;
	cout << v.size() - 1 << '\n';
}