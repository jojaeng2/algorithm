#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n,m;
int visit[1001];
vector<int> graph[1001],v;
priority_queue<int> pq;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a;
        cin >> a;
        if(a==0) continue;
        int dat[a];
        for(int j=0;j<a;j++){
            cin >> dat[j];
        }
        for(int j=1;j<a;j++){
            graph[dat[j-1]].push_back(dat[j]);
            visit[dat[j]]++;
        }
    }
    
    for(int i=1;i<=n;i++){
        if(visit[i]==0) pq.push(-i);
    }

    while(!pq.empty()){
        int x = -pq.top();
        pq.pop();
        v.push_back(x);
        for(int i=0;i<graph[x].size();i++){
            int next = graph[x][i];
            visit[next]--;
            if(visit[next]==0) pq.push(-next);
        }
    }
    if(v.size()!=n){
        cout << 0 << endl;
    } else {
        for(int i=0;i<v.size();i++){
            cout << v[i] << endl;
        }
    }
}