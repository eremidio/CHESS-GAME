//ESTE ARQUIVO CONTÉM FUNÇÕES DE TEXTO QUE SERÃO USADAS NA APLICAÇÃO
//***************************************************************************************************************************
/*CABEÇALHO*/
#include<cstdio>
#include<cstdlib>
using namespace std;

//***************************************************************************************************************************

//CABEÇALHO
void introduction(){
printf("\n");
printf("\033[94m\033[01m  CCCCC  HH   HH EEEEEEE  SSSSS   SSSSS  \n\033[0m");
printf("\033[94m\033[01m CC    C HH   HH EE      SS      SS      \n\033[0m");
printf("\033[94m\033[01m CC      HHHHHHH EEEEE    SSSSS   SSSSS  \n\033[0m");
printf("\033[94m\033[01m CC    C HH   HH EE           SS      SS \n\033[0m");
printf("\033[94m\033[01m  CCCCC  HH   HH EEEEEEE  SSSSS   SSSSS  \n\033[0m");
printf("\n");
printf("\033[01m Bem vindo ao jogo de xadrez!\nEsperamos que você se divirta!!! \033[0m");
printf("\033[01m vamos jogar este jogo num tabuleiro 8x8:\033[0m\n");
printf("+------+------+------+------+------+------+------+------+  \n");
printf("|      |      |      |      |      |      |      |      |  \n");
printf("|      |      |      |      |      |      |      |      | 8\n");
printf("|      |      |      |      |      |      |      |      |  \n");
printf("+------+------+------+------+------+------+------+------+  \n");
printf("|      |      |      |      |      |      |      |      |  \n");
printf("|      |      |      |      |      |      |      |      | 7\n");
printf("|      |      |      |      |      |      |      |      |  \n");
printf("+------+------+------+------+------+------+------+------+  \n");
printf("|      |      |      |      |      |      |      |      |  \n");
printf("|      |      |      |      |      |      |      |      | 6\n");
printf("|      |      |      |      |      |      |      |      |  \n");
printf("+------+------+------+------+------+------+------+------+  \n");
printf("|      |      |      |      |      |      |      |      |  \n");
printf("|      |      |      |      |      |      |      |      | 5\n");
printf("|      |      |      |      |      |      |      |      |  \n");
printf("+------+------+------+------+------+------+------+------+  \n");
printf("|      |      |      |      |      |      |      |      |  \n");
printf("|      |      |      |      |      |      |      |      | 4\n");
printf("|      |      |      |      |      |      |      |      |  \n");
printf("+------+------+------+------+------+------+------+------+  \n");
printf("|      |      |      |      |      |      |      |      |  \n");
printf("|      |      |      |      |      |      |      |      | 3\n");
printf("|      |      |      |      |      |      |      |      |  \n");
printf("+------+------+------+------+------+------+------+------+  \n");
printf("|      |      |      |      |      |      |      |      |  \n");
printf("|      |      |      |      |      |      |      |      | 2\n");
printf("|      |      |      |      |      |      |      |      |  \n");
printf("+------+------+------+------+------+------+------+------+  \n");
printf("|      |      |      |      |      |      |      |      |  \n");
printf("|      |      |      |      |      |      |      |      | 1\n");
printf("|      |      |      |      |      |      |      |      |  \n");
printf("+------+------+------+------+------+------+------+------+  \n");
printf("   a      b       c      d      e      f      g      h     \n");
printf("\n");
                   };

void how_to_play(){
printf("\033[01m\nEis as regras de como usar esta aplicação:\nPara executar o movimento de uma peça você deve especificar a posição inicial e a posição final das casas do tabuleiro que caracterizam o movimento\nusando a notação de coordenadas do tabuleiro acima como 'a1', 'b7', etc.\nA notação 'o-o' será usada para denotar o pequeno roque e a notação 'o-o-o' denota o grande roque, movimentos especiais do jogo.\nPara fazer uma captura de peões en passant digite 'en' quando lhe for solicitado que especifique a casa inicial, em seguida siga as instruções na tela do app.\nInsira estes comandos para execução do roque quando lhe for solicitado a casa inicial na qual está a peça a ser movida\nAs peças de cada jogador são especificadas por uma sigla contendo o primeira letra do nome e a cor da peça:\nPB-> peão branco, CB-> cavalo branco, BB-> bispo branco, TB-> Torre branca, DB-> dama branca, RB-> rei branco\nPP-> peão preto, CP-> cavalo preto, BP-> bispo preto, TP-> Torre preta, DP-> dama preta, RP-> rei preto.\nEm caso de promoção de peões o usuário deverá usar a notação acima para especificar para qual peça o peão será promovido.\nQuando aparecer o símbolo ':::' digite 'e' para propor empate ao adversário ou aperte enter para continuar.\nAs regras básicas do jogo e a movimentação básica das peças estão disponíveis nos links:\nhttps://pt.wikipedia.org/wiki/Leis_do_xadrez e https://pt.wikipedia.org/wiki/Xadrez\n \033[0m");
                  };

void credits(){
printf("\033[95m\nEscrito por Elias Rodrigues Emídio.\n\033[0m");
              };

void end_text(){

printf("\033[34m\033[05m\033[01m  OOOOO  BBBBB   RRRRRR  IIIII   GGGG    AAA   DDDDD    OOOOO     PPPPPP   OOOOO  RRRRRR  \n\033[0m");        
printf("\033[34m\033[05m\033[01m OO   OO BB   B  RR   RR  III   GG  GG  AAAAA  DD  DD  OO   OO    PP   PP OO   OO RR   RR \n\033[0m");        
printf("\033[34m\033[05m\033[01m OO   OO BBBBBB  RRRRRR   III  GG      AA   AA DD   DD OO   OO    PPPPPP  OO   OO RRRRRR  \n\033[0m");        
printf("\033[34m\033[05m\033[01m OO   OO BB   BB RR  RR   III  GG   GG AAAAAAA DD   DD OO   OO    PP      OO   OO RR  RR  \n\033[0m");        
printf("\033[34m\033[05m\033[01m  OOOO0  BBBBBB  RR   RR IIIII  GGGGGG AA   AA DDDDDD   OOOO0     PP       OOOO0  RR   RR \n\n\033[0m");        
                                                                                         
printf("\033[34m\033[05m\033[01m     JJJ  OOOOO    GGGG    AAA   RRRRRR     !!! !!! !!!                                  \n\033[0m");        
printf("\033[34m\033[05m\033[01m     JJJ OO   OO  GG  GG  AAAAA  RR   RR    !!! !!! !!!                                   \n\033[0m");        
printf("\033[34m\033[05m\033[01m     JJJ OO   OO GG      AA   AA RRRRRR     !!! !!! !!!                                   \n\033[0m");        
printf("\033[34m\033[05m\033[01m JJ  JJJ OO   OO GG   GG AAAAAAA RR  RR                                                   \n\033[0m");        
printf("\033[34m\033[05m\033[01m  JJJJJ   OOOO0   GGGGGG AA   AA RR   RR    !!! !!! !!!  \n\n\033[0m");        
              };


