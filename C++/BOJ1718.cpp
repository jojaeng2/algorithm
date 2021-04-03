#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
using namespace std;

vector<pair<int,int> >graph[201];
int visit[201];
int result[201][201];

void dijk(int start){
    priority_queue<pair<int,int> > pq;
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
                result[now][start] = graph[now][i].first;
                pq.push(make_pair(-cost,graph[now][i].first));
            }
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    for(int i=1;i<=n;i++){
        int result[201][201];
        fill(visit,visit+201,INF);
        dijk(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                cout << "-" << " ";
            }
            else{
                cout << result[i][j] << " ";
            }
        }
        cout << '\n';
    }
}