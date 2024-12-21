#include <iostream>
#include <vector>

using namespace std;

int punto_fisso (vector <int> a);
int punto_fisso_aux (vector <int> a, int start, int finish);

int main () {

    vector <int> a;
    a.resize (5);
    a.push_back(1);
    a.push_back(2);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    cout << punto_fisso (a)<< endl;
    return 0;
}


int punto_fisso (vector <int> a) {
    return punto_fisso_aux (a,0,a.size()-1);
}

int punto_fisso_aux (vector <int> a, int start, int finish) {
    int middle = (start + finish)/2;
    if (start < finish) {
        if (a[middle]-1 == middle) {
            return punto_fisso_aux (a,middle+1,finish);
        }
        else if (a[middle]-1 > middle) {
            return punto_fisso_aux (a,0,middle);
        }
    }
    else if (start == finish) {
        return start + 2;
        
    }
}
