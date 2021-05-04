#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define X first
#define Y second
#define INF 98765432
using namespace std;
typedef pair<int,int> pii;
int T,visit[101],n,m,k,ans,result;
vector<pii> graph[101];
vector<int> v;

void find_mini(int idx){
	int cnt = 0;
	for(int i=0;i<v.size();i++){
		cnt += visit[v[i]];
	}
	if(ans>cnt){
		ans = cnt;
		result = idx;
	}
}

void dijk(int start){
	priority_queue<pii, vector<pii>, greater<pii> >pq;
	pq.push(make_pair(0,start));
	visit[start] = 0;
	while(!pq.empty()){
		int dist = pq.top().X;
		int now = pq.top().Y;
		pq.pop();
		if(visit[now]<dist) continue;
		for(int i=0;i<graph[now].size();i++){
			int cost = dist + graph[now][i].X;
			int next = graph[now][i].Y;
			if(cost<visit[next]){
				visit[next] = cost;
				pq.push(make_pair(cost,next));
			}
		}
	}
	find_mini(start);
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while(T--){
		if(T==-1) break;
		for(int i=1;i<=100;i++) graph[i].clear();
		v.clear();
		ans = INF;
		result = 0;
		cin >> n >> m;
		for(int i=0;i<m;i++){
			int a,b,c;
			cin >> a >> b >> c;
			graph[a].push_back(make_pair(c,b));
			graph[b].push_back(make_pair(c,a));
		}

		cin >> k;
		for(int i=0;i<k;i++){
			int a;
			cin >> a;
			v.push_back(a);
		}

		for(int i=1;i<=n;i++){		
			memset(visit,INF,sizeof(visit));
			dijk(i);
		}
		cout << result << '\n';
	}
}