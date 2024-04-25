N, B = map(int, input().split())

answer = ""  # str 타입

while N // B > 0:  # 1) 몫이 0 초과인 경우 루프
    if N % B < 10:
        answer = answer + str(N % B)  # 1-1) 나머지 : 10 이하인 경우 숫자 그대로 추가
    if N % B >= 10:
        answer = answer + str(chr(N % B + 55))  # 1-2) 나머지 : 10 이상인 경우 아스키 코드 변환하여 추가
    N = N // B  # 3) N을 B으로 나눈 몫

## ※ B는 2 이상(1인 경우, N//B 값이 계속 N으로 동일하여 무한 루프 발생)

if N // B == 0:  # 2) 몫이 0이 된 순간 or 처음부터 0인 경우, 마지막 나눗셈의 나머지만 추가하고 종료
    if N % B < 10:
        answer = answer + str(N % B)  # 2-1) 10 이하인 경우 숫자 그대로
    if N % B >= 10:
        answer = answer + str(chr(N % B + 55))  # 2-2) 10 이상인 경우 아스키 코드 변환

print(answer[::-1])  # 3) B진법 수 (역순 출력)
