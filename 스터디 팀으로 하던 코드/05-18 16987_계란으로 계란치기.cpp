#include <iostream>
#include <vector>
using namespace std;

struct Egg {
	int n; // 내구도
	int w; // 무게	
	bool broken = false;
};

vector<Egg> eggList;

int N; // 계란 수
int answer;

void Input() {
	cin >> N;
	int n, w;
	for (int i = 0; i < N; i++) {
		cin >> n >> w;
		eggList.push_back(Egg{ n, w });
	}
}


int Count() {
	int num = 0;
	for (int i = 0; i < eggList.size(); i++) {
		if (eggList[i].broken) num++;
	}
	//cout << "count: " << num << endl;
	return num;
}

bool AllBroken(int exc) {

	for (int i = 0; i < eggList.size(); i++) {
		if (i != exc && eggList[i].broken == false) return false;
	}

	return true;
}

void Simulate(int idx) { // idx: 손에 드는 계란
	if (AllBroken(idx) || idx >= eggList.size()) { // 더 깰 수 있는 계란이 안 남아있다면 또는 제일 오른쪽 계란을 이미 들었다면
		
		int tmp = Count();
		if (tmp > answer) answer = tmp;
		return;
	}

	if (eggList[idx].broken) {
		Simulate(idx + 1);
	}
	else {
		for (int i = 0; i < eggList.size(); i++) {
			if (eggList[i].broken) continue;
			if (idx == i) continue;

			// 부딪힌다
			eggList[idx].n -= eggList[i].w;
			eggList[i].n -= eggList[idx].w;

			if (eggList[idx].n <= 0) eggList[idx].broken = true;
			if (eggList[i].n <= 0) eggList[i].broken = true;

			Simulate(idx + 1);

			// 원상복구
			eggList[idx].n += eggList[i].w;
			eggList[i].n += eggList[idx].w;
			if (eggList[idx].n > 0) eggList[idx].broken = false;
			if (eggList[i].n > 0) eggList[i].broken = false;
		}
	}
	
}

int main() {

	Input();

	Simulate(0);

	cout << answer;

	return 0;
}