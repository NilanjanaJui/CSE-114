#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int i = s1.size() - 1, j = s2.size() - 1;
    int backspace1 = 0, backspace2 = 0;

    while (i >= 0 || j >= 0) {
        // Count consecutive '#' characters and move pointer back
        while (i >= 0 && (s1[i] == '#' || backspace1 > 0)) {
            backspace1 += (s1[i] == '#') ? 1 : -1;
            i--;
        }

        while (j >= 0 && (s2[j] == '#' || backspace2 > 0)) {
            backspace2 += (s2[j] == '#') ? 1 : -1;
            j--;
        }

        // Check if characters are equal after backspaces
        if (i >= 0 && j >= 0 && s1[i] != s2[j]) {
            cout << "false" << endl;
            return 0;
        }

        // If one string has been processed but the other hasn't
        if ((i >= 0) != (j >= 0)) {
            cout << "false" << endl;
            return 0;
        }

        i--;
        j--;
    }

    // Both strings have been processed and are equal
    cout << "true" << endl;
    return 0;
}
