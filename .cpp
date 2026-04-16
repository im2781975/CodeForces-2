//4264838   Aug 11, 2013 12:28:28 PM	fuwutu	 17A - Noldbach problem	 GNU C++0x	Accepted	 30 ms	 0 KB
#include <cstdio>

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    int prime[1000] = {3, 5}, count(2);
    for (int number = 7; number <= n && k != 0; number += 2)
    {
        int i = 0;
        while (i < count && number % prime[i] != 0)
        {
            ++i;
        }
        if (i == count)
        {
            for (int j = 1; j < count; ++j)
            {
                if (prime[j] + prime[j-1] + 1 == number)
                {
                    k -= 1;
                    break;
                }
            }
            prime[count++] = number;
        }
    }
    printf(k == 0 ? "YES\n" : "NO\n");
    return 0;
}
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
//4057937   Jul 13, 2013 9:13:14 AM	fuwutu	 116B - Little Pigs and Wolves	 GNU C++0x	Accepted	 15 ms	 0 KB
#include <cstdio>
// 116B
int main()
{
    int n, m;
    char c[12][13];
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", &c[i][1]);
    }
    int eaten(0);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (c[i][j] == 'W')
            {
                if (c[i-1][j] == 'P' || c[i+1][j] == 'P' || c[i][j-1] == 'P' || c[i][j+1] == 'P')
                {
                    eaten += 1;
                }
            }
        }
    }
    printf("%d\n", eaten);
    return 0;
}
//4005085     Jul 3, 2013 3:50:19 AM	fuwutu	 118A - String Task	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <string>
// 118A
using namespace std;

int main()
{
    string s, r;
    cin >> s;
    for (char c : s)
    {
        if (c >= 'A' && c <= 'Z')
        {
            c += 'a' - 'A';
        }
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'y')
        {
            r.append(1, '.');
            r.append(1, c);
        }
    }
    cout << r << endl;
    return 0;
}
//4027858   Jul 5, 2013 8:37:21 PM	fuwutu	 118B - Present from Lena	 GNU C++0x	Accepted	 15 ms	 0 KB
#include <iostream>
#include <cmath>
// 118B
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int row = -n; row <= n; ++row)
    {
        int top = n - abs(row);
        for (int i = 0; i < abs(row); ++i)
        {
            cout << "  ";
        }
        for (int i = 0; i < top; ++i)
        {
            cout << i << " ";
        }
        for (int i = top; i > 0; --i)
        {
            cout << i << " ";
        }
        cout << 0 << endl;
    }
    return 0;
}
// 119A
//4006915   Jul 3, 2013 6:07:36 PM	fuwutu	 119A - Epic Game	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int GCD(int m, int n)
{
    int r;
    while ((r = m % n) != 0)
    {
        m = n;
        n = r;
    }
    return n;
}

int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    while (true)
    {
        n -= GCD(a, n);
        if (n == 0)
        {
            cout << 0 << endl;
            break;
        }
        n -= GCD(b, n);
        if (n == 0)
        {
            cout << 1 << endl;
            break;
        }
    }
    return 0;
}
// 122A
//4027427   Jul 5, 2013 6:40:47 PM	fuwutu	 122A - Lucky Division	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

bool lucky(int n)
{
    while (n != 0)
    {
        if (n % 10 != 4 && n % 10 != 7)
        {
            return false;
        }
        n /= 10;
    }
    return true;
}

bool almost_lucky(int n)
{
    if (lucky(n))
    {
        return true;
    }

    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0 && (lucky(i) || lucky(n / i)))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int n;
    cin >> n;
    if (almost_lucky(n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
// 122B
#4076744   Jul 15, 2013 8:50:51 PM	fuwutu	 122B - Lucky Substring	 Python 3	Accepted	62 ms	100 KB
s = input()
count4 = count7 = 0
for c in s:
    if c == '4':
        count4 += 1
    elif c == '7':
        count7 += 1
if count4 == 0 and count7 == 0:
    print(-1)
elif count4 >= count7:
    print(4)
else:
    print(7)
// 124A
//4032912   Jul 7, 2013 5:46:56 AM	fuwutu	 124A - The number of positions	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    cout << min(n - a, b + 1) << endl;
    return 0;
}
// 127A
//4034181   Jul 7, 2013 2:00:39 PM	fuwutu	 127A - Wasted Time	 GNU C++0x	Accepted	15 ms	100 KB
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    double x, y, x0, y0, total(0.0);
    cin >> x0 >> y0;
    while (--n)
    {
        cin >> x >> y;
        total += sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0));
        x0 = x;
        y0 = y;
    }
    cout << fixed << setprecision(6) << total * k / 50 << endl;
    return 0;
}
// 127B
//4035363   Jul 7, 2013 7:45:38 PM	fuwutu	 127B - Canvas Frames	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, a, count[101] = {0};
    cin >> n;
    while (n--)
    {
        cin >> a;
        count[a] += 1;
    }
    int total = 0;
    for (int i = 1; i <= 100; ++i)
    {
        total += count[i] / 2;
    }
    cout << total / 2 << endl;
    return 0;
}
// 129A
//4033714   Jul 7, 2013 12:04:07 PM	fuwutu	 129A - Cookies	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, a, odd(0), even(0);
    cin >> n;
    while (n--)
    {
        cin >> a;
        if (a % 2 == 0)
        {
            even += 1;
        }
        else
        {
            odd += 1;
        }
    }

    cout << (odd % 2 == 1 ? odd : even) << endl;
    return 0;
}
// 131A
//4006936   Jul 3, 2013 6:14:19 PM	fuwutu	 131A - cAPS lOCK	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    bool change = true;
    for (size_t i = 1; i < s.length(); ++i)
    {
        if (s[i] >= 'a')
        {
            change = false;
            break;
        }
    }

    if (change)
    {
        for (size_t i = 0; i < s.length(); ++i)
        {
            if (s[i] >= 'a')
            {
                s[i] -= ('a' - 'A');
            }
            else
            {
                s[i] += ('a' - 'A');
            }
        }
    }

    cout << s << endl;
    return 0;
}
// 131B
//4034968   Jul 7, 2013 5:38:17 PM	fuwutu	 131B - Opposites Attract	 GNU C++0x	Accepted	31 ms	0 KB
#include <cstdio>

using namespace std;

int main()
{
    int n, t, count[21] = {0};
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &t);
        count[t + 10] += 1;
    }
    long long result = static_cast<long long>(count[10]) * static_cast<long long>(count[10] - 1) /2;
    for (int i = 0; i < 10; ++i)
    {
        result += static_cast<long long>(count[i]) * static_cast<long long>(count[20 - i]);
    }
    printf("%I64d\n", result);
    return 0;
}
// 131C
//4212008	 Aug 1, 2013 9:09:20 AM	fuwutu	 131C - The World is a Theatre	 GNU C++0x	Accepted	 30 ms	 0 KB
#include <iostream>

using namespace std;

long long C(int n, int m)
{
    long long result(1);
    for (int i = 0; i < m; ++i)
    {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

int main()
{
    int n, m, t;
    cin >> n >> m >> t;

    long long ways(0);
    for (int i = 4; i <= t - 1; ++i)
    {
        ways += C(n, i) * C(m, t - i);
    }
    cout << ways << endl;
}
// 133A
//4007157   Jul 3, 2013 7:19:37 PM	fuwutu	 133A - HQ9+	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    if (s.find_first_of("HQ9") != string::npos)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
// 133B
//4136816   Jul 22, 2013 9:05:14 PM	fuwutu	 133B - Unary	 GNU C++0x	Accepted	15 ms	0 KB
#include <cstdio>

int main()
{
    char p[101];
    scanf("%s", p);
    int size(0);
    for (size_t i = 0; p[i] != 0; ++i)
    {
        size *= 16;
        switch (p[i])
        {
        case '>':
            size += 8;
            break;

        case '<':
            size += 9;
            break;

        case '+':
            size += 10;
            break;

        case '-':
            size += 11;
            break;

        case '.':
            size += 12;
            break;

        case ',':
            size += 13;
            break;

        case '[':
            size += 14;
            break;

        case ']':
            size += 15;
            break;

        default:
            break;
        }

        size %= 1000003;
    }
    printf("%d\n", size);
    return 0;
}
// 136A
//4021420   Jul 4, 2013 7:30:15 PM	fuwutu	 136A - Presents	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, p;
    cin >> n;
    vector<int> f(n+1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> p;
        f[p] = i;
    }
    cout << f[1];
    for (int i = 2; i <= n; ++i)
    {
        cout << " " << f[i];
    }
    cout << endl;
    return 0;
}
// 136B
//4172198   Jul 27, 2013 5:09:00 AM	fuwutu	 136B - Ternary Logic	 GNU C++0x	Accepted	30 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int a, c, ad[20] = {0}, an(0), cd[20] = {0}, cn(0);
    cin >> a >> c;

    while (a != 0)
    {
        ad[an++] = a % 3;
        a /= 3;
    }

    while (c != 0)
    {
        cd[cn++] = c % 3;
        c /= 3;
    }

    int tor(0);
    for (int i = max(an, cn) - 1; i >= 0; --i)
    {
        tor = tor * 3 + (cd[i] + 3 - ad[i]) % 3;
    }
    cout << tor << endl;
    return 0;
}
// 137A
//4035232   Jul 7, 2013 7:00:58 PM	fuwutu	 137A - Postcards and photos	 GNU C++0x	Accepted	 15 ms	 0 KB
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int result(0), count(1);
    for (size_t i = 1; i < s.length(); ++i)
    {
        if (s[i] == s[i-1])
        {
            count += 1;
        }
        else
        {
            result += (count + 4) / 5;
            count = 1;
        }
    }
    result += (count + 4) / 5;
    cout << result << endl;
    return 0;
}
// 137B
//4055758   Jul 12, 2013 8:25:21 PM	fuwutu	 137B - Permutation	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, a, appear[5001] = {0};
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        if (a <= n)
        {
            appear[a] = 1;
        }
    }
    cout << count(appear + 1, appear + n + 1, 0) << endl;
    return 0;
}
