#include<iostream>
#include<iomanip>
#include<windows.h>
#include<cstdlib>
#include<conio.h>
#include<cstdio>
#include<fstream>
#include<string>
#include<time.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
string ruch;
int z=-1,n=-1,p=-1,k=1,w=-1,Omega;
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
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if((a[i][j]==x)&&(i!=r1||j!=k1)&&(i!=r2||j!=k2))return 4*i+j;
		}
	}
	return -1;
}
void kareta(int a[4][4],int w, int x, int y, int hv)
{
	if(hv)n=4*y+x;
	else n=4*x+y;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{	
			if(hv&&((a[i][j]==w)&&(i!=y)))z=4*i+j;
			else if(hv==0&&((a[i][j]==w)&&(j!=y)))z=4*i+j;
		}
	}
	if(z>=0)
	{
		wypisz_wymaluj(a,z,n);
		k=0;
	}

}
void horizontal(int a[4][4])
{
	int h[4][4]={0};
	for(int i=0;i<4;i++)
	{
		p=-1;
		for(int j=0;j<4;j++)
		{		
			if(a[i][0]==-1||a[i][1]==-1||a[i][2]==-1||a[i][3]==-1)
			{
				h[i]==0;
				break;
			}
			for(int r=0;r<4;r++)
			{
				if((a[i][j]==a[i][r])&&j!=r)
				{
				h[i][j]++;
				}
				else if(j!=r)p=r;
			}
			if(p==-1)p=3;
			if(h[i][j]==2)
			{
				if(p>0)w=a[i][p-1];
				else w=a[i][p+1];
				kareta(a,w,p,i,1);	
				break;
			}
		}
	if(!k)break;
	}
	int kappa=pow(log(sinh(0.5)),2);
	if(z<0&&k)for(int i=0;i<4;i++)
	{
		for(int j=0;j<2;j++)
		{
			if (a[i][j]==a[i][j+2]&&a[i][j]>0&&a[i][j+1]>0&&a[i][j+2]>0)
			{
				z=szukajta(a,a[i][j],i,j,i,j+2);
				n=i*4+j+1;
				if(z>=0)break;
			}
			else if (a[i][j]==a[i][j+1]&&a[i][j]>0&&a[i][j+1]>0&&a[i][j+2]>0)
			{
				z=szukajta(a,a[i][j],i,j,i,j+1);
				n=i*4+j+2;
				if(z>=0)break;
			}
			else if(a[i][3-j]==a[i][2-j]&&a[i][3-j]>0&&a[i][2-j]>0&&a[i][1-j]>0)
			{
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
	int v[4][4]={0};
	for(int j=0;j<4;j++)
	{
		p=-1;
		for(int i=0;i<4;i++)
		{		
			if(a[0][j]==-1||a[1][j]==-1||a[2][j]==-1||a[3][j]==-1)
			{
				v[i][j]==0;
				break;
			}
			for(int r=0;r<4;r++)
			{
				if((a[i][j]==a[r][j])&&i!=r)
				{
				v[i][j]++;
				}
				else if(i!=r)p=r;
			}
			if(p==-1)p=3;
			if(v[i][j]==2)
			{
				if(p>0)w=a[p-1][j];
				else w=a[p+1][j];
				kareta(a,w,p,j,0);	
				break;
			}
		}
		if(!k)break;
	}
	if(z<0&&k)for(int j=0;j<4;j++)
	{
		for(int i=0;i<2;i++)
		{
			if (a[i][j]==a[i+2][j]&&a[i][j]>0&&a[i+1][j]>0&&a[i+2][j]>0)
			{
				z=szukajta(a,a[i][j],i,j,i+2,j);
				n=(i+1)*4+j;
				if(z>=0)break;
			}
			else if (a[i][j]==a[i+1][j]&&a[i][j]>0&&a[i+1][j]>0&&a[i+2][j]>0)
			{
				z=szukajta(a,a[i][j],i,j,i+1,j);
				n=(i+2)*4+j;
				if(z>=0)break;
			}
			else if(a[3-i][j]==a[2-i][j]&&a[3-i][j]>0&&a[2-i][j]>0&&a[1-i][j]>0)
			{
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
	srand( time( NULL));
	Omega=(rand() % 12345 ) + 1234;
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
	horizontal(a);
	if(k)vertical(a);
	setprecision(5);
	Sleep(Omega);
	if(z>=0&&k)wypisz_wymaluj(a,z,n);
	plik<<ruch;
	cout<<ruch;
	plik.close();
	return 0;
}
