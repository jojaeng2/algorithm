#include <string>
#include <vector>
#include <cstring>
using namespace std;
int psum[2010];

int solution(vector<int> cookies) {
    memset(psum, 0, sizeof(psum));
    int answer = 0;
    for(int i=0; i<cookies.size(); i++) {
        int cookie = cookies[i];
        psum[i+1] = cookie;
        psum[i+1] += psum[i];
    }
    for(int i=1; i<=cookies.size(); i++) {
        int l = 1, r = cookies.size();
        while(l <= r) {
            int right = psum[r]-psum[i];
            int left = psum[i] - psum[l-1];
            if(left == right) {
                answer = max(answer, right);
                break;
            }
            if(left < right) r--;
            else l++;
        }
    }
    return answer;
}