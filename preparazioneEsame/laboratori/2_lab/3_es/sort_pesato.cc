#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void mergeSort (vector<pair<int,int>> &vec, int first, int last);
void merge (vector <pair<int,int>> &vec, int first, int mid, int last);
int sort_num (vector<int> &vec, vector<pair<int,int>> &ves);
int sort_cost (vector<int> &vec, vector<pair<int,int>> &ves);
int sort_cost_2 (vector<int> &vec, vector<pair<int,int>> &ves);

int main () {

    ifstream in("input.txt");
    ofstream out("output.txt");
    vector <int> vec;
    vector <int> vet, vet_2; 
    vector <pair<int,int>> ves;
    int dim = 0, temp, index = 0;
    in >> dim;
    while (in >> temp) {
        vec.push_back(temp);
        vet.push_back(temp);
        vet_2.push_back(temp);
        ves.push_back(make_pair(temp,index++));
    }
    mergeSort(ves,0,dim-1);
    out << sort_num (vec,ves) << " ";
    int n1 = sort_cost(vet,ves);
    int n2 = sort_cost_2 (vet_2,ves);
    out << (n1 < n2? n1 : n2);
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

int sort_num (vector<int> &vec, vector<pair<int,int>> &ves) {
    int i = 0, temp, res = 0;
    while (i < vec.size()) {
        if (vec[i]==ves[i].first)
            ++i;
        else {
            ++res;
            temp = vec[i];
            vec[i] = vec[vec[i]-1];
            vec[temp-1] = temp;
            if (vec[i] == ves[i].first)
                ++i;
        }
    }
    return res;
}

int sort_cost_2 (vector<int> &vec, vector<pair<int,int>> &ves) {
    int i = 0, temp, tot_cost = 0, min = -1;
    
    while (i < vec.size()) {
        if (vec[i] == ves[i].first)
            ++i;
        else { 
            temp = vec[i];
            vec[i] = vec[ves[i].second];
            vec[ves[i].second] = temp;
            ves[temp-1].second =  ves[i].second;
            tot_cost += vec[i] + vec[ves[i].second];
            ++i;
        }
    }


    return tot_cost;
}

int sort_cost (vector<int> &vec, vector<pair<int,int>> &ves) {
    int i = vec.size()-1, temp, tot_cost = 0;
    
    while (i >= 0) {
        if (vec[i] == ves[i].first)
            --i;
        else { 
            temp = vec[i];
            vec[i] = vec[ves[i].second];
            vec[ves[i].second] = temp;
            ves[temp-1].second =  ves[i].second;
            tot_cost += vec[i] + vec[ves[i].second];
            --i;
        }
    }


    return tot_cost;
}
