#include <iostream>
#include <queue>

using namespace std;
queue<pair<int,int> >q;

int main(){
    int n,m,x,cnt;
    cin >> n >> m;
    q.push(make_pair(m,1));
    while(!q.empty()){
        x = q.front().first;
        cnt = q.front().second;
        q.pop();
        if(x==n){
            break;
        }
        if(x%10==1){
            int y = x/10;
            q.push(make_pair(y,cnt+1));
        } 
        if(x > 0 && x%2==0){
            int y = x/2;
            q.push(make_pair(y,cnt+1));
        }
    }
    if(x==n){
        cout << cnt << endl;
    } else {
        cout << -1 << endl;
    }
}