#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//변수 선언
	int N = 0;
	vector<int> vArray;
	int p = 0;
	double sum = 0.0;
	cin >> N;
	int countArray[8001] = { 0, };
	int value = 0;
	bool flag = false;
	int max = 0;

	//결과 받아줄 변수들 
	double sansul = 0;
	int jungang = 0;
	int chebin = 0;
	int range = 0;

	//값을 배열에 넣어줌
	for (int i = 0; i < N; i++) {
		cin >> p;
		vArray.push_back(p);
		// 총 합 구하기
		sum = sum + p;
		// 누적 함수 생성
		countArray[p + 4000]++;
		// 공통된 수의 최대 개수 구하기
		if (countArray[p + 4000] > max) {
			max = countArray[p + 4000];
		}
	}
	
	//크기 순으로 정렬한다.
	sort(vArray.begin(), vArray.end());

	//산술 평균 값
	sansul = sum / (float)N;

	//중앙 값
	jungang = vArray[N / 2];

	//범위 값
	range = vArray[N - 1] - vArray[0];

	//최빈 값 구하기
	for (int i = -4000; i < 4001; i++) {
		if (countArray[i + 4000] == max) {
			if (flag == true) {
				chebin = i;
				break;
			}
			else {
				flag = true;
				chebin = i;
			}
		}
	}

	//결과 출력
	// -0이 나올 가능성은 배제
	if (round(sansul) == -0)
		cout << 0 << "\n";
	else
		cout << round(sansul) << "\n";
	cout << jungang << "\n";
	cout << chebin << "\n";
	cout << range << "\n";

	return 0;
}
