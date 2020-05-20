#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int ver = 3;
    int hor = (brown + yellow) / ver;
    
    while(hor >= ver && hor >= 3) {
        hor = (brown + yellow) / ver;
        //cout << "hor: " << hor << " ver: " << ver << endl;
        
        if((ver-2) * (hor-2) == yellow) {
            answer.push_back(hor);
            answer.push_back(ver);
            break;
        }
        
        ver++;
        while( (brown+yellow)%ver != 0)
            ver++;
        
    }
    
    return answer;
}