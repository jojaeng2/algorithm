#include <iostream>

int li[5];
using namespace std;
int main(){
    for(int i = 0;i <= 4;i++){
        cin >> li[i];
    }
    int x;
    bool change = true;
    while(change != false){
        change = false;
        for(int i=0;i<4;i++){
            if(li[i] > li[i+1]){
                x = li[i];
                li[i] = li[i+1];
                li[i+1] = x;
                change = true;
                for(int j=0;j<=4;j++){
                    cout << li[j] << " ";
                }
                cout << endl;
            }
        }
    }

}