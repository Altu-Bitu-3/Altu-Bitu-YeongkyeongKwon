#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int> q;

void popK(int k) {
	vector<int> arr;
	int cnt = 1;
	
	while (!q.empty()) {
		
		int front;

		if (cnt == k) {//k��°��� ���� arr�� ���� �� ����
			arr.push_back(q.front());
			q.pop();
			cnt = 0;
		}
		else {//k��°�� �ƴ϶�� ���� �� �ڷ� �̵� ��Ŵ
			front = q.front();
			q.pop();
			q.push(front);
		}
		
		cnt++;
	}

	//���
	cout << "<";
	for (int i = 0; i < arr.size() - 1; i++) {
		cout << arr[i] << ", ";
	}
	cout << arr[arr.size() - 1] << ">";
}

int main() {
	int n, k;

	//�Է�
	cin >> n;
	cin >> k;

	for (int i = 1; i <= n; i++) {//n������ ���ڸ� ť�� �Է�
		q.push(i);
	}

	popK(k);

	return 0;
}