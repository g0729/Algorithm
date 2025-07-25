# [Gold IV] 소용돌이 - 23019 

[문제 링크](https://www.acmicpc.net/problem/23019) 

### 성능 요약

메모리: 2164 KB, 시간: 68 ms

### 분류

브루트포스 알고리즘, 구현, 정렬, 문자열

### 제출 일자

2025년 6월 18일 17:49:09

### 문제 설명

<p>Albert는 크기가 n × n 인 2차원 행렬 모양의 게임 보드를 이용한 "소용돌이" 게임을 즐긴다. 편의상 게임 보드의 r행 c열에 해당하는 칸을 (r, c)로 나타내도록 한다.</p>

<p>이 게임 보드의 각 칸에는 영문 대문자 알파벳이 ('A'-'Z') 하나씩 적혀있다. 예를 들어, 아래 그림의 좌측은 크기가 3 x 3인 게임 보드를 나타낸다. (1, 2) 칸에는 "C"가 적혀있고 (3, 1) 칸에는 "G"가 적혀있다.<br>
그림의 우측은 크기가 5 x 5인 게임 보드를 나타낸다. 이 게임 보드의 <em>가장 바깥쪽</em> 칸에는 "A" 혹은 "B"가 적혀있다 (총 16개의 칸이 이에 해당한다). <em>가장 안쪽</em>에 위치한 칸에는 "Z"가 적혀있다. 나머지 칸에는 "X" 혹은 "Y"가 적혀있다 (총 8개의 칸이 이에 해당한다).</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/e8f42741-54cb-4ede-9b2c-48dacb3f8360/-/preview/" style="height: 184px; width: 190px;">             <img alt="" src="https://upload.acmicpc.net/c4f84957-9514-4dd2-88a1-fb9c8bd5c7ad/-/preview/" style="height: 301px; width: 300px;"></p>

<p>구체적으로, n x n인 게임 보드의 "가장 바깥쪽"칸 부터 "가장 안쪽"칸은 아래와 같이 정의한다.</p>

<ul>
	<li>가장 처음이나 마지막 행 혹은 열에 위치한 칸이 "가장 바깥쪽" 칸에 해당한다. 아래 4 x 4와 5 x 5 게임보드에서 "1"로 표시된 칸이 가장 바깥 쪽 칸이다.</li>
	<li>가장 바깥쪽 칸을 모두 제외하고 나면 (n-2) x (n-2) 게임 보드가 남게 된다. 위와 마찬가지로 남은 게임 보드에서 가장 처음이나 마지막 행 혹은 열에 위치한 칸이 (두 번째로) 바깥 쪽에 위치한 칸이다. 아래 그림에서 "2"로 표시된 칸이 이에 해당한다.</li>
	<li>이와 같이 계속 게임 보드의 안쪽을 향하여 가장 바깥 쪽 부터 가장 안 쪽 칸 까지 정의 할 수 있다.</li>
</ul>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/fdbb0ba7-6427-45f0-8f0e-41b707bbcfc0/-/preview/" style="height: 261px; width: 500px;"></p>

<p>소용돌이 게임은 아래와 같은 규칙에 따라 한 칸씩 선택하여 총 n<sup>2</sup>개의 칸을 선택하는 게임이다.</p>

<ol>
	<li>먼저, 게임 보드의 모서리에 해당하는 (1, 1), (1, n), (n, 1), 혹은 (n, n)중 한 칸을 선택하여 게임을 시작한다. 이후, 모든 칸이 한 번씩 선택될 때 까지 아래 규칙에 따라 게임을 진행한다.</li>
	<li>현재 선택한 칸에서 상/하/좌/우에 인접한 칸 중 하나를 선택하는 것을 반복하되, 아래와 같은 규칙에 따라 선택한다:
	<ul>
		<li>규칙 1: 이전에 선택된 칸을 다시 선택할 수 없다.</li>
		<li>규칙 2: 규칙 1을 어기지 않으면서 선택할 수 있는 모든 칸 중 게임 보드의 가장 바깥 쪽에 위치한 칸을 선택해야 한다 (그러한 칸이 여럿이라면 그 중 아무 것이나 하나를 선택할 수 있다).</li>
	</ul>
	</li>
</ol>

<p>위 규칙을 지키면서 모든 n<sup>2</sup>개의 칸을 선택하여 얻을 수 있는 (길이가 n<sup>2</sup>인) 문자열을 "소용돌이 문자열" 이라 부른다.</p>

<p>예를 들어 위의 3 x 3 게임 보드의 경우 아래와 같은 방법으로 소용돌이 문자열을 얻을 수 있다:</p>

<ul>
	<li>턴 1: (1, 1)에서 시작하는 경우:
	<ul>
		<li>규칙 1에 따라 다음으로 선택할 수 있는 칸은 (1, 2) 혹은 (2, 1) 뿐이다.</li>
		<li>이 둘 모두 가장 게임 보드 가장 바깥 쪽에 위치하므로, 둘 중 어느 것을 선택하여도 된다. 이 예제에서는 (1, 2)를 선택한다.</li>
	</ul>
	</li>
	<li>턴 2: (1, 2)를 선택한 이후:
	<ul>
		<li>규칙 1에 따라 다음으로 선택할 수 있는 칸은 (1, 3) 혹은 (2, 2) 뿐이다.</li>
		<li>이 두 칸 중 (1, 3)이 (2, 2)보다 더 바깥 쪽에 위치했으므로 규칙 2에 따라 반드시 (1, 3)을 선택해야 한다.</li>
	</ul>
	</li>
	<li>턴 3: (1, 3)을 선택한 이후:
	<ul>
		<li>규칙 1에 따라 반드시 (2, 3)을 선택해야 한다.</li>
	</ul>
	</li>
	<li>턴 4-9: (2, 3)을 선택한 이후 상기한 규칙에 따라 반드시 (3, 3), (3, 2), (3, 1), (2, 1), (2, 2)의 순서로 남은 칸을 선택해야 한다.</li>
	<li>이 방법을 통해 얻어지는 소용돌이 문자열은 "BCDFIHGEA"가 된다.</li>
	<li>만약 턴 2에 (1, 2)가 아닌 (2, 1)을 고를 경우 "BEGHIFDCA"를 얻을 수 있다.</li>
</ul>

<p>같은 게임 보드에서 (3, 3)에서 시작하는 경우 위와 다른 소용돌이 문자열을 얻을 수 있다:</p>

<ul>
	<li>(3, 3) 이후 (3, 2)를 선택하는 경우: "IFDCBEGHA"</li>
	<li>(3, 3) 이후 (2, 3)을 선택하는 경우: "IHGEBCDFA"</li>
</ul>

<p>이 외에도 (1, 3) 혹은 (3, 1)에서 시작할 수 있다.</p>

<p>Albert는 임의의 게임 보드를 이용해서 얻을 수 있는 "최대" 소용돌이 문자열과 "최소" 소용돌이 문자열이 무엇인지 궁금하다.<br>
위의 예제의 경우 최대 소용돌이 문자열은 "IHGEBCDFA" 이며 최소 소용돌이 문자열은 "BCDFIHGEA" 이다.</p>

<p><em>최대 (최소) 소용돌이 문자열은 소용돌이 게임에서 얻을 수 있는 모든 소용돌이 문자열 중 사전순으로 가장 늦게 (먼저) 나오는 문자열이다.</em></p>

### 입력 

 <p>입력 첫 줄에 테스트 케이스의 수 T가 주어진다.</p>

<p>각 테스트 케이스의 첫 줄에 게임 보드의 크기 n이 주어진다.</p>

<p>다음 n줄에 걸쳐 각 줄에 길이 n인 문자열이 주어진다.</p>

### 출력 

 <p>각 테스트 케이스의 정답인 최대 소용돌이 문자열과 최소 소용돌이 문자열을 공백으로 구분하여 각 줄에 출력한다.</p>

