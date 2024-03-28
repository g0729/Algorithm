#pragma warning(disable: 4996)
#define _CRT_NO_SECURE_WARNINGS

#include <stdio.h>
#include <math.h>

int main(void)
{
	int decompose;			//분해합
	int generator;			//생성자
	int digit = 1;			//자릿수
	int tempSum = 0;
	int tempDecom;
	int start;				//검사할 생성자의 최소 범위

	scanf("%d", &decompose);

	//예외 처리
	if (decompose == 1)
	{
		printf("%d", 0);

		return 0;
	}

	//분해합의 자릿수 구하기
	while ((decompose % (int)pow(10, digit)) != decompose)
	{
		digit++;
	}

	//i 초기값, 검사할 생성자의 범위를 가능한 최소(분해합 - (9 * 분해합의 자릿수))부터 검사 시작
	if (decompose > 18)
		start = (decompose - digit * 9);
	else
		start = 1;


	//i : 현재 검사하는 생성자
	for (int i = start; i <= decompose; i++)
	{
		tempDecom = i;
		tempSum = tempDecom;

		//i 값을 tempDecom에 복사하여 임시 분해합 만들기
		for (int j = digit-1; j >= 0; j--)
		{
			tempSum += tempDecom / (int)pow(10, j);
			tempDecom = tempDecom % (int)pow(10, j);

			//연산 도중 임시 분해합이 분해합보다 클 경우 다음 케이스로 넘어가기
			if (tempSum > decompose)
				break;

			//모든 자리의 숫자를 더했고, 그 합이 분해합과 동일할 경우
			if (j == 0 && tempSum == decompose)
			{
				printf("%d", i);
				
				return 0;
			}

		}
	}

	printf("%d", 0);


	return 0;

}

