#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9

using namespace std;
vector<pair<int,int> >graph[101];
int item[101];
int visit[101];

void dijk(int start, int visit[101]){
    priority_queue<pair<int,int> >pq;
    pq.push(make_pair(0,start));
    visit[start] = 0;
    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(visit[now] < dist){
            continue;
        }
        for(int i=0;i<graph[now].size();i++){
            int cost = dist + graph[now][i].second;
            if(cost < visit[graph[now][i].first]){
                visit[graph[now][i].first] = cost;
                pq.push(make_pair(-cost,graph[now][i].first));
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,r;
    cin >> n >> m >> r;
    for(int i=1;i<=n;i++){
        cin >> item[i];
    }
    for(int i=0;i<r;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    int mx = 0;
    for(int i=1;i<=n;i++){
        int visit[101];
        fill(visit,visit+101,INF);
        dijk(i,visit);
        int dat = 0;
        for(int j=1;j<=n;j++){
            if(visit[j] <= m){
                dat += item[j];
            }
        }
        if(mx < dat){
            mx = dat;
        }
    }
    cout << mx << '\n';
}