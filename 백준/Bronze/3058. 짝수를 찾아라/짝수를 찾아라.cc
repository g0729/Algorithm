#include <iostream>
#include <algorithm>
#include <string> 
#include<vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	int num1[7], num2[7];
	vector<string> result_;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < 7; j++) {
			cin >> num1[j];
		}
		int count = 0;
		for (int j = 0; j < 7; j++) {
			if (num1[j] % 2 == 0) {
				num2[count] = num1[j];
				count++;
			}
		}
		sort(num2, num2 + count);
		int sum = 0;
		for (int k = 0; k < count; k++) {
			sum += num2[k];
		}
		int min = num2[0];

		string sum_ = to_string(sum);
		string min_ = to_string(min);
		string result = sum_ +' ' + min_;
		result_.push_back(result);
	}
	for (int i = 0; i < t; i++) {
		cout << result_[i] << '\n';
	}

}