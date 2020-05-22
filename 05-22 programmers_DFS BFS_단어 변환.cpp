#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Word {
    string word;
    int cnt;
};
queue<Word> q;
vector<int> visited;

bool CannotConvert(string start, string end) {
    int diff = 0;
    for(int i=0; i<start.size(); i++) {
        if(start[i] != end[i]) diff++;
        if(diff > 1) return true;
    }
    return false;
}

int BFS(string target, vector<string> words) {
    while(!q.empty()) {
        Word thisWord = q.front();
        q.pop();
        
        for(int i=0; i<words.size(); i++) {
            if(CannotConvert(thisWord.word, words[i])) continue;
            if(visited[i]) continue;
            
            if(words[i] == target) return thisWord.cnt+1;
            
            visited[i] = 1;
            q.push(Word{words[i], thisWord.cnt+1});
        }
    }
    
    return 0; // 변환 불가
}

int solution(string begin, string target, vector<string> words) {
    for(int i=0; i<words.size(); i++) {
        visited.push_back(0);
    }
    int answer = 0;
    
    q.push(Word{begin, 0});
    answer = BFS(target, words);
    
    return answer;
}