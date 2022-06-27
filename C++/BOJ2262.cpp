#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,cnt=0;
vector<int> v;
int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		v.push_back(a);
	}
	while(true){
		if(v.size()==1) break;
		int maxi = 0;
		int idx = 0;
		for(int i=0;i<v.size();i++){
			if(maxi<v[i]){
				maxi = v[i];
				idx = i;
			}
		}
		if(idx==0){
			cnt += maxi - v[idx+1];
			v.erase(v.begin()+idx);
		}
		else if(idx==v.size()-1){
			cnt += maxi - v[idx-1];
			v.erase(v.begin()+idx);
		}
		else{
			if(v[idx-1]<v[idx+1]){
				cnt += maxi - v[idx+1];
				v.erase(v.begin()+idx);
			}
			else{
				cnt += maxi - v[idx-1];
				v.erase(v.begin()+idx);
			}
		}
	}
	cout << cnt << '\n';
}