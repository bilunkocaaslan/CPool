#include <stdio.h>
#include <conio.h>  
#include <stdlib.h>  
#include <string.h>

FILE *dosyaptr;
void film_ekle();            
void film_listele();         
void film_guncelle(char ad[60]);
void film_sil(char ad[60]);     
void film_ara();              
int  islemDevam();
void aramayapisi(char x[60], int determ);
int arsiv(char x[BUFSIZ]);		

int gonder;			
char cevap, film[60];
struct Film_Bilgiler 
{
	char film_adi[60];     
	char yayin_tarihi[10];  
	char yonetmen[60]; 
	char senarist[60];  
	char basrol[60];  
}data;
int main()
{
	int secim;
	printf("-------------MENU---------------");	
	printf("\n| ------------------------- |\n");
	printf("| 1. Film Ekle               |\n");
	printf("| 2. Film Listele            |\n");  
	printf("| 3. Film Guncelle           |\n");
	printf("| 4. Film Sil                |\n");
	printf("| 5. Film Arama yap          |\n");
	printf("| 6. Cikis                   |\n");
	printf("| -------------------------- |\n");
	printf("Tercihiniz: ");
	scanf("%d", &secim);
	if (secim == 1 || secim == 2 || secim == 3 || secim == 4 || secim == 5 || secim == 6)
	{
		switch (secim)
		{
		case 1: 	film_ekle(); break; 
		case 2:		film_listele(); break; 
		case 3:	
		{
			do
			{
				printf("Guncellenicek filmi giriniz:");
				scanf("%s",&film);
				film_guncelle(film);
				for ( ; ; )
				{
					printf("\n");
					printf("Guncelleme islemine devam icin (G) \n");
					printf("Menuye donmek icin             (M) \n");
					printf("Cikis  yapmak icin             (C) \n\n");
					printf("Tercihiniz: ");
					cevap = getch(); 
					printf("\n");
					if (cevap == 'g' || cevap == 'G')
					{
						secim = 3; break;
					}
					else if (cevap == 'm' || cevap == 'M')
					{
						main(); break;
					}
					else if (cevap == 'c' || cevap == 'C')
					{
						exit(1); break;
					}
					else
						printf("\nYanlis secim yaptiniz!Lutfen belirtilen tuslari kullaniniz\n");
				}
			} while (secim = 3);
			break;
				}
		case 4:{
			do
			{
				printf("Silinecek film adi ? :");
				scanf("%s",&film);
			    film_sil(film);
				for (;;)
				{
					printf("\n");
					printf("Silme islemine devam icin      (S) \n");
					printf("Menuye donmek icin             (M) \n");
					printf("Cikis  yapmak icin             (C) \n\n");
					printf("Tercihiniz: ");
					getch();
					scanf("%c", &cevap);
					
					if (cevap == 'S' || cevap == 's')
					{
						secim = 4; break;
					}
					else if (cevap == 'm' || cevap == 'M')
					{
						main(); break;
					}
					else if (cevap == 'c' || cevap == 'C')
					{
						exit(1); break;
					}
					else
						printf("\nYanlis secim yaptiniz!Lutfen belirtilen tuslari kullaniniz\n");
				}
			} while (secim = 4);
			break;
			   }

		case 5:		film_ara(); break; 
		case 6:		exit(1); break;
		default:	printf("Lutfen belirtilen Tuslari kullaniniz");
			break;
		}
	}
	else printf("Yanlis secim yaptiniz!Tekrar Deneyiniz\n"); main();
	return 0;
}
void film_ekle() 
{
	dosyaptr = fopen("Film_Arsivi.txt", "a");
	rewind(dosyaptr);
	if (dosyaptr == NULL){ printf("Dosya bulunamadi"); }
	else
	{
		printf("Yeni Kayit\n");
		printf("----------\n\n");					
		printf("\tFilm adi: ");	
		_flushall();				
		gets(data.film_adi);
		fputs(data.film_adi ,dosyaptr);
		fputs("\n ",dosyaptr);
		
		printf("\tYayin tarihi: ");										
		gets(data.yayin_tarihi);
		fputs(data.yayin_tarihi ,dosyaptr);
		fputs("\n ",dosyaptr);
		
		printf("\tYonetmen: ");						
		gets(data.yonetmen);
		fputs(data.yonetmen ,dosyaptr);
		fputs("\n ",dosyaptr);
		
		printf("\tSenarist adi: ");
		gets(data.senarist);
		fputs(data.senarist ,dosyaptr);
		fputs("\n ",dosyaptr);
		
		printf("\tBasrol adi: ");
		gets(data.basrol);
		fputs(data.basrol ,dosyaptr);
		fputs("\n ",dosyaptr);
		
		fclose(dosyaptr); 
		printf("Film eklendi.\n\n");
		islemDevam();
	}
}
void film_listele()
{					
	dosyaptr = fopen("Film_Arsivi.txt", "r");
	int Secim;
	if (dosyaptr == NULL)
	{

		while (1)
		{
			printf("Suan arsivinizde hicbir film ekli degil ekleme yapmak icin (E) tusuna basiniz !");
			Secim = getche();
			if (Secim == 'e' || Secim == 'E')
			{
				film_ekle(); break;
			}
			else
			printf("\nYanlis secim yaptiniz!Lutfen belirtilen tuslari kullaniniz\n");
		}
	}
	else 
	{
		printf("Film Arsivi \n");
		printf("---------------\n\n");
		while (fscanf(dosyaptr, "%s\n%s\n%s\n%s\n%s\n", &data.film_adi, &data.yayin_tarihi, &data.yonetmen, &data.senarist, &data.basrol)!=EOF)
		{
			printf("Film adi:%s\n Yayin Tarihi:%s\n Yonetmen:%s\n  Senarist:%s\n  Basrol Oyuncusu:%s\n\n", data.film_adi, data.yayin_tarihi, data.yonetmen, data.senarist, data.basrol);
		}
		fclose(dosyaptr);
		islemDevam();
	}
}
void film_guncelle(char ad[60])
{
	FILE *dosyaptr, *yeni;
	int k = 0;
	dosyaptr = fopen("Film_Arsivi.txt", "r"); 
	yeni = fopen("Film_Arsivi1.txt", "w");
	if (dosyaptr == NULL)
	{
		printf("Suan arsivinizde hicbir film ekli degil!");
	}
	else
	{
		rewind(dosyaptr);
		rewind(yeni);
		while (!feof(dosyaptr))
		{
			fscanf(dosyaptr, "%s %s %s %s %s ", &data.film_adi, &data.yayin_tarihi, &data.yonetmen, &data.senarist, &data.basrol);
			if (strcmp(data.film_adi, ad) == 0)
			{
				k = 1;
				printf("\nGuncellenen Film Bilgileri\n");
				printf("-------------------------\n");
				printf("\tFilm adi: ");
				scanf("%s", data.film_adi);
				printf("\tYayin Tarihi: ");
				scanf("%s", data.yayin_tarihi);
				do
				{
					printf("\tYonetmen: ");
					scanf("%s", &data.yonetmen);
					gonder = arsiv(data.yonetmen);
				} while (gonder != 1);
				do
				{
					printf("\tSenarist: ");
					scanf("%s", &data.senarist);
					gonder = arsiv(data.senarist);
				} while (gonder != 1);
				do
				{
					printf("\tBasrol: ");
					scanf("%s", &data.basrol);
					gonder = arsiv(data.basrol);
				} while (gonder != 1);
				printf("\nFilm bilgileri guncellendi.\n\n");
				fprintf(yeni, "%s %s %s %s %s \t  \n", data.film_adi, data.yayin_tarihi, data.yonetmen, data.senarist, data.basrol);
			} 	
			else
				fprintf(yeni, "%s %s %s %s %s \t  \n", data.film_adi, data.yayin_tarihi, data.yonetmen, data.senarist, data.basrol);
		}
		_fcloseall();
		remove("Film_Arsivi.txt");
		rename("Film_Arsivi1.txt", "Film_Arsivi.txt");
		if (k == 0)
			printf("Bu film arsivde kayitli degildir...\n");
	}
}
void film_sil(char ad[60])
{
	FILE *dosyaptr;
	int a = 0;
	dosyaptr = fopen("Film_Arsivi.txt", "r+");
	if (dosyaptr == NULL)
	{
		printf("Suan arsivinizde hicbir film ekli degil!");
	}
	else
	{
		rewind(dosyaptr);
		printf("\n%s Filmini silmek istiyormusunuz? (E)-(H)\n", film);
		cevap = getch();
		if (cevap == 'E' || cevap == 'e')
		{
			while (!feof(dosyaptr))
			{
				fscanf(dosyaptr, "%s %s %s %s %s ", &data.film_adi, &data.yayin_tarihi, &data.yonetmen, &data.senarist, &data.basrol);
				if (!strcmp(data.film_adi, ad))
				{
					printf("\nSilinen Bilgileri\n");
					printf("------------------------\n");
					printf("Film adi:\t%s\nYayin Tarihi:  %s\nYonetmen: %s\nSenarist:  %s\nBasrol Oyuncusu:  %s\n\n\n", data.film_adi, data.yayin_tarihi, data.yonetmen, data.senarist, data.basrol);
					printf("\nFilm silindi...");
					a = 1;
				}
				else
					fprintf(dosyaptr, "%s\n%s\n%s\n%s\n%s\n\t\n", data.film_adi, data.yayin_tarihi, data.yonetmen, data.senarist, data.basrol);
			}
			_fcloseall();
			remove("Film_Arsivi.txt");	
			rename("Film_Arsivi1.txt", "Rehber.txt");
			if (a == 0)
				printf("\nBu film arsivde kayitli degil!\n");
		}
		else if (cevap == 'h' || cevap == 'H')
		{	printf("Menuye donuluyor....\n"); main();}
		else { printf("Yanlis tus kombinasyonu!\n"); printf("Menuye donuluyor....\n"); main(); };
	}
}
void film_ara()
{
	char film_adi[60], yayin_tarihi[10],yonetmen[60],senarist[60],basrol[60],determ;
	int Secim, flag = 0;
	dosyaptr = fopen("Film_Arsivi.txt", "r");
	if (dosyaptr == NULL)
	{
		printf("Dosya bulunamadi!\n");
	}
	else
	{
		printf("1-Film adi ile arama\n");
		printf("2-Yayin Tarihi ile arama\n");
		printf("3-Yonetmen ile arama\n");
		printf("4-Senarist ile arama\n");
		printf("5-Basrol ile arama\n");
		Secim=0;
		scanf("%d", &Secim);
		getch();
		switch (Secim)
		{
		case 1: 
			{
				printf("Aranan filmin adini giriniz:");
			    printf("%s\n",film_adi);
				scanf("%s",&film_adi); 
				aramayapisi(film_adi, determ);
				break;
			   }
		case 2:
			{
				printf("Aranan filmin yayin tarihini giriniz:");
			    printf("%s\n", &yayin_tarihi);
			    scanf("%s",&yayin_tarihi);
				aramayapisi(yayin_tarihi, determ);
				break;
			  }
		case 3:
			{
				printf("Aranan filmin yonetmenini giriniz:");
			     printf("%s\n", yonetmen);  
			     scanf("%s",&yonetmen);
				aramayapisi(yonetmen, determ);
				break;
			  }
		case 4:
			{
				printf("Aranan filmin senaristini giriniz:");
			     printf("%s\n", senarist);  
			     scanf("%s",&senarist);
				aramayapisi(senarist, determ);
				break;
			  }	  
			  
		case 5:
			{
				printf("Aranan filmin basrol oyuncusunu giriniz:");
			     printf("%s\n", basrol);  
			     scanf("%s",&basrol);
				aramayapisi(basrol, determ);
				break;
			  }	  
		}
		islemDevam();
	}
}
int arsiv(char x[BUFSIZ])
{

}
void aramayapisi(char x[60], int determ)
{
	int flag = 0;
	rewind(dosyaptr);
	while (fscanf(dosyaptr, "%s", &data.film_adi) != EOF) 
	{
		fscanf(dosyaptr, "%s", &data.yayin_tarihi);	 
		fscanf(dosyaptr, "%s", &data.yonetmen);		
		fscanf(dosyaptr, "%s", &data.senarist);		
		fscanf(dosyaptr, "%s", &data.basrol);				
		if (!strcmp(data.film_adi, x))
			{
				printf("Film Bilgileri\n");
				printf("--------------\n");
				printf("Film adi:%s\n Yayin Tarihi:%s\n Yonetmen:%s\n Senarist:%s\n Basrol oyuncusu:%s\n\n\n", data.film_adi, data.yayin_tarihi, data.yonetmen, data.senarist, data.basrol);
				flag = 1;
			}
			if (!strcmp(data.yayin_tarihi, x)) 
			{
			printf("Film Bilgileri\n");
				printf("--------------\n");
				printf("Film adi:%s\n Yayin Tarihi:%s\n Yonetmen:%s\n Senarist:%s\n Basrol oyuncusu:%s\n\n\n", data.film_adi, data.yayin_tarihi, data.yonetmen, data.senarist, data.basrol);
				flag = 1;
			}
		
			if (!strcmp(data.yonetmen, x))
			{
				printf("Film Bilgileri\n");
				printf("--------------\n");
				printf("Film adi:%s\n Yayin Tarihi:  %s\n Yonetmen: %s\n Senarist:  %s\n Basrol oyuncusu:  %s\n\n\n", data.film_adi, data.yayin_tarihi, data.yonetmen, data.senarist, data.basrol);
				flag = 1;
			}
		
			if (!strcmp(data.senarist, x))
			{
				printf("Film Bilgileri\n");
				printf("--------------\n");
				printf("Film adi:%s\n Yayin Tarihi:  %s\n Yonetmen: %s\n Senarist:  %s\n Basrol oyuncusu:  %s\n\n\n", data.film_adi, data.yayin_tarihi, data.yonetmen, data.senarist, data.basrol);
				flag = 1;
			}
		
			if (!strcmp(data.basrol, x))
			{
				printf("Film Bilgileri\n");
				printf("--------------\n");
				printf("Film adi:%s\n Yayin Tarihi:  %s\n Yonetmen: %s\n Senarist:  %s\n Basrol oyuncusu:  %s\n\n\n", data.film_adi, data.yayin_tarihi, data.yonetmen, data.senarist, data.basrol);
				flag = 1;
			}
		
	}
	if (flag == 0)
	{
		printf("\nBu film arsivde kayitli degil!\n\n");
	}
}
int islemDevam()
{
	while (1)
	{
		printf("Yeni bir film eklemek icin    (E)\n");
		printf("Menuye donmek icin            (M||m)\n");
		printf("Film aramasi yapmak icin      (A)\n");
		printf("Filmleri goruntulemek icin    (G)\n");
		printf("Cikis  yapmak icin            (C||c)\n\n");
		printf("Tercihiniz: ");
		cevap = getch();
	if (cevap == 'e' || cevap == 'E')
		{
			film_ekle(); 
			break;
		}
		
		else if (cevap == 'm' || cevap == 'M')
		{
			main(); 
			break;
		}
		
		else if (cevap == 'a' || cevap == 'A')
		{
			film_ara();
			break;
		}
		
		else if (cevap == 'g' || cevap == 'G')
		{
			film_listele();
			break; 
		}
		
		else if (cevap == 'c' || cevap == 'C')
		{
			exit(1); 
			break;
		}
		
		else 
		   printf("\nYanlis secim yaptiniz!Lutfen belirtilen tuslari kullaniniz\n");
	}
}
