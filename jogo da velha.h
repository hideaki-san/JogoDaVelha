//ESPECIFICAÇAO

#ifndef JOGO_VELHA_H
#define JOGO_VELHA_H

//ASSINATURAS

char **AlocaMemoria();
int FinalizaJogo(char **M);
void LiberarTabuleiro(char **M);
void InserirJogador2(char **M);
void InserirJogador1(char **M);

#endif