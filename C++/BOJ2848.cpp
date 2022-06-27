#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <cmath>
#include <deque>
#define X first
#define Y second
#define NUM 200010
#define INF 1000000000
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
int n, cnt = 1, in[30], flag = 0;
bool visit[30][30];
string answer = "";
vector<string> v;
vector<int> graph[30];
map<char, int> m;
map<int, char> rev;

void topo() {
	queue<int> q;
	for(int i=1; i<cnt; i++) {
		if(!in[i]) {
			q.push(i);
			answer += rev[i];
		}
	}
	if(q.size() == 0) flag = 1;
	while(!q.empty()) {
		int now = q.front();
		if(q.size() >= 2) {
			flag = 2;
			break;
		}
		q.pop();
		for(int next:graph[now]) {
			if(!--in[next]) {
				q.push(next);
				answer += rev[next];
			}
		}
	}
}

void init() {
	memset(visit, false, sizeof(visit));
	memset(in, 0, sizeof(in));
	cin >> n;
	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
		for(int j=0; j<s.size(); j++) {
			if(m.find(s[j]) != m.end()) continue;
			m.insert({s[j], cnt});
			rev.insert({cnt++, s[j]});
		}
	}
	for(int i=0; i<v.size(); i++) {
		for(int j=i+1; j<v.size(); j++) {
			for(int k=0; k<min(v[i].size(), v[j].size()); k++) {
				if(v[i][k] != v[j][k]) {
					if(visit[m[v[j][k]]][m[v[i][k]]]) {
						flag = 1;
						break;
					}
					if(visit[m[v[i][k]]][m[v[j][k]]]) break;
					visit[m[v[i][k]]][m[v[j][k]]] = true;
					graph[m[v[i][k]]].push_back(m[v[j][k]]);
					in[m[v[j][k]]]++;
					break;
				}
			}
		}
	}
	for(int i=0; i<v.size(); i++) {
		for(int j=i+1; j<v.size(); j++) {
			if(v[i].find(v[j]) == 0 && v[i] != v[j]) flag = 1;
		}
	}
	if(flag == 0) topo();
	if(flag == 1) cout << "!" << '\n';
	else if(flag == 2) cout << "?" << '\n';
	else {
		cout << answer << '\n';
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}