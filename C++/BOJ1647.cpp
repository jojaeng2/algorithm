#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
int n,m;
vector<pii>graph[100001];
int visit[100001];
void prim(){
    priority_queue<pii> pq;
    pq.push(make_pair(0,1));
    visit[1] = 0;
    for(int i=0;i<graph[1].size();i++){
        pq.push(make_pair(-graph[1][i].second,graph[1][i].first));
    }
    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(visit[now]!=-1) continue;
        visit[now] = dist;
        for(int i=0;i<graph[now].size();i++){
            pq.push(make_pair(-graph[now][i].second,graph[now][i].first));
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    fill(visit,visit+100001,-1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    prim();
    int result = 0;
    int maxnum = 0;
    for(int i=1;i<=n;i++){
        result += visit[i];
        maxnum = max(maxnum,visit[i]);
    }
    cout << result - maxnum << '\n';
}