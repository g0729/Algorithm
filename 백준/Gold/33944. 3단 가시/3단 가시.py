import sys

# 빠른 입력을 위한 설정
input = sys.stdin.readline


def solve():
    """맵의 클리어 가능성을 판별하는 함수"""

    # 입력 처리
    try:
        # N은 문제 풀이에 직접 사용되진 않지만, 형식상 입력받습니다.
        n_str = input()
        if not n_str:
            return
        n = int(n_str)

        x = int(input())
        spikes = list(map(int, input().split()))
    except (IOError, ValueError):
        return

    # 가시 위치를 O(1)에 조회하기 위해 set으로 변환
    spike_set = set(spikes)

    # dp[i]의 역할을 할 set.
    # 이전 단계까지 클리어했을 때 가능한 착지 위치들을 담습니다.
    # dp_prev는 dp[i-1], dp_curr는 dp[i]에 해당합니다.
    # 처음에는 위치 0에 착지한 상태로 시작합니다.
    possible_landings = {0}

    # 모든 가시를 순서대로 순회
    for p in spikes:
        # 현재 가시(p)를 처리한 후 가능한 새로운 착지 위치들
        next_possible_landings = set()

        # 이전 단계에서 가능했던 모든 착지 위치(land_pos)를 확인
        for land_pos in possible_landings:
            # Case 1: 이전 점프로 현재 가시(p)를 이미 넘어선 경우
            # 이 착지 위치는 여전히 유효하므로 그대로 다음 상태로 넘겨줍니다.
            if land_pos > p:
                next_possible_landings.add(land_pos)
                continue

            # Case 2: 현재 가시(p)를 넘기 위해 새로 점프해야 하는 경우
            # 3가지 점프(p-3, p-2, p-1에서)를 모두 시도합니다.
            for jump_offset in range(1, 4):
                jump_pos = p - jump_offset

                # 점프 지점까지 걸어갈 수 있는지 확인 (land_pos <= jump_pos)
                if land_pos <= jump_pos:
                    new_land_pos = jump_pos + 4

                    # 새로운 착지 지점에 가시가 없는지 확인
                    if new_land_pos not in spike_set:
                        next_possible_landings.add(new_land_pos)

        # 현재 가시를 처리한 결과(다음 착지 위치 set)로 상태를 업데이트
        possible_landings = next_possible_landings

        # 만약 어떤 방법으로도 현재 가시를 통과할 수 없다면,
        # 가능한 착지 위치가 없으므로 즉시 종료합니다.
        if not possible_landings:
            break

    # 최종 결과 출력
    if possible_landings:
        print("POSSIBLE")
    else:
        print("IMPOSSIBLE")


# 메인 로직
def main():
    try:
        t = int(input())
        for _ in range(t):
            solve()
    except (IOError, ValueError):
        return


if __name__ == "__main__":
    main()
