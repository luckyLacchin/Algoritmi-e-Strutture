#include <iostream>

using namespace std;

bool hasMajority (int *a, int n);
bool hasMajority_2 (int *a,int n,int first,int last);

int main () {
    int *a;
    int n;
    hasMajority (a,n);

    return 0;
}



bool hasMajority (int *a, int n) {
    
    return hasMajority_2 (a,n,0, n-1);

}

bool hasMajority_2 (int *a,int n,int first,int last) {


    return false;
}

