#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int sottoseq (vector <char> &buffer, char s[],int size_s);
int sottoseq_aux (vector <char> &buffer, char s[], vector <int> &DP, int i, int j);

int main () {

    ifstream in ("input.txt");
    vector <char> buffer;
    char temp;
    while (in >> temp) {
        buffer.push_back(temp); 
    }
    char seq [] = "dog";
    cout << "Il numero di sottosequenze e': " << sottoseq (buffer,seq,3) << endl;

    return 0;
}

int sottoseq (vector <char> &buffer, char s[],int size_s) {

    vector <int> DP;
    DP.resize(buffer.size(),-1);
    sottoseq_aux (buffer,s,DP,buffer.size()-1,size_s-1);
    for (int i = 0; i < buffer.size(); i++) {
        cout << DP[i] << " ";
    }
    return DP[buffer.size()-1];

}

int sottoseq_aux (vector <char> &buffer, char s[], vector <int> &DP, int i, int j) {

    if (i >= 0 && j >= 0) {
        if (DP[i] < 0) {
            if(buffer[i] == s[j]) {
                if (j == 0) {
                    cout << "trovato!" << endl;
                    DP[i] = 1;
                }
                else {
                    DP[i] = sottoseq_aux(buffer,s,DP,i-1,j-1) + sottoseq_aux(buffer,s,DP,i-1,j);
                }
            }
            else {
                DP[i] = sottoseq_aux(buffer,s,DP,i-1,j);
            }
        }
        return DP[i];
    }
    else
        return 0;

}