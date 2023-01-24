#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int sum_max(vector<int> &vec);

int main () {

    ifstream in("input.txt");
    ofstream out("output.txt");
    vector <int> vec;
    int temp, righe = 0;
    in >> righe;
    while (in >> temp) {
        vec.push_back(temp);
    }
    int maxSoFar = 0;
    int maxTemp = 0;

    for (int t : vec) {
        maxTemp += t;
        maxTemp = max(maxTemp,0);
        maxSoFar = max(maxTemp,maxSoFar);
        
    }
    out << maxSoFar;


    return 0;
}
