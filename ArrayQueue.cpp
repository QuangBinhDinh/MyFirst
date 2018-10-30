#include<iostream>
#include<stdlib.h>
using namespace std;
//Note: cach Enqueue va Dequeue duoi day su dung theo phuong thuc them du lieu vao vong tron (tuc la head va tail co the ket noi voi nhau duoc)
class Queue1{
	private:
		int *a, length;
		int head,tail;//2 moc trong queue
		//du lieu se duoc insert vao tail va se duoc lay ra tai head
	public:
		Queue1(int n){
			length = n;
			a = new int[length-1];//tao ra 1 Queue co so phan tu la length
			head = tail = -1;//mac dinh index cua head va tail la -1(Queue dang rong)
		}
		void Enqueue(int n){//them du lieu vao tail Queue
			if(head == -1 && tail == -1){
				++head; ++tail;
				a[tail] = n;
			}else if(tail > 99){
				cout<<"Queue is full !!!"<<endl;
			}else{
				tail = (tail +1)% length;//tra ve so du cua phep chia(lam cho gia tri cua tail luon trong khoang 0 -> length-1)
				a[tail] = n;
			}
		}
		void Dequeue(){//xoa du lieu voa head Queue
			if(head == -1 && tail == -1){
				cout<<"Queue is empty !!!"<<endl;//truong hop Queue rong
			}else if(head == tail && head != -1){
				head == tail == -1;//truong hop Queue chi co duy nhat 1 phan tu (head cung la tail cua Queue)
			}else {
				head = (head + 1)% length;//lam cho gia tri cua head luon trong khoang 0 -> (length-1)
			}
		}
		void Print(){
			int i,count, index;
			count = Count();
			for(i = 0; i< count ; i++){//in cac phan tu trong Queue
			    index = (head + i)%length;//index moi chinh la chi so dich thuc cua cac phan tu trong Queue
				cout<<a[index]<<" ";
			}
			cout<<endl;
		}
		int Count(){
			return (tail + length - head)%length +1;//tim so phan tu trong Queue
	    }
		int Peek(){//tra ve phan tu dang la head cua Queue
			return a[head];
		}
};
int main(){
	Queue1 q(10);
	q.Enqueue(10);
	q.Enqueue(11);
	q.Enqueue(16);
	q.Print();
	q.Dequeue();
	
	q.Print();
	return 0;
}
