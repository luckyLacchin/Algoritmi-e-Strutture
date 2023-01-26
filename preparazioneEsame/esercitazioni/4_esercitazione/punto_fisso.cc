#include <iostream>
#include <vector>

using namespace std;

bool punto_fisso (vector<int> &a, int size);
bool punto_fisso_aux (vector <int> &a, int first, int last);

int main () {

    vector <int> a;
    int n = 6;
    a.push_back(-5);
    a.push_back(-3);
    a.push_back(-1);
    a.push_back(0);
    a.push_back(2);
    a.push_back(5);
    cout << "Esiste un punto fisso: " << (punto_fisso(a,n) == true ? "si" : "no") << endl;

    return 0;
}

bool punto_fisso (vector<int> &a, int size) {

    return punto_fisso_aux (a,0,size-1);
}

bool punto_fisso_aux (vector <int> &a, int first, int last) {

    
    if (first <= last) {

        int m = (first + last) / 2;
        if (a[m] == m) {
            return true;
        }
        else if (a[m]>m) {
            return punto_fisso_aux(a,first,m-1);
        }
        else if (a[m] < m) {
            return punto_fisso_aux(a,m+1,last);
        }
    }
    else 
        return false; //ricordati il caso in cui è false!!!
}
