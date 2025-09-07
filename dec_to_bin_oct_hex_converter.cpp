#include <iostream>
#include <string>
using namespace std;

int bin(int n)
{
    string s = "";
    while (n > 0)
    {
        s = to_string(n % 2) + s;
        n /= 2;
    }
    n = stoi(s);

    return n;
}

int oct(int n)
{
    string s = "";
    while (n > 0)
    {
        s = to_string(n % 8) + s;
        n /= 8;
    }
    n = stoi(s);

    return n;
}

string hex(int n)
{
    string s = "";
    while (n > 0)
    {
        int r = n % 16;
        if (r < 10)
            s = char('0' + r) + s;
        else
            s = char('A' + r - 10) + s;
        n /= 16;
    }
    return s;
}

int main()
{
    int n;
    cin >> n;

    cout << bin(n) << '\n';
    cout << oct(n) << '\n';
    cout << hex(n) << '\n';

    return 0;
}
