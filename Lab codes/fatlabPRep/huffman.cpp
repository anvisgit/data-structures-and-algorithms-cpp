
#include<bits/stdc++.h>
using namespace std;

struct Node{
    char ch;
    int freq;
    Node *left,*right;
    Node(char c,int f){
        ch=c;
        freq=f;
        left=right=NULL;
    }
};

struct Compare{
    bool operator()(Node*a,Node*b){
        return a->freq>b->freq;
    }
};

Node* buildtree(char ch[],int fre[],int n){
    priority_queue<Node*,vector<Node*>,Compare> pq;
    for(int i=0;i<n;i++)
        pq.push(new Node(ch[i],fre[i]));

    while(pq.size()>1){
        Node*a=pq.top(); pq.pop();
        Node*b=pq.top(); pq.pop();
        Node*p=new Node('$',a->freq+b->freq);
        p->left=a;
        p->right=b;
        pq.push(p);
    }
    return pq.top();
}

void gencode(Node*root,string code=""){
    if(!root) return;
    if(!root->left&&!root->right){
        cout<<root->ch<<": "<<(code.empty()?"0":code)<<endl;
        return;
    }
    gencode(root->left,code+"0");
    gencode(root->right,code+"1");
}

int main(){
    int n;
    cin>>n;
    char ch[n];
    int fre[n];

    for(int i=0;i<n;i++)
        cin>>ch[i]>>fre[i];

    Node*root=buildtree(ch,fre,n);
    gencode(root);
    return 0;
}
