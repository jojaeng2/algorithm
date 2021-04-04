#include <iostream>
#include <map>

using namespace std;
int visit[100001];


int find(int gate){
    if(gate == 0){
        return 0;
    }
    if(gate == visit[gate]){
        visit[gate] = visit[gate-1];
        return gate;
    }
    visit[gate] = find(visit[gate]);
    return visit[gate];
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int g,p;
    cin >> g >> p;
    for(int i=1;i<=g;i++){
        visit[i] = i;
    }
    int cnt = 0;
    bool flag = true;
    for(int i=0;i<p;i++){
        int airplane;
        cin >> airplane;
        if(flag){
            if(find(airplane) != 0){
                cnt += 1;
            } 
            else {
                flag = false;
            }
        }
    }
    cout << cnt << '\n';
}