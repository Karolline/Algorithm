#include <string>
#include <vector>

using namespace std;

vector<int> visited;

void DFS(int start, int n, vector<vector<int>> computers) {
    visited[start] = 1;
    for(int i=0; i<n; i++) {
        if(computers[start][i] && visited[i] != 1) {
           DFS(i, n, computers) ;
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    for(int i=0; i<n; i++) {
        visited.push_back(0);
    }
    
    int answer = 0;
    
    
    for(int i=0; i<n; i++) {
        if(!visited[i]) answer++;
        DFS(i, n, computers);
    }
    return answer;
}