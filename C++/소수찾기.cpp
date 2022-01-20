#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>
using namespace std;
bool visit[10] = {false};
vector<char> v;
vector<int> nums;
int answer = 0;
set<int> st;

bool sosu(int number) {
	if(number/10 == 0) {
		if(number==2 || number==3 || number==5 || number==7) return true;
		else return false;
	}
	for(int i=2;i<sqrt(number)+1;i++) {
		if(number % i == 0) return false;
	} 
	return true;
}


void dfs(string nums, string psum) {
    if(psum.size() != 0 && st.find(stoi(psum)) == st.end() && sosu(stoi(psum)) ) {
        st.insert(stoi(psum));
        cout << psum << '\n';
        answer++;
    }
    for(int i=0; i<nums.size(); i++) {
        if(visit[i]) continue;
        visit[i] = true;
        dfs(nums, psum + nums[i]);
        visit[i] = false;
    }
}

int solution(string numbers) {
    dfs(numbers, "");
    return answer;
}