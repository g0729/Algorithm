# [Platinum III] 적군을 막아라 - 14261 

[문제 링크](https://www.acmicpc.net/problem/14261) 

### 성능 요약

메모리: 2688 KB, 시간: 0 ms

### 분류

최대 유량, 최대 유량 최소 컷 정리, 그래프 이론

### 제출 일자

2025년 5월 11일 19:02:25

### 문제 설명

<p>sys나라에 nein나라가 전쟁을 일으켰다. nein나라가 군대를 이끌고 sys나라에 쳐들어 가려 하고 있고, sys나라에서는 이 군대들을 막아야 한다.</p>

<p>sys나라와 nein나라 사이에는 주요한 거점지들이 있고, 그 거점지들 사이에 도로로 이어져 있다. 즉, 한 거점지가 뚫린다면, 도로로 이어진 거점지를 공격할 수 있다.</p>

<p>sys나라의 왕 영선이는 주어진 병력을 가지고 nein나라의 침공을 막아야 한다. 다행히 오랜 전쟁경험을 통해 거점지마다 얼마의 병력을 투입하면 공격받았을 때 그 거점지를 확실히 막을 수 있는 알고 있다. (해당하는 병력을 투입하지 않으면 그 거점지는 뚫린다) 따라서 병력을 거점지에 적절히 배치하여 nein나라의 침공을 막고자 한다. 하지만, sys나라로 올 수 있는 거점지가 하나라도 뚫린다면, 나라가 공격당해 전쟁에서 지게 된다.</p>

<p>영선이는 병력을 적절히 배치하여 nein나라의 침공을 막을 수 있으면 좋겠지만, 모든 병력을 사용하더라도 침공을 막을 수 없다면, 국민을 희생시킬 수 없으므로, 항복을 하려한다.</p>

<p>따라서 이 병력 배치문제를 sys나라에서 가장 똑똑한 당신에게 부탁하였다. sys나라의 병력의 수 k가 주어졌을 때, 병력을 적절히 배치하여 nein나라의 침공을 막을 수 있는지 없는지를 알아내 왕에게 보고하라.</p>

### 입력 

 <p>첫째 줄에는 거점지의 수 n과 도로의 수 m, 병력의 수 k가 주어진다.(2≤n≤100, 1≤m≤1,000, 1≤k≤10,000)</p>

<p>다음 줄에는 각 거점지에서 침공을 막을 수 있는 병력의 수ai가 주어진다.(1≤ai≤1,000 or ai=-1)</p>

<p>그 다음 m줄에는 도로가 잇는 두 거점지의 번호가 주어진다. 거점지는 1번부터 주어진다. sys나라의 수도는 거점지 1번에, nein나라의 수도는 거점지 n번에 위치하며 두 수도에는 병력을 배치할 수 없다.(입력으로는 -1이 들어온다)</p>

### 출력 

 <p>병력 k를 적절히 배치하여 nein나라의 침공을 막을 수 있다면 “YES”,아니면 “NO”를 출력하라.</p>

