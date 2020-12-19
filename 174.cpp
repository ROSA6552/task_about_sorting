#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

const int N = 40;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    double sum;
    int n;
    in >> n;
    double men[N];
    for (int i = 0; i < n; i++)
        in >> men[i];

    in >> sum;

    sort(men, men + n);

    for (int i = 0; i < n; i++)
    {
        if (sum < men[i])
            sum = (sum + men[i]) / 2;
    }

    out << fixed << setprecision(6) << sum;

    return 0;
}
