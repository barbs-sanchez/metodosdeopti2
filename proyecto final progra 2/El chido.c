#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int equipos(int numero);//Lee los datos de los equipos
int linea(int g);
int menu();//menu de la categoria
int menuc();//menu de la cantidad
int matematicas(int nume);
int espanol(int nume);
int computacion(int nume);
int ganador(int nume);
int ct=0,cd=3,cc=6;// para matematicas
int cct=10,ccd=13,ccc=16;//para computación
int cet=20,ced=23,cec=26;//para español
struct equipo
{
    int suma;
    char ne[50];//nmbre del equipo

}equipo[5];
struct integrantes
{
    char nom[50];
    int edad;
    char carrera[50];
}integ[3];

FILE *fp;
FILE *equi; //para guardar a los equipos

int main()
{

     int g;
     int opcion;
     int i,x=10,n,p,numero;//numero es para ver hasta que numero son los equipos
     int cantidad;
     int nume;//es para el n�meo de equipo
     printf("¿Cuántos equipos participarán? (Maximo 5)\n");
     scanf("%d",&numero);
     printf("Cada equipo debe contener 3 participantes");
     equipos(numero);
	 for (i=0;i<x;i++)
	{
		system("cls");
	      printf("¿Qué equipo pasará? ");
          scanf("%d",&nume);
          opcion=menu();
          switch (opcion)
          {
          	case 1: matematicas(nume);
          	        break;
          	case 2: computacion(nume);
          	        break;
			case 3: espanol(nume);
			        break;
		  }
		printf("\n¿Desea salir? 0=si 1=no");
		scanf("%d",&n);
		if (n==0){ printf ("\nAdios");
		 break;
      }
  }
	printf("\n Las sumas quedaron:");
	ganador(numero);
	for (p=1;p<=numero;p++)
    {
        printf(" \nLa suma del equipo %d es = %d",p,equipo[p].suma);
    }
     return 0;
}
int equipos(int numero)
{
    int i,j,x;

    equi=fopen("Equipos.txt","a");
    for (i=0;i<numero;i++)
    {
        printf("\nEquipo %d",i+1);
        printf("\nNombre del equipo: ");
        fflush(stdin);
        gets(equipo[i].ne);
        for (j=0;j<3;j++)
        {
            printf("\nIntegrante %d",j+1);
            printf("\nNombre: ");
            fflush(stdin);
            gets(integ[j].nom);
            printf("\nEdad: ");
            scanf("%d",&integ[j].edad);
            printf("\ncarrera: ");
            fflush(stdin);
            gets(integ[j].carrera);

        }



       fprintf(equi,"Nombre del equipo %s",equipo[i].ne);
       for (x=0;x<3;x++)
       {
               fprintf(equi,"\nIntegrante %d",x+1);
            fprintf(equi,"\nNombre: %s",integ[x].nom);
            fprintf(equi,"\nEdad: %d ",integ[x].edad);
            fprintf(equi,"\ncarrera: %s",integ[x].carrera);

    }
}
fclose(equi);
return 0;
}
int linea(int g)
{

     int i;
      char pregunta[1000];//nos da la pregunta deceada
        if( ( fp = fopen("preguntas.txt","r") ) == NULL )//comprueba que haya un archivo con nombre archivo.txt que se pueda leer
         {
            printf("Error al leer el archivo.");
         }

       else
	   {
          for(i = 0; i < g ; i++)//lee l�nea por l�nea guard�ndola en la variable nombre hasta llegar a la l�nea g
          {
            if(!feof(fp))//se asegura de que no haya llegado al final del archivo
          fgets(pregunta, 10000, fp);
          }
           printf("%s",pregunta);
       }
    fclose(fp); //cierra el archivo

    getch();
}
int menu()
{
	int opcion;
	printf("\n Selecciona la categoria \n");
	printf("\n 1.Matemáticas");
	printf("\n 2.Computacón");
	printf("\n 3.Español");
	scanf("%d",&opcion);
	return opcion;
}
int ganador(int numero)
{
    int i,j,maximo,va;
   maximo=0;
    for (j=0;j<=numero;j++)

  {
      if (equipo[j].suma>maximo)
      {
        maximo=equipo[j].suma;
        va=j;

      }


  }
    printf("\n El equipo ganador es el equipo: %d",va);
}
int menuc()
{
	int cantidad;
	 printf("¿De qué cantidad deseas la pregunta?   ");
	      printf("\n1=300");
	     printf("\n2=200");
	     printf("\n3=100");
	     scanf("%d",&cantidad);
	     return cantidad;
}
int matematicas(int nume)
{
	int cantidad;
	int g,y,z,j;
	cantidad=menuc();
	 switch (cantidad)
	     {
	     	case 1:
	     	        ct=ct+1;//ct va ser la variable de cuantas veces pase por la de 300
	     	        g=ct;
	     	        linea(g);//para mostrarnos la pregunta
	     	        printf("\n¿Respondió correcto? 1=Si 0=No");
	     	        scanf("%d",&y);
			        if (y==1)
					{
					equipo[nume].suma=equipo[nume].suma+300;//suma a la variable del equipo ganador
					break;
			       	}
	     	        else
	     	        {  equipo[nume].suma=equipo[nume].suma-300;//le resta al equipo que le tocaba contestar
	     	            printf("\n¿Algun equipo respodió correcto? 1=si 0=no");
	     	          scanf("%d",&z);
	     	          if (z==1){
	     	          	printf("¿Cuál equipo? ");
	     	          	scanf("%d",&j);
	     	          	equipo[j].suma=equipo[j].suma+300;
					   }
					   break;
					}

	     	case 2:
	     	         cd=cd+1;//cd va ser la variable de cuantas veces pase por la de 200
	     	        g=cd;
	     	        linea(g);
	     	     printf("\n¿Respondió correcto? 1=Si 0=No");
	     	        scanf("%d",&y);
			        if (y==1)
					{
					equipo[nume].suma=equipo[nume].suma+200;
					break;
			       	}
	     	        else
	     	        { equipo[nume].suma=equipo[nume].suma-200;
	     	            printf("\n¿Algun equipo respodió correcto? 1=si 0=no");
	     	          scanf("%d",&z);
	     	          if (z==1){
	     	          	printf("\n¿Cuál equipo?");
	     	          	scanf("%d",&j);
	     	          	equipo[j].suma=equipo[j].suma+200;
					   }
					   break;
					}

	     	case 3:  cc=cc+1;//ct va ser la variable de cuantas veces pase por la de 300
	     	        g=cc;
	     	        linea(g);
	     	    printf("\n¿Respondió correcto? 1=si 0=no");
	     	        scanf("%d",&y);
			        if (y==1)
					{
					equipo[nume].suma=equipo[nume].suma+100;
					break;
			       	}
	     	        else
	     	        {   equipo[nume].suma=equipo[nume].suma-100;
	     	            printf("\n¿Algun equipo respodió correcto? 1=si 0=no");
	     	          scanf("%d",&z);
	     	          if (z==1){
	     	          	printf("\n¿Cuál equipo? ");
	     	          	scanf("%d",&j);
                        equipo[j].suma=equipo[j].suma+100;
					   }
					   break;
					}
		 }

}
int computacion(int nume)
{
	int cantidad;
		int g,y,z,j;
	cantidad=menuc();
	 switch (cantidad)
	     {
	     	case 1:
	     	        cct=cct+1;//ct va ser la variable de cuantas veces pase por la de 300
	     	        g=cct;
	     	        linea(g);//para mostrarnos la pregunta
	     	        printf("\n¿Respondió correcto? 1=Si 0=No");
	     	        scanf("%d",&y);
			        if (y==1)
					{
					equipo[nume].suma=equipo[nume].suma+300;//suma a la variable del equipo ganador
					break;
			       	}
	     	        else
	     	        {  equipo[nume].suma=equipo[nume].suma-300;//le resta al equipo que le tocaba contestar
	     	            printf("\n¿Algun equipo respodió correcto? 1=si 0=no");
	     	          scanf("%d",&z);
	     	          if (z==1){
	     	          	printf("\n¿Cuál equipo? ");
	     	          	scanf("%d",&j);
	     	          	equipo[j].suma=equipo[j].suma+300;
					   }
					   break;
					}

	     	case 2:
	     	         ccd=ccd+1;//cd va ser la variable de cuantas veces pase por la de 200
	     	        g=ccd;
	     	        linea(g);
	     	     printf("\n¿Respondió correcto? 1=Si 0=No");
	     	        scanf("%d",&y);
			        if (y==1)
					{
					equipo[nume].suma=equipo[nume].suma+200;
					break;
			       	}
	     	        else
	     	        { equipo[nume].suma=equipo[nume].suma-200;
	     	            printf("\n¿Algun equipo respodió correcto? 1=si 0=no");
	     	          scanf("%d",&z);
	     	          if (z==1){
	     	          	printf("\n¿Cuál equipo? ");
	     	          	scanf("%d",&j);
	     	          	equipo[j].suma=equipo[j].suma+200;
					   }
					   break;
					}

	     	case 3:  ccc=ccc+1;//ct va ser la variable de cuantas veces pase por la de 300
	     	        g=ccc;
	     	        linea(g);
	     	    printf("\n¿Respondió correcto? 1=si 0=no");
	     	        scanf("%d",&y);
			        if (y==1)
					{
					equipo[nume].suma=equipo[nume].suma+100;
					break;
			       	}
	     	        else
	     	        {   equipo[nume].suma=equipo[nume].suma-100;
	     	            printf("\n¿Algun equipo respodió correcto? 1=si 0=no");
	     	          scanf("%d",&z);
	     	          if (z==1){
	     	          	printf("\n¿Cuál equipo? ");
	     	          	scanf("%d",&j);
                        equipo[j].suma=equipo[j].suma+100;
					   }
					   break;
					}
		 }
}
int espanol(int nume)
{
	int cantidad;
		int g,y,z,j;
	cantidad=menuc();
	 switch (cantidad)
	     {
	     	case 1:
	     	        cet=cet+1;//ct va ser la variable de cuantas veces pase por la de 300
	     	        g=cet;
	     	        linea(g);//para mostrarnos la pregunta
	     	        printf("\n¿Respondió correcto? 1=si 0=no");
	     	        scanf("%d",&y);
			        if (y==1)
					{
					equipo[nume].suma=equipo[nume].suma+300;//suma a la variable del equipo ganador
					break;
			       	}
	     	        else
	     	        {  equipo[nume].suma=equipo[nume].suma-300;//le resta al equipo que le tocaba contestar
	     	            printf("\n¿Algun equipo respodió correcto? 1=Si 0=No");
	     	          scanf("%d",&z);
	     	          if (z==1){
	     	          	printf("\n¿Cuál equipo? ");
	     	          	scanf("%d",&j);
	     	          	equipo[j].suma=equipo[j].suma+300;
					   }
					   break;
					}

	     	case 2:
	     	         ced=ced+1;//cd va ser la variable de cuantas veces pase por la de 200
	     	        g=ced;
	     	        linea(g);
	     	         printf("\n¿Respondió correcto? 1=si 0=no");
	     	        scanf("%d",&y);
			        if (y==1)
					{
					equipo[nume].suma=equipo[nume].suma+200;
					break;
			       	}
	     	        else
	     	        { equipo[nume].suma=equipo[nume].suma-200;
	     	            printf("\n¿Algun equipo respodió correcto? 1=Si 0=No");
	     	          scanf("%d",&z);
	     	          if (z==1){
	     	          	printf("\n¿Cuál equipo? ");
	     	          	scanf("%d",&j);
	     	          	equipo[j].suma=equipo[j].suma+200;
					   }
					   break;
					}

	     	case 3:  cec=cec+1;//ct va ser la variable de cuantas veces pase por la de 300
	     	        g=cec;
	     	        linea(g);
	     	    printf("\n¿Respondió correcto? 1=si 0=no");
	     	        scanf("%d",&y);
			        if (y==1)
					{
					equipo[nume].suma=equipo[nume].suma+100;
					break;
			       	}
	     	        else
	     	        {   equipo[nume].suma=equipo[nume].suma-100;
	     	            printf("\n¿Algun equipo respodió correcto? 1=Si 0=No");
	     	          scanf("%d",&z);
	     	          if (z==1){
	     	          	printf("\n¿Cuál equipo? ");
	     	          	scanf("%d",&j);
                        equipo[j].suma=equipo[j].suma+100;
					   }
					   break;
					}
		 }
}

