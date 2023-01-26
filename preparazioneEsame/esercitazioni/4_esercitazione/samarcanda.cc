#include <iostream>
#include <vector>

using namespace std;

int samarcanda (vector <int> s);
int samarcanda_aux (vector <int> s, int first, int last);

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
    return samarcanda_aux(s,0,s.size()-1);
}
/*
pair<int,int> samarcanda_aux (vector <int> s, int first, int last, int &maxSoFar) {

    int maxHere = 0, maxSoFarDx, maxSoFarSx;
    pair<int,int> dx;
    pair<int,int> sx;
    int m = (first + last) / 2;
    if (first < last)  {
        sx = samarcanda_aux (s,first,m,maxSoFarSx);
        dx = samarcanda_aux (s,m+1,last,maxSoFarDx);
        maxHere = dx.second-sx.first;
        cout << "dx.max = " << dx.second << endl;
        cout << "dx.min = " << dx.first << endl;
        cout << "sx.max = " << sx.second << endl;
        cout << "sx.min = " << sx.first << endl;
        cout << "maxSoFarSx = " << maxSoFarSx<< endl;
        cout << "maxSoFarDx = " << maxSoFarDx << endl;
        if (maxHere > maxSoFar) {
            //cout << "dx.max = " << dx.second << endl;
            //cout << "sx.min = " << sx.first << endl;
            maxSoFar = maxHere;
            return (make_pair(sx.first,dx.second));
        }
        else if (maxHere < 0) {
            maxSoFar = max(maxSoFarSx,maxSoFarDx);
            if (dx.second < sx.second) {
                return make_pair(min(dx.second,dx.first),min(dx.second,dx.first));
            }
            else {
                return make_pair(sx.first,sx.second);
            }
        }
        else {
            if (maxSoFarSx > maxSoFarDx)
                return make_pair (sx.first,sx.second);
            else
                return make_pair (dx.first,dx.second);
        }
    }
    else if (first == last) {
        cout << "s[m] = " << s[m] << endl;
        maxSoFar = 0;
        return (make_pair(s[m],s[m]));
    }

}
*/

//finiscilo dopo ma mi sa che mi son parecchio complicato la vita! la mia soluzione potrebbe essere addirittura 0(n). Devi gestire quando maxHere < 0 (metti come minore dx.second, controlla che sia minore a tutto), che coppia restituire e lasciare credo lo stesso maxSoFar. Invece se è maggiore di 0 ma è minore di MaxSoFar restituisce la coppia o dx o sx che ha il maxSoFar maggiore!

int samarcanda_aux (vector <int> s, int first, int last) {
    if (first >= last)
        return 0;
    int m = (last + first) / 2;
    int maxLeft = samarcanda_aux (s,first,m);
    int maxRight = samarcanda_aux (s,m+1,last);
    int ml = INT32_MAX, mr = INT32_MIN;
    for (int i = 0; i <= m; i++) {
        ml = min(ml,s[i]);
    }
    for (int i = m+1; i <= last; i++) {
        mr = max(mr,s[i]);
    }
    int maxCross = max (0,mr-ml);
    return max(maxLeft,max(maxRight,maxCross));
}