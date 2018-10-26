#include<iostream> 
#include<stdio.h>
#include<conio.h>

using namespace std;
const int Max = 30;
const int vocung = 63555;//gia tri lon nhat
int hang, cot;  double a[Max][Max];
/*************************************************************************/
void Tbdhinhg(int c[], int cs[], double b[]);
void Ktdvi(int cs[], int c[]);
void Delta1(double delta[], int c[], int cs[]);
int  Toiuu(double delta[]);
void Minteta(double b[], int &jo, int &io);
void Maxdelta(double delta[], int &io);
void Nhappa(double b[]);  void Nhapmt(int c[]);
void NhapMtran();
void Nhapcach(int cach[]);
void XuatMtran();
void Xuatpa(double b[]);
void Xuatcp(int c[]);
void Xuatcs(int cs[]);
void Xuatdelta(double delta[]);
void Xuatbang(double b[], int c[], int cs[]);
double f(double b[], int cs[]);
/*************************************************************************/
int main() {
	int c[Max], cs[Max];
	double b[Max];
	cout << "\n  ***   CHUONG TRINH THUAT TOAN DON HINH   ***";
	cout << "\n Nhap so hang = ";
	cin >> hang;
	cout << "\n Nhap so cot = ";
	cin >> cot;
	cout << "\n Nhap vao  ma tran cuoc phi A :";
	NhapMtran();
	XuatMtran();
	system("pause");
	cout << "\n Nhap vao cac he so cho ham muc tieu C";
	Nhapmt(c);
	cout << "\n Nhap vao cac phuong an B";
	Nhappa(b);
	cout << "\n Bang moi nhap ";
	Xuatpa(b);
	Ktdvi(c, cs);
	Xuatcs(cs);
	Xuatbang(b, c, cs);

	Tbdhinhg(c, cs, b);
	system("pause");
	return 0;
}
/*************************************************************************/
void Tbdhinhg(int c[], int cs[], double b[]) {
	int jo, io;  int i, j;
	double delta[Max], tam;;  int ktra, thu = 0; // ktdvi(cs); 
	do {
		Delta1(delta, c, cs);
		cout << "\n Gia tri cua delta la : \n";
		Xuatdelta(delta);
		system("pause");
		ktra = Toiuu(delta);
		if (ktra == 1) {
			cout << "\n Thuat toan ket thuc \n ";
			cout << "\n Bang don hinh cuoi \n  ";
			Xuatbang(b, c, cs);
			cout << "\n Gia tri ham muc tieu:" << f(b, cs) << "\n";
			system("pause");
		}
		else     if (ktra == -1) {
			cout << "\n Thuat toan khong co phuong an toi uu";
			cout << "\n  Bang ket thuc  ";
			Xuatbang(b, c, cs);
			cout << "\n Ham muc tieu:" << f(b, cs);
			system("pause");
			
		}
		else
		{
			thu++;
			Maxdelta(delta, jo);
			Minteta(b, jo, io);
			//doi coso;     
			cs[jo] = c[io];
			//tim phuong an moi  
			for (i = 1; i <= hang; i++)
				if (i != io)
					b[i] = (b[i] * a[io][jo] - a[i][jo] * b[io]) / a[io][jo];
			//bang moi;     
			for (i = 1; i <= hang; i++)
				if (i != io)
					for (j = 1; j <= cot; j++)
						if (j != jo)
						{
							a[i][j] = (a[i][j] * a[io][jo] - a[i][jo] * a[io][j]);
							if (a[i][j] == 0)
								a[i][j] = 0;//khong chia duoc  
							else
								a[i][j] = a[i][j] / a[io][jo];
						}   b[io] = b[io] / a[io][jo];
						// tinh tren cot chuan
						for (i = 1; i <= hang; i++)
							if (i != io)
								a[i][jo] = 0;
						//tinh tren hang chuan;   
						for (j = 1; j <= cot; j++)
							if (a[io][jo] != 0)
								a[io][j] = a[io][j] / a[io][jo];
						cout << "\n Bang thu  " << thu;
						Xuatbang(b, c, cs);
						cout << "\n";
		}
	} while (ktra != 1);
}
/*************************************************************************/
//   Ham tinh gia tri cua ham muc tieu 
double f(double b[],int cs[])  
{  
	int tam=0,t;  
	for(int i=1;i<=hang;i++)    
		tam+=cs[i]*b[i];   
	return tam;   }
/*************************************************************************/
// Thu tuc kiem tra ma tran don vi ung voi ma tran muc tieu
void Ktdvi(int c[],int cs[])  {  
	int i,j,k=1;   
	int kt1=0,kt2=0;  
	for(i=1;i<=cot;i++)  
		if((a[1][i]==1)&&(!kt1))   
		{   
			for(j=2;j<=hang;j++) 
				if((a[j][i]!=0)&&(!kt2)) 
					kt2=1;  
			if(kt2==0)    
			{
				kt1=1;
				cs[k]=c[i];   
			}  
			kt2=0;
		} 
	//Kiem tra cac cot ke tiep cua matran don vi 
	for(k=2;k<=hang;k++)   
		for(i=1;i<=cot;i++) 
			if(a[1][i]==0)   
			{   
				if((a[k][i]!=1)&&!kt2)  
					kt2=1;
				//neu dong ke tiep khong thoa matran don vi 
				if(kt2==0) 
	for (j = 1; j <= hang; j++)  
		if ((j != k) && (a[j][i] != 0) && (!kt2))  
			kt2 = 1;

		if (kt2 == 0) {
			cs[k] = c[i]; }  
		kt2 = 0;
}  
} 
/*************************************************************************/ 
void Delta1(double delta[], int c[], int cs[]) {
	int i, j, tam = 0; 
	for (j = 1; j <= hang; j++) 
	{
		tam = 0;      
		for (i = 1; i <= hang; i++)  
			tam += cs[i] * a[i][j]; 
		delta[j] = tam - c[j];
	} }
/*************************************************************************/ 
int Toiuu(double delta[]) {
	int i, j, ktra; 
	for (j = 1; j <= cot; j++)   
		if (delta[j] > 0) {

		for (i = 1; i <= hang; i++)  
			if (a[i][j] > 0)   
				ktra = 0;     // Tiep tuc giai bai toan
			else ktra=-1; //khong co phuong an toi uu 
		}    else ktra=1;//Bai toan ton tai phuong an toi uu  
	return ktra;  }
/*************************************************************************/
//  Thu tuc tim gia tri Max cua Delta 
void Maxdelta(double delta[],int &jo ) {  
	int i,Max;   
	jo=0;
	Max =delta[1];   
	for(int j=1;j<=cot;j++)   
		if(Max<delta[j])  { 
			Max=delta[j];  
			jo=j; 
		}   } 
/*************************************************************************/ 
//  Thu tuc tim gia tri min cua Delta 
void Minteta(double b[],int &jo,int &io )  { 
	int teta[Max],
		Min, i, j; 
	for (i = 1; i <= hang; i++)
		if (a[i][jo] > 0)  
			teta[i] = b[i] / a[i][jo];  
		else teta[i] = vocung;  
	Min = teta[1]; 
	io = 0; 
	for (i = 1; i <= hang; i++) 
		if (teta[i] != vocung)  
			if (teta[i] < Min) 
			{ 
				Min = teta[i]; 
				io = i;
			}
} /*************************************************************************/
void  Nhappa(double b[]) { 
	for (int i = 1; i <= cot; i++) {
		cout << "\n b[" << i << "]="; cin >> b[i]; } } 
/*************************************************************************/
//  Thu tuc nhap gia tri cho cac he so cua ham muc tieu
void  Nhapmt(int c[]) {  
	for(int i=1;i<=cot;i++)     { 
		cout<<"\n c["<<i<<"]=";cin>>c[i];   
	}   } 
/*************************************************************************/ 
//  Thu tuc nhap cac phuong trinh tuong ung voi ma tran
void  NhapMtran()    {   
	int i,j; 
	for(i=1;i<=hang;i++)   
		for(j=1;j<=cot;j++)
		{     
			cout<<"\n a["<<i<<"]["<<j<<"]=";   
			cin>>a[i][j]; 
		}    } 
/*************************************************************************/
void Nhapcach(int cach[])   {    
	for(int i=1;i<=cot;i++) 
cach[i] = i + 1;   } 
/*************************************************************************/
void XuatMtran() {
	int i, j; 
	for (i = 1; i <= hang; i++)
	{ 
		cout << "\n";  
		for (j = 1; j <= cot; j++)    
			cout << "\t " << a[i][j];
	} }
/*************************************************************************/ 
//  Ham xuat cac phuong an
void Xuatpa(double b[])     { 
	cout<<"\n ";    
	for(int i=1;i<=hang;i++)  
		cout<<"\n"<<b[i]; 
}
/*************************************************************************/ 

