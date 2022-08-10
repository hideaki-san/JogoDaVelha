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
        Tabuleiro(C);

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
                n = 9;
                Tabuleiro(C);
                printf("\n\nJOGADOR 2(x) FOI O VENCEDOR");
                printf("\n\n-JOGO FINALIZADO-\n");
                C = AlocaMemoria();
                system("pause");
                }
              if(i == 2)
                {
                n = 9;
                Tabuleiro(C);
                printf("\n\nJOGADOR 1(o) FOI O VENCEDOR");
                printf("\n\n-JOGO FINALIZADO-\n");
                C = AlocaMemoria();
                system("pause");
                }
            }
        }

      Tabuleiro(C);

      printf("\n\n-SAIR(0)-\n-JOGAR(1)-\n");
      LiberarTabuleiro(C);
      C = AlocaMemoria();
      fflush(stdin);
      scanf("%d", &z);

      }while(z != 0);

  LiberarTabuleiro(C);
  system("cls");
  return 0;
  }
