#include<bits/stdc++.h>


using namespace std;

class DT{
	private:
		int n,a[10];
	public:
		DT()
		{
			n = 0;
			a[n] = {0}; 
		}
		DT(int c,int b[10])
		{
			n = c;
			for(int i = 0;i < c;i++){
				a[i] = b[i];
			}
		 }
		 ~DT()
		 {
		 	n = 0;
		 	a[n] = 0;
		  } 
		void NhapDT();
		void XuatDT();
		DT Tong(DT dt2);
		DT Hieu(DT dt2);	
};

void DT::NhapDT()
{
	cout << "\nNhap bac cua da thuc : ";
	cin >> n;
	cout << "\nnhap he so cua da thuc : ";
	for(int i = 0;i <= n ;i++){
		cout << "\na[" << i << "] = ";
		cin >> a[i];
	}
}

void DT::XuatDT()
{
	cout << a[n] << "x^" << n;
	for(int i = n - 1;i >= 1;i--)
	{
		if(a[i] > 0)
			cout << "+" << a[i] << "x^" << i;
		else if (a[i] < 0)
			cout << a[i] << "x^" << i;	
	}
	if(a[0] >= 0)
		cout << "+" << a[0] << endl;
	else
		cout << a[0] << endl;	
};
DT DT::Hieu(DT dt2)
{
	DT t;
	if(n >= dt2.n)
	{
		t.n = n;
		for(int i = 0; i <= dt2.n;i++)
		{
			t.a[i] = a[i] - dt2.a[i];
		}
		for(int i = dt2.n + 1 ;i <= n;i++)
			t.a[i] = a[i];
	}
	else if(n < dt2.n)
	{
		t.n = dt2.n;
		for(int i = 0; i <= n;i++)
		{
			t.a[i] = a[i] - dt2.a[i];
		}
		for(int i = n + 1 ;i <= dt2.n;i++)
		if(dt2.a[i] > 0)
			t.a[i] = dt2.a[i];
		else
			t.a[i] = (-1)*dt2.a[i];	
	}
	return t;
};



DT DT::Tong(DT dt2)
{
	DT t;
	if(n >= dt2.n)
	{
		t.n = n;
		for(int i = 0; i <= dt2.n;i++)
		{
			t.a[i] = a[i] + dt2.a[i];
		}
		for(int i = dt2.n + 1 ;i <= n;i++)
			t.a[i] = a[i];
	}
	else if(n < dt2.n)
	{
		t.n = dt2.n;
		for(int i = 0; i <= n;i++)
		{
			t.a[i] = a[i] + dt2.a[i];
		}
		for(int i = n + 1 ;i <= dt2.n;i++)
			t.a[i] = dt2.a[i];
	}
	return t;
};


int main(){
	DT dt1,dt2,t;
	cout << "nhap da thuc 1 :"; dt1.NhapDT();
	cout << "nhap da thuc 2 :"; dt2.NhapDT();
	cout << "da thuc 1 = 	" ; dt1.XuatDT(); cout << endl;
	cout << "da thuc 2 = 	" ; dt2.XuatDT(); cout << endl;
	cout << "tong 2 da thuc :"; dt1.Tong(dt2).XuatDT();	
	return 0;
}
