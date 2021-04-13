#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<pair<int,int>,int> piii;
vector<piii>graph;
int visit[10001];
int v,e,result;

int find(int start){
    if(start==visit[start]){
        return start;
    }
    visit[start] = find(visit[start]);
    return visit[start];
}

bool uni(int a,int b){
    int na = find(a);
    int nb = find(b);
    if(na==nb) return false;
    if(na<nb) visit[nb] = na;
    else visit[na] = nb;
    return true;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> v >> e;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph.push_back({{c,a},b});
    }
    sort(graph.begin(),graph.end());
    for(int i=0;i<=v;i++){
        visit[i] = i;
    }
    for(int i=0;i<graph.size();i++){
        int dat = graph[i].first.first;
        int x = graph[i].first.second;
        int y = graph[i].second;
        if(uni(x,y)) result += dat;
    }
    cout << result << endl;
}