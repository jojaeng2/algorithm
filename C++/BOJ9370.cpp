#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
#define X first
#define Y second

using namespace std;
typedef pair<int,int> pii;
int T,n,m,t,s,g,h;
vector<pii> graph[2001];
vector<int> v;
int visit1[2001],visit2[2001],visit3[2001];

void dijk(int start,int visit[2001]){
    priority_queue<pii, vector<pii>, greater<pii> >pq;
    pq.push(make_pair(0,start));
    visit[start] = 0;
    while(!pq.empty()){
        int dist = pq.top().X;
        int now = pq.top().Y;
        pq.pop();
        if(visit[now]<dist) continue;
        for(int i=0;i<graph[now].size();i++){
            int cost = dist + graph[now][i].Y;
            int next = graph[now][i].X;
            if(cost<visit[next]){
                visit[next] = cost;
                pq.push(make_pair(cost,next));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--){
        if(T==-1) break;
        fill(visit1,visit1+2001,INF);
        fill(visit2,visit2+2001,INF);
        fill(visit3,visit3+2001,INF);
        for(int i=0;i<2001;i++){
            graph[i].clear();
        }
        v.clear();
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        for(int i=0;i<m;i++){
            int a,b,c;
            cin >> a >> b >> c;
            graph[a].push_back(make_pair(b,c));
            graph[b].push_back(make_pair(a,c));
        }
        dijk(s,visit1);
        dijk(g,visit2);
        dijk(h,visit3);
        for(int i=0;i<t;i++){
            int a,res;
            cin >> a;
            res = visit1[a];
            if(res==visit1[g]+visit2[h]+visit3[a] || res == visit1[h]+visit3[g]+visit2[a]) v.push_back(a);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
}