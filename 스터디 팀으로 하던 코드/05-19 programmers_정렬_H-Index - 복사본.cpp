#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater<int>());
    for(int i=0; i<citations.size(); i++) {
        cout << citations[i];
    }
    
    for(int i=0; i<citations.size(); i++) {
        if(i+1 <= citations[i]) answer = i+1;
    }
    
    return answer;
}