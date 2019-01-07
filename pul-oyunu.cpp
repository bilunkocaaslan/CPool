#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
int pulmax(int, int, int);
int pulmin(int, int, int);
bool asalsayi(int, int, int);

  main()
{  
	int i,sonuc;
	int pul1,pul2,pul3;
    int topl;
    int N[3];
    char tus='e'||'E';
    printf("Oyuna baslamak icin herhangi bir tusa basiniz:\n");
		getch();
{	
	do
	
	 for(i=1;i<3;i++)
		{	srand(time(NULL));
			pul1=rand()%99+1;
			pul2=rand()%99+1;
			pul3=rand()%99+1;		
		if (pul1==pul2||pul2==pul3||pul1==pul3)
	       pul2=rand()%99+1;
	       pul3=rand()%99+1;	
	     printf("%d.pul: %d\n",i++,pul1,N[i]++);
         printf("%d.pul: %d\n",i++,pul2,N[i]++);
         printf("%d.pul: %d\n",i++,pul3,N[i]++);
         }
         while(tus=='E');
}
         topl=pul1+pul2+pul3;
         printf("Toplam: %d\n",topl);
    if(topl<150)
        printf("\nTebrikler ilk kurala gore kazandiniz.(1)\n");
    else if(asalsayi(pul1,pul2,pul3)==true)
	    printf("\nTebrikler ikinci kurala gore kazandiniz.(2)\n");
	else if(pul1!=pulmax(pul1,pul2,pul3) && pul1!=pulmin(pul1,pul2,pul3) && pulmax(pul1,pul2,pul3)-pulmin(pul1,pul2,pul3)>pul1)
	  	printf("\nTebrikler ucuncu kurala gore kazandiniz.(3)\n");
	else if(pul2!=pulmax(pul1,pul2,pul3) && pul1!=pulmin(pul1,pul2,pul3) && pulmax(pul1,pul2,pul3)-pulmin(pul1,pul2,pul3)>pul2 )
	    printf("\nTebrikler ucuncu kurala gore kazandiniz.(3)\n");
    else if(pul3!=pulmax(pul1,pul2,pul3) && pul1!=pulmin(pul1,pul2,pul3) && pulmax(pul1,pul2,pul3)-pulmin(pul1,pul2,pul3)>pul3)
	    printf("\nTebrikler ucuncu kurala gore kazandiniz.(3)\n");
	else
		printf("\nOyunu kaybettiniz...\n");
		    printf("Devam etmek istiyorsaniz--> [E]");
		        tus=getch();
	}
	int pulmin(int a,int b,int c)
{
	int pulmin=a;
	if(b<pulmin)
	    pulmin=b;
	if(c<pulmin)
	    pulmin=c;
	return pulmin;    
}	
int pulmax(int a,int b,int c)
{
	int pulmax=a;
	if(b>pulmax)
	    pulmax=b;
	if(c>pulmax)
	    pulmax=c;
	return pulmax;
}
bool asalsayi(int a,int b,int c)
{
	bool asalsayi=1;
	int t=0;
	t =a+b+c;
	for(int i=2;i<t;i++)
	{
		if(t%i==0)
		return 0;
	} 
}
		
		
