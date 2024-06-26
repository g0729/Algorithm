# [Platinum V] 까다로운 아이들과 선물 상자 - 23760 

[문제 링크](https://www.acmicpc.net/problem/23760) 

### 성능 요약

메모리: 4368 KB, 시간: 72 ms

### 분류

자료 구조, 세그먼트 트리

### 제출 일자

2023년 4월 28일 16:27:04

### 문제 설명

<p>상훈이는 $N$개의 선물 상자를 가지고 있다. 선물 상자에는 현재 담겨있는 선물의 개수가 적혀있다.</p>

<p>선물을 받을 아이들이 $M$명 있다. 아이들은 각자 $1$에서 $M$까지의 서로 다른 번호를 하나씩 부여받았다.</p>

<p>$1$번 아이부터 $M$번 아이까지 한 번에 한 명씩, 자신의 배려심 $b_i$번째로 많은 선물이 들어있는 선물 상자에서 각자 원하는 만큼 선물을 가져간다. 예를 들어 어떤 아이의 배려심이 $3$이라면, 선물이 3번째로 많이 들어있는 선물 상자에서 가져간다. 이 때, 앞서 누군가 선물을 가져갔던 선물 상자에서 또다시 가져가도 상관없다</p>

<p>하지만 상자에 자신이 원하는 것보다 적은 개수의 선물이 들어있다면, 선물을 가져가지 못해 실망한다.</p>

<p>상훈이는 한 사람이라도 실망하지 않고 모두가 선물을 가져갈 수 있는지 궁금하다.</p>

### 입력 

 <p>첫째 줄에 선물 상자의 수 $N$과 아이들의 수 $M$이 공백을 사이에 두고 주어진다. ($1\le M\le N\le 10^5$)</p>

<p>둘째 줄에 선물 상자에 들어있는 선물의 개수 $c_1,c_2,\ldots ,c_N$이 공백을 사이에 두고 주어진다. ($1\le c_i\le 10^5$)</p>

<p>셋째 줄에 아이들의 번호 순으로 각 아이가 원하는 선물의 개수 $w_1,w_2,\ldots ,w_M$이 공백을 사이에 두고 주어진다. ($1\le w_i\le 10^5$)</p>

<p>넷째 줄에 아이들의 번호 순으로 각 아이의 배려심 $b_1, b_2, \ldots ,b_M$이 공백을 사이에 두고 주어진다. ($1\le b_i\le N$)</p>

### 출력 

 <p>모든 아이들이 실망하지 않고 각자 원하는 만큼 선물을 가져갈 수 있으면 $1$을, 그렇지 않으면 $0$을 출력한다.</p>

