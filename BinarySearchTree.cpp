#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *pleft;
    node *pright;
};

typedef struct node NODE;
typedef NODE* TREE;

//Khoi tao cay
void KhoiTaoCay(TREE &t){
    t = NULL;//cay rong
}

//ham them phan tu x vao cay nhi phan
void Insert(TREE &t,int x){//khai bao TREE &t tuc la dang cho t tham chieu den 1 con tro kieu node
    //neu cay rong
    if( t == NULL)
    {
        NODE *a = new NODE;//Khoi tao 1 node de them vao cay
        a->data = x;
        a->pleft = NULL;
        a->pright = NULL;
        t = a;//node p chinh la node goc
    }
    else //cay co ton tai phan tu
    {
        //neu phan tu them vao ma nho hon node goc ==> them vao cay con trai cua node goc
        if(t->data > x)
        {
            Insert(t->pleft,x);
        }
        else if(t->data < x){
            Insert(t->pright,x);
        }
    }
}

//Duyet cay nhi phan theo NLR tho thu  tu truoc
void NLR(TREE t)
{
    //neu cay con phan tu thi tiep tuc duyet
    if(t != NULL){
        cout << t->data << " ";//xaut du lieu trong node
        NLR(t->pleft);
        NLR(t->pright);
    }
}
//duyet cay nhi phan theo tt giua LNR
void LNR(TREE t){
    if(t != NULL)
    {
        LNR(t->pleft);
        cout << t->data << " ";//xuat gia tri cua node
        LNR(t->pright);
    }
}

//duyet cay nhi phan theo thu tu sau LRN
void LRN(TREE t){
    if(t != NULL)
    {
        LRN(t->pleft);
        LRN(t->pright);
        cout << t->data << " ";
    }
}
void DiTimNodeTheMang(TREE &X,TREE &Y){//X la phan tu can xoa //Y la cay con phai cua X
    //dueyt sang node trai nhat cua cay con phai
    if(Y->pleft != NULL)
    {
        DiTimNodeTheMang(X,Y->pleft); //duyet tiep sang ben trai
    }else{//tim ra duoc node trai nhat
         X->data = Y->data;//cap nhat data cua node can xoa chinh la data cua node the mang
         X = Y;//cho node X tro den node the mang ==> sau nay xoa node X
         Y = Y->pright;//Tro den NULL
    }
}
//ham xoa node bat ki trong cay nhi phan tim kiem
void XoaNode(TREE &t,int data){
    if(t == NULL){
        return;
    }
    else{
       //neu node xoa nho hon node goc 
       if(data < t->data)
       {
        XoaNode(t->pleft,data);
       }
       else if( data > t->data)
       {
        XoaNode(t->pright,data);
       }
       else{ //data == t-> data
            NODE *X = t;//NODE the mang dung de xoa
            //neu nhu nhanh trai bang NULL => cay con phai
            if(t->pleft == NULL){
                t = t->pright;//duyet sang phai node can xoa
            }
            else if(t ->pright == NULL)
            {
                t = t->pleft;//duyet sang trai cua node can xoa
            }
             else{//xoa node co 2 con
                //Cach 1:Tim node trai nhat cua cay con phai (cua node can xoa)
                NODE *Y = t ->pright;//node the mang cho node can xoa 
                DiTimNodeTheMang(X,Y);
             }
            delete X;
       }
    }
}
int main()
{

}