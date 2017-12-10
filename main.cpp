#include<iostream>
#include "SiralamaAlgoritmasi.cpp"


int main()
{
	int dizi[6]={3,9,2,3,7,3};
	SiralamaAlgoritmasi s;
	
	for(int i=0;i<6;i++)
	{
		dugum *y;
		s.ekleDugum(y,dizi[i]);	
	}

	s.KabarcikSiralama();
	cout<<endl<<"...Son Hali..."<<endl;
	s.listele();

	return 0;
}
