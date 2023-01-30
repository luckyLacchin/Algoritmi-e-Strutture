#include <vector>
#include <iostream>

using namespace std;

int shift (vector<int> a);
void shift_aux (vector<int> a, int first, int last,int &result);

int main () {

    vector <int> a;
    int n = 8;
    a.resize(n);
    a[0] = 35;
    a[1] = 42;
    a[2] = 1;
    a[3] = 7;
    a[4] = 15;
    a[5] = 18;
    a[6] = 28;
    a[7];
    cout << "Lo shift e' stato fatto di: " << shift(a) << endl;

    return 0;
}

int shift (vector<int> a) {
    int result = 0;
    shift_aux(a,0,a.size()-1,result);
    return result;
}

void shift_aux (vector<int> a, int first, int last,int &result) {

    if (first >= last) {
        if (result == 0)
            result = first;
    }
    else {
        int m = (last + first) / 2;
        if ((a[m] < a[m+1]) && (a[m] > a[m-1])) {
            shift_aux(a,first,m,result);
            shift_aux(a,m+1,last,result);
        }
        if (a[m] > a[m+1]) {
            shift_aux(a,m+1,last,result);
        }
        else if (a[m] < a[m-1]) {
            shift_aux(a,first,m,result);
        }

        
    }
}
/*guarda soluzione del prof però anche questa dovrebbe essere corretta - http://disi.unitn.it/~montreso/asd/compiti/18-08-21.soluzione.pdf*/