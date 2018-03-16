//made by Grzege
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
				int h[3],v[3];
				h[0]=(2-j)*k*3+(j-1)*k+j+i;//j=1,k=1|j=2,k=1|j=1vj=2 k=0
				h[1]=(2-j)*k+(j-1)*(-k)+(j+1)+i;
				h[2]=(2-j)*(-k)+(j-1)*(-k)*3+(j+2)+i;
				v[0]=(2-j)*k*12+(j-1)*k*4+(j-1)*3+j+i/4;//j=1,k=1|j=2,k=1|j=1vj=2 k=0
				v[1]=(2-j)*k*4+(j-1)*k*(-4)+(j-1)*3+j+4+i/4;
				v[2]=(2-j)*k*(-4)+(j-1)*k*(-12)+(j-1)*3+j+8+i/4;
				if((a[h[0]]==a[h[1]])&&a[h[2]]>0&&a[h[0]]>0&&a[h[1]]>0)
				{
					//cout<<h[0]<<" "<<h[1]<<endl;
					int z=szukajta(a,a[h[0]],h[0],h[1]);
					if(z>0)
					{
						wypisz_wymaluj(h[2],z);
						plik<<ruch;
						cout<<ruch;
						plik.close();
						return 0;
					}
				}
				if((a[h[0]]==a[h[2]])&&a[h[2]]>0&&a[h[0]]>0&&a[h[1]]>0)
				{
					//cout<<h[0]<<" "<<h[1]<<endl;
					int z=szukajta(a,a[h[0]],h[0],h[2]);
					if(z>0)
					{
						wypisz_wymaluj(h[1],z);
						plik<<ruch;
						cout<<ruch;
						plik.close();
						return 0;
					}
				}
				if((a[v[0]]==a[v[1]])&&a[v[2]]>0&&a[v[0]]>0&&a[v[1]]>0)
				{
					//cout<<h[0]<<" "<<h[1]<<endl;
					int z=szukajta(a,a[v[0]],v[0],v[1]);
					if(z>0)
					{
						wypisz_wymaluj(v[2],z);
						plik<<ruch;
						cout<<ruch;
						plik.close();
						return 0;
					}
				}
				if((a[v[0]]==a[v[2]])&&a[v[2]]>0&&a[v[0]]>0&&a[v[1]]>0)
				{
					//cout<<v[0]<<" "<<v[2]<<endl;
					int z=szukajta(a,a[v[0]],v[0],v[2]);
						//cout<<z<<" "<<v[1]<<endl;
					if(z>0)
					{
						wypisz_wymaluj(v[1],z);
						plik<<ruch;
						cout<<ruch;
						plik.close();
						return 0;
					}
				}
			}
		}
	}

}
