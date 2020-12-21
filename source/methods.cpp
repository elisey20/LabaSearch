#include <iostream>
#include <vector>

using namespace std;

vector<size_t> findString(const string& lookingString, const string& searchStr)
{
    const string s = searchStr + "@" + lookingString;
    size_t n = s.length();
    vector<size_t> pi(n);
    for (size_t i=1; i<n; ++i)
    {
        size_t j = pi[i-1];
        while ((j > 0) && (s[i] != s[j]))
            j = pi[j-1];

        if (s[i] == s[j])
            ++j;
        pi[i] = j;
    }

    vector<size_t> result;
    size_t lenStr = searchStr.length();
    size_t j = 0;
    size_t trueLenStr = 0;

    while (j < lenStr)
    {
        if (s[j] < '\xC0')
            j++;
        else if (s[j] < '\xE0')
            j += 2;
        else if (s[j] < '\xF0')
            j += 3;
        else
            j += 4;
        trueLenStr++;
    }

    size_t pos = trueLenStr + 2;

    j = lenStr + 1;
    while (j < n)
    {
        if ((unsigned char)s[j] < (unsigned char)'\xC0')
            j++;
        else if (s[j] < '\xE0')
            j += 2;
        else if (s[j] < '\xF0')
            j += 3;
        else
            j += 4;

        pos++;
        if (pi[j-1] == lenStr) {
            result.push_back(pos - trueLenStr);
        }
    }

    return result;
}