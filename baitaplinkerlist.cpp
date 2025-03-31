#include<bits/stdc++.h>

using namespace std;
//Xay dung cau truc sinh vien
struct SinhVien{
    string ma,hoten;
    float gpa;
    char loaibang;
};
typedef struct SinhVien SV;

//tao cau truc cua danh sach lien ket don
struct Node
{
    SV *data;
    Node *pNext;
};

struct SingleList
{
    Node *pHead;
    Node *pTail;
};

//Khoi tao cho phead va ptail
void Initialize(SingleList *&list)
{
    list=new SingleList;
    list->pHead=list->pTail=NULL;
};

//Nhap du lieu cho sinh vien

SV *NhapSinhVien(){
    SV *sv = new SV;
    cout << "Nhap ma sinh vien:";
    cin >> sv->ma;
    cin.ignore();
    cout << "Nhap ho ten sinh vien:";
    cin >> sv->hoten;
    cout << "Nhap gpa";
    cin >> sv->gpa;
    return sv;
}

//Tao node sinh vien(Cap phat bo nho va gan du lieu va con tro next)
Node *CreateNode(SV *sv){
    Node *pNode = new Node;
    if(pNode != NULL)
    {
        pNode->data=sv;
        pNode->pNext=NULL;
    }
    else
    {
        cout << "Cap phat bo nho that bai!!!";
    }
    return pNode;
}

//Them node vao dau danh sach
void InsertFirst(SingleList *&list, SV *sv)
{
    Node *pNode=CreateNode(sv);
    if(list->pHead==NULL){//danh sach trong
        list->pHead=pNode;
        list->pTail=pNode;
    }
    else{
        pNode->pNext = list->pHead;
        list->pHead = pNode;    
    }
}

 //Ham Xep loai sinh vien
 void Xeploai(SingleList *list) { // Không cần tham chiếu & vì không thay đổi danh sách
    Node *current = list->pHead; // Sử dụng biến tạm để duyệt danh sách

    while (current != NULL) {
        if (current->data->gpa >= 9) {
            current->data->loaibang = 'G';
        } 
        else if (current->data->gpa > 8) { // Sửa điều kiện thành else if
            current->data->loaibang = 'K';
        } 
        else {
            current->data->loaibang = 'Y';
        }
        current = current->pNext; // Di chuyển đến node tiếp theo
    }
}

 //Ham hien thi thong tin sinh vien
 void hienthi(SingleList *list) {
    Node *current = list->pHead;
    while (current != NULL) {
        cout << "Ma sinh vien: " << current->data->ma << endl;
        cout << "Ho ten sinh vien: " << current->data->hoten << endl;
        cout << "GPA: " << current->data->gpa << endl;
        cout << "Xep loai: " << current->data->loaibang << endl;
        current = current->pNext;
    }
}

int main(){
    SingleList *list;
    Initialize(list);

    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin sinh vien " << i + 1 << ":\n";
        SinhVien *sv = NhapSinhVien();
        InsertFirst(list, sv);
    }
    Xeploai(list);
    hienthi(list);
    return 0;
}