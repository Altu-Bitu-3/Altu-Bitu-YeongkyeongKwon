#include <iostream>
#include <stack>
#include <string>

using namespace std;
stack<char> s;
int checkPaired(string str) {
	int min_cal = 0; //�ּ� ������ ��

	for (int i = 0; i < str.size(); i++) {
		
		switch (str[i]) {
			case'{':	
				s.push(str[i]);
				break;
			case'}':
				if (!s.empty()&& s.top() == '{') {//¦�� �´� ��쿡�� pop
					s.pop();
				}
				else {//¦�� ���� �ʴ� ��쿡�� push
					s.push(str[i]);
				}
				break;
		}
	}

	while(!s.empty()){
		int before = s.top();
		s.pop();
		if (before == s.top()) {// {{ Ȥ�� }} �� ��� ���� 1�� �ʿ�
			min_cal += 1;
		}
		else { // }{ �� ��� ���� 2�� �ʿ�
			min_cal += 2; 
		}
		s.pop();
	}

	return min_cal;
}

int main() {
	string str;
	int i = 1;
	int result;

	while (true) {
		//�Է�
		cin >> str;
		if (str.find('-')!=string::npos) { //-�� �� ���ڿ��� ��� break
			break;
		}

		result=checkPaired(str);

		//���
		cout << i++ << ". " <<result<< "\n";
	}

	return 0;
}