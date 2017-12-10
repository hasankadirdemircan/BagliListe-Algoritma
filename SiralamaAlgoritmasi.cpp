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
				son->next=NULL;//son gelen elemanýn iþaretçisi NULL olarak atanýyor
			}
			else //ilk düðüm iste burasý yürütülür.
			{
				ilk=d;
				son=d;
				ilk->next=NULL;
			}
		}
	
    void silDugum(dugum *d)
	{	
		dugum *p,*bironceki;
		p=ilk;// ilk düðüm p ye atýlýyor.

		while(p!=d)//p düðümü d düðümünden farklý mý?
		{
			bironceki=p; //p düðümünü bir öncekiye at.
			p=p->next;// p düðümünü 1 ilerlet
			
		}//düðümler eþit ise
		bironceki->next=p->next;// biröncekinin nextine p nin nextine atýlýr.(2 tane olan tek e düþer.)
		free(p); //p düðümü(fazla olan) silinir.
	
	}
		 
         
		void listele()
		{	
			dugum *p;
			p=ilk;//listenin baþlangýç adresi p'ye alýnýyor.
			
			if(p==NULL) //liste boþ ise.
				cout<<"Liste Boþ"<<endl;
			else
			{
				while(p!=NULL) //NULL olana kadar döndürülür.
				{
					cout<<p->sayi<<"   "; //veri yi yazýyor
					p=p->next; //bir sonraki düðümü gösteriyor						
				}					
			}
		}
		int toplamDugum()//düðümde kaç eleman olduðunu bulan fonksiyon
		{
			int n=0;
			dugum *p;
			p=ilk;
			while(p!=NULL) //düðümde eleman varsa
			{
				n++;
				p=p->next;
			}
			
			return n; //düðümdeki toplam eleman sayisini döndürüyor.
		}		
		dugum *getirDugum(int index)// istenen sayi düðümde var mý diye bakan fonksiyon
		{
			int a=0;
			dugum *p;
			p=ilk;
			while(p!=NULL)// düðümde eleman varsa.
			{
				if(a==index)//istenen indisde ki sayi gönderiliyor.
					return p;
				
				a++;
				p=p->next;
			}
			return NULL;			
		}

		int * KabarcikSiralama() //düðümdeki elemanlarý sýralayan fonksiyon.
		{
  			int gecici,k,hareket,i,n=toplamDugum();
		
			for (hareket=0;hareket<n-1;hareket++)
   			{
      			for (k=0;k<n-1-hareket;k++)
      			{
      				
				  	if(getirDugum(k)->sayi > getirDugum(k+1)->sayi) //komþular karþýlaþtýrýlýyor
      				{
       					gecici=getirDugum(k)->sayi; // yer deðiþtirme iþlemleri					
						getirDugum(k)->sayi=getirDugum(k+1)->sayi;
       					getirDugum(k+1)->sayi=gecici;
       				}
				  }		     
			}
			listele();
			cout << endl;
			dugum *p;
			p=ilk; //düðümün ilk elemaný atandý
			int deger=0;
			while(deger<n-1)//n-1 e kadar bakýyor.
			{
				cout << p->sayi << " ile " << p->next->sayi << " baktim? ";
				if(p->sayi == p->next->sayi)//ayný sayý var mý?
				{
					cout << "esitmis siliyoruz ";
					silDugum(p->next);//varsa silDugum fonksiyonuna düðümü yolluyoruz.(sayiyi deðil.!)
				}
				else //eþit deðilse
				{
					cout << "esit degil p artiriliyor ";
					p=p->next;//bir sonraki düðüme geçiyor. 
				}
				cout << "bu hale geldi: ";
				listele();
				cout << endl;
				deger++; //sayac 1 arttýrýlýyor.
			}
						
		}
		
};

