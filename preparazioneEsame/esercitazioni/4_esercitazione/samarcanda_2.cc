#include <iostream>
#include <vector>

using namespace std;

int samarcanda (vector <int> s);
pair<int,pair<int,int>> samarcanda_aux  (vector <int> s, int first, int last);

int main () {

    vector <int> s;
    s.push_back(10);
    s.push_back(3);
    s.push_back(11);
    s.push_back(4);
    s.push_back(12);
    s.push_back(15);
    int diffHere = 0, start = 0; 
    pair<int,pair<int,int>> maxSoFar;
    if (s.size() >= 1) {
        for (int i = 1; i < s.size(); i++) {
            diffHere = s[i] - s[start];
            if (diffHere < 0)
                start = i;
            else if (diffHere > maxSoFar.first) {
                maxSoFar.first = diffHere;
                maxSoFar.second.first = start+1;
                maxSoFar.second.second = i+1;
            }

        } 
        cout << "Il guadagno massimo e': " << maxSoFar.first << ", comprando la merce il giorno " << maxSoFar.second.first << " e vendendola il giorno " << maxSoFar.second.second << endl;
    }
    else
        cout << "Vettore vuoto o con solo un elemento, non può esserci differenza e guadagno" << endl; 
    cout << "Il guadagno massimo e': " << samarcanda (s) << endl;
    return 0;
}

int samarcanda (vector <int> s) { 
    return samarcanda_aux(s,0,s.size()-1).first;
}

pair<int,pair<int,int>> samarcanda_aux (vector <int> s, int first, int last) {

    if (first >= last) {
        return make_pair(0,(make_pair(s[first],s[first])));
    }
    else {
        int m = (first + last) / 2;
        pair<int,pair<int,int>> left = samarcanda_aux (s,first,m);
        pair<int,pair<int,int>> right = samarcanda_aux (s,m+1,last);
        int maxCross = right.second.second - left.second.first;
        if (maxCross > right.first && maxCross > left.first) {
            return make_pair (maxCross,make_pair(left.second.first,right.second.second));
        }
        else if (left.first > right.first) {
            return make_pair (left.first,make_pair(left.second.first,left.second.second));
        }
        else if (left.first < right.first)
            return make_pair (right.first,make_pair(right.second.first,right.second.second));
        else {
            if (right.second.second < left.second.first)
                return make_pair(right.first,make_pair(right.second.second,INT32_MIN));
            else 
                return make_pair(left.first,make_pair(left.second.first,left.second.second));

        }
    }

}
