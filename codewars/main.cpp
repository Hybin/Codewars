//
//  main.cpp
//  codewars
//
//  Created by Hybin on 2018/3/28.
//  Copyright © 2018年 Hybin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

// Highest Score of lexicon
vector<string> split(string const &s, string token)
{
    string::size_type index;
    vector<string> result;
    string ss = string(s, 0, string::npos);
    while (ss.size()) {
        index = ss.find(token);
        if (index != string::npos) {
            result.push_back(ss.substr(0, index));
            ss = ss.substr(index + token.size());
        }
        else
        {
            result.push_back(ss);
            ss = "";
        }
    }
    return result;
}

int convert(const char a)
{
    int r = 0;
    std::vector<char> alpha = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                               'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                               's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    std::vector<int> scores = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
                               15, 16,17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
    for (int i = 0; i < alpha.size(); ++i)
        if (alpha[i] == a)
            r = scores[i];
    return r;
}

int count(string s)
{
    int sum = 0;
    for (auto i : s) {
        sum += convert(i);
    }
    return sum;
}

int maxIndex(vector<int> const &v)
{
    int j = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > v[j]) {
            j = i;
        }
    }
    return j;
}

string counts(string const &s)
{
    vector<string> targets = split(s, " ");
    vector<int> scores;
    for (auto &i : targets) {
        scores.push_back(count(i));
    }
    return targets[maxIndex(scores)];
}

// Steps in Primes
class StepInPrimes
{
public:
    // if there are no such primes return {0, 0}
    static pair <long long, long long> step(int g, long long m, long long n);
    static bool prime(long long n);
};

pair <long long, long long> StepInPrimes::step(int g, long long m, long long n) {
    pair <long long, long long> res;
    if ((n - m) < g)
        res = make_pair(0, 0);
    
    while (m <= (n - g)) {
        if (StepInPrimes::prime(m)) {
            if (StepInPrimes::prime(m + g)) {
                res = make_pair(m, m +g);
                break;
            }
        }
        ++m;
    }
    return res;
}

bool StepInPrimes::prime(long long n) {
    bool is_prime = true;
    int i = 2;
    while (i <= sqrt(n)) {
        if (n % i == 0) {
            is_prime = false;
            break;
        }
        ++i;
    }
    return is_prime;
}

// Sort and Star
int minIndex(vector<int> v)
{
    int j = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] < v[j]) {
            j = i;
        }
    }
    return j;
};

string twoSort(vector<string> s)
{
    vector<int> scores;
    string t, r;
    for (auto &i : s) {
        scores.push_back(convert(i[0]));
    }
    t = s[minIndex(scores)];
    for (int i = 0; i < t.size() - 1; ++i) {
        r = r + t[i] + "***";
    }
    r = r + t[t.size() - 1];
    return r;
}

// Backwards Read Primes
class BackWardsPrime
{
public:
    static string backwardsPrime(long long start, long long end);
    static bool prime(long long n);
    static long long reverseInt(long long n);
};

bool BackWardsPrime::prime(long long n) {
    bool is_prime = true;
    int i = 2;
    while (i <= sqrt(n)) {
        if (n % i == 0) {
            is_prime = false;
            break;
        }
        ++i;
    }
    return is_prime;
}

long long BackWardsPrime::reverseInt(long long n) {
    long long number = 0, m;
    
    while (n > 0) {
        m = n % 10;
        n = (n - m) / 10;
        number = number * 10 + m;
    }
    return number;
}

string BackWardsPrime::backwardsPrime(long long start, long long end) {
    string res = "";
    if (end < start)
        return "";
    while (start <= end) {
        if (BackWardsPrime::prime(start)) {
            if (BackWardsPrime::reverseInt(start) != start) {
                if (BackWardsPrime::prime(BackWardsPrime::reverseInt(start))) {
                    res = res + to_string(start) + " ";
                }
            }
        }
        ++start;
    }
    size_t pos = res.find_last_not_of(" ") + 1;
    return res.erase(pos);
}

// Replace every nth
class Kata
{
public:
    static std::string replaceNth(std::string text, int n, char oldValue, char newValue)
    {
        if (n <= 0 || n > text.size())
            return text;
        
        std::vector<int> position;
        for (int i = 0; i < text.size(); ++i) {
            if (text.at(i) == oldValue) {
                position.push_back(i);
            }
        }
        while (n <= position.size()) {
            text.at(position[n - 1]) = newValue;
            n = n + n;
        }
        return text;
    }
};

// RGB To Hex Conversion
class RGBToHex
{
public:
    static string rgb(int r, int g, int b);
    static int check(int m);
    static string convert(int n);
};

string RGBToHex::rgb(int r, int g, int b)
{
    string res;
    r = RGBToHex::check(r);
    g = RGBToHex::check(g);
    b = RGBToHex::check(b);
    res = RGBToHex::convert(r) + RGBToHex::convert(g) + RGBToHex::convert(b);
    return res;
}

int RGBToHex::check(int m)
{
    if (m > 255)
        m = 255;
    if (m < 0) {
        m = 0;
    }
    return m;
}

string RGBToHex::convert(int n)
{
    vector<string> chars = {"0", "1", "2", "3", "4", "5", "6", "7",
                            "8", "9", "A", "B", "C", "D", "E", "F"};
    return chars[n / 16] + chars[n % 16];
}

// Reducing by steps
class Operarray
{
public:
    static long long gcdi(long long a, long long b);
    static long long lcmi(long long a, long long b);
    static long long som(long long a, long long b);
    static long long maxi(long long a, long long b);
    static long long mini(long long a, long long b);
    template<typename Func>
    static vector<long long> operArray(Func func, vector<long long> &arr, long long init);
};

long long Operarray::gcdi(long long a, long long b)
{
    return (b > 0) ? gcdi(b, b % a) : a;
}

long long Operarray::lcmi(long long a, long long b)
{
    return abs(a * b) / gcdi(a, b);
}

long long Operarray::som(long long a, long long b)
{
    return a + b;
}

long long Operarray::maxi(long long a, long long b)
{
    return (a > b) ? a : b;
}

long long Operarray::mini(long long a, long long b)
{
    return (a < b) ? a : b;
}

template<typename Func>
vector<long long> Operarray::operArray(Func func, std::vector<long long> &arr, long long init)
{
    vector<long long> res;
    res.push_back(func(init, arr[0]));
    for (int i = 1; i < arr.size(); ++i) {
        res.push_back(func(arr[i - 1], arr[i]));
    }
    return res;
}

// Integers: Recreation One
class SumSquaredDivisors
{
public:
    static string listSquared(long long m, long long n);
    static vector<long long> getDivisors(long long a);
    static long long getSum(vector<long long> v);
    static bool is_integer(long long i);
};

vector<long long> SumSquaredDivisors::getDivisors(long long a)
{
    vector<long long> res;
    for (int i = 1; i <= a; ++i) {
        if (a % i == 0) {
            res.push_back(i);
        }
    }
    return res;
}

long long SumSquaredDivisors::getSum(vector<long long> v)
{
    long long res = 0;
    for (auto &i : v) {
        res += pow(i, 2);
    }
    return res;
}

bool SumSquaredDivisors::is_integer(long long i)
{
    float t = sqrt(i);
    return floor(t) == t;
}

string SumSquaredDivisors::listSquared(long long m, long long n)
{
    string res = "{";
    while (m <= n) {
        long long a = SumSquaredDivisors::getSum(SumSquaredDivisors::getDivisors(m));
        if (SumSquaredDivisors::is_integer(a)) {
            res += "{" + to_string(m) + ", " + to_string(a) + "}, ";
        }
        m += 1;
    }
    if (res.size() > 1) {
        res.erase(res.end() - 2, res.end());
    }
    res += "}";
    return res;
}

// Going to zero or to infinity?
class Suite
{
public:
    static double going(int n);
    static float fact(int n);
    static int sigma(int n);
};

float Suite::fact(int n)
{
    float res = 1.0;
    
    if (n < 1)
        res = -1;
    
    for (int i = 1; i <= n; ++i) {
        res = res * i;
    }
    
    return res;
}

int Suite::sigma(int n)
{
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res += fact(i);
    }
    return res;
}

double Suite::going(int n)
{
    double res;
    res = (1 / fact(n)) * sigma(n);
    return res;
}

// Common Denominators
// https://www.codewars.com/kata/common-denominators/train/cpp

class Fracts
{
public:
    static string convertFrac(vector<vector<unsigned long long>> &lst);
    static unsigned long long leastCommonMulti(vector<unsigned long long> &nums);
};

unsigned long long Fracts::leastCommonMulti(vector<unsigned long long> &nums)
{
    unsigned long long maxNum = *max_element(nums.begin(), nums.end());
    while (true) {
        int count = 0;
        for (auto &i : nums) {
            if (maxNum % i == 0)
                ++count;
        }
        
        if (count == nums.size())
            break;
        else
            ++maxNum;
    }
    return maxNum;
}

string Fracts::convertFrac(vector<vector<unsigned long long>> &lst)
{
    string res = "";
    vector<unsigned long long> denom;
    for (auto &v : lst) {
        denom.push_back(v[1]);
    }
    
    unsigned long long lcm = Fracts::leastCommonMulti(denom);
    for (auto &v : lst) {
        v[0] = lcm / v[1] * v[0];
        v[1] = lcm;
        res += "(" + to_string(v[0]) + "," + to_string(v[1]) + ")";
    }
    
    return res;
}


int main(int argc, const char * argv[]) {
    std::vector<std::vector<unsigned long long>> r1 = { {1, 2}, {1, 3}, {1, 4} };
    std::string ans1 = Fracts::convertFrac(r1);
    cout << ans1 << endl;
    return 0;
}
