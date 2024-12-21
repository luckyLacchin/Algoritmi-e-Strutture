/*bfs(Tree t)
Queue Q = Queue()
Q.enqueue(t)
while not Q.isEmpty() do
Tree u = Q.dequeue()
% visita per livelli nodo u
print u
u = u.leftmostChild()
while u 6= nil do
Q.enqueue(u)
u = u.rightSibling()
*/
#include <queue>
#include <iostream>
#include <vector> 

using namespace std;


void controlloLivello (Node *node, int livello, int &count); 
void sbilanciamento (Node *root, int max);
int sumSubTree (Node *node, int sum);
// A Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};
 
// Iterative method to find height of Binary Tree
void printLevelOrder(Node* root)
{
    // Base Case
    int livello = 0;
    int count = 0; 
    if (root == NULL)
        return;
 
    // Create an empty queue for level order traversal
    queue<Node*> q;
 
    // Enqueue Root and initialize height
    q.push(root);
    controlloLivello (root, livello,count); 
    while (q.empty() == false) {
        // Print front of queue and remove it from queue
        Node* node = q.front();
        cout << node->data << " ";
        q.pop();
 
        /* Enqueue left child */
        if (node->left != NULL) {
            q.push(node->left);
            controlloLivello(node->left,livello+1,count); 
        }
 
        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
            controlloLivello(node->left,livello+1,count); 

    }
}//in questa dovrei implementare la coda come la ho implementata nel mio programma, in cui 
// mi sono dimenticato di mettere il caso base, vale a dire root == NULL, fin 
//dall'inizio!  

void controlloLivello (Node *node, int livello, int &count) {
    if (node->data == livello) {
        ++count; 
    }
}

void controlloAlbero (Node *root) {
    int max = 0; 
    int path = pathValue (root->left, 0); 
    int path1 = pathValue (root -> right, 0); 
}

int pathValue (Node *node, int max) {
    max += node -> data;
    if (node == NULL) {
        cout << "ciao" << endl; 
    }
    else {
        if ( (node -> left != NULL) && (node -> data < node -> left -> data))
            int res = pathValue(node->left, max);
        if ((node -> right != NULL) && (node -> data < node -> right -> data))
            int res1 = pathValue(node->right, max); 

    }

}



void sbilanciamento (Node *root,int max) {

    int sumLeft = sumSubTree (root->left,0); 
    int sumRight = sumSubTree (root -> right,0); 

} 

int sumSubTree (Node *node, int sum) {
    
}