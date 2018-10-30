#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *next;
};
Node* insertFirst(Node *head, int data){
	//insert du lieu vao dau list
	Node* temp = new Node();
	temp->data = data;
	if(head != NULL) temp->next = head;//neu list khong rong thi cho temp tro den head
	head = temp;//cho head tro lai den temp(dinh nghia head moi)
	//code nay cx dung voi truong hop head == NULL (gan luon cho temp)
	return head;
};
Node* insertLast(Node *head, int data){
	Node *p = new Node();//tao node moi
	p->data = data;
	p->next = NULL;
	if(head == NULL) head = p;//truong hop list rong
	else{//truong hop list khong rong
		Node *temp = head;//cho duyet list
		while(temp->next != NULL){
			temp = temp->next;
		}//sau vong lap temp dang tro den ptu cuoi list
		temp->next = p;//gan temp vao p
	}
	return head;
};
Node* reverseList(Node *head){
	Node *newList; newList = NULL;
	Node *temp = head;
	while(temp!= NULL){
		Node *p = new Node();
		p->data = temp->data;
		p->next = NULL;
		if(newList != NULL) p->next = newList;
		newList = p;
		temp = temp->next;
	}
	return newList;
};
Node* insert(Node *head, int data, int n){//chen node vao vi tri thu n trong list(n =1 ung voi chen vao vi tri dau list)
//ham nay tra ve linked list
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	int i;
	if(n == 1){
		temp->next = head;
		head = temp->next;
		return head;
	}
	Node* cont = head;//con tro de duyet node
	for(i = 0;i < n-2;i++){//vong lap thuc hien n-2 lan. Tuc la neu n la 3 thi vong lap dc thuc hien 1 lan (con tro cont tro den node ke tiep)
		cont = cont->next;
	}//sau vong lap cont dang tro den node thu n-1
	temp->next = cont->next;//cho node moi tro den con->next(con->next la node sau vi tri can chen)
	cont->next = temp;//cho con tro den chinh node moi
	return head;//return con tro dau list
};
Node* Delete(Node *head, int n){//xoa node o vi tri thu n trong list
    Node* cont = head;//con tro cont dung de duyet dang tro ve dau list
    if(n == 1){
    	head = cont->next;//cho head tro den phan tu cont->next
    	delete cont;//xoa phan tu dau tien
    	return head;//return ve head moi
	}
	int i;
	for(i = 0;i < n-2;i++){
		cont = cont->next;//sau vong lap cont se tra den Node thu n-1
	}
	Node* temp = cont->next;//cho temp tro den Node thu n( la node can xoa)
	cont->next = temp->next;//cho node thu n-1 tro den node thu n+1 (bo qua node temp)
	delete temp;//xoa node ra khoi list
	return head;
};
void printNode(Node *head){
	Node* temp = head;
	while(temp!= NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
};
int main(){
	Node *list = NULL;
	Node *newList = NULL;
	list = insertLast(list,14);
	list = insertLast(list,22);
	list = insertLast(list,31);
	list = insertLast(list,33);
	printNode(list);
	newList = reverseList(list);
	printNode(newList);
	return 0;
}
