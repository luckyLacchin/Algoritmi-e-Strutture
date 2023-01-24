#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void mergeSort (vector<pair<int,int>> &vec, int first, int last);
void merge (vector <pair<int,int>> &vec, int first, int mid, int last);
pair <int,int> interval (vector<pair<int,int>> &vec);

int main () {

    ifstream in("input.txt");
    ofstream out("output.txt");
    vector <pair<int,int>> vec;
    int dim = 0, t,s;
    in >> dim;
    while ((in >> t) && (in >> s)) {
        vec.push_back(make_pair(t,s));
    }
    mergeSort(vec,0,dim-1);

    pair<int,int> maxPair = interval(vec);
    out << maxPair.first << " " << maxPair.second;
    return 0;
}

void mergeSort (vector<pair<int,int>> &vec, int first, int last) {
    
    int mid = (last + first) / 2;
    if (first < last) {
        mergeSort (vec,first,mid);
        mergeSort (vec,mid+1,last);
        merge (vec,first,mid,last);
    }

}

void merge (vector <pair<int,int>> &vec, int first, int mid, int last) {

    vector <pair<int,int>> b;
    int i = first, j = mid+1, index = first;
    while ((i <= mid) || (j <= last)) {
        if ((i <= mid) && (j <= last)) {
            if (vec[i].first<=vec[j].first) {
                b.push_back(vec[i]);
                ++i;
            }
            else {
                b.push_back(vec[j]);
                ++j;
            }
        }
        if ((i > mid) && (j <= last)) {
            b.push_back(vec[j]);
            ++j;
        }

        if ((j > last) && (i <= mid)) {
            b.push_back(vec[i]);
            ++i;
        }
    }

    for (pair<int,int> i : b) {
        vec[index] = i;
        ++index;
    }

}

pair <int,int> interval (vector<pair<int,int>> &vec) {
    int intervallo = 0, maxInterval = 0; 
    pair <int,int> maxPair = make_pair(0,0);
    for (int i = 0; i < vec.size() - 1; i++) {
        if (vec[i+1].first>=vec[i].second) {
            intervallo = vec[i+1].first - vec[i].second;
            maxInterval = max(intervallo,maxInterval);
            maxPair = make_pair (vec[i].second,vec[i+1].first);
        }
    }
    return maxPair;
}