#include <cstdlib>
#include<stdio.h>
struct  dane {
	long long int pozostaje;
	long long int indeks;
	bool skreslana;
};
long long int pow(int podst, int wykladnik)
{
	int wynik = 1;
	for (int i = 0; i < wykladnik; i++)
	{
		wynik *= podst;
	}
	return wynik;
}
long long int ostatni(long long int n) {
	if (n == 1)
		return 1;

	else if ((n & 1) == 0)
		return 2 * ostatni(n >> 1) - 1;
	else
		return 2 * ostatni(((n - 1) >> 1)) + 1;
}


long long int pierwsza(long long int ospozostalo, bool start) //start
{
	if (ospozostalo == 1)
		return false;

	if ((ospozostalo & 1) == 0)
		return start;
	else
		return !start;
}
long long int pozostalo(long long int ospozostalo, bool start)//pozostalo
{
	if ((ospozostalo & 1) == 0)
		return ospozostalo >> 1;
	else {
		if (start == false)
			return ospozostalo >> 1;
		else
			return (ospozostalo >> 1) + 1;
	}
}
long long int index(bool start, long long int instart, int i)
{
	if (start == true)
		return instart;
	else
		return instart + pow(2, i - 1);
}
long long int wynik(bool start, long long int npoz, long long int mazostac, int wiersz, long long int indeks)
{
	if (start == false)
		return (npoz - mazostac - 1)*pow(2, wiersz) + indeks;
	else
		return indeks + pow(2, wiersz - 1) + (npoz - mazostac - 1)*pow(2, wiersz);
}



int main()
{
	dane dana[64];
	int linie;
	int wiersz;
	long long int n;
	long long int k;
	long long int mazostac;
	scanf("%i", &linie);
	for (int i = 0; i < linie; i++)
	{
		scanf("%lli", &n);
		scanf("%lli", &k);
		if (n == k || k == -1)
			printf("%lli \n", ostatni(n));
		else {
			dana[0] = { n,1,true };
			if (k > 0)
				mazostac = n - k;
			else
				mazostac = -k - 1;
			for (int i = 1; i < 64; i++)
			{
				dana[i].pozostaje = pozostalo(dana[i - 1].pozostaje, dana[i - 1].skreslana);
				dana[i].skreslana = pierwsza(dana[i - 1].pozostaje, dana[i - 1].skreslana);
				dana[i].indeks = index(dana[i - 1].skreslana, dana[i - 1].indeks, i);
				if (dana[i - 1].pozostaje > mazostac && dana[i].pozostaje <= mazostac)
				{
					wiersz = i;
					printf("%lli \n", wynik(dana[i - 1].skreslana, dana[i - 1].pozostaje, mazostac, wiersz, dana[i - 1].indeks));
					break;
				}
			}
		}

	}
}