#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *next;
};
Node* head = NULL;
Node* tail = NULL;
void Enqueue(int data){//chen them 1 phan tu vao tail cua Node
    Node *p = new Node();//tao ra node moi
    p->data = data;
    p->next = NULL;
	if(head == NULL && tail == NULL){//truong hop Queue rong
		head = tail = p;//cho ca head va tail deu tro vao temp
		return;
	}
	//truong hop con lai, cho tail->next tro de temp va set temp la tail moi cua Queue
	tail->next = p;
	tail = p;
};
void Dequeue(){//xoa phan tu tai head cua Node
	if(head == NULL && tail == NULL){
		cout<<"Queue is empty"<<endl;//truong hop Queue rong
	}else if(head == tail && head != NULL){//truong hop Queue co duy nhat 1 ptu
		Node *temp = head;//tao ra Node temp tro vao head
		head = tail = NULL;//set head va tail NULL(queue rong)
		delete temp;//xoa temp ra khoi bo nho
	}else{//truong hop Queue co 2 phan tu tro len
		Node *temp = head;
		head = head->next;//cho head tro den phan tu ke tiep
		delete temp;//xoa temp ra khoi bo nho
	}
};
int Peek(){
	if(head == NULL) return 0;//tra ve 0 neu Queue rong
	else return head->data;//tra ve phan tu dau Queue
};
void Print(){
	Node* temp = head;//tao ra 1 con tro temp de duyet
	while(temp!= NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
};
int main(){
	Enqueue(3);
	Enqueue(7);
	Enqueue(11);
	Enqueue(22);
	Print();
	Dequeue();
	Enqueue(15);
	Print();
	return 0;
}

