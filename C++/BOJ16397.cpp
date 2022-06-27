#include <iostream>
#include <queue>

using namespace std;
int visit[100000] = {0};
queue<int>q;
int main(){
    int n,t,g;
    cin >>n >> t >> g;
    visit[n] = 1;
    q.push(n);
    bool flag = false;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(visit[x] - 1 <= t){
            if(x == g){
                cout << visit[x]-1 << '\n';
                flag = true;
                break;
            }
            if(x + 1 <= 99999 && visit[x+1] == 0){
                visit[x+1] = visit[x] + 1;
                q.push(x+1);
            }
            int num = 2*x;
            if(num <= 99999){
                int dat = num;
                int one = 1;
                while(num){
                    num /= 10;
                    one *= 10;
                }
                one /= 10;
                dat -= one;
                if(dat < 99999 && visit[dat] == 0){
                    visit[dat] = visit[x] + 1;
                    q.push(dat);
                }
            }
        }
    }
    if(flag == false){
        cout << "ANG" << endl;
    }
}