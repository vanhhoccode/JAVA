#include<bits/stdc++.h>

using namespace std;


//1:Xay dung 1 Node
//Con tro luu du lieu cua 1 bien khac ma no tro den
struct Node
{
    int data;
    Node *prv,*nxt;
    
    Node(int _data){
        data = _data;
        prv = NULL;
        nxt = NULL;
    }
};
//Them node vao vi tri dau
struct Linkerlist{
    Node *head;
    int sz = 0;
    void addNewNode(int pos, int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            sz++;
            return;
        }
      //Them vao vi tri dau tien
        if(pos == 1){
            head->prv = newNode;
            newNode->nxt = head;
            head = newNode;
            sz++;
            return;
        }
        //Them vao sau vi tri cuoi
        if(pos == sz + 1)  
        {
            Node *tmp = head;
            while(tmp->nxt != NULL) tmp = tmp->nxt;
            //Tmp luc nay dang la phan tu cuoi cung
            newNode->prv = tmp;
            tmp->nxt = newNode;
            sz++;
            return;
        }
        //Them vao vi tri xac dinh
        int count = 1;
        Node* temp = head;
        // Node temp sau thao tác này chính là node ở vị trí thứ pos
        while(count < pos){
            //Duyet qua danh sach lien ket den khi nao tim duoc nut can them
            temp = temp->nxt;
            count++;
        }

        newNode->nxt = temp;//dang can chen vao vi tri thu 5
        newNode->prv = temp->prv;//tro den vi tri truoc vi tri thu 5
        newNode->prv->nxt = newNode;//cho node t4 tro den new node
        temp->prv = newNode;//luc nay lai cho tmp la node dung sau new node tro den new node
        sz++;

        }
     void deleteNode(int pos){
        Node* temp = head;
        //Th chi co 1 node trong ds 
        if(sz == 1){
            head = NULL;
            sz--;
            return;
        }
        int count = 1;
        // Node temp sau thao tác này chính là node ở vị trí thứ pos
        while(count < pos){
            temp = temp->nxt;
            count++;
        }

        if(pos == 1){ // Xoá bỏ node đầu
            temp->nxt->prv = NULL;
            head = temp->nxt;
            sz--;
            return;
        }

        if(pos == sz){ // Xoá bỏ node cuối
            temp->prv->nxt = NULL;
            sz--;
            return;
        }

        temp->prv->nxt = temp->nxt;
        temp->nxt->prv = temp->prv;
        sz--;
    }

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->nxt;
        }
    }
} LinkedList;

int main(){
    LinkedList.addNewNode(1, 3); 
    // [3]
    LinkedList.addNewNode(2, 5);
    // [3, 5]
    LinkedList.addNewNode(2, 7);
    // [3, 7, 5]
    LinkedList.print();
    LinkedList.deleteNode(2);
    // [3, 5]
    LinkedList.print();
    LinkedList.deleteNode(2);
    // [3]
    LinkedList.print();
    LinkedList.deleteNode(1);
    // []
    LinkedList.print();

    return 0;
}
