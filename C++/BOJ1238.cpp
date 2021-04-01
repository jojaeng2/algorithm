#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;
vector<pair<int,int> > graph1[1001];
vector<pair<int,int> > graph2[1001];
int visit1[1001];
int visit2[1001];

void daik(int star,vector<pair<int,int> >graph[1001],int visit[1001]){
    priority_queue<pair<int,int> >heap;
    heap.push(make_pair(0,start));
    visit[start] = 0;
    while(!heap.empty()){
        int dist = -heap.top().first;
        int now = heap.top().second;
        heap.pop();
        if(visit[now] < dist){
            continue;
        }
        for(int i=0;i<graph1[now].size();i++){
            int cost = dist + graph1[now][i].second;
            if(cost < visit[graph1[now][i].first]){
                visit[graph1[now][i].first] = cost;
                heap.push(make_pair(-cost,graph1[now][i].first));
            }
        }
    }
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(visit1,visit1+1001,INF);
    fill(visit2,visit2+1001,INF);
    int n,m,start;
    cin >> n >> m >> start;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph1[b].push_back(make_pair(a,c));
        graph2[a].push_back(make_pair(b,c));
    }
    daik(start);
    daik(start);
    int mx = 0;
    for(int i=1;i<n+1;i++){
        if(visit1[i]+visit2[i] > mx){
            mx = visit1[i] + visit2[i];
        }
    }
    cout << mx << endl;
}