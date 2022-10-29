#include <iostream>
#include <queue> 
#include <vector>
using namespace std;


void distance (vector <vector <int>> list, int r,int *dista);

int main () {
    vector <vector <int>> list;
    int *distance = new int [list.size()]; 


    delete [] distance; 
}

void distance (vector <vector <int>> list, int r, int *dista) { 
    queue <int> q;
    q.push (r);
    for (int i = 0; i < list.size();i++) {
        for (int j = 0; j < list[i].size(); j++) {
            //prova a casa visita in un vettore di vettori
        }
    }
}