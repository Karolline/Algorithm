#include <iostream>
#include <vector>
using namespace std;

struct Egg {
	int n; // ������
	int w; // ����	
	bool broken = false;
};

vector<Egg> eggList;

int N; // ��� ��
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

void Simulate(int idx) { // idx: �տ� ��� ���
	if (AllBroken(idx) || idx >= eggList.size()) { // �� �� �� �ִ� ����� �� �����ִٸ� �Ǵ� ���� ������ ����� �̹� ����ٸ�
		
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

			// �ε�����
			eggList[idx].n -= eggList[i].w;
			eggList[i].n -= eggList[idx].w;

			if (eggList[idx].n <= 0) eggList[idx].broken = true;
			if (eggList[i].n <= 0) eggList[i].broken = true;

			Simulate(idx + 1);

			// ���󺹱�
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