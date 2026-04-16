// 102B
#include <cstdio>
int main() {
    char digits[100001];
    scanf("%s", digits);

    int times(0);
    if (digits[1] != 0)
    {
        int digitsum(0);
        char* p = digits;
        while (*p != 0)
        {
            digitsum += (*p - '0');
            ++p;
        }
        ++times;

        while (digitsum > 9)
        {
            int m(digitsum);
            digitsum = 0;
            while (m != 0)
            {
                digitsum += m % 10;
                m /= 10;
            }
            ++times;
        }
    }
    printf("%d\n", times);
    return 0;
}
// 104A
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n <= 10 || n > 21)
    {
        cout << 0 << endl;
    }
    else if (n == 20)
    {
        cout << 15 << endl;
    }
    else
    {
        cout << 4 << endl;
    }
    return 0;
}
// 106A
#include <cstdio>
using namespace std;

int rank(char c)
{
    const char* order = "6789TJQKA";
    char* find = const_cast<char*>(order);
    while (*find != c)
    {
        ++find;
    }
    return find - order;
}

int main()
{
    char suit[2], card1[3], card2[3];
    scanf("%s%s%s", suit, card1, card2);

    bool beat = (card1[1] == suit[0] && card2[1] != suit[0])
        || (card1[1] == card2[1] && rank(card1[0]) > rank(card2[0]));
    printf(beat ? "YES\n" : "NO\n");
    return 0;
}
// 106B
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n, speed[101], ram[101], hdd[101], cost[101];
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d%d", &speed[i], &ram[i], &hdd[i], &cost[i]);
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (speed[i] < speed[j] && ram[i] < ram[j] && hdd[i] < hdd[j])
            {
                cost[i] = 1001; // 100 <= cost <= 1000
            }
        }
    }

    printf("%u\n", min_element(cost + 1, cost + 1 + n) - cost);

    return 0;
}
// 108A
#include <cstdio>

int main()
{
    int hh, mm;
    scanf("%d:%d", &hh, &mm);
    do 
    {
        ++mm;
        if (mm == 60)
        {
            ++hh;
            mm = 0;
        }
        if (hh == 24)
        {
            hh = 0;
        }
    } while (hh % 10 * 10 + hh / 10 != mm);
    printf("%02d:%02d\n", hh, mm);
    return 0;
}
// 110A
#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    int count = 0;
    while (n != 0)
    {
        if (n % 10 == 4 || n % 10 == 7)
        {
            count += 1;
        }
        n /= 10;
    }
    if (count == 4 || count == 7)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
// 110B
n = int(input())
s = "abcd" * (n // 4) + "abcd"[0 : n % 4]
print(s)
// 112A
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    cout << strcmp(s1.c_str(), s2.c_str()) << endl;
    return 0;
}
// 114A
#include <iostream>

using namespace std;

int main()
{
    int k, l, importance(-1);
    cin >> k >> l;
    while (l % k == 0)
    {
        l /= k;
        importance += 1;
    }
    if (importance >= 0 && l == 1)
    {
        cout << "YES" << endl << importance << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
// 116A
#include <cstdio>

int main()
{
    int n, a, b, c(0), m(0);
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d", &a, &b);
        c -= a;
        c += b;
        if (c > m)
        {
            m = c;
        }
    }

    printf("%d\n", m);
    return 0;
}
