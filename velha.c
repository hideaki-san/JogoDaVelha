#include "jogo da velha.h"
#include <stdio.h>
#include <stdlib.h>

int main()
  {
  char **C;
  int n = 0,i = 0, z = 1;

  C = AlocaMemoria();

  printf("-SAIR(0)-\n-JOGAR(1)-\n");
  fflush(stdin);
  scanf("%d", &z);

     do
      {
      for(n = 0; n < 9; n++)
        {
        system("cls");
        printf("\n\t %c | %c | %c", (*(*(C + 0) + 0)), (*(*(C + 0) + 1)), (*(*(C + 0) + 2)));
        printf("\n\t-----------");
        printf("\n\t %c | %c | %c", (*(*(C + 1) + 0)), (*(*(C + 1) + 1)), (*(*(C + 1) + 2)));
        printf("\n\t-----------");
        printf("\n\t %c | %c | %c", (*(*(C + 2) + 0)), (*(*(C + 2) + 1)), (*(*(C + 2) + 2)));


          if(n % 2 != 0)
            {
            InserirJogador2(C);
            }
          else
            {
            InserirJogador1(C);
            }

          if(n >= 4)
            {
            i = FinalizaJogo(C);
              if(i == 1)
                {
                system("cls");
                n = 9;
                printf("\n\t %c | %c | %c", (*(*(C + 0) + 0)), (*(*(C + 0) + 1)), (*(*(C + 0) + 2)));
                printf("\n\t-----------");
                printf("\n\t %c | %c | %c", (*(*(C + 1) + 0)), (*(*(C + 1) + 1)), (*(*(C + 1) + 2)));
                printf("\n\t-----------");
                printf("\n\t %c | %c | %c", (*(*(C + 2) + 0)), (*(*(C + 2) + 1)), (*(*(C + 2) + 2)));
                printf("\n\nJOGADOR 2(x) FOI O VENCEDOR");
                printf("\n\n-JOGO FINALIZADO-\n");
                C = AlocaMemoria();
                system("pause");
                }
              if(i == 2)
                {
                system("cls");
                n = 9;
                printf("\n\t %c | %c | %c", (*(*(C + 0) + 0)), (*(*(C + 0) + 1)), (*(*(C + 0) + 2)));
                printf("\n\t-----------");
                printf("\n\t %c | %c | %c", (*(*(C + 1) + 0)), (*(*(C + 1) + 1)), (*(*(C + 1) + 2)));
                printf("\n\t-----------");
                printf("\n\t %c | %c | %c", (*(*(C + 2) + 0)), (*(*(C + 2) + 1)), (*(*(C + 2) + 2)));
                printf("\n\nJOGADOR 1(o) FOI O VENCEDOR");
                printf("\n\n-JOGO FINALIZADO-\n");
                C = AlocaMemoria();
                system("pause");
                }
            }
        }

      system("cls");
      printf("\n\t %c | %c | %c", (*(*(C + 0) + 0)), (*(*(C + 0) + 1)), (*(*(C + 0) + 2)));
      printf("\n\t-----------");
      printf("\n\t %c | %c | %c", (*(*(C + 1) + 0)), (*(*(C + 1) + 1)), (*(*(C + 1) + 2)));
      printf("\n\t-----------");
      printf("\n\t %c | %c | %c", (*(*(C + 2) + 0)), (*(*(C + 2) + 1)), (*(*(C + 2) + 2)));

      printf("\n\n-SAIR(0)-\n-JOGAR(1)-\n");
      C = AlocaMemoria();
      fflush(stdin);
      scanf("%d", &z);

      }while(z != 0);

  LiberarTabuleiro(C);
  system("cls");
  return 0;
  }
