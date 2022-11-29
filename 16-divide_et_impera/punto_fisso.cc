#include <iostream>
#include <vector>

using namespace std;

bool punto_fisso (vector <int> a);
bool punto_fisso_aux (vector <int> a, int start, int finish);

int main () {

    vector <int> a;
    return 0;
}


bool punto_fisso (vector <int> a) {
    return punto_fisso_aux (a,0,a.size()-1);
}

bool punto_fisso_aux (vector <int> a, int start, int finish) {
    int middle = (start + finish)/2;
    if (start <= finish) {
        if (a[middle] < middle) {
            return punto_fisso_aux (a,middle+1,finish);
        }
        else if (a[middle] > middle) {
            return punto_fisso_aux (a,0,middle-1);
        }
        else 
            return true;
    }
    else
        return false;
}
