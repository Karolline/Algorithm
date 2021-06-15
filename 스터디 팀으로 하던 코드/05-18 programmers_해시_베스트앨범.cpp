#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<string, vector<pair<int, int>>> map; 
// vector<pair<int, int>>에서 첫번째 int: 재생횟수 두번째 int: 고유번호
// vector의 0번째 요소: 해당 장르의 총 재생횟수


bool cmp1(pair<string, vector<pair<int, int> > > a, pair<string, vector<pair<int, int> > > b) {
    return a.second[0].first > b.second[0].first;
}

bool cmp2(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for(int i=0; i<genres.size(); i++) {
        if(map.count(genres[i])) { // 이미 있다
            map.find(genres[i])->second.push_back(make_pair(plays[i], i));
            map.find(genres[i])->second[0].first += plays[i];
        }
        else {
            vector<pair<int, int>> list;
            list.push_back(make_pair(plays[i], -1)); // 총 재생 횟수
            list.push_back(make_pair(plays[i], i)); // 특정 노래의 재생횟수 및 고유번호
            map.insert(make_pair(genres[i], list));
        }
        
    }
    
    vector<pair<string, vector<pair<int, int> > > > vec;
    for(auto it=map.begin(); it!=map.end(); it++) {
        sort(it->second.begin()+1, it->second.end(), cmp2);
        /*cout << it->first << endl;
        for(int i=0; i<it->second.size(); i++) {
            cout << it->second[i].first << "(" << it->second[i].second << ")" << endl;
        }*/
        vec.push_back(make_pair(it->first, it->second));
    }
    
    
    sort(vec.begin(), vec.end(), cmp1);
    
    /*for(int i=0; i<vec.size(); i++) {
        cout << vec[i].first << "====" << endl;
        for(int j=0; j<vec[i].second.size(); j++) {
            cout << vec[i].second[j].first << " ";
        }
        cout << endl;
    }*/
    
    for(int i=0; i<vec.size(); i++) {
        for(int j=1; j<3; j++) {
            if(j >= vec[i].second.size()) break;
            answer.push_back(vec[i].second[j].second);
        }
    }
    
    return answer;
}