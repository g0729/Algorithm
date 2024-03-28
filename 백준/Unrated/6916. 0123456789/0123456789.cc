#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

#define DIGIT_ZERO " * * *\n"  \
                   "*     *\n" \
                   "*     *\n" \
                   "*     *\n" \
                   "\n"        \
                   "*     *\n" \
                   "*     *\n" \
                   "*     *\n" \
                   " * * *\n"

#define DIGIT_ONE "\n"        \
                  "      *\n" \
                  "      *\n" \
                  "      *\n" \
                  "\n"        \
                  "      *\n" \
                  "      *\n" \
                  "      *\n"

#define DIGIT_TWO " * * *\n"  \
                  "      *\n" \
                  "      *\n" \
                  "      *\n" \
                  " * * *\n"  \
                  "*\n"       \
                  "*\n"       \
                  "*\n"       \
                  " * * *\n"

#define DIGIT_THREE " * * *\n"  \
                    "      *\n" \
                    "      *\n" \
                    "      *\n" \
                    " * * *\n"  \
                    "      *\n" \
                    "      *\n" \
                    "      *\n" \
                    " * * *\n"

#define DIGIT_FOUR "\n"        \
                   "*     *\n" \
                   "*     *\n" \
                   "*     *\n" \
                   " * * *\n"  \
                   "      *\n" \
                   "      *\n" \
                   "      *\n"

#define DIGIT_FIVE " * * *\n"  \
                   "*\n"       \
                   "*\n"       \
                   "*\n"       \
                   " * * *\n"  \
                   "      *\n" \
                   "      *\n" \
                   "      *\n" \
                   " * * *\n"

#define DIGIT_SIX " * * *\n"  \
                  "*\n"       \
                  "*\n"       \
                  "*\n"       \
                  " * * *\n"  \
                  "*     *\n" \
                  "*     *\n" \
                  "*     *\n" \
                  " * * *\n"

#define DIGIT_SEVEN " * * *\n"  \
                    "      *\n" \
                    "      *\n" \
                    "      *\n" \
                    "\n"        \
                    "      *\n" \
                    "      *\n" \
                    "      *\n"

#define DIGIT_EIGHT " * * *\n"  \
                    "*     *\n" \
                    "*     *\n" \
                    "*     *\n" \
                    " * * *\n"  \
                    "*     *\n" \
                    "*     *\n" \
                    "*     *\n" \
                    " * * *\n"

#define DIGIT_NINE " * * *\n"  \
                   "*     *\n" \
                   "*     *\n" \
                   "*     *\n" \
                   " * * *\n"  \
                   "      *\n" \
                   "      *\n" \
                   "      *\n" \
                   " * * *\n"

const char *DIGITS[] = {
    DIGIT_ZERO,
    DIGIT_ONE,
    DIGIT_TWO,
    DIGIT_THREE,
    DIGIT_FOUR,
    DIGIT_FIVE,
    DIGIT_SIX,
    DIGIT_SEVEN,
    DIGIT_EIGHT,
    DIGIT_NINE};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cout << DIGITS[n];
    return 0;
}