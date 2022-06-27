#include <iostream>
#include <algorithm>
using namespace std;
long list[5001];
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    // list에 용액을 입력받아 정렬해줍니다.
    for(int i=0;i<n;i++){
        cin >> list[i];
    }
    sort(list,list+n);

    //result 배열에 세 합이 가장 0에 가까운 용액을 저장할것 입니다.
    long result[3] = {list[0],list[1],list[2]};
    for(int i=0;i<n;i++){
        //용액 한개를 고정시키고, start와 end 를 이동시키면서 가장 0에 가까운 용액을 찾습니다.
        int start=i+1, end=n-1;
        while(start<end){
            //data에는 현재 세 용액의 합이 들어가고, sum에는 이전에 세 합이 0과 가장 가까운 용액의 절대값이 들어있습니다.
            //절대값을 사용한 이유는 음수든 양수든 0과 가까운 값을 찾기위해서 입니다.
            long data = list[i]+list[start]+list[end];
            long sum = abs(result[0]+result[1]+result[2]);
            //만약 data의 절대값이 sum보다 작다면 세합이 0과 가까운 새로운 세용액을 찾은것이기 때문에 result 배열의 값을 바꿔줍니다.
            if(abs(data) < sum){
                result[0] = list[i];
                result[1] = list[start];
                result[2] = list[end];
            } 
            //data가 0보다 크다면 더 작게 만들어 0과 가깝게 만들기 위해서 end-1을, 0보다 작다면 반대로 start += 1을 해주었습니다.
            if(data > 0){
                end -= 1;
            } else {
                start += 1;
            }
        }
    }
    for(int i=0;i<3;i++){
        cout << result[i] << " ";
    }
}