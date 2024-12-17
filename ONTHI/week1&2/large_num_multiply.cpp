#include <bits/stdc++.h>
using namespace std;

string multiplyStrings(string a, string b)
{
    // Edge case for zero multiplication
    if (a == "0" || b == "0")
        return "0";

    int m = a.size();
    int n = b.size();
    vector<int> result(m + n, 0);

    // Reverse both strings to make multiplication easier
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    // Perform multiplication digit by digit
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int product = (a[i] - '0') * (b[j] - '0');
            int sum = product + result[i + j];
            result[i + j] = sum % 10;
            result[i + j + 1] += sum / 10;
        }
    }

    // Remove leading zeros and convert result to string
    string resultStr;
    bool leadingZero = true;
    for (int i = m + n - 1; i >= 0; --i)
    {
        if (result[i] != 0)
            leadingZero = false;
        if (!leadingZero)
            resultStr += to_string(result[i]);
    }

    return resultStr.empty() ? "0" : resultStr;
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << multiplyStrings(a, b);
}
