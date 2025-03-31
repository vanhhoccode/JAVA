#include<bits/stdc++.h>

using namespace std;

stack<int> s;
float tinhHauTo(){
    string str;
    int i = 0;
    getline(cin,str);
    while(i < str.length()){
        char c = str.at(i);
        if(c != ' '){
            if( c - '0' >= 0 && c - '0' <= 9) s.push(c);
        }
        else if()
    }

}