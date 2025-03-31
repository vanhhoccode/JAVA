#include<bits/stdc++.h>

using namespace std;

int uT(char c){
    if( c == '(') return 0;
    if( c == '+' || c == '-') return 1;
    if( c == '*' || c == '*') return 2;
    if( c == '^') return 3;
}

void hauTo(){
    stack<char> s;
    int i = 0;
    string str,str1 = "";
    getline(cin ,str);
    while(i < str.length()){
        char c = str.at(i);
        if( c != ' '){
            if( c - '0' >= 0 && c - '0' <= 9 || isalpha(c)) str1 += c;//ktra xem phan tu la chu hay so thi them no vao str1
            else{
                cout << str1 << " ";
                str1 = "";
                if( c == '(') s.push(c);//phan tu la dau mo ngoac day no vao stack
                else{
                    if( c == ')'){//neu phan tu la dau dong ngoac
                        while( s.top() != '('){//lay tat ca cac phan tu tu stack cho den khi gap dau mow ngoac
                            cout << s.top();
                            s.pop();
                        }
                        s.pop();//xoa di dau mo ngoac
                    }
                    else{
                        while( !s.empty() && uT(c) <= uT(s.top())){//Toan tu trong stack co do uu tien lon hon toan tu hien tai
                            cout << s.top();//lay no ra khoi stack
                            s.pop();
                        }
                        s.push(c); //luc nay khong con toan tu nao co do uu tien cao hon c nua nen push c vao stack
                    }
                }
            }
        }  
        i++;
    }
    if( str1 != "") cout << str1 << " ";
    //in not nhung gi con lai trong stack
    //str1 dung de luu toan hang
    //str dung de nhap chuoi ban dau
    //stack s dung de luu cac toan tu va dau ngoac
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
}


int main(){
    hauTo();
    return 0;
}