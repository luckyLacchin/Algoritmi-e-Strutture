#include <iostream>
#include <fstream>
#include <vector>
#include <queue> 

using namespace std;

struct node {
    vector<int> adj;
    bool before_last = false;
};

class Compare {
    public:
        bool operator () (pair<node,pair<int,int>> a, pair<node,pair<int,int>> b) {
            if ((a.first.before_last == true) && (b.first.before_last == true))
                return a.second.first < b.second.first;
            else if (a.first.before_last == true && b.first.before_last == false)
                return false;
            else if (a.first.before_last == false && b.first.before_last == true)
                return true;
            else
                return a.second.first < b.second.first;
        }
};

int mincover (priority_queue <pair<node,pair<int,int>>,std::vector<pair<node,pair<int,int>>>, Compare> &pq, vector <int> &grades, vector <node> &tree, int nodi);

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
    priority_queue <pair<node,pair<int,int>>,std::vector<pair<node,pair<int,int>>>, Compare> pq;

    for (int i = 0; i < nodi; i++) {
        for (int v  : tree[i].adj) {
            if (grades[v] == 1)
                tree[i].before_last = true;
        }
    }
    
    for (int i = 0; i < nodi; i++) {
        pq.push(make_pair(tree[i],make_pair(grades[i],i)));
        //cout << "grades["<< i << "] = " << grades[i] << endl;
    } // O(nlogn)
    //cout << endl;
    out <<   mincover (pq,grades,tree,nodi);


    return 0;
}

int mincover (priority_queue <pair<node,pair<int,int>>,std::vector<pair<node,pair<int,int>>>, Compare> &pq, vector <int> &grades, vector <node> &tree, int nodi) {
    
    int count = 0;
    while (!pq.empty()) {
        //cout << "ciaooo" << endl;
        pair<node,pair<int,int>> temp = pq.top();
        //cout << "nodo = " << temp.second.second << endl;
        ++count;
        pq.pop();
        for (int i : temp.first.adj) {
            //cout << "i = " << i << endl; 
            --grades[i];
            --grades[temp.second.second];
        }
        pq = priority_queue <pair<node,pair<int,int>>,std::vector<pair<node,pair<int,int>>>, Compare> ();
        for (int i = 0; i < nodi; i++) {
            if (grades[i] > 0) {
                //cout << "i1 = " << i << endl;
                //cout << "grades1["<< i << "] = " << grades[i] << endl;
                //cout << "ciao" << endl;
                pq.push(make_pair(tree[i],make_pair(grades[i],i))); //O(logn)
            }// O(nlogn)
        }
    }
    return count;
}