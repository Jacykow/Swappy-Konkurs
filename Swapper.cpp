#include<fstream>
using namespace std;
int main(){
	fstream plik;
	plik.open("plansza.txt",ios::in);
	int a;
	plik>>a;
	plik.close();
	plik.open("ruch.txt",ios::out);
	plik<<"o o o o\no o x o\no x o o\no o o o";
	plik.close();
	return 0;
}
