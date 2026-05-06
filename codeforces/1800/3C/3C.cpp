#include <iostream>
#include <string>
#include <algorithm>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

bool hasWon(char p, string t) {
    for (int i = 0; i < 9; i += 3)
        if (t[i] == p && t[i+1] == p && t[i+2] == p) return true;
    for (int i = 0; i < 3; ++i)
        if (t[i] == p && t[i+3] == p && t[i+6] == p) return true;
    if (t[0] == p && t[4] == p && t[8] == p) return true;
    if (t[2] == p && t[4] == p && t[6] == p) return true;
    
    return false;
}

int main() {
    FAST_IO;
    string f1, f2, f3;
    cin >> f1 >> f2 >> f3;
    string t = f1 + f2 + f3;

    int x = count(t.begin(), t.end(), 'X');
    int o = count(t.begin(), t.end(), '0');

    bool winX = hasWon('X', t);
    bool win0 = hasWon('0', t);

    if ((x - o != 0 && x - o != 1) ||      
        (winX && win0) ||                  
        (winX && x == o) ||               
        (win0 && x > o)) {                
        cout << "illegal" << endl;
    } 
    else if (winX) {
        cout << "the first player won" << endl;
    } else if (win0) {
        cout << "the second player won" << endl;
    } else if (x + o == 9) {
        cout << "draw" << endl;
    } else {
        cout << (x == o ? "first" : "second") << endl;
    }

    return 0;
}
