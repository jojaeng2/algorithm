#include <iostream>
#include <queue>
#include <vector>
#include <map>

#define INF 1e9
using namespace std;

vector<pair<int,int> >graph[1001];
priority_queue<int> dat[1001];

void dijk(int start,int k){
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
    pq.push(make_pair(0,start));
    dat[1].push(0);
    while(!pq.empty()){
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i].first;
            int cost = dist + graph[now][i].second;
            if(dat[next].size() < k){
                dat[next].push(cost);
                pq.push(make_pair(cost,next));
            } else {
                if(dat[next].top() > cost){
                    dat[next].pop();
                    dat[next].push(cost);
                    pq.push(make_pair(cost,next));
                }
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
    }
    dijk(1,k);
    for(int i=1;i<=n;i++){
        if(dat[i].size() < k){
            cout << -1 << '\n';
        } else {
            cout << dat[i].top() << '\n';
        }
    }
}