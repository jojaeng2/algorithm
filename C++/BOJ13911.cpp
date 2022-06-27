#include <iostream>
#include <queue>
#include <vector>
#define INF 10e9
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
int n,m,mac,x,star,y;

vector<pii>graph[20000];
ll donald[20000];
ll bucks[20000];

void dijk(int start,ll visit[20000]){
    priority_queue<pii>pq;
    pq.push({0,start});
    visit[start] = 0;
    while(!pq.empty()){
        ll dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(visit[now]<dist){
            continue;
        }
        for(int i=0;i<graph[now].size();i++){
            int dollar = graph[now][i].second;
            int son = graph[now][i].first;
            ll cost = dist + dollar;
            if(cost < visit[son]){
                visit[son] = cost;
                pq.push({-cost,son));
            }
        }
    }
}

void deomi(int cnt,int k){
    for(int i=0;i<cnt;i++){
        int a;
        cin >> a;
        graph[k].push_back({a,0));
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(donald,donald+20000,INF);
    fill(bucks,bucks+20000,INF);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c));
        graph[b].push_back({a,c));
    }
    cin >> mac >> x; 
    deomi(mac,n+1);
    cin >> star >> y;
    deomi(star,n+2);
    
    dijk(n+1,donald);
    dijk(n+2,bucks);

    ll result = INF;
    for(int i=0;i<graph[n+1].size();i++){
        donald[graph[n+1][i].first] = -1;
    }
    for(int i=0;i<graph[n+2].size();i++){
        bucks[graph[n+2][i].first] = -1;
    }
    
    for(int i=1;i<=n;i++){
        if(donald[i]<=x && bucks[i]<=y && bucks[i]!=-1 && donald[i]!=-1){
            result = min(result,donald[i]+bucks[i]);
        }
    }

    if(result==INF){
        result = -1;
    }
    cout << result << '\n';
}