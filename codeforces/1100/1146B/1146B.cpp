#include <iostream>
#include <string>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main() {
    FAST_IO;
    string t;
    cin >> t;

    string temp = "";
    for (char c : t) {
        if (c != 'a') temp += c;
    }

    if (temp.empty()) {
        cout << t << endl;
        return 0;
    }

    size_t n_sin_a = temp.size();
    
    if (n_sin_a % 2 == 0) {
        size_t mid = n_sin_a / 2;
        string s_prime = temp.substr(mid);

        if (temp.substr(0, mid) == s_prime) {
            if (t.substr(t.size() - mid) == s_prime) {
                cout << t.substr(0, t.size() - mid) << endl;
                return 0;
            }
        }
    }

    cout << ":(" << endl;
    return 0;
}

