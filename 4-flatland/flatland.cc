#include <iostream> 
#include <fstream>
#include <vector> 
#include <cstdlib> 
#include <ctime>
#include<algorithm>

using namespace std; 

struct tr {
    char direzione;
    int pos;
}; 
bool contained(vector<int> vec, int elem);


int main () {
    
    ofstream output ("output.txt"); 
    int n;
    int index = 0;  
    ifstream in ("input.txt"); 
    in >> n;
    srand(time(NULL));
    if (n%2!=0) {
        vector <int> sol;
        while (index < 100) { 
            vector <tr*> list;  
            char tmp;
            tr *tra;
            for (int i = 0; i < n; i++) {
                in >> tmp;
                tra = new tr; 
                tra->direzione = tmp; 
                tra->pos = i;
                list.push_back(tra); 
            } 
            while (list.size() > 1) {       
                int i; 
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
            }
            
            for (int i = 0; i < list.size();i++) {
                    cout << list.at(i) -> pos;
                }
                cout << endl; 

            if (!contained(sol,list.at(0)->pos)) {
                sol.push_back(list.at(0)->pos); 
            }  
            ++index;
            in.close(); 
            in.open ("input.txt"); 
            in >> n;
        } 
        output << sol.size() << endl;
        for (int i = 0; i < sol.size(); i++) {
            output << sol.at(i)<< " ";
        }
    }
    else {
        cout << "Bisogna inserire un numero dispari di triangoli" << endl; 
    }
    
    output.close(); 

}

bool contained(vector<int> vec, int elem)
{
    bool result = false;
    for (int i = 0; i < vec.size() && !result; i++) {
        if (vec.at(i) == elem)
            result = true;
    }
    return result;
}