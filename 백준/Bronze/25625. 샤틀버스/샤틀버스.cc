#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> x >> y;

    if (y < x) {
        // Case 1: 서울대입구역 -> 제2공학관 방향인 경우
        // 제2공학관 도착(y) + 다시 서울대입구역으로 복귀(x)
        cout << y + x << endl;
    } else {
        // Case 2: 제2공학관 -> 서울대입구역 방향인 경우
        // 서울대입구역에 도착하는 시간은 (전체 왕복 중 남은 시간 y)에서 (제2공학관->서울대입구역 소요시간 x)를 뺀 값
        cout << y - x << endl;
    }

    return 0;
}