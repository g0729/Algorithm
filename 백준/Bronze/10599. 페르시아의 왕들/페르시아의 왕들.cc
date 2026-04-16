#include <iostream>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;

    while (true) {
        cin >> a >> b >> c >> d;

        // 종료 조건: 모든 입력이 0인 경우
        if (a == 0 && b == 0 && c == 0 && d == 0) {
            break;
        }

        // 최소 나이: (가장 빠른 사망일) - (가장 늦은 출생일)
        // 최대 나이: (가장 늦은 사망일) - (가장 빠른 출생일)
        int min_age = c - b;
        int max_age = d - a;

        cout << min_age << " " << max_age << "\n";
    }

    return 0;
}