#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9
using namespace std;
vector<pair<int,int> >graph[1001];
int visit[1001];
queue<pair<int,int> >result;

void daik(int start){
    priority_queue<pair<pair<int,int>,int> > pq;
    pq.push(make_pair(make_pair(0,start),start));
    visit[start] = 0;
    while(!pq.empty()){
        int dist = -pq.top().first.first;
        int now = pq.top().first.second;
        int before = pq.top().second;
        pq.pop();
        if(visit[now] < dist){
            continue;
        }
        result.push(make_pair(before,now));
        for(int i=0;i<graph[now].size();i++){
            int cost = dist + graph[now][i].second;
            if(cost < visit[graph[now][i].first]){
                visit[graph[now][i].first] = cost;
                pq.push(make_pair(make_pair(-cost,graph[now][i].first),now));
            } 
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(visit,visit+1001,INF);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    daik(1);
    result.pop();
    cout << result.size() << '\n';
    while(!result.empty()){
        cout << result.front().first << " " << result.front().second << '\n';
        result.pop();
    }
         
    
}