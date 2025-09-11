#include <iostream>
#include <string>
using namespace std;

string arab_to_rome(int n)
{
    const int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const string symbole[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string s = "";
    for (int i = 0; i < 13; i++)
    {
        while (n >= val[i])
        {
            n -= val[i];
            s += symbole[i];
        }
    }
    return s;
}

int roman_wartosci(char c)
{
    switch (c)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}

int rome_to_arab(string s)
{
    int wynik = 0;
    int wartosc_pre = 0;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        char c = s[i];
        if (c >= 'a' && c <= 'z')
            c = c - 'a' + 'A';

        int wartosc_cur = roman_wartosci(c);

        if (wartosc_cur == 0)
            return -1;

        if (wartosc_cur < wartosc_pre)
            wynik -= wartosc_cur;
        else
            wynik += wartosc_cur;

        wartosc_pre = wartosc_cur;
    }

    return wynik;
}

int main()
{
    int wybour;
    cout << "wybór: 1. arab -> rome; 2. rome -> arab" << '\n';
    cin >> wybour;

    switch (wybour)
    {
    case 1:
    {
        int arabic;
        cin >> arabic;

        cout << arab_to_rome(arabic) << '\n';
        break;
    }
    case 2:
    {
        string roman;
        cin >> roman;

        cout << rome_to_arab(roman) << '\n';
        break;
    }
    default:
        return 0;
    }

    return 0;
}
