#include <stdio.h>
#include <stdlib.h>

char **AlocaMemoria();
int FinalizaJogo(char **M);
void LiberarTabuleiro(char **M);
void InserirJogador2(char **M);
void InserirJogador1(char **M);

char **AlocaMemoria()
  {
  char **M;
  int linha=0, coluna=0;

  M =(char **) malloc(sizeof(char *));

    for(linha = 0; linha < 3; linha++)
      {
      *(M + linha) = (char *) malloc(coluna * sizeof(char));
      }

    for(linha = 0; linha < 3; linha++)
      {
        for(coluna = 0; coluna < 3; coluna++)
          {
          *(*(M + linha) + coluna) =  ' ';
          }
      }
  return(M);
  }

int FinalizaJogo(char **M)
  {
  if( (*(*(M + 0) + 0)) == 'x' && (*(*(M + 0) + 1)) == 'x' && (*(*(M + 0) + 2)) == 'x' )
    return 1;
  if( (*(*(M + 1) + 0)) == 'x' && (*(*(M + 1) + 1)) == 'x' && (*(*(M + 1) + 2)) == 'x' )
    return 1;
  if( (*(*(M + 2) + 0)) == 'x' && (*(*(M + 2) + 1)) == 'x' && (*(*(M + 2) + 2)) == 'x' )
    return 1;


  if( (*(*(M + 0) + 0)) == 'x' && (*(*(M + 1) + 0)) == 'x' && (*(*(M + 2) + 0)) == 'x' )
    return 1;
  if( (*(*(M + 0) + 1)) == 'x' && (*(*(M + 1) + 1)) == 'x' && (*(*(M + 2) + 1)) == 'x' )
    return 1;
  if( (*(*(M + 0) + 2)) == 'x' && (*(*(M + 1) + 2)) == 'x' && (*(*(M + 2) + 2)) == 'x' )
    return 1;


  if( (*(*(M + 0) + 0)) == 'x' && (*(*(M + 1) + 1)) == 'x' && (*(*(M + 2) + 2)) == 'x' )
    return 1;
  if( (*(*(M + 0) + 2)) == 'x' && (*(*(M + 1) + 1)) == 'x' && (*(*(M + 2) + 0)) == 'x' )
    return 1;


  if( (*(*(M + 0) + 0)) == 'o' && (*(*(M + 0) + 1)) == 'o' && (*(*(M + 0) + 2)) == 'o' )
    return 2;
  if( (*(*(M + 1) + 0)) == 'o' && (*(*(M + 1) + 1)) == 'o' && (*(*(M + 1) + 2)) == 'o' )
    return 2;
  if( (*(*(M + 2) + 0)) == 'o' && (*(*(M + 2) + 1)) == 'o' && (*(*(M + 2) + 2)) == 'o' )
    return 2;


  if( (*(*(M + 0) + 0)) == 'o' && (*(*(M + 1) + 0)) == 'o' && (*(*(M + 2) + 0)) == 'o' )
    return 2;
  if( (*(*(M + 0) + 1)) == 'o' && (*(*(M + 1) + 1)) == 'o' && (*(*(M + 2) + 1)) == 'o' )
    return 2;
  if( (*(*(M + 0) + 2)) == 'o' && (*(*(M + 1) + 2)) == 'o' && (*(*(M + 2) + 2)) == 'o' )
    return 2;


  if( (*(*(M + 0) + 0)) == 'o' && (*(*(M + 1) + 1)) == 'o' && (*(*(M + 2) + 2)) == 'o' )
    return 2;
  if( (*(*(M + 0) + 2)) == 'o' && (*(*(M + 1) + 1)) == 'o' && (*(*(M + 2) + 0)) == 'o' )
    return 2;

return 0;
  }

void LiberarTabuleiro(char **M)
  {
  int linha = 0;
    for(linha = 0; linha < 3; linha++)
      {
      free(*(M + linha));
      *(M + linha) = NULL;
      }
  free(M);
  M = NULL;
  }

void InserirJogador2(char **M)
  {
  int linha = 0, coluna = 0;

  printf("\n\n-JOGADOR 2(x)-\n");
  printf("\nLINHA: ");
  fflush(stdin);
  scanf("%d", &linha);
  printf("\nCOLUNA: ");
  fflush(stdin);
  scanf("%d", &coluna);

    if(linha > 3 || linha < 1 || coluna > 3 || coluna < 1)
      {
        while(linha > 3 || linha < 1 || coluna > 3 || coluna < 1)
          {
          printf("\n\nPOSICAO INEXISTENTE");
          printf("\n\n-JOGADOR 2(x)-\n");
          printf("\nLINHA: ");
          fflush(stdin);
          scanf("%d", &linha);
          printf("\nCOLUNA: ");
          fflush(stdin);
          scanf("%d", &coluna);
          }
      }

  linha = (linha - 1);
  coluna = (coluna - 1);

    if( (*(*(M + linha) + coluna)) == 'x' || (*(*(M + linha) + coluna)) == 'o' )
      {
        while((*(*(M + linha) + coluna)) == 'x' || (*(*(M + linha) + coluna)) == 'o')
          {
          system("cls");
          printf("\n\t %c | %c | %c", (*(*(M + 0) + 0)), (*(*(M + 0) + 1)), (*(*(M + 0) + 2)));
          printf("\n\t-----------");
          printf("\n\t %c | %c | %c", (*(*(M + 1) + 0)), (*(*(M + 1) + 1)), (*(*(M + 1) + 2)));
          printf("\n\t-----------");
          printf("\n\t %c | %c | %c", (*(*(M + 2) + 0)), (*(*(M + 2) + 1)), (*(*(M + 2) + 2)));

          printf("\n\n-POSICAO JA OCUPADA\n\n");
          printf("\n\n-JOGADOR 2(x)-\n");
          printf("\nLINHA: ");
          fflush(stdin);
          scanf("%d", &linha);
          printf("\nCOLUNA: ");
          fflush(stdin);
          scanf("%d", &coluna);

          linha = (linha - 1);
          coluna = (coluna - 1);
          }
      *(*(M + linha) + coluna) = 'x';
      }
    else
      {
      *(*(M + linha) + coluna) = 'x';
      }
  }

void InserirJogador1(char **M)
  {
  int linha = 0, coluna = 0;

  printf("\n\n-JOGADOR 1(o)-\n");
  printf("\nLINHA: ");
  fflush(stdin);
  scanf("%d", &linha);
  printf("\nCOLUNA: ");
  fflush(stdin);
  scanf("%d", &coluna);

  if(linha > 3 || linha < 1 || coluna > 3 || coluna < 1)
      {
        while(linha > 3 || linha < 1 || coluna > 3 || coluna < 1)
          {
          printf("\n\nPOSICAO INEXISTENTE");
          printf("\n\n-JOGADOR 1(o)-\n");
          printf("\nLINHA: ");
          fflush(stdin);
          scanf("%d", &linha);
          printf("\nCOLUNA: ");
          fflush(stdin);
          scanf("%d", &coluna);
          }
      }

  linha = (linha - 1);
  coluna = (coluna - 1);

    if( (*(*(M + linha) + coluna)) == 'x' || (*(*(M + linha) + coluna)) == 'o' )
      {
        while((*(*(M + linha) + coluna)) == 'x' || (*(*(M + linha) + coluna)) == 'o')
          {
          system("cls");
          printf("\n\t %c | %c | %c", (*(*(M + 0) + 0)), (*(*(M + 0) + 1)), (*(*(M + 0) + 2)));
          printf("\n\t-----------");
          printf("\n\t %c | %c | %c", (*(*(M + 1) + 0)), (*(*(M + 1) + 1)), (*(*(M + 1) + 2)));
          printf("\n\t-----------");
          printf("\n\t %c | %c | %c", (*(*(M + 2) + 0)), (*(*(M + 2) + 1)), (*(*(M + 2) + 2)));

          printf("\n\n-POSICAO JA OCUPADA\n\n");
          printf("\n\n-JOGADOR 1(o)-\n");
          printf("\nLINHA: ");
          fflush(stdin);
          scanf("%d", &linha);
          printf("\nCOLUNA: ");
          fflush(stdin);
          scanf("%d", &coluna);

          linha = (linha - 1);
          coluna = (coluna - 1);
          }
        *(*(M + linha) + coluna) = 'o';
      }
    else
      {
      *(*(M + linha) + coluna) = 'o';
      }
  }


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
