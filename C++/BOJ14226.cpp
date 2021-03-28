#include <iostream>
#include <queue>

using namespace std;

int board[2001][2001];
queue<pair<pair<int,int>,int> >q;

int main(){
    int n;
    cin >> n;
    q.push(make_pair(make_pair(1,0),1));
    board[1][0] = 0;
    while(!q.empty()){
        int x = q.front().first.first;
        int clip = q.front().first.second;
        int time  = q.front().second;
        q.pop();
        if(x == n){
            cout << time-1 << endl;
            break;
        }
        if(x+clip < 2001 && board[x+clip][clip] == 0){
            board[x+clip][clip] = 1;
            q.push(make_pair(make_pair(x+clip,clip),time+1));
        }
        if(x<2001 && board[x][x] == 0){
            board[x][x] = 1;
            q.push(make_pair(make_pair(x,x),time+1));
        }
        if(x-1>0 && board[x-1][clip] == 0){
            board[x-1][clip] = 1;
            q.push(make_pair(make_pair(x-1,clip),time+1));
        }
    }
}