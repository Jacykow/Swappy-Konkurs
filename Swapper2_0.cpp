#include<iostream>
#include<fstream>
#include<string>
using namespace std;
string ruch;
int z=-1,n=-1;
void kafelki(int a[4][4])
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			{
				if(a[i][j]>0)cout<<" ";
				cout<<a[i][j]<<" ";
			}
			cout<<endl;	
	}
}
void wypisz_wymaluj(int a[4][4],int x, int y)
{
	for(int i=0;i<16;i++)
	{
		if(i==x||i==y)ruch+="x ";
		else ruch+="o ";
		if((i+1)%4==0)ruch+="\n";
	}
}
int szukajta (int a[4][4],int x, int r1, int k1, int r2, int k2)
{
	//cout<<r1<<" "<<k1<<" "<<r2<<" "<<k2<<"\n";
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if((a[i][j]==x)&&(i!=r1||j!=k1)&&(i!=r2||j!=k2))return 4*i+j;
		}
	}
	return -1;
}
void horizontal(int a[4][4])
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<2;j++)
		{
			if (a[i][j]==a[i][j+2]&&a[i][j]>0&&a[i][j+1]>0&&a[i][j+2]>0)
			{
				//cout<<"y1"<<endl;
				z=szukajta(a,a[i][j],i,j,i,j+2);
				n=i*4+j+1;
				if(z>=0)break;
			}
			else if (a[i][j]==a[i][j+1]&&a[i][j]>0&&a[i][j+1]>0&&a[i][j+2]>0)
			{
				//cout<<"y2"<<endl;
				z=szukajta(a,a[i][j],i,j,i,j+1);
				n=i*4+j+2;
				if(z>=0)break;
			}
			else if(a[i][3-j]==a[i][2-j]&&a[i][3-j]>0&&a[i][2-j]>0&&a[i][1-j]>0)
			{
				//cout<<a[i][3-j]<<" "<<a[i][2-j]<<" y3"<<endl;
				z=szukajta(a,a[i][3-j],i,3-j,i,2-j);
				n=i*4+1-j;
				if(z>=0)break;
			}
		}
		if(z>=0)break;
	}
}
void vertical(int a[4][4])
{
	for(int j=0;j<4;j++)
	{
		for(int i=0;i<2;i++)
		{
			if (a[i][j]==a[i+2][j]&&a[i][j]>0&&a[i+1][j]>0&&a[i+2][j]>0)
			{
				cout<<i<<" "<<j<<" "<<"y1"<<endl;
				z=szukajta(a,a[i][j],i,j,i+2,j);
				n=(i+1)*4+j;
				if(z>=0)break;
			}
			else if (a[i][j]==a[i+1][j]&&a[i][j]>0&&a[i+1][j]>0&&a[i+2][j]>0)
			{
				cout<<"y2"<<endl;
				z=szukajta(a,a[i][j],i,j,i+1,j);
				n=(i+2)*4+j;
				if(z>=0)break;
			}
			else if(a[3-i][j]==a[2-i][j]&&a[3-i][j]>0&&a[2-i][j]>0&&a[1-i][j]>0)
			{
				cout<<a[i][3-j]<<" "<<a[i][2-j]<<" y3"<<endl;
				z=szukajta(a,a[3-i][j],3-i,j,2-i,j);
				n=(1-i)*4+j;
				if(z>=0)break;
			}
		}
		if(z>=0)break;
	}
}
int main(){
	fstream plik;
	plik.open("plansza.txt",ios::in);
	int a[4][4];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			plik>>a[i][j];
		}
	}
	kafelki(a);
	plik.close();
	plik.open("ruch.txt",ios::out);
	//plik<<"x o o o\no o o o\no x o o\no o o o";
	horizontal(a);
	if(z<0)vertical(a);
	cout<<"z="<<z<<"\t n="<<n<<endl;
	if(z>=0)wypisz_wymaluj(a,z,n);
	plik<<ruch;
	cout<<ruch;
	plik.close();
	return 0;
}
