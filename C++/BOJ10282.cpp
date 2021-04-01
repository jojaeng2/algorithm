#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        vector<pair<int,int> >graph[10001];
        int visit[10001];
        fill(visit,visit+10001,INF);
        int n,m,d;
        cin >> n >> m >> d;
        
        for(int j=0;j<m;j++){
            int a,b,c;
            cin >> a >> b >> c;
            graph[b].push_back(make_pair(a,c));
        }

        priority_queue<pair<int,int> >pq;
        pq.push(make_pair(0,d));
        visit[d] = 0;

        while(!pq.empty()){
            int dist = -pq.top().first;
            int now = pq.top().second;
            pq.pop();
            if(visit[now] < dist){
                continue;
            }
            for(int p=0;p<graph[now].size();p++){
                int cost = dist + graph[now][p].second;
                if(cost < visit[graph[now][p].first]){
                    visit[graph[now][p].first] = cost;
                    pq.push(make_pair(-cost,graph[now][p].first));
                }
            }
        }
        int result = 0,cnt = 0;
        for(int j=0;j<n+1;j++){
            if(visit[j] != INF){
                cnt += 1;
                if(visit[j] > result){
                    result = visit[j];
                }
            }
        }
        cout << cnt << " " << result << '\n';
    }
    
}