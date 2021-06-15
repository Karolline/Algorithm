#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<pair<int, int>> sum(3, make_pair(0, 0));
    
    for(int i=0; i<3; i++) {
        sum[i].second = i+1;
    }
    
    int aDap[5] = {1, 2, 3, 4, 5};
    int bDap[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int cDap[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for(int t=0; t<answers.size(); t++) {
        if(answers[t] == aDap[t%5]) sum[0].first++;
        if(answers[t] == bDap[t%8]) sum[1].first++;
        if(answers[t] == cDap[t%10]) sum[2].first++;
    }
    
    // cout << sum[0].first << " " << sum[1].first << " " << sum[2].first << endl;
    sort(sum.begin(), sum.end(), cmp);
    
    answer.push_back(sum[0].second);
    int std = sum[0].first; // 최고점
    for(int i=1; i<sum.size(); i++) {
        if(std == sum[i].first) {
            answer.push_back(sum[i].second);
        }
        else {
            break;
        }
    }
    
    return answer;
}