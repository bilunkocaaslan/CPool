#include<stdio.h>

FILE *dosyaptr;

struct arabaBilgi
{
   char	plaka[BUFSIZ];
   char giris_saati[BUFSIZ];
   char cikis_saati[BUFSIZ];	
}data;

void araba_ekle()
{
	dosyaptr = fopen("Park.txt", "a");
	rewind(dosyaptr);
	if (dosyaptr == NULL){ printf("Dosya bulunamadi"); }
	else 
	{
		printf("\tAraba plakasi: ");	
		_flushall();				
		gets(data.plaka);
		fputs(data.plaka ,dosyaptr);
		fputs("\n ",dosyaptr);
		
		printf("\tOtoparka giris saati: ");				
		gets(data.giris_saati);
		fputs(data.giris_saati ,dosyaptr);
		fputs("\n ",dosyaptr);
		
		printf("\tOtoparktan cikis saati: ");					
		gets(data.cikis_saati);
		fputs(data.cikis_saati ,dosyaptr);
		fputs("\n ",dosyaptr);
			
	}	
}

void hesapla()
{
  int ucret=0,sure=0;
  float giris=0,cikis=0;	
   sure = cikis-giris;
  
	if(sure<60)
	ucret=2;
	else if(sure>100 && sure<200)
	ucret=4;
	else if(sure>200 && sure<400)
	ucret=6;
	else (sure>400 && sure<2400);
	ucret=8;	
	
	printf("Otopark ucretiniz:%d",ucret);
}

main()
{
	printf("-------OTOPARk UCRETI-------\n");
	printf("1 saate kadar :2TL\n1-4 saat arasi:4TL\n4-8 saat arasi:6TL\n8-24 saat arasi:8TL\n");
	
	
	araba_ekle();
	hesapla();	
}
