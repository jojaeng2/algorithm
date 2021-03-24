#include <iostream>

using namespace std;

int main(){
    int cnt = 0;
    int a,b;
    cin >> a >> b;
    int x = 0;
    int y = 0;
    int num = 0;
    int i = 0;
    
    while(cnt<1001){
        i += 1;
        for(int j=0;j<i;j++){
            num += i;
            cnt += 1;
            if(cnt+1==a){
                x = num;
            }
            if(cnt==b){
                y = num;
            }
        }
    }
    cout << y-x << endl;
}