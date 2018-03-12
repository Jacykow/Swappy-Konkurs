#include<fstream>
using namespace std;
int main(){
	fstream plik;
	plik.open("plansza.txt",ios::in);
	int a;
	plik>>a;
	plik.close();
	plik.open("ruch.txt",ios::out);
	plik<<"x o o o\no o o o\no o o o\no o x o";
	plik.close();
	return 0;
}
