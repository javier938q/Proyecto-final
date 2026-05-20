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
int votos [100][3];
int contcanciones[10]={0};
int top3[3];
int puntos[100]={0};
int i,j;
//prototipos de funciones
int guardado();
int canciones();
void puntajeganador(int total);
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
  
  int total= guardado();//nota:aqui es dond ese hace el llamada a la funcion 
  
  printf("\n--- Resultados guardados ---\n");
  for(int i = 0; i < total; i++) 
  {
    printf("Oyente %d: %d %d %d\n", i+1, votos[i][0], votos[i][1], votos[i][2]);
  }
  repeticiones(total);
  puntajegandor(total);
  return 0;
}



int guardado()
{
  int i=0;
  while (i<100)
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

/*2.- Calcular los votos obtenidos por cada canción e indicar cuáles son la 1er y 2da canción más votada.
Según el ejemplo anterior:*/

void repeticiones(int total)//nota:esta es la funcion de contara los votos y hara el top tres de las canciones
{
    for(i = 0; i < total; i++)
    {
        for(j = 0; j < 3; j++) 
        {
            contcanciones[votos[i][j]]++;
        }
    }
    printf("\n--- TOP 3 CANCIONES mas votadas---\n");
    int cancionganadora;
    int maxvotos;
    int lugar;
    for(lugar = 0; lugar <3; lugar++)
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
      top3[lugar] = cancionganadora;
       
        if(cancionganadora != -1)
        {
          printf("Lugar %d: Cancion numero %d con %d votos\n", lugar+1, cancionganadora, maxvotos);
          printf("\n\n");
          contcanciones[cancionganadora] = -1;
        }
    }
}
/*3.- Al final de la emisión se reparten puntos entre los oyentes que han concursado de la siguiente
manera: 30 puntos si entre las 3 canciones votadas está la no. 1, 20 puntos si está la no. 2 y 10 puntos
suplementarios si han acertado los dos títulos más votados. Se desea obtener el número del oyente que
más puntos ha obtenido, ya que se le dará un premio.*/
void puntajeganador(int total)
{
  int ganador=-1;
  int oyente=0;
  for(i=0;i<3;i++)
  {
    printf("%d\n",top3[i]);
  }
  printf("\n\n");
  printf("%d",total);
  printf("---A continuacion se hara la reparticion de puntoos---\n");
  for(i = 0; i < total; i++)
  {
    for(j = 0; j < 3; j++)
      {
        if(votos[i][j] == 1)
        {
          puntos[i]=puntos[i]+30;
        }
        if(votos[i][j] == 2)
        {
          puntos[i]=puntos[i]+20;       
        }
        if(votos[i][j]==top3[0])
          {
              puntos[i]=puntos[i]+10;
          }
       }
       printf("El Oyente %d consiguio un total de: %d puntos\n\n", i + 1, puntos[i]);
        if(puntos[i]>ganador)
        {
          ganador=puntos[i];
          oyente=i;
        }
    }
    printf("EL GANADOR DEL CONCURSO ES EL OYENTE %d CON UN TOTAL DE %d PUNTOS\n",oyente,gandor);
    printf("TE GANASTE UN PAR DE BOLETOS PARA IR A VER CEPILLIN");
}

    




