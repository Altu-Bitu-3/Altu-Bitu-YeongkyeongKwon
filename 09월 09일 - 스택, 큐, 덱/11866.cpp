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

		if (cnt == k) {//k번째라면 값을 arr에 넣은 뒤 삭제
			arr.push_back(q.front());
			q.pop();
			cnt = 0;
		}
		else {//k번째가 아니라면 값을 맨 뒤로 이동 시킴
			front = q.front();
			q.pop();
			q.push(front);
		}
		
		cnt++;
	}

	//출력
	cout << "<";
	for (int i = 0; i < arr.size() - 1; i++) {
		cout << arr[i] << ", ";
	}
	cout << arr[arr.size() - 1] << ">";
}

int main() {
	int n, k;

	//입력
	cin >> n;
	cin >> k;

	for (int i = 1; i <= n; i++) {//n까지의 숫자를 큐에 입력
		q.push(i);
	}

	popK(k);

	return 0;
}