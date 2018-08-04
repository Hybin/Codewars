//
//  hScore.cpp
//  codewars
//
//  Created by Hybin on 2018/3/28.
//  Copyright © 2018年 Hybin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

int main(int argc, const char * argv[]) {
    cout << counts("take two bintang and a dance please") << endl;
    return 0;
}
