/*Una emisora de radio quiere hacer un concurso en el que proponen a sus oyentes los títulos de 10
canciones, a las que ha numerado del 0 al 9. Cada participante debe llamar para dar los números de 3
títulos por orden de preferencia decreciente. Se le dan 3 puntos a la canción que el oyente nombra en
1er lugar, 2 puntos a la que indica en 2do lugar y 1 punto al 3er lugar.*/
/*1.- Leer y almacenar los votos emitidos por cada oyente, suponemos que como máximo pueden
concursar 100 oyentes. Y a medida que llaman los concursantes se les asigna un número de forma
correlativa. La entrada de datos se realizará en forma de tríos, con los números de las canciones que
vota cada oyente. Para finalizar se introducirá el valor -1 en el primer dato del trio, sin importar el valor
de los otros dos datos.*/
#include <stdio.h>
//Arreglos globales 
int votos [5][3];
int contcanciones[10]={0};
int i,j;
//prototipos de funciones
int guardado();
int canciones();
void repeticiones(int total);


int main()
{
  printf("Bienvenido al concurso de la 3.14\n");
  printf("A continuacion se le presentara las 10 canciones mas escuchadas\n");
  for(i=0;i<10;i++)
    {
      printf("Cancion %d\n",i);
    }
  printf("Con las canciones mostradas seleccione las tres que mas le gusten en orden desendiente\n\n");
  printf("Para terminar con la votacion ingrese como primer valor el -1\n\n");
  int total= guardado();
  printf("\n--- Resultados guardados ---\n");
  for(int i = 0; i < total; i++) 
  {
    printf("Oyente %d: %d %d %d\n", i+1, votos[i][0], votos[i][1], votos[i][2]);
  }
  repeticiones(total);
  return 0;
}



int guardado()
{
  int i=0
  while (i<5)
    {
      
      printf("Oyente %d: ",i+1);
      scanf("%d",&votos[i][0]);
        if(votos[i][0] == -1)
        {
          votos[i][1]=0;
          votos[i][2]=0;
          break;
        }
        scanf("%d %d",&votos[i][1],&votos[i][2]);
        i++;
        }
   printf("Los votos han sido guardados correctamente\n");
   return i;  
}


void repeticiones(int total) 
{
    for(i = 0; i < total; i++)
    {
        for(j = 0; j < 3; j++) 
        {
            contcanciones[votos[i][j]]++;
        }
    }
    
    printf("\n--- TOP 3 CANCIONES GANADORAS ---\n");
    for(int lugar = 1; lugar <= 3; lugar++)
      {
        int maxvotos = -1; 
        int cancionganadora = -1;
        for(i = 0; i < 10; i++)
        {
            if(contcanciones[i] > maxvotos)
            {
                maxvotos = contcanciones[i];
                cancionganadora = i;
            }
        }
        if(cancionganadora != -1)
        {
            printf("Lugar %d: Cancion numero %d con %d votos\n", lugar, cancionganadora, maxvotos);
            contcanciones[cancionganadora] = -1;
        }
    }
}
/*2.- Calcular los votos obtenidos por cada canción e indicar cuáles son la 1er y 2da canción más votada.
Según el ejemplo anterior:*/





