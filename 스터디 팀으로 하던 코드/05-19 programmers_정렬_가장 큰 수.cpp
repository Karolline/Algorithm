#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(int a, int b) {
    string sa = to_string(a);
    string sb = to_string(b);
    
    return sa+sb > sb+sa;
}

string solution(vector<int> numbers) {
    string answer;
    sort(numbers.begin(), numbers.end(), cmp);
    
    if(numbers[0] == 0) return "0"; // 
    
    for(int i=0; i<numbers.size(); i++) {
        //cout << numbers[i];
        answer += to_string(numbers[i]);
    }
    //cout << endl;
    
    return answer;
}