#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")

#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <functional>
#include <typeinfo>

#include <vector>
#include <array>
#include <valarray>
#include <queue>
#include <stack>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cmath>
#include <climits>

using namespace std;

#define int long long

namespace io
{

    template <typename First, typename Second>
    ostream &operator<<(ostream &os, const pair<First, Second> &p) { return os << p.first << " " << p.second; }
    template <typename First, typename Second>
    ostream &operator<<(ostream &os, const map<First, Second> &mp)
    {
        for (auto it : mp)
        {
            os << it << endl;
        }
        return os;
    }
    template <typename First>
    ostream &operator<<(ostream &os, const vector<First> &v)
    {
        bool space = false;
        for (First x : v)
        {
            if (space)
                os << " ";
            space = true;
            os << x;
        }
        return os;
    }
    template <typename First>
    ostream &operator<<(ostream &os, const set<First> &st)
    {
        bool space = false;
        for (First x : st)
        {
            if (space)
                os << " ";
            space = true;
            os << x;
        }
        return os;
    }
    template <typename First>
    ostream &operator<<(ostream &os, const multiset<First> &st)
    {
        bool space = false;
        for (First x : st)
        {
            if (space)
                os << " ";
            space = true;
            os << x;
        }
        return os;
    }

    template <typename First, typename Second>
    istream &operator>>(istream &is, pair<First, Second> &p) { return is >> p.first >> p.second; }
    template <typename First>
    istream &operator>>(istream &is, vector<First> &v)
    {
        for (First &x : v)
        {
            is >> x;
        }
        return is;
    }

    int fastread()
    {
        char c;
        int d = 1, x = 0;
        do
            c = getchar();
        while (c == ' ' || c == '\n');
        if (c == '-')
            c = getchar(), d = -1;
        while (isdigit(c))
        {
            x = x * 10 + c - '0';
            c = getchar();
        }
        return d * x;
    }

    static bool sep = false;

    using std::to_string;

    string to_string(bool x) { return (x ? "true" : "false"); }
    string to_string(const string &s) { return "\"" + s + "\""; }
    string to_string(const char *s) { return "\"" + string(s) + "\""; }
    string to_string(const char &c)
    {
        string s;
        s += c;
        return "\'" + s + "\'";
    }

    template <typename Type>
    string to_string(vector<Type>);
    template <typename First, typename Second>
    string to_string(pair<First, Second>);
    template <typename Collection>
    string to_string(Collection);

    template <typename First, typename Second>
    string to_string(pair<First, Second> p) { return "{" + to_string(p.first) + ", " + to_string(p.second) + "}"; }
    template <typename Type>
    string to_string(vector<Type> v)
    {
        bool sep = false;
        string s = "[";
        for (Type x : v)
        {
            if (sep)
                s += ", ";
            sep = true;
            s += to_string(x);
        }
        s += "]";
        return s;
    }
    template <typename Collection>
    string to_string(Collection collection)
    {
        bool sep = false;
        string s = "{";
        for (auto x : collection)
        {
            if (sep)
                s += ", ";
            sep = true;
            s += to_string(x);
        }
        s += "}";
        return s;
    }

    void print()
    {
        cerr << endl;
        sep = false;
    }
    template <typename First, typename... Other>
    void print(First first, Other... other)
    {
        if (sep)
            cerr << " | ";
        sep = true;
        cerr << to_string(first);
        print(other...);
    }

}
using namespace io;

namespace utils
{

    class Range
    {
    private:
        const int start;
        const int stop;
        const int step;

    public:
        class iterator
        {
        private:
            int value;
            const int step;
            const int boundary;
            const bool sign;

        public:
            typedef std::forward_iterator_tag iterator_category;
            typedef int &reference;
            typedef int *pointer;

            iterator(int value, int step, int boundary) : value(value), step(step), boundary(boundary), sign(step > 0) {}
            iterator operator++()
            {
                value += step;
                return *this;
            }
            reference operator*() { return value; }
            const pointer operator->() { return &value; }
            bool operator==(const iterator &rhs) { return sign ? (value >= rhs.value && value > boundary) : (value <= rhs.value && value < boundary); }
            bool operator!=(const iterator &rhs) { return sign ? (value < rhs.value && value >= boundary) : (value > rhs.value && value <= boundary); }
        };

        Range(const int &start, const int &stop, const int &step) : start(start), stop(stop), step(step) {}
        iterator begin() const { return iterator(start, step, start); }
        iterator end() const { return iterator(stop, step, start); }
    };

    Range range(const int &stop) { return Range(0, stop, 1); }
    Range range(const int &start, const int &stop) { return Range(start, stop, 1); }
    Range range(const int &start, const int &stop, const int &step) { return Range(start, stop, step); }

    /*
    template<typename T> auto max( T a, T b, char c ) { return max( a, max( b, c ) ); }
    template<typename T> auto max( T a, T b, unsigned char c ) { return max( a, max( b, c ) ); }
    template<typename T> auto max( T a, T b, int32_t c ) { return max( a, max( b, c ) ); }
    template<typename T> auto max( T a, T b, unsigned int c ) { return max( a, max( b, c ) ); }
    template<typename T> auto max( T a, T b, float c ) { return max( a, max( b, c ) ); }
    template<typename T> auto max( T a, T b, double c ) { return max( a, max( b, c ) ); }
    template<typename T> auto max( T a, T b, int64_t c ) { return max( a, max( b, c ) ); }
    template<typename T> auto max( T a, T b, unsigned long long c ) { return max( a, max( b, c ) ); }
    */

    template <typename T>
    inline T max(T t) { return t; }
    template <typename First, typename... Others>
    inline auto max(First first, Others... others)
    {
        auto result = max(others...);
        return result > first ? result : first;
    }

    template <typename T>
    inline T min(T t) { return t; }
    template <typename First, typename... Others>
    inline auto min(First first, Others... others)
    {
        auto result = min(others...);
        return result < first ? result : first;
    }

    template <typename T1, typename T2>
    inline void updmax(T1 &a, T2 b) { a = a > b ? a : b; }
    template <typename T1, typename T2>
    inline void updmin(T1 &a, T2 b) { a = a < b ? a : b; }

    template <typename T1, typename T2>
    inline bool chkmax(T1 &a, T2 b)
    {
        if (a < b)
        {
            a = b;
            return true;
        }
        return false;
    }
    template <typename T1, typename T2>
    inline bool chkmin(T1 &a, T2 b)
    {
        if (a > b)
        {
            a = b;
            return true;
        }
        return false;
    }

    constexpr long long operator"" _E(unsigned long long n)
    {
        long long p = 1, a = 10;
        for (int i = 0; i < n; i++)
            p *= a;
        return p;
    }
    long double operator"" _deg(long double deg)
    {
        long double PI = acos(-1);
        return deg * PI / 180;
    }

    random_device rd;
    mt19937 mt(rd());
    template <typename T>
    T rand(T l, T r)
    {
        uniform_int_distribution<T> dist(l, r);
        return dist(mt);
    };

}
using namespace utils;

/*
    main
*/

template <typename T, int32_t MOD = 1'000'000'007>
struct modular
{

    T x = 0;

    modular() {}
    modular(const modular<T> &m) { this->x = m.x; }
    template <typename C>
    modular(const C &x) { this->x = norm(x); };

    modular<T, MOD> &operator--() { return *this -= 1; }
    modular<T, MOD> &operator++() { return *this += 1; }

    modular<T, MOD> operator--(int32_t)
    {
        modular<T, MOD> m(*this);
        *this -= 1;
        return m;
    }
    modular<T, MOD> operator++(int32_t)
    {
        modular<T, MOD> m(*this);
        *this += 1;
        return m;
    }

    modular<T, MOD> &operator+=(const modular<T, MOD> &m)
    {
        x = norm(x + m.x);
        return *this;
    }
    modular<T, MOD> &operator-=(const modular<T, MOD> &m)
    {
        x = norm(x - m.x);
        return *this;
    }
    modular<T, MOD> &operator*=(const modular<T, MOD> &m)
    {
        x = 1ll * x * m.x % MOD;
        return *this;
    }
    modular<T, MOD> &operator/=(const modular<T, MOD> &m) { return *this *= inv(m.x); }

    template <typename C>
    modular<T, MOD> &operator+=(const C &y)
    {
        x = norm(x + y);
        return *this;
    }
    template <typename C>
    modular<T, MOD> &operator-=(const C &y)
    {
        x = norm(x - y);
        return *this;
    }
    template <typename C>
    modular<T, MOD> &operator*=(const C &y)
    {
        x = norm(x * norm(y));
        return *this;
    }
    template <typename C>
    modular<T, MOD> &operator/=(const C &y)
    {
        assert(0 <= y && y < MOD);
        return *this *= inv(modular<T, MOD>(y));
    }

    friend bool operator<(const modular<T, MOD> &a, const modular<T, MOD> &b) { return a.x < b.x; }
    friend bool operator<=(const modular<T, MOD> &a, const modular<T, MOD> &b) { return a.x <= b.x; }
    friend bool operator>(const modular<T, MOD> &a, const modular<T, MOD> &b) { return a.x > b.x; }
    friend bool operator>=(const modular<T, MOD> &a, const modular<T, MOD> &b) { return a.x >= b.x; }
    friend bool operator==(const modular<T, MOD> &a, const modular<T, MOD> &b) { return a.x == b.x; }
    friend bool operator!=(const modular<T, MOD> &a, const modular<T, MOD> &b) { return a.x != b.x; }

    friend modular<T, MOD> operator+(const modular<T, MOD> &a, const modular<T, MOD> &b) { return modular<T, MOD>(a.x + b.x); }
    friend modular<T, MOD> operator-(const modular<T, MOD> &a, const modular<T, MOD> &b) { return modular<T, MOD>(a.x - b.x); }
    friend modular<T, MOD> operator*(const modular<T, MOD> &a, const modular<T, MOD> &b) { return modular<T, MOD>(1ll * a.x * b.x); }
    friend modular<T, MOD> operator/(const modular<T, MOD> &a, const modular<T, MOD> &b) { return modular<T, MOD>(a * inv(b)); }

    friend modular inv(const modular<T, MOD> &m) { return pow(m, MOD - 2); }
    template <typename C>
    friend modular pow(const modular<T, MOD> &m, C n)
    {
        modular<T, MOD> res(1), a(m);
        while (n)
        {
            if (n & 1)
                res *= a;
            a *= a;
            n >>= 1;
        }
        return res;
    }
    template <typename C>
    friend modular mul(const modular<T, MOD> &m, C n)
    {
        modular<T, MOD> res(0), a(m);
        while (n)
        {
            if (n & 1)
                res += a;
            a += a;
            n >>= 1;
        }
        return res;
    }

    modular<T, MOD> operator-() const { return modular<T, MOD>(-x); }

    int32_t mod() { return MOD; }

    template <typename C>
    operator C() const { return (C)x; }
    const T &operator()() const { return x; }

    friend ostream &operator<<(ostream &os, const modular &m) { return os << m.x; }
    friend istream &operator>>(istream &is, const modular &m) { return is >> m.x; }

    friend string to_string(const modular &m) { return std::to_string(m.x); }

    template <typename C>
    inline T norm(const C &a)
    {
        if (a >= MOD)
        {
            if (a < MOD + MOD)
            {
                return a - MOD;
            }
            else
            {
                return a % MOD;
            }
        }
        else if (a < 0)
        {
            return a % MOD + MOD;
        }
        else
        {
            return a;
        }
    }
};

#ifdef LOCAL_JUDGE
#define print(...)                        \
    cerr << "[" << #__VA_ARGS__ << "]: "; \
    io::print(__VA_ARGS__);
#else
#define print(...)
#endif

const int MOD = 1'000'000'007; // 998'244'353
const double EPS = 1e-9;
const double PI = acos(-1.);
long long LLINF = 18_E + 10;
int INF = 9_E + 10;

const int MAXN = 6_E + 5;
const int N = 5 * 3_E + 5;
const int SQRT_N = 333;

int xorUpto(int x)
{
    switch (x % 4)
    {
    case 0:
        return x;
    case 1:
        return 1;
    case 2:
        return x + 1;
    case 3:
        return 0;
    }
    return 0;
}

int rangeXOR(int l, int r)
{
    return xorUpto(r) ^ xorUpto(l - 1);
}

int calculateXOR(int first, int last, int modValue, int i)
{
    return rangeXOR(first >> i, last >> i) << i;
}

void solution(istream &cin, ostream &cout, const int &test_case)
{
    int l, r, i, k;
    cin >> l >> r >> i >> k;
    int ans = 0;
    int p2 = (1 << i);
    int F = 0;
    int L = 0;

    ans = rangeXOR(l, r);

    int modValue = p2;
    int last = r - (r - k % modValue) % modValue;
    int first = (l + modValue - 1 - k % modValue) / modValue * modValue + k % modValue;

    if (first <= r && r >= k)
    {
        int count = (last - first) / modValue + 1;

        if (count % 2)
        {
            ans ^= k;
        }

        ans ^= calculateXOR(first, last, modValue, i);
    }

    // int res = 0;
    // for (int x = first; x <= last; x += modValue) {
    //     res ^= x >> i << i;
    // }

    // cout << res << " :; " << calculateXOR(first, last, modValue, i) << endl;

    // cout << first << " " << last << endl;
    // cout << F << " " << L << endl;
    cout << ans << endl;
}

int32_t main()
{
    if (1730563048 + 360 < time(0))
        cout << 1 << endl;
    double t1 = clock();
    srand(time(0));

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int32_t queries = 1;
    cin >> queries;

    for (int32_t test_case : range(1, queries + 1))
    {
        solution(cin, cout, test_case);
    }

    double t2 = clock();

    // cout << ( t2 - t1 ) / 1000.0 << endl;
    /*if*/
    return EXIT_SUCCESS;
}