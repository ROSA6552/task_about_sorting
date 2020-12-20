#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, voters;

    in >> n;

    int* groups = new int[n];

    for (int i = 0; i < n; i++) {
        in >> groups[i];
    }

    sort(groups, groups + n - 1);

    n = n / 2 + 1;

    for (int i = 0; i < n; i++) {
        voters += groups[i] / 2 + 1;
    }

    out << voters;

    return 0;
}
