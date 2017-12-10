#include<iostream>
#include<cstdlib>

using namespace std;

struct dugum{
	int sayi;
	dugum *next;
	
};

class SiralamaAlgoritmasi
{
	public:
		dugum *ilk;
		dugum *son;
		
		
		SiralamaAlgoritmasi()
		{
			ilk=NULL;
			son=NULL;
		}
		
		void ekleDugum(dugum *d,int deger)
		{
			d=(dugum*)malloc(sizeof(dugum));
			d->sayi=deger;
		
			if(ilk!=NULL) //listede eleman varsa
			{
				son->next=d; 
				son=d;
				son->next=NULL;//son gelen eleman�n i�aret�isi NULL olarak atan�yor
			}
			else //ilk d���m iste buras� y�r�t�l�r.
			{
				ilk=d;
				son=d;
				ilk->next=NULL;
			}
		}
	
    void silDugum(dugum *d)
	{	
		dugum *p,*bironceki;
		p=ilk;// ilk d���m p ye at�l�yor.

		while(p!=d)//p d���m� d d���m�nden farkl� m�?
		{
			bironceki=p; //p d���m�n� bir �ncekiye at.
			p=p->next;// p d���m�n� 1 ilerlet
			
		}//d���mler e�it ise
		bironceki->next=p->next;// bir�ncekinin nextine p nin nextine at�l�r.(2 tane olan tek e d��er.)
		free(p); //p d���m�(fazla olan) silinir.
	
	}
		 
         
		void listele()
		{	
			dugum *p;
			p=ilk;//listenin ba�lang�� adresi p'ye al�n�yor.
			
			if(p==NULL) //liste bo� ise.
				cout<<"Liste Bo�"<<endl;
			else
			{
				while(p!=NULL) //NULL olana kadar d�nd�r�l�r.
				{
					cout<<p->sayi<<"   "; //veri yi yaz�yor
					p=p->next; //bir sonraki d���m� g�steriyor						
				}					
			}
		}
		int toplamDugum()//d���mde ka� eleman oldu�unu bulan fonksiyon
		{
			int n=0;
			dugum *p;
			p=ilk;
			while(p!=NULL) //d���mde eleman varsa
			{
				n++;
				p=p->next;
			}
			
			return n; //d���mdeki toplam eleman sayisini d�nd�r�yor.
		}		
		dugum *getirDugum(int index)// istenen sayi d���mde var m� diye bakan fonksiyon
		{
			int a=0;
			dugum *p;
			p=ilk;
			while(p!=NULL)// d���mde eleman varsa.
			{
				if(a==index)//istenen indisde ki sayi g�nderiliyor.
					return p;
				
				a++;
				p=p->next;
			}
			return NULL;			
		}

		int * KabarcikSiralama() //d���mdeki elemanlar� s�ralayan fonksiyon.
		{
  			int gecici,k,hareket,i,n=toplamDugum();
		
			for (hareket=0;hareket<n-1;hareket++)
   			{
      			for (k=0;k<n-1-hareket;k++)
      			{
      				
				  	if(getirDugum(k)->sayi > getirDugum(k+1)->sayi) //kom�ular kar��la�t�r�l�yor
      				{
       					gecici=getirDugum(k)->sayi; // yer de�i�tirme i�lemleri					
						getirDugum(k)->sayi=getirDugum(k+1)->sayi;
       					getirDugum(k+1)->sayi=gecici;
       				}
				  }		     
			}
			listele();
			cout << endl;
			dugum *p;
			p=ilk; //d���m�n ilk eleman� atand�
			int deger=0;
			while(deger<n-1)//n-1 e kadar bak�yor.
			{
				cout << p->sayi << " ile " << p->next->sayi << " baktim? ";
				if(p->sayi == p->next->sayi)//ayn� say� var m�?
				{
					cout << "esitmis siliyoruz ";
					silDugum(p->next);//varsa silDugum fonksiyonuna d���m� yolluyoruz.(sayiyi de�il.!)
				}
				else //e�it de�ilse
				{
					cout << "esit degil p artiriliyor ";
					p=p->next;//bir sonraki d���me ge�iyor. 
				}
				cout << "bu hale geldi: ";
				listele();
				cout << endl;
				deger++; //sayac 1 artt�r�l�yor.
			}
						
		}
		
};

