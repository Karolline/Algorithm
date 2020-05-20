#include <string>
#include <vector>
#include <iostream>

using namespace std;

pair<int, int> cmp(int target, int std) {
    string targets = to_string(target);
    string stds = to_string(std);

    int strike = 0;
    int ball = 0;

    for(int i=0; i<targets.size(); i++) {
        for(int j=0; j<targets.size(); j++) {
            if(targets[i] == stds[j]) {
                if(i==j) {
                    strike++;
                }
                else {
                    ball++;
                }
            }
        }
    }
    return make_pair(strike, ball);
}

vector<int> ele;
bool Pass(int cand) {
    ele.clear();
    int tmp = 0;
    while(cand >= 1) {
        tmp = cand%10;
        if(tmp == 0) return true;
        ele.push_back(tmp);

        cand /= 10;
    }
    if(ele[0] == ele[1] || ele[0] == ele[2] || ele[1] == ele[2])
        return true;

    return false;
}

int solution(vector<vector<int>> baseball) {
    int answer = 0;

    /*int tmp = 324;
    pair<int, int> rslt = cmp(tmp, baseball[3][0]);
    cout << rslt.first << " " << rslt.second << endl;*/

    int cand = 102;
    while(cand <= 987) {
        bool matched = false;

        if(Pass(cand)) {
            cand++;
            continue;
        }

        for(int i=0; i<baseball.size(); i++) {
            pair<int, int> rslt = cmp(cand, baseball[i][0]);
            if(rslt.first != baseball[i][1] || rslt.second != baseball[i][2])
                break;

            if(i == baseball.size()-1) {
                matched = true;
                // cout << cand << "가 부합" << endl;
            }
        }

        if(matched) answer++;

        cand++;
    }

    return answer;
}