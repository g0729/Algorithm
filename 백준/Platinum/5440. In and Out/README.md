# [Platinum II] In and Out - 5440 

[문제 링크](https://www.acmicpc.net/problem/5440) 

### 성능 요약

메모리: 8352 KB, 시간: 248 ms

### 분류

최대 유량, 최소 비용 최대 유량, 그래프 이론

### 제출 일자

2025년 5월 15일 00:16:31

### 문제 설명

<p>The young pirate Will Twister has lost his precious medallion, once given to him by his father. It is now in the hands of governor Goose. Since this medallion is very dear to Will, he decides to steal it back. His presence will not go unnoticed (he’s not a ninja), hence to increase his chances of a successful getaway he will use the cover of night. That does mean though that the journey to the governor’s house will also be dangerous, because someone walking through town at night is suspicious.</p>

<p>Throughout the town, sentries<sup>3</sup> are placed at strategically chosen junctions. Will is not a very good fighter, hence he will rely on the element of surprise and his speed to make it past them. However, if he were to pass the same sentry on both the journey to and from the governor’s house, the element of surprise would be gone the second time and there is a big risk that he gets caught. Therefore, he does not want to pass the same sentry twice.</p>

<p>Will’s journey will start and end at the harbor, where he will arrive and leave by boat. He has a map of the town, complete with the locations of the sentries. Given that he’ll have to do a lot of running, he wishes to find the shortest route to and from the governor’s house that doesn’t take him twice past any sentry. Can you help him determine this route?</p>

<p><sup>3</sup>A sentry is a stationary guard</p>

### 입력 

 <p>The first line of the input contains a single number: the number of test cases to follow. Each test case has the following format:</p>

<ul>
	<li>One line with two integers N and R, satisfying 2 ≤ N ≤ 1000 and 1 ≤ R ≤ 10, 000: the number of junctions and the number of roads, respectively.</li>
	<li>R lines, each with three integers a, b and l, satisfying 1 ≤ a, b ≤ N and 1 ≤ l ≤ 1000, indicating that there is a bidirectional road between junctions a and b of length l.</li>
	<li>One line with one integer S, satisfying 0 ≤ S ≤ min(N − 2, 100): the number of sentries.</li>
	<li>One line with S distinct integers, satisfying 2 ≤ s<sub>i</sub> < N, indicating that there is a sentry at junction s<sub>i</sub>.</li>
</ul>

<p>The junctions are numbered 1 through N. Will’s boat is at junction 1 and the governor’s house is at junction N. A path from the boat to the governor’s house is guaranteed to exist.</p>

### 출력 

 <p>For every test case in the input, the output should contain one integer on a single line: the minimum total distance Will has to cover. If there is no route that passes each sentry at most once, the output should be “No safe route” (without the quotation marks) on a single line.</p>

