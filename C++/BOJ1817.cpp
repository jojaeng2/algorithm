#include <iostream>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int book[n];
    int cnt = 1;
    int num = m;
    for(int i=0;i<n;i++){
        cin >> book[i];
        if(num-book[i] >= 0){
            num -= book[i];
        } else {
            cnt += 1;
            num = m;
            num -= book[i];
        }
    }
    if(n==0){
        cout << 0 << endl;
    } else {
        cout << cnt << endl;
    }
}