#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct polinom
{

 int katsayi;  
 int us;  
 struct polinom *sonraki; 
}polinom;

polinom *p3=NULL,*g3;
polinom* polinom_topla(polinom *g1,polinom *g2)//fonksiyonumuz recursive fonksiyondur
{	

	if(g1->sonraki==NULL && g2->sonraki==NULL)return g3;//fonksiyonun d�ng�den ��kma �art� her iki polinomunda bitmesidir
	if(g1->sonraki==NULL)//e�er bir polinom bitip di�er polinom bitmemi�se bitmeyen polinomun kalan de�erlerini toplam polinomuna ekler
	{
		while(g2->sonraki!=NULL)
		{
			p3->katsayi=g2->katsayi;
			p3->us=g2->us;
			g2=g2->sonraki;
			p3->sonraki=(polinom*)malloc(sizeof(polinom));
			p3=p3->sonraki;
			p3->sonraki=NULL;
		}
		return g3;
	}
	if(g2->sonraki==NULL)//e�er bir polinom bitip di�er polinom bitmemi�se bitmeyen polinomun kalan de�erlerini toplam polinomuna ekler
	{
		while(g1->sonraki!=NULL)
		{
			p3->katsayi=g1->katsayi;
			p3->us=g1->us;
			g1=g1->sonraki;
			p3->sonraki=(polinom*)malloc(sizeof(polinom));
			p3=p3->sonraki;
			p3->sonraki=NULL;
		}
		return g3;
	}
	if(g1->us>g2->us)//b�y�k olan polinom de�erini toplam polinomuna polinomun sonraki eleman�n� fonksiyona tekrar yollar.K���k olan polinomda de�i�me olmaz.
	{	if(p3==NULL)//bu if �art� ba�� listenin ilk eleman�n�n olu�turulup olu�turulmad���n� kontrol eder olu�turulmad�ysa yer ay�r�r
		{
			p3=(polinom*)malloc(sizeof(polinom));
			g3=p3;
		}
		p3->katsayi=g1->katsayi;
		p3->us=g1->us;	
		p3->sonraki=(polinom*)malloc(sizeof(polinom));
		p3=p3->sonraki;
		p3->sonraki=NULL;
		polinom_topla(g1->sonraki,g2);	
	}
	else {
		if(g1->us<g2->us)//b�y�k olan polinom de�erini toplam polinomuna polinomun sonraki eleman�n� fonksiyona tekrar yollar.K���k olan polinomda de�i�me olmaz.
		{
			if(p3==NULL)
		{
			p3=(polinom*)malloc(sizeof(polinom));
			g3=p3;
		}
			p3->katsayi=g2->katsayi;
			p3->us=g2->us;
			p3->sonraki=(polinom*)malloc(sizeof(polinom));
			p3=p3->sonraki;
			p3->sonraki=NULL;
			polinom_topla(g1,g2->sonraki);	
		}
		else 
		{
			if(p3==NULL)//polinomlardaki �sler ayn� ise 2 polinom de�erinin katsay�lar�n� toplayarak toplam polinomunun yenir eleman�na ekler
		{
			p3=(polinom*)malloc(sizeof(polinom));
			g3=p3;
		}
			p3->katsayi=g1->katsayi+g2->katsayi;
			p3->us=g1->us;
			p3->sonraki=(polinom*)malloc(sizeof(polinom));
			p3=p3->sonraki;
			p3->sonraki=NULL;
			polinom_topla(g1->sonraki,g2->sonraki);	
		}
	}
}


int main (){
	polinom *gecici;
	polinom *p1,*p2;
	FILE *dosya1,*dosya2,*dosya3;
	dosya1=fopen("polinom1.txt","r");//polinomlar� almak i�in polinom1.txt ve polinom2.txtyi read modunda toplamlar� yazd�rmak i�inde polinom3.txt yi write modunda a�t�k 
	dosya2=fopen("polinom2.txt","r");
	dosya3=fopen("polinom3.txt","w");
	p1=(polinom*)malloc(sizeof(polinom));
	p2=(polinom*)malloc(sizeof(polinom));
	gecici=p1;
	while(!feof(dosya1))//p1 in ilk eleman�n� tutan ba��l listemizi i�ine polinom1.txtden gelen verileri ekleyerek olu�turduk
	{	
		
		fscanf(dosya1,"%dx%d",&gecici->katsayi,&gecici->us);
		gecici->sonraki=(polinom*)malloc(sizeof(polinom));
		gecici=gecici->sonraki;
		gecici->sonraki=NULL;
		
	}
	
	gecici=p2;
	while(!feof(dosya2))//p2 i�inde polinom2.txt verilerini okuyup ekledik
	{
		fscanf(dosya2,"%dx%d",&gecici->katsayi,&gecici->us);
		gecici->sonraki=(polinom*)malloc(sizeof(polinom));
		gecici=gecici->sonraki;
		gecici->sonraki=NULL;
	}
	p3=polinom_topla(p1,p2);//yeni toplam polinomu olu�turmak i�in fonksiyona yollad�k
	gecici=p3;
	while(gecici->sonraki!=NULL)//toplam ba��l listemizin son eleman�na kadar polinom3.txt ye de�erleri yazd�rd�k
	{	
		fprintf(dosya3,"%dx%d+",gecici->katsayi,gecici->us);
		gecici=gecici->sonraki;
	}
	
	fclose(dosya1);
	fclose(dosya2);
	fclose(dosya3);//dosyalar� kapatt�k
	return 0;
}
