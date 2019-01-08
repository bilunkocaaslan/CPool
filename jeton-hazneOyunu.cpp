#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
main()
{
	srand(time(NULL));
	int sayi=0;
	int i;
	int j=0;
	int t=0;
	int hazne[9];
	
	  printf("Jeton sayisini giriniz-->");
	  scanf("%d",&t);
	  
	int jeton[t];
	for(i=0;i<10;i++)
	{
		hazne[i]=0;
	}		
	while(j<t)
	{ 
		jeton[j]=0;
		printf("Jeton icin herhangi bir tusa basiniz --> ");
		getch();
		for(i=0;i<10;i++)
		{	 
			sayi=rand()%2;			
			jeton[j]=sayi+jeton[j];			
		}
		printf("%2d.top %d numarali hazneye dustu.\n",j+1,jeton[j]+1);
		hazne[jeton[j]]++;
		j++;
	}	
	for(i=0;i<10;i++)
	{
		printf("\n%d numarali haznedeki top sayisi %d",i+1,hazne[i]);
		getch();
		
	}
}
