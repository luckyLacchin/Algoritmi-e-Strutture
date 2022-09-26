#include <iostream> 
#include <fstream>
#include <vector> 
#include <cstdlib> 
#include <ctime>

using namespace std; 

struct tr {
    char direzione;
    int pos;
}; 

int main () {
    ifstream in ("input.txt"); 
    ofstream output ("output.txt"); 
    int n; 
    in >> n; 
    if (n%2!=0) {
        srand((unsigned)time(0)); 
        vector <tr*> list;
        char tmp;
        int i; 
        tr *tra;
        for (int i = 0; i < n; i++) {
            in >> tmp;
            tra = new tr; 
            tra->direzione = tmp; 
            tra->pos = i;
            list.push_back(tra); 
        } 

        while (list.size() > 2) {
            cout << "size = " << list.size() << endl; 
            for (int i = 0; i < list.size();i++) {
                cout << list.at(i) -> direzione;
            }
            cout << endl; 

            for (int i = 0; i < list.size();i++) {
                cout << list.at(i) -> pos;
            }
            cout << endl; 

            tr *remove; 
            do {
                //cout << "ciao3" << endl;
                i = (rand()%list.size()); 
                remove = list.at(i); 
            }while ((remove == list.front()) || (remove == list.back()));
            cout << "posizione = " << remove->pos << endl;
            list.erase(list.begin()+i);
            
            for (int i = 0; i < list.size();i++) {
                cout << list.at(i) -> direzione;
            }
            cout << endl; 

            for (int i = 0; i < list.size();i++) {
                cout << list.at(i) -> pos;
            }
            cout << endl; 
            
            
            if (remove->direzione == 's') {
                if (remove != list.front()) {
                    list.erase(list.begin()+i -1);
                }
                else {
                    list.erase(list.end()); 
                }
                
            }
            else {
                if(remove != list.back()) {
                    list.erase(list.begin()+i); 
                }
                else {
                    list.erase(list.begin()); 
                }
            }
            for (int i = 0; i < list.size();i++) {
                cout << list.at(i) -> pos;
            }
            cout << endl; 
            //cout << "ciao6" << endl; 
        }
    
        cout << "size = " << list.size() << endl; 
        output << list.size()<<endl; 
        for (int i = 0; i < list.size();i++){
            tra = list.at(i); 
            cout << tra -> pos << " "; 
            output << tra -> pos << " "; 
        }
        
        
    }
    else {
        cout << "Bisogna inserire un numero dispari di triangoli" << endl; 
    }

    in.close(); 
    output.close(); 

}