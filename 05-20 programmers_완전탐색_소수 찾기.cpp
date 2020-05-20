#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

vector<char> nums;
vector<int> visited(10, 0);
vector<int> checked(9000000, 0);
int answer = 0;

string picked = "";

void Test() {
    int num = atoi(picked.c_str());
    if(num == 1) return;
    if(checked[num]) return; // 이미 확인해본 수
    
    checked[num] = 1;
    
    int std = sqrt(num);
    while(std>1) { // num ~ 2의 제곱근까지의 숫자로 나눠본다
        if(num%std == 0) { // 소수 아님
            return;
        }
        std--;
    }
    
    // 소수임
    answer++;
}

void DFS(int cnt) {
    if(cnt >= nums.size()) {
        return;
    }
    
    for(int i=0; i<nums.size(); i++) {
        if(visited[i]) continue;
        if(cnt == 0 && nums[i] == '0') continue; // 제일 앞에 0은 불가능
        visited[i] = 1;
        
        picked += nums[i];
        Test();
        DFS(cnt+1);
        
        picked = picked.substr(0, picked.size()-1);
        visited[i] = 0;
    }
}

int solution(string numbers) {
    
    for(int i=0; i<numbers.size(); i++) {
        nums.push_back(numbers[i]);
    }
    
    DFS(0);
    
    return answer;
}