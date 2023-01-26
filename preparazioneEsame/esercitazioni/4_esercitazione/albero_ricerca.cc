#include <iostream>
#include <vector>

using namespace std;

struct tree {

    int value;
    tree *left;
    tree *right;
};

void mergeSort (vector<int> &vec, int first, int last);
void merge (vector <int> &vec, int first, int mid, int last);
tree *buildTree (vector <int> &s, int first, int last);
void printTree (tree *t); 


int main () {

    vector <int> s;
    s.push_back(10);
    s.push_back(3);
    s.push_back(11);
    //s.push_back(6);
    s.push_back(4);
    s.push_back(12);
    s.push_back(15);
    mergeSort(s,0,s.size()-1);
    tree *t = buildTree (s,0,s.size()-1);
    printTree (t);

    return 0;
}

void mergeSort (vector<int> &vec, int first, int last) {
    
    int mid = (last + first) / 2;
    if (first < last) {
        mergeSort (vec,first,mid);
        mergeSort (vec,mid+1,last);
        merge (vec,first,mid,last);
    }

}

void merge (vector <int> &vec, int first, int mid, int last) {

    vector <int> b;
    int i = first, j = mid+1, index = first;
    while ((i <= mid) || (j <= last)) {
        if ((i <= mid) && (j <= last)) {
            if (vec[i]<=vec[j]) {
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
    
    for (int i : b) {
        vec[index] = i;
        ++index;
    }
}

void printTree (tree *t) {

    if (t!= NULL) {
        printTree(t->left);
        cout << t -> value << " ";
        printTree(t->right);
    }
}

tree *buildTree (vector <int> &s, int first, int last) {

    
    if (first >= last) {
        tree *t = new tree();
        cout << "s[first] = " << s[first] << endl;
        t -> value = s[first];
        t -> left = NULL;
        t -> right = NULL;
        return t;
    }else {
        //tree *t = new tree();
        int m = (last + first) / 2;
        cout << "s[m] = " << s[m] << endl;
        //t -> value = s[m];
        //t -> left = buildTree (s,first,m-1);
        //t -> right = buildTree (s,m+1,last);
        tree *tleft = buildTree (s,first,m-1);
        tree *tright = buildTree (s,m+1,last);
        tree *t = new tree ();
        t -> value = s[m];
        if (tleft -> value != t -> value)
            t -> left = tleft;
        if (tright-> value != t -> value)
            t -> right = tright;
        return t;
    }
}