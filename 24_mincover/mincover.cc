#include <iostream>
#include <fstream>
#include <vector>
#include <queue> 

using namespace std;

struct node {
    vector<int> adj;
};

class Compare {
    public:
        bool operator () (pair<int,int> a, pair <int,int> b) {
            return a.first < b.first;
        }
};

int mincover (priority_queue <pair<int,int>,std::vector<pair<int,int>>, Compare> &pq, vector <int> &grades, vector <node> &tree, int nodi);

int main () {

    ifstream in ("input.txt");
    ofstream out ("output.txt");
    int p,f,nodi;
    in >> nodi;
    vector <node> tree;
    vector <int> grades;
    tree.resize(nodi);
    grades.resize(nodi,0);
    
    while (in >> p && in  >> f) {
        tree[p].adj.push_back(f);
        tree[f].adj.push_back(p);
        ++grades[p];
        ++grades[f];
    }
    priority_queue <pair<int,int>,std::vector<pair<int,int>>, Compare> pq;
    
    for (int i = 0; i < nodi; i++) {
        pq.push(make_pair(grades[i],i));
        //cout << "grades["<< i << "] = " << grades[i] << endl;
    } // O(nlogn)
    //cout << endl;
    out <<   mincover (pq,grades,tree,nodi);


    return 0;
}

int mincover (priority_queue <pair<int,int>,std::vector<pair<int,int>>, Compare> &pq, vector <int> &grades, vector <node> &tree, int nodi) {
    
    int count = 0;
    while (!pq.empty()) {
        //cout << "ciaooo" << endl;
        pair<int,int> temp = pq.top();
        if (grades[temp.second] == 0) {
            //cout << "ciaone1" << endl;
        }
        else {
            //cout << "grades["<< temp.second << "] = " << grades[temp.second] << endl;
            ++count;
            pq.pop();
            vector <int> vicini = tree[temp.second].adj;
            for (int i = 0; i < vicini.size(); i++) {
                //cout << "vicini[i] = " << vicini[i] << endl; 
                --grades[vicini[i]];
                --grades[temp.second];
            }
            pq = priority_queue <pair<int,int>,std::vector<pair<int,int>>, Compare> ();
            for (int i = 0; i < nodi; i++) {
                if (grades[i] > 0) {
                    //cout << "i = " << i << endl;
                    //cout << "grades1["<< i << "] = " << grades[i] << endl;
                    pq.push(make_pair(grades[i],i)); //O(logn)
                }
            } // O(nlogn)
        }
    }
    return count;
}