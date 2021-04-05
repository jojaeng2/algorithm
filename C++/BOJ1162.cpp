#include <iostream>
#include <queue>
#include <vector>
#define INF 5000000000001
using namespace std;
vector<pair<int,long long> >graph[10001];
vector<long long>visit[10001];
int n,m,k;

void dijk(int start){
    priority_queue<pair<pair<long long,int>,int> >pq;
    pq.push(make_pair(make_pair(0,start),0));
    while(!pq.empty()){
        long long dist = -pq.top().first.first;
        int now = pq.top().first.second;
        int cnt = pq.top().second;
        pq.pop();
        if(visit[now][cnt] < dist){
            continue;
        }
        for(int i=0;i<graph[now].size();i++){
            long long cost = dist + graph[now][i].second;
            if(cost < visit[graph[now][i].first][cnt]){
                visit[graph[now][i].first][cnt] = cost;
                pq.push(make_pair(make_pair(-cost,graph[now][i].first),cnt));
            }
            long long rmcost = dist;
            if(cnt < k && rmcost < visit[graph[now][i].first][cnt+1]){
                visit[graph[now][i].first][cnt+1] = rmcost;
                pq.push(make_pair(make_pair(-rmcost,graph[now][i].first),cnt+1));
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(i==1){
                visit[i].push_back(0);
            } else {
                visit[i].push_back(INF);
            }
        }
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    dijk(1);
    long long result = 5000000000001;
    for(int i=0;i<=k;i++){
        if(visit[n][i] < result){
            result = visit[n][i];
        }
    }
    cout << result << endl;
}