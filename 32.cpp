#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int min (int a)
{
    int a1, a2;
    if (a / 10 > a % 10)
    {
        a1 = a / 10;
        a2 = a % 10;
        a = a2 * 10 + a1;
    }
    return a;
}

int max (int a)
{
    int a1, a2;
    if (a / 10 < a % 10)
    {
        a1 = a / 10;
        a2 = a % 10;
        a = a2 * 10 + a1;
    }
    return a;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int a, b, res[4], a1, b1, a2, b2;
    bool flaga = false;
    bool flagb = false;

    in >> a >> b;

    if (a < 0)
        flaga = true;
    if (b < 0)
        flagb = true;

    a = abs(a);
    b = abs(b);

    if (a > 10 && a % 10 != 0)
    {
        if (b > 10 && b % 10 != 0)
        {
            if (min(a) < min(b))
                a = min(a);
            else
                b = min(b);

            if (max(a) > max(b))
                a = max(a);
            else
                b = max(b);

            if (flaga)
                a = a * (-1);
            if (flagb)
                b = b * (-1);

            out << abs(a - b);
        }
        else
        {
            a = max(a);

            if (flaga)
                a = a * (-1);
            if (flagb)
                b = b * (-1);

            out << abs(a - b);
        }
    }
    else
    {
        if (b > 10 && b % 10 != 0)
        {
            b = max(b);

            if (flaga)
                a = a * (-1);
            if (flagb)
                b = b * (-1);

            out << abs(a - b);
        }
        else
        {
            if (flaga)
                a = a * (-1);
            if (flagb)
                b = b * (-1);

            out << abs(a - b);
        }
    }

    return 0;
}
