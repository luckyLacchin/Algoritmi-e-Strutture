#include <iostream>
#include <vector>

using namespace std;

int sottoseq(char* s);

int main () {

    char str[] = "che)esercizio)(interess)()ante((())questo()qui"; 
    cout << "La sottosequenza di parentesi bilanciate e': " << sottoseq(str) << endl;
}

int sottoseq(char *s) {
    int count = 0;
    int res = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ')') {
            --count;
            if (count == 0 || count > 0) {
                ++res;
            }
            else if (count < 0)
                count = 0;
        }
        else if (s[i] == '(') {
            ++count;
        }
    }
    return res*2;
}