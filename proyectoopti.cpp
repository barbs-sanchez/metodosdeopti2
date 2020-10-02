#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

float costo[100][100];
float mataux[100][100];
float chicor[100],chicoc[100],sumar=0,sumacol=0, renglonfuera[100][100],columnafuera[100][100];
int ceroc[100],ceror[100],maxr[100],maxc[100],tachadaR[100],tachadaC[100];
int tache=0,posc,posr;
	int nuevod=100;
	int nuevoo=100;

int origen=0;
float optimo=0;
int destino=0;

int leeproblema()
{
	int i=0,j=0;
	printf("Ingrese el numero de nodos ");
	scanf("%d",&origen);
	destino=origen;
	
	
	for(i=0;i<origen;i++)
	{
		
	    for(j=0;j<destino;j++)
  	   {
		   if(i==j)
		   {
		   	 costo[i][j]=1000;
		   }else
		    {
		   
		        printf("Ingrese el costo de ir de %d a %d ",i+1,j+1);
		        scanf("%f",&costo[i][j]);
        	}
	   }
	
	}
	
	
}

int imprimetache()
{
	int i=0,j=0;
	
	printf("\n los datos ingresados son \n");
	for(i=0;i<nuevoo;i++)
	{
		
		printf("\n");
	    for(j=0;j<nuevod;j++)
  	   {
		  printf("%.2f    ", costo[i][j]);
	   }
	
	}
	
	
}


int imprime()
{
	int i=0,j=0,posicionr,posicionc;
	
	printf("los datos ingresados son \n");
	for(i=0;i<origen;i++)
	{
		
		printf("\n");
	    for(j=0;j<destino;j++)
  	   {
		  printf("%.2f    ", costo[i][j]);
	   }
	
	}
	
	
}

int minimosR()
{
	int i,j;
	float m,n;
	// Minimo de los renglones
     	for(i=0;i<origen;i++)
	{
		m=1000;
	    for(j=0;j<destino;j++)
  	   {
		  if(m>costo[i][j])
		  m=costo[i][j];
		  chicor[i]=m;
	   }
	
	}
		
		printf("\n Los minimos de los renglones son: \n");
     	for(i=0;i<origen;i++)
	{
	   
  	   
		  printf("%f" ,chicor[i]);
		  	printf("\n");
		  	sumar=sumar+chicor[i];
	   
	}


	
}

int minimosC()
{
	int i,j;
	float n;
	 //Minimo de las columnas
         	for(j=0;j<destino;j++)
	{
		 	n=1000;
	
	    for(i=0;i<origen;i++)
  	   {
  	  
		  if(n>costo[i][j])
		  n=costo[i][j];
		  chicoc[j]=n;
	   }
	
	}
		
		printf("\n Los minimos de las columnas son: \n");
     	for(j=0;j<destino;j++)
	{
	   
  	   
		  printf("%f" ,chicoc[j]);
		  	printf("\n");
	   sumacol= sumacol+chicoc[j];
	}

}

int restarenglon()
{
	int i,j;
	
	for(i=0;i<origen;i++)
	{
		for(j=0;j<destino;j++)
		{
			costo[i][j]=costo[i][j]-chicor[i];
		}
	}
}

int restacolumna()
{
	int i,j,m;
	
	for(j=0;j<destino;j++)
	{
		for(i=0;i<origen;i++)
		{
			costo[i][j]=costo[i][j]-chicoc[j];
		}
	}
	
	optimo=sumar+sumacol;
	printf("\n\n El optimo es: %f",optimo);
}

int taches() //uso una matriz auxiliar para los taches 
{
	 nuevod=destino;
	nuevoo=origen;
	 int guardao=0,guardad=0,naux1,aux2; //para guardar la columna y renglon con mayor 0s

		int i,j,k,flag=0,l,flag2=0,x,y,taches,filta,colta;
			int resp=0,resp2=0;
			printf("\n¿Desea tachar algun renglón?   Sí=1  No=0  ");
			scanf(" %d ",&resp);
		//	int au1=nuevoo,au2=nuevod;
			do
			{
				int pos;
				printf("\nQue posicion tiene el renglon que desea tachar ");
				scanf("%d",&pos);
				
				for(i=0;i<nuevoo;i++)
				{
					if(i==pos-1)
					{
						for(j=0;j<nuevod;j++)
						{
							renglonfuera[i][j]=costo[i][j];
					    	costo[i][j]=costo[i+1][j];
						}
						nuevoo--;
					}
				}
				
				taches++;
				
				imprimetache();
				
					printf("\n¿Desea tachar algun renglón?   Sí=1  No=0");
		        	scanf("%d ",&resp);
				
			}while(resp==1);
				printf("%d\n", nuevoo);
	
		
		
		printf("\n\nRenglon sacado\n");
		for(i=0;i<nuevoo;i++)
			{
				printf("\n");
				for(j=0;j<nuevod;j++)
				{
				    printf("%d",renglonfuera[i][j]);
				}
			}	
			
					printf("\n¿Desea tachar alguna columna?   Sí=1  No=0  ");
			scanf(" %d ",&resp2);
	
			do
			{
				int pos;
				printf("\nQue posicion tiene el renglon que desea tachar ");
				scanf("%d",&pos);
				
				for(i=0;i<nuevod;i++)
				{
					if(i==pos-1)
					{
						for(j=0;j<nuevoo;j++)
						{
							columnafuera[i][j]=costo[i][j];
					    	costo[i][j]=costo[i][j+1];
						}
						nuevod--;
					}
				}
				
				taches++;
				
				imprimetache();
				
					printf("\n¿Desea tachar alguna columna?   Sí=1  No=0");
		        	scanf("%d ",&resp2);
				
			}while(resp2!=0);
			printf("%d\n", nuevod);
	
		
		
		printf("\n\nColumna sacada\n");
		for(i=0;i<nuevod;i++)
			{
				printf("\n");
				for(j=0;j<nuevoo;j++)
				{
				    printf("%d",columnafuera[i][j]);
				}
			}			

}


int main()
{
	leeproblema();
	imprime();
	minimosR();
	restarenglon ();
	imprime ();
	minimosC();
	restacolumna();
	imprime();
	taches();
	imprimetache();
	
}
