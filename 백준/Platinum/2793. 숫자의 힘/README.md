# [Platinum IV] 숫자의 힘 - 2793 

[문제 링크](https://www.acmicpc.net/problem/2793) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학, 정수론

### 제출 일자

2022년 2월 3일 20:25:03

### 문제 설명

<p>양의 정수 N이 있을 때, N을 나눌 수 없는 가장 작은 수 A를 찾을 수 있다. 예를 들어, 6은 4로 나누어 떨어지지 않으므로, A는 4가 된다.</p>

<p>이렇게 A를 찾은 다음, 그 수를 다시 N이라고 하고, 나눌 수 없는 가장 작은 수 A를 찾는 것을 계속해서 한다면, 결국에는 A는 2가 된다.</p>

<p>N이 2가 된다면, 더이상 찾지 않고 여기서 그만한다.</p>

<p>우리는 이런 성질을 이용해서 strength(N)을 위의 방법에서 나온 N의 수열의 길이로 정의할 수 있다.</p>

<p>예를 들어, N=6이라면 6, 4, 3, 2를 얻을 수 있으므로, strength(6) = 4가 된다.</p>

<p>두 양의 정수 A < B가 주어졌을 때, A와 B를 포함하여 그 사이에 있는 숫자의 힘의 합을 구하는 프로그램을 작성하시오.</p>

<p>strength(A) + strength(A+1) + ... + strength(B)</p>

### 입력 

 <p>첫째 줄에 두 정수 A와 B가 주어진다. (3 <= A < B < 10<sup>17</sup>)</p>

### 출력 

 <p>첫째 줄에 A와 B를 포함하여 그 사이에 있는 숫자의 합을 출력한다.</p>

