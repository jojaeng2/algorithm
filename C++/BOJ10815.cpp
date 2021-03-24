#include <iostream>
#include <algorithm>

using namespace std;
int num[500001],card[500001];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    sort(num,num+n);
    int m;
    cin >> m;
    for(int j=0;j<m;j++){
        cin >> card[j];
    }
    for(int i=0;i<m;i++){
        int start = 0;
        int end = n-1;
        while(start<=end){
            int mid = (start+end)/2;
            if (num[mid] > card[i]){
                end = mid - 1;
            } else if(num[mid] == card[i]){
                card[i] = 10000001;
                break;
            } else {
                start = mid + 1;
            }
        }
    }
    for(int i=0;i<m;i++){
        if(card[i] == 10000001){
            cout << 1 << " ";
        }else{
            cout << 0 << " ";
        }
        
    }
}