#include<iostream>
#include<fstream>
#include<string>
using namespace std;
string ruch;
void kafelki(int a[])
{
	for(int i=1;i<=16;i++)
	{
		if(a[i]>0)cout<<" ";
		cout<<a[i]<<" ";
		if(i%4==0)cout<<endl;
	}
	cout<<endl;
}
void wypisz_wymaluj(int x, int y)
{
	//cout<<x<<" "<<y<<endl;
	for(int i=1;i<=16;i++)
	{
		if(i==x||i==y)ruch+="x ";
		else ruch+="o ";
		if(i%4==0)ruch+="\n";
	}
}
int szukajta (int a[],int x, int pw1, int pw2)
{
	for(int i=1;i<=16;i++)
	{
		if(a[i]==x&&i!=pw1&&i!=pw2) 
		{
			return i;
			break;
		}
	}
	return -1;
}
int main(){
	fstream plik;
	plik.open("plansza.txt",ios::in);
	int a[17];
		for(int i=1;i<=16;i++)
	{
		plik>>a[i];
	}
	kafelki(a);
	plik.close();
	plik.open("ruch.txt",ios::out);
	//plik<<"x o o o\no o o o\no x o o\no o o o";
	for(int k=0;k<=1;k++)//k=0 l->p v g->d, k=1 p->l v d->g 
	{
		for(int j=1;j<=2;j++) //j=1 (1-2-3) j=2 (2-3-4)
		{
			for(int i=0;i<16;i+=4)//i->rz¹d planszy numerowany od 0, ró¿nica pionowa pomiêdzy rzêdami wynosi 4
			{
				int h14=(2-j)*k*3+(j-1)*k+j+i;//j=1,k=1|j=2,k=1|j=1vj=2 k=0
				int h23=(2-j)*k+(j-1)*(-k)+(j+1)+i;
				int h32=(2-j)*(-k)+(j-1)*(-k)*3+(j+2)+i;
				int v14=(2-j)*k*12+(j-1)*k*4+(j-1)*3+j+i/4;//j=1,k=1|j=2,k=1|j=1vj=2 k=0
				int v23=(2-j)*k*4+(j-1)*k*(-4)+(j-1)*3+j+4+i/4;
				int v32=(2-j)*k*(-4)+(j-1)*k*(-12)+(j-1)*3+j+8+i/4;
				if((a[h14]==a[h23])&&a[h32]>0&&a[h14]>0&&a[h23]>0)
				{
					//cout<<h14<<" "<<h23<<endl;
					int z=szukajta(a,a[h14],h14,h23);
					if(z>0)
					{
						wypisz_wymaluj(h32,z);
						plik<<ruch;
						goto kuniec_dymbiec;
					}
				}
				if((a[h14]==a[h32])&&a[h32]>0&&a[h14]>0&&a[h23]>0)
				{
					//cout<<h14<<" "<<h23<<endl;
					int z=szukajta(a,a[h14],h14,h32);
					if(z>0)
					{
						wypisz_wymaluj(h23,z);
						plik<<ruch;
						goto kuniec_dymbiec;
					}
				}
				if((a[v14]==a[v23])&&a[v32]>0&&a[v14]>0&&a[v23]>0)
				{
					//cout<<h14<<" "<<h23<<endl;
					int z=szukajta(a,a[v14],v14,v23);
					if(z>0)
					{
						wypisz_wymaluj(v32,z);
						plik<<ruch;
						goto kuniec_dymbiec;
					}
				}
				if((a[v14]==a[v32])&&a[v32]>0&&a[v14]>0&&a[v23]>0)
				{
					//cout<<v14<<" "<<v32<<endl;
					int z=szukajta(a,a[v14],v14,v32);
						//cout<<z<<" "<<v23<<endl;
					if(z>0)
					{
						wypisz_wymaluj(v23,z);
						plik<<ruch;
						goto kuniec_dymbiec;
					}
				}
			}
		}
	}
	kuniec_dymbiec:
	cout<<ruch;
	plik.close();
	return 0;
}
