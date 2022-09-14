#include <iostream>
#include <stack>
#include <string>

using namespace std;
stack<char> s;
int checkPaired(string str) {
	int min_cal = 0; //최소 연산의 수

	for (int i = 0; i < str.size(); i++) {
		
		switch (str[i]) {
			case'{':	
				s.push(str[i]);
				break;
			case'}':
				if (!s.empty()&& s.top() == '{') {//짝이 맞는 경우에는 pop
					s.pop();
				}
				else {//짝이 맞지 않는 경우에는 push
					s.push(str[i]);
				}
				break;
		}
	}

	while(!s.empty()){
		int before = s.top();
		s.pop();
		if (before == s.top()) {// {{ 혹은 }} 의 경우 연산 1번 필요
			min_cal += 1;
		}
		else { // }{ 의 경우 연산 2번 필요
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
		//입력
		cin >> str;
		if (str.find('-')!=string::npos) { //-가 들어간 문자열일 경우 break
			break;
		}

		result=checkPaired(str);

		//출력
		cout << i++ << ". " <<result<< "\n";
	}

	return 0;
}