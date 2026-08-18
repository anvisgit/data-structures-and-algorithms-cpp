#include <iostream>
#include <queue>
#include<algorithm>
using namespace std;

struct node{
  char ch;
  int freq;
  int *left,*right;
  node(char c, int f){
    ch=c;
    freq=f;
    left=right=NULL;
  }
};

struct compare{
  bool operator()(node *a,node *b){
    return a->freq>b->freq;
  }
};

void printcodes(node * root, string code){
  if(root==NULL)
    return;
  if(root->left==NULL && root->right ==NULL){
    cout<<root->ch<< " : "<<code<<endl;
    return;}
  printcodes(root->left, code + "0");
  printcodes(root->right, code+"1");    
}
int main(){
  int n;
  cout<<"enter number of characters: ";
  cin>>n;
  priority_queue<node*, vector<node*>, compare> pq;
  cout << "Enter character and frequency:"<<endl;
  for(int i=0;i<n;i++){
    char ch;
    int freq;
    cin>>ch>>freq;
    pq.push(new node(ch,freq));
      
    while (pq.size() > 1) {

        node* a = pq.top();
        pq.pop();

        node* b = pq.top();
        pq.pop();

        Node* parent = new Node('$', a->freq + b->freq);

        parent->left = a;
        parent->right = b;

        pq.push(parent);
    }


  }
}
