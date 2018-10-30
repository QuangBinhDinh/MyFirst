#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *next;
};
Node* Push(Node *head,int data){
	Node *p = new Node();
	p->data = data;
	if(head != NULL) p->next = head;
	head = p;
	return head;
};
Node* Pop(Node *head){
	Node *temp = head;
	head = head->next;
	delete temp;
	return head;
};
void Top(Node *head){
	cout<<head->data<<endl;
};
int isEmpty(Node *head){
	if(head == NULL) return 0;
	else return 1;
};
void Print(Node *head){
	Node *cont = head;
	while(cont != NULL){
		cout<<cont->data<<" ";
		cont = cont->next;
	}
	cout<<endl;
};
int main(){
	Node *list = NULL;
	list = Push(list,11);
	list = Push(list,22);
	list = Push(list,33);
	Print(list);
	list = Pop(list);
	Print(list);
	return 0;
}
