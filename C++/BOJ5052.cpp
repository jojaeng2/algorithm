#include <iostream>
#include <set>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int t,n;
set<string> phone;
vector<string> v;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while(t>0){
		bool flag = false;
		phone.clear();
		v.clear();
		t--;
		cin >> n;
		for(int i=0;i<n;i++){
			string s;
			cin >> s;
			phone.insert(s);
			v.push_back(s);
		}
		for(int i=0;i<n;i++){
			string now="";
			string s = v[i];
			for(int j=0;j<s.size()-1;j++){
				now += s[j];
				if(phone.find(now) != phone.end()){
					flag = true;
				}
			}
		}
		if(flag) cout << "NO" << '\n';
		else cout << "YES" << '\n';
	}
}