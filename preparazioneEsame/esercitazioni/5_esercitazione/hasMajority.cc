#include <iostream>
#include <vector>

using namespace std;

bool hasMajority (vector<int> s);
int hasMajority_aux (vector<int> s, int first, int last, int candidate);



int main () {

    vector <int> s;
    s.push_back(3);
    s.push_back(3);
    s.push_back(3);
    s.push_back(3);
    s.push_back(12);
    s.push_back(15);

    cout << "Il vettore contiene un valore di maggioranza: " << (hasMajority(s)?"Si" : "No");
    return 0;

}

bool hasMajority (vector <int> s) {
    int candidate = s[(s.size()-1)/2];
    int first = hasMajority_aux (s,0,s.size()-1, candidate);
    return s[first] == s[first+s.size()/2];
}

int hasMajority_aux (vector <int> s, int first, int last, int candidate) {
    if (first == last) {
        return first;
    }
    else {
        int m = (last + first) / 2;
        if (candidate <= s[m]) {
            return hasMajority_aux(s,first,m,candidate);
        }
        else {
            return hasMajority_aux(s,m+1,last,candidate);
        }
    }
}