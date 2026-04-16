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
// 139A
//4034061   Jul 7, 2013 1:27:10 PM	fuwutu	 139A - Petr and Book	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, y[8] = {0};
    cin >> n;
    for (int d = 1; d <= 7; ++d)
    {
        cin >> y[d];
        y[d] += y[d-1];
    }
    n = (n - 1) % y[7] + 1;
    for (int d = 1; d <= 7; ++d)
    {
        if (y[d] >= n)
        {
            cout << d << endl;
            break;
        }
    }
    return 0;
}
// 140A
//4236895   Aug 6, 2013 4:35:30 PM	fuwutu	 140A - New Year Table	 GNU C++0x	Accepted	30 ms	0 KB
#include <cstdio>
#include <cmath>

int main()
{
    int n;
    double R, r;
    scanf("%d%lf%lf", &n, &R, &r);
    if (   n == 1 && r <= R
        || n == 2 && r * 2 <= R
        || asin(r / (R - r)) * n <= 3.1415927)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
// 141A
//4027532   Jul 5, 2013 7:07:08 PM	fuwutu	 141A - Amusing Joke	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int dict[128] = {0};
    string s;
    cin >> s;
    for (size_t i = 0; i < s.length(); ++i)
    {
        dict[s[i]] += 1;
    }
    cin >> s;
    for (size_t i = 0; i < s.length(); ++i)
    {
        dict[s[i]] += 1;
    }
    cin >> s;
    for (size_t i = 0; i < s.length(); ++i)
    {
        dict[s[i]] -= 1;
    }

    if (count(dict, dict + sizeof(dict) / sizeof(dict[0]), 0) == sizeof(dict) / sizeof(*dict))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
// 143A
//4236777   Aug 6, 2013 3:58:53 PM	fuwutu	 143A - Help Vasilisa the Wise 2	 GNU C++0x	Accepted	30 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int r1, r2, c1, c2, d1, d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    int a11 = (r1 + c1 - d2) / 2;
    int a12 = r1 - a11;
    int a21 = c1 - a11;
    int a22 = d1 - a11;
    if (a11 != a12 && a11 != a21 && a11 != a22 && a12 != a21 && a12 != a22 && a21 != a22
        && a11 >= 1 && a11 <= 9
        && a12 >= 1 && a12 <= 9
        && a21 >= 1 && a21 <= 9
        && a22 >= 1 && a22 <= 9
        && a21 + a22 == r2
        && a12 + a22 == c2
        && a12 + a21 == d2)
    {
        cout << a11 << " " << a12 << endl;
        cout << a21 << " " << a22 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}
// 144A
//4008690   Jul 4, 2013 3:55:22 AM	fuwutu	 144A - Arrival of the General	 GNU C++0x	Accepted	 15 ms	 0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, a;
    cin >> n >> a;
    int mina(a), maxa(a), mini(0), maxi(0);
    for (int i = 1; i < n; ++i)
    {
        cin >> a;
        if (a > maxa)
        {
            maxa = a;
            maxi = i;
        }
        if (a <= mina)
        {
            mina = a;
            mini = i;
        }
    }
    cout << maxi + (n - 1 - mini) - (mini < maxi ? 1 : 0) << endl;
    return 0;
}
// 146A
//4033946   Jul 7, 2013 12:54:50 PM	fuwutu	 146A - Lucky Ticket	 GNU C++0x	Accepted	 15 ms	 0 KB
#include <iostream>
#include <string>

using namespace std;

int main()
{
    size_t n;
    string s;
    cin >> n >> s;

    bool lucky = true;
    int diff(0);
    n /= 2;
    for (size_t i = 0; i < n; ++i)
    {
        if ((s[i] != '4' && s[i] != '7') || (s[n+i] != '4' && s[n+i] !='7'))
        {
            lucky = false;
            break;
        }
        diff += (s[i] - s[n+i]);
    }
    lucky = lucky && (diff == 0);
    cout << (lucky ? "YES" : "NO") << endl;
    return 0;
}
// 148A
//4007107   Jul 3, 2013 7:04:01 PM	fuwutu	 148A - Insomnia cure	 GNU C++0x	Accepted	 15 ms	 0 KB
#include <iostream>

using namespace std;

int LCM(int m, int n)
{
    int mm(m), nn(n), r;
    while ((r = m % n) != 0)
    {
        m = n;
        n = r;
    }
    return mm / n * nn;
}

int main()
{
    int k, l, m, n, d, count(0);
    cin >> k >> l >> m >> n >> d;

    int lcm = LCM(LCM(k, l), LCM(m, n));
    if (d > lcm)
    {
        int r = 0;
        for (int i = 1; i <= d % lcm; ++i)
        {
            if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0)
            {
                r += 1;
            }
        }

        int c = r;
        for (int i = d % lcm + 1; i <= lcm; ++i)
        {
            if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0)
            {
                c += 1;
            }
        }

        count = c * (d / lcm) + r;
    }
    else
    {
        for (int i = 1; i <= d; ++i)
        {
            if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0)
            {
                count += 1;
            }
        }
    }
    cout << count << endl;
    return 0;
}
// 149A
//4032903   Jul 7, 2013 5:41:16 AM	fuwutu	 149A - Business trip	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int k, a[12], total(0);
    cin >> k;
    for (size_t i = 0; i < 12; ++i)
    {
        cin >> a[i];
        total += a[i];
    }

    if (total < k)
    {
        cout << -1 << endl;
    }
    else
    {
        sort(a, a + sizeof(a) / sizeof(a[0]), greater<int>());
        int sum = 0;
        int month = 0;
        while (sum < k)
        {
            sum += a[month];
            month += 1;
        }
        cout << month << endl;
    }

    return 0;
}
// 151A
//4033228   Jul 7, 2013 9:03:08 AM	fuwutu	 151A - Soft Drinking	 GNU C++0x	Accepted	0 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    cout << min(min(k * l / nl, c * d), p / np) / n << endl;
    return 0;
}
// 152A
//4034103   Jul 7, 2013 1:39:50 PM	fuwutu	 152A - Marks	 GNU C++0x	Accepted	15 ms	100 KB
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    size_t n, m;
    cin >> n >> m;
    vector<string> marks(n);
    for (size_t i = 0; i < n; ++i)
    {
        cin >> marks[i];
    }
    vector<bool> successful(n, false);
    for (size_t subject = 0; subject < m; ++subject)
    {
        char best = '0';
        for (size_t i = 0; i < n; ++i)
        {
            if (marks[i][subject] > best)
            {
                best = marks[i][subject];
            }
        }
        for (size_t i = 0; i < n; ++i)
        {
            if (marks[i][subject] == best)
            {
                successful[i] = true;
            }
        }
    }
    cout << count(successful.begin(), successful.end(), true);
    return 0;
}
// 155A
//4027892   Jul 5, 2013 8:45:43 PM	fuwutu	 155A - I_love_%username%	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, points;
    cin >> n >> points;
    int min(points), max(points), amazing(0);
    while (--n)
    {
        cin >> points;
        if (points < min)
        {
            min = points;
            ++amazing;
        }
        if (points > max)
        {
            max = points;
            ++amazing;
        }
    }
    cout << amazing << endl;
    return 0;
}
// 155B
//4136855   Jul 22, 2013 9:19:15 PM	fuwutu	 155B - Combination	 GNU C++0x	Accepted	15 ms	0 KB
#include <cstdio>
#include <algorithm>

using namespace std;

struct card
{
    int a;
    int b;
};

bool cmp(const card& left, const card& right)
{
    return (left.b > right.b)
        || (left.b == right.b && left.a > right.a);
}

int main()
{
    int n;
    scanf("%d", &n);

    card c[1000];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &c[i].a, &c[i].b);
    }

    sort(c, c + n, cmp);
    int points(c[0].a), cards(c[0].b);
    for (int i = 1; i < n && i <= cards; ++i)
    {
        points += c[i].a;
        cards += c[i].b;
    }

    printf("%d\n", points);
    return 0;
}
// 157A
//4042683   Jul 9, 2013 5:48:49 PM	fuwutu	 157A - Game Outcome	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, m[30][30], r[30] = {0}, c[30] = {0}, win(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> m[i][j];
            r[i] += m[i][j];
        }
    }
    for (int j = 0; j < n; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            c[j] += m[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (r[i] < c[j])
            {
                win += 1;
            }
        }
    }
    cout << win << endl;
    return 0;
}
// 157B
//4058096   Jul 13, 2013 9:59:34 AM	fuwutu	 157B - Trace	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, a[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + n, greater<int>());
    int rr(0);
    for (int i = 0; i < n; ++i)
    {
        rr += a[i] * a[i] * (1 - i % 2 * 2);
    }
    double pi = asin(1) * 2;
    cout << fixed << setprecision(10) << (pi * rr) << endl;
    return 0;
}
// 158A
//4004018   Jul 2, 2013 8:42:28 PM	fuwutu	 158A - Next Round	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int a;
    for (int i = 0; i < k; ++i)
    {
        cin >> a;
        if (a == 0)
        {
            cout << i << endl;
            return 0;
        }
    }

    int b;
    for (int i = k; i < n; ++i)
    {
        cin >> b;
        if (b != a)
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << n << endl;
    return 0;
}
// 158B
//4005097     Jul 3, 2013 3:58:36 AM	fuwutu	 158B - Taxi	 GNU C++0x	Accepted	46 ms	0 KB
#include <stdio.h>

using namespace std;

int main()
{
    int n, s, count[5]= {0};
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &s);
        count[s] += 1;
    }
    int total = count[4] + count[3] + count[2] / 2;
    count[1] -= count[3];
    if (count[2] % 2 == 1)
    {
        total += 1;
        count[1] -= 2;
    }
    if (count[1] > 0)
    {
        total += (count[1] + 3) / 4;
    }
    printf("%d\n", total);
    return 0;
}
// 158C
//4027816   Jul 5, 2013 8:24:34 PM	fuwutu	 158C - Cd and pwd commands	 GNU C++0x	Accepted	15 ms	100 KB
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    string command, parameter;
    vector<string> path;
    cin >> n;
    while (n--)
    {
        cin >> command;
        if (command.compare("pwd") == 0)
        {
            cout << "/";
            for (size_t i = 0; i < path.size(); ++i)
            {
                cout << path[i] << "/";
            }
            cout << endl;
        }
        else
        {
            cin >> parameter;
            size_t pos = 0;
            if (parameter[0] == '/')
            {
                path.clear();
                pos = 1;
            }
            while (true)
            {
                size_t next_pos = parameter.find('/', pos);
                if (next_pos != string::npos)
                {
                    string dir = parameter.substr(pos, next_pos - pos);
                    if (dir.compare("..") != 0)
                    {
                        path.push_back(dir);
                    }
                    else
                    {
                        if (!path.empty())
                        {
                            path.pop_back();
                        }
                    }
                    pos = next_pos + 1;
                }
                else
                {
                    string dir = parameter.substr(pos, string::npos);
                    if (dir.compare("..") != 0)
                    {
                        path.push_back(dir);
                    }
                    else
                    {
                        if (!path.empty())
                        {
                            path.pop_back();
                        }
                    }
                    break;
                }
            }
        }
    }
    return 0;
}
// 158D
//4030436   Jul 6, 2013 2:16:09 PM	fuwutu	 158D - Ice Sculptures	 GNU C++0x	Accepted	15 ms	100 KB
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, t[20000], sum(0), partsum[20000];
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &t[i]);
        sum += t[i];
    }

    int maximum(sum);
    for (int d = 2; d <= n / 3; ++d)
    {
        if (n % d == 0)
        {
            fill(partsum, partsum + d, 0);
            int x = n / d;
            int k = 0;
            for (int i = 0; i < x; ++i)
            {
                for (int j = 0; j < d; ++j)
                {
                    partsum[j] += t[k++];
                }
            }
            for (int j = 0; j < d; ++j)
            {
                if (partsum[j] > maximum)
                {
                    maximum = partsum[j];
                }
            }
        }
    }
    printf("%d\n", maximum);
    return 0;
}
// 159B
//4192310   Jul 28, 2013 5:58:29 AM	fuwutu	 159B - Matchmaker	 GNU C++0x	Accepted	342 ms	1500 KB
#include <cstdio>
#include <algorithm>

using namespace std;

struct marker
{
    int ax;
    int by;
};

bool cmp(const marker& left, const marker& right)
{
    return (left.by < right.by)
        || (left.by == right.by && left.ax < right.ax);
}

int main()
{
    marker markers[100000], caps[100000];
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &markers[i].ax, &markers[i].by);
    }

    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &caps[i].ax, &caps[i].by);
    }

    sort(markers, markers + n, cmp);
    sort(caps, caps + m, cmp);

    int u(0);
    for (int i = 0, j = 0; i < n && j < m; )
    {
        if (markers[i].by < caps[j].by)
        {
            ++i;
        }
        else if (markers[i].by > caps[j].by)
        {
            ++j;
        }
        else
        {
            ++u;
            ++i;
            ++j;
        }
    }

    int v(0);
    for (int i = 0, j = 0; i < n && j < m; )
    {
        if (markers[i].by < caps[j].by)
        {
            ++i;
        }
        else if (markers[i].by > caps[j].by)
        {
            ++j;
        }
        else
        {
            if (markers[i].ax < caps[j].ax)
            {
                ++i;
            }
            else if (markers[i].ax > caps[j].ax)
            {
                ++j;
            }
            else
            {
                ++v;
                ++i;
                ++j;
            }
        }
    }

    printf("%d %d\n", u, v);
    return 0;
}
// 160A
//4007272   Jul 3, 2013 7:54:19 PM	fuwutu	 160A - Twins	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int value = accumulate(a.begin(), a.end(), 0) / 2;

    sort(a.begin(), a.end(), greater<int>());
    int mine = 0;
    size_t i = 0;
    while (mine <= value)
    {
        mine += a[i++];
    }

    cout << i << endl;
    return 0;
}
// 160B
//4033517   Jul 7, 2013 11:10:00 AM	fuwutu	 160B - Unlucky Ticket	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    size_t n;
    string s, l, r;
    cin >> n >> s;
    l = s.substr(0, n);
    r = s.substr(n, n);
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    bool strictly_less(true), strictly_more(true);
    for (size_t i = 0; i < n; ++i)
    {
        if (l[i] >= r[i])
        {
            strictly_less = false;
            break;
        }
    }
    for (size_t i = 0; i < n; ++i)
    {
        if (l[i] <= r[i])
        {
            strictly_more = false;
            break;
        }
    }
    cout << ((strictly_less || strictly_more) ? "YES" : "NO") << endl;
    return 0;
}
// 161A
//4172027   Jul 27, 2013 4:39:57 AM 	fuwutu 	161A - Dress'em in Vests! 	GNU C++0x 	Accepted 	342 ms 	800 KB
#include <cstdio>

using namespace std;

int main()
{
    int n, m, x, y, a[100000], b[100000];
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int j = 0; j < m; ++j)
    {
        scanf("%d", &b[j]);
    }

    int count(0);
    for (int i = 0, j = 0; i < n && j < m; )
    {
        if (b[j] < a[i] - x)
        {
            ++j;
        }
        else if (b[j] > a[i] + y)
        {
            ++i;
        }
        else
        {
            a[count] = ++i;
            b[count] = ++j;
            ++count;
        }
    }

    printf("%d\n", count);
    for (int k = 0; k < count; ++k)
    {
        printf("%d %d\n", a[k], b[k]);
    }
    return 0;
}
// 165A
//4033090   Jul 7, 2013 7:51:42 AM	fuwutu	 165A - Supercentral Point	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, x[200], y[200], supercentral(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; ++i)
    {
        int bit = 15;
        for (int j = 0; j < n && bit != 0; ++j)
        {
            if (x[j] == x[i])
            {
                if (y[j] < y[i])
                {
                    bit &= (15 - 1);
                }
                if (y[j] > y[i])
                {
                    bit &= (15 - 2);
                }
            }
            if (y[j] == y[i])
            {
                if (x[j] < x[i])
                {
                    bit &= (15 - 4);
                }
                if (x[j] > x[i])
                {
                    bit &= (15 - 8);
                }
            }
        }
        if (bit == 0)
        {
            supercentral += 1;
        }
    }
    cout << supercentral << endl;
    return 0;
}
// 165B
#4314087  Aug 20, 2013 4:53:51 AM    fuwutu   165B - Burning Midnight Oil     Python 3   Accepted    124 ms  0 KB
l = input().split(' ')
n, k = int(l[0]), int(l[1])
left, right = 1, n
while left != right:
    x = middle = (left + right) // 2
    sum = 0
    while x != 0:
        sum += x
        x //= k
    if sum >= n:
        right = middle
    else:
        left = middle + 1
print(left)
// 166A
//4042740   Jul 9, 2013 6:04:04 PM	fuwutu	 166A - Rank List	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <algorithm>

using namespace std;

struct team
{
    int problems;
    int penaltytime;
};

bool cmp(const team& left, const team& right)
{
    return left.problems > right.problems
        || (left.problems == right.problems && left.penaltytime < right.penaltytime);
}

int main()
{
    int n, k;
    team t[50];
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> t[i].problems >> t[i].penaltytime;
    }
    sort(t, t + n, cmp);
    k -= 1;
    int l(k), r(k);
    while (l > 0 && t[l-1].problems == t[k].problems && t[l-1].penaltytime == t[k].penaltytime)
    {
        l -= 1;
    }
    while (r + 1 < n && t[r+1].problems == t[k].problems && t[r+1].penaltytime == t[k].penaltytime)
    {
        r += 1;
    }
    cout << r - l + 1 << endl;
    return 0;
}
// 166E
//4324919	 Aug 22, 2013 8:27:14 PM	fuwutu	 166E - Tetrahedron	 GNU C++0x	Accepted	62 ms	0 KB
#include <cstdio>
#include <memory.h>

int main()
{
    int n;
    scanf("%d", &n);

    long long a[4][4] = {{0, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 0}};
    long long b[4][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    while (n != 0)
    {
        if (n % 2 == 1)
        {
            long long c[4][4] = {0};
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    for (int k = 0; k < 4; ++k)
                    {
                        c[i][j] += a[i][k] * b[k][j];
                    }
                    c[i][j] %= 1000000007LL;
                }
            }
            memcpy(b, c, sizeof(b));
        }

        long long c[4][4] = {0};
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                for (int k = 0; k < 4; ++k)
                {
                    c[i][j] += a[i][k] * a[k][j];
                }
                c[i][j] %= 1000000007LL;
            }
        }
        memcpy(a, c, sizeof(a));

        n /= 2;
    }

    printf("%I64d\n", b[0][0]);
    return 0;
}
// 168A
//4033567   Jul 7, 2013 11:26:18 AM	fuwutu	 168A - Wizards and Demonstration	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    int clones = (n * y + 99) / 100 - x;
    if (clones < 0)
    {
        clones = 0;
    }
    cout << clones << endl;
    return 0;
}
// 172A
//4059111   Jul 13, 2013 2:09:39 PM 	fuwutu 	172A - Phone Code 	GNU C++0x 	Accepted 	31 ms 	0 KB
#include <cstdio>
#include <cstring>

int main()
{
    int n;
    char s0[21], s[21];
    scanf("%d%s", &n, s0);
    int m = strlen(s0);
    while (--n)
    {
        scanf("%s", s);
        for (int i = 0; i < m; ++i)
        {
            if (s[i] != s0[i])
            {
                m = i;
                break;
            }
        }
    }
    printf("%d\n", m);
    return 0;
}
// 182B
#4314540	 Aug 20, 2013 9:13:16 AM	fuwutu	 182B - Vasya's Calendar	 Python 3	Accepted	 124 ms	 0 KB
d = int(input())
n = int(input())
l = input().split(' ')
times = 0
for i in range(0, n-1):
    times += d - int(l[i])
print(times)
// 186A
//4240233   Aug 7, 2013 4:37:55 PM	fuwutu	 186A - Строкосравнитель	 GNU C++0x	Accepted	 62 ms	 200 KB
#include <cstdio>
#include <cstring>

int main()
{
    char s1[100001], s2[100001];
    scanf("%s%s", s1, s2);

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    bool same = false;
    if (len1 == len2)
    {
        int diff[3], diffcount(0);
        for (int i = 0; i < len1; ++i)
        {
            if (s1[i] != s2[i])
            {
                diff[diffcount++] = i;
                if (diffcount == 3)
                {
                    break;
                }
            }
        }
        if (diffcount == 2 && s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]])
        {
            same = true;
        }
    }
    printf(same ? "YES\n" : "NO\n");

    return 0;
}
// 189A
//4240283   Aug 7, 2013 4:58:38 PM	fuwutu	 189A - Cut Ribbon	 GNU C++0x	Accepted	 30 ms	 0 KB
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, a, b, c, maximum(0);
    scanf("%d%d%d%d", &n, &a, &b, &c);

    bool x[4001] = {false}, y[8001] = {false};
    x[0] = true;
    for (int step = 1; ; ++step)
    {
        int count(0);
        for (int i = 0; i <= n; ++i)
        {
            if (x[i])
            {
                y[i+a] = true;
                y[i+b] = true;
                y[i+c] = true;
                count += 1;
            }
        }

        if (count == 0)
        {
            break;
        }

        copy(y, y + n + 1, x);
        fill(y, y + n + 1, false);

        if (x[n])
        {
            maximum = step;
        }
    }
    printf("%d\n", maximum);
    return 0;
}
// 190A
//4240283   Aug 7, 2013 4:58:38 PM	fuwutu	 189A - Cut Ribbon	 GNU C++0x	Accepted	 30 ms	 0 KB
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, a, b, c, maximum(0);
    scanf("%d%d%d%d", &n, &a, &b, &c);

    bool x[4001] = {false}, y[8001] = {false};
    x[0] = true;
    for (int step = 1; ; ++step)
    {
        int count(0);
        for (int i = 0; i <= n; ++i)
        {
            if (x[i])
            {
                y[i+a] = true;
                y[i+b] = true;
                y[i+c] = true;
                count += 1;
            }
        }

        if (count == 0)
        {
            break;
        }

        copy(y, y + n + 1, x);
        fill(y, y + n + 1, false);

        if (x[n])
        {
            maximum = step;
        }
    }
    printf("%d\n", maximum);
    return 0;
}
// 194A
//4238316   Aug 7, 2013 4:47:59 AM	fuwutu	 194A - Exams	 GNU C++0x	Accepted	 30 ms	 0 KB
#include <cstdio>

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%d\n", k <= n * 3 ? n * 3 - k : 0);
    return 0;
}
// 194B
//4339876	 Aug 26, 2013 6:25:52 PM	fuwutu	 194B - Square	 GNU C++0x	Accepted	30 ms	0 KB
#include <cstdio>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n;
        scanf("%I64d", &n);
        if ((n + 1) % 4 == 0)
        {
            printf("%I64d\n", n + 1);
        }
        else if ((n + 1) % 2 == 0)
        {
            printf("%I64d\n", n * 2 + 1);
        }
        else
        {
            printf("%I64d\n", n * 4 + 1);
        }
    }
    return 0;
}
// 195A
#4324702	 Aug 22, 2013 7:41:39 PM	fuwutu	 195A - Let's Watch Football	 Python 3	Accepted	124 ms	0 KB
l = input().split(' ')
a, b, c = int(l[0]), int(l[1]), int(l[2])
d = ((a - b) * c + b - 1) // b
print(d)
// 199A
#4055616   Jul 12, 2013 7:40:42 PM	fuwutu	 199A - Hexadecimal's theorem	 Python 3	Accepted	78 ms	100 KB
n = int(input())
if n == 0:
    print(0, 0, 0)
else:
    a, b = 0, 1
    while a + b != n:
        a, b = b, a + b
    print(0, a, b)
    
