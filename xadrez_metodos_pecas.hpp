//ESTE ARQUIVO IRÁ CONTER MÉTODOS PARA EXECUTAR O MOVIMENTO DE PEÇAS

/*CABEÇALHO*/
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include"xadrez_classe.hpp"
using namespace std;

//****************************************************************************************************************************
//FUNÇÕES QUE VALIDAM O MOVIMENTO DE PEÇAS (USAREMOS QUATRO REPRESENTANDO AS COORDENADAS LINHAS/COLUNAS INICIAIS E FINAIS)

//PEÃO DAS BRANCAS
bool chess_game::validate_white_pawn_move(int x1, int y1, int x2, int y2){
//CHECANDO SE  AS COORDENADAS ESTÃO DENTRO DO LIMITE ACEITÁVEL
if(x1<0 || x1>7 || y1<0 || y1>7 || x2<0 || x2>7 || y2<0 || y2>7){
return false;
                                                                };
//MOVIMENTOS REGULARES DE PEÃO (+2,0) OU (+1, 0) 
//CASA INICIAL 
if(x1==1 && (x2-x1)<=2 && (x2-x1)>0 && y1==y2 && board[x2][y2]=="  ")
return true;
if(x1>1 && (x2-x1)==1 && y1==y2 && board[x2][y2]=="  ")
return true;

//MOVIMENTO DE CAPTURA (+1,-1) OU (-1, +1)
if((x2-x1)==1 && abs(y1-y2)==1){
if(board[x2][y2]=="TP" || board[x2][y2]=="BP" || board[x2][y2]=="CP" || board[x2][y2]=="DP" || board[x2][y2]=="PP")
return true;
                                  };

//MOVIMENTO DE CAPTURA EM PASSANT
if(white_en_passant==true){
if(board[x1][y1-1]=="PP" && (y1-1)>=0)
{return true;}
if(board[x1][y1+1]=="PP" && (y1+1)<8)
{return true;}
                          };

//CASO NENHUMA DAS CONDIÇÕES ACIMA SEJA SATISFEITA
return false;
                                                                         };

//PEÃO DAS NEGRAS
bool chess_game::validate_black_pawn_move(int x1, int y1, int x2, int y2){
//CHECANDO SE  AS COORDENADAS ESTÃO DENTRO DO LIMITE ACEITÁVEL
if(x1<0 || x1>7 || y1<0 || y1>7 || x2<0 || x2>7 || y2<0 || y2>7){
return false;
                                                                };
//MOVIMENTOS REGULARES DE PEÃO (-2,0) OU (-1, 0) 
//CASA INICIAL 
if(x1==6 && (x1-x2)<=2 && (x1-x2)>0 && y1==y2 && board[x2][y2]=="  ")
return true;
if(x1<6 && (x1-x2)==1 && y1==y2 && board[x2][y2]=="  ")
return true;
//MOVIMENTO DE CAPTURA (+1,-1) OU (-1, +1)
if((x1-x2)==1 && abs(y1-y2)==1){
if(board[x2][y2]=="TB" || board[x2][y2]=="BB" || board[x2][y2]=="CB" || board[x2][y2]=="DB" || board[x2][y2]=="PB")
return true;
                                  };
//MOVIMENTO DE CAPTURA EM PASSANT
if(black_en_passant==true){
if(board[x1][y1-1]=="PB" && (y1-1)>=0)
return true;
if(board[x1][y1+1]=="PB" && (y1+1)<8)
return true;

                          };

//CASO NENHUMA DAS CONDIÇÕES ACIMA SEJA SATISFEITA
return false;
                                                                         };

//CAVALO DAS BRANCAS
bool chess_game::validate_white_knight_move(int x1, int y1, int x2, int y2){
//CHECANDO SE  AS COORDENADAS ESTÃO DENTRO DO LIMITE ACEITÁVEL
if(x1<0 || x1>7 || y1<0 || y1>7 || x2<0 || x2>7 || y2<0 || y2>7){
return false;
                                                                };

//CAVALO FAZ MOVIMENTOS EM L (+/-1, +/-2) OU (+/-2, +/-1) E NÃO POUSA SOBRE PEÇAS DO PRÓPRIO JOGADOR
if(abs(x1-x2)==2 && abs(y1-y2)==1){
if(board[x2][y2]!="PB" && board[x2][y2]!="TB" && board[x2][y2]!="CB" && board[x2][y2]!="BB" && board[x2][y2]!="DB" && board[x2][y2]!="RB")
return true;
                                  };
if(abs(x1-x2)==1 && abs(y1-y2)==2){
if(board[x2][y2]!="PB" && board[x2][y2]!="TB" && board[x2][y2]!="CB" && board[x2][y2]!="BB" && board[x2][y2]!="DB" && board[x2][y2]!="RB")
return true;
                                  };

//CASO NENHUMA DAS CONDIÇÕES ACIMA SEJA SATISFEITA
return false;
                                                                           };

//CAVALO DAS NEGRAS
bool chess_game::validate_black_knight_move(int x1, int y1, int x2, int y2){
//CHECANDO SE  AS COORDENADAS ESTÃO DENTRO DO LIMITE ACEITÁVEL
if(x1<0 || x1>7 || y1<0 || y1>7 || x2<0 || x2>7 || y2<0 || y2>7){
return false;
                                                                };

//CAVALO FAZ MOVIMENTOS EM L (+/-1, +/-2) OU (+/-2, +/-1) E NÃO POUSA SOBRE PEÇAS DO PRÓPRIO JOGADOR
if(abs(x1-x2)==2 && abs(y1-y2)==1){
if(board[x2][y2]!="PP" && board[x2][y2]!="TP" && board[x2][y2]!="CP" && board[x2][y2]!="BP" && board[x2][y2]!="DP" && board[x2][y2]!="RP")
return true;
                                  };
if(abs(x1-x2)==1 && abs(y1-y2)==2){
if(board[x2][y2]!="PP" && board[x2][y2]!="TP" && board[x2][y2]!="CP" && board[x2][y2]!="BP" && board[x2][y2]!="DP" && board[x2][y2]!="RP")
return true;
                                  };

//CASO NENHUMA DAS CONDIÇÕES ACIMA SEJA SATISFEITA
return false;
                                                                           };


//BISPO DAS BRANCAS
bool chess_game::validate_white_bishop_move(int x1, int y1, int x2, int y2){
//VARIÁVEIS LOCAIS
int i, j, gap_h, gap_v;

//AJUSTE DE VARIÁVEIS
gap_v=x2-x1;
gap_h=y2-y1;

//CHECANDO SE  AS COORDENADAS ESTÃO DENTRO DO LIMITE ACEITÁVEL
if(x1<0 || x1>7 || y1<0 || y1>7 || x2<0 || x2>7 || y2<0 || y2>7){
return false;
                                                                };
//BISPOS SE MOVEM EM DIAGONAIS
if(abs(gap_h)!=abs(gap_v)){
return false;
                          };

//CHECANDO POR OBSTRUÇÕES DAS PRÓPRIAS PEÇAS E DAS PEÇAS ADVERSÁRIAS
//OBSTRUÇÃO NA CASA DE DESTINO
if(board[x2][y2]=="TB" || board[x2][y2]=="CB" || board[x2][y2]=="DB" || board[x2][y2]=="PB" || board[x2][y2]=="RB"){
return false;
                                                                                                                   };
//DIAGONAL SUPERIOR DIREITA(+1, +1)
if(gap_v>0 && gap_h>0){
for(i=1; i<gap_v; ++i){
if(board[x1+i][y1+i]!="  "){
return false;
                           };
                      };
                      };

//DIAGONAL SUPERIOR ESQUERDA(+1, -1)
if(gap_v>0 && gap_h<0){
for(i=1; i<gap_v; ++i){
if(board[x1+i][y1-i]!="  "){
return false;
                           };
                      };
                      };

//DIAGONAL INFERIOR DIREITA(-1, +1)
if(gap_v<0 && gap_h>0){
for(i=1; i<abs(gap_v); ++i){
if(board[x1-i][y1+i]!="  "){
return false;
                           };
                           };
                      };

//DIAGONAL INFERIOR ESQUERDA(-1, -1)
if(gap_v<0 && gap_h>0){
for(i=1; i<abs(gap_v); ++i){
if(board[x1-i][y1-i]!="  "){
return false;
                           };
                           };
                      };
//CASO NENHUMA DAS CONDIÇÕES ACIMA SEJA SATISFEITA
return true;
                                                                           };

//BISPO DAS NEGRAS
bool chess_game::validate_black_bishop_move(int x1, int y1, int x2, int y2){
//VARIÁVEIS LOCAIS
int i, j, gap_h, gap_v;

//AJUSTE DE VARIÁVEIS
gap_v=x2-x1;
gap_h=y2-y1;

//CHECANDO SE  AS COORDENADAS ESTÃO DENTRO DO LIMITE ACEITÁVEL
if(x1<0 || x1>7 || y1<0 || y1>7 || x2<0 || x2>7 || y2<0 || y2>7){
return false;
                                                                };
//BISPOS SE MOVEM EM DIAGONAIS
if(abs(gap_h)!=abs(gap_v)){
return false;
                          };

//CHECANDO POR OBSTRUÇÕES DAS PRÓPRIAS PEÇAS E DAS PEÇAS ADVERSÁRIAS
//OBSTRUÇÃO NA CASA DE DESTINO
if(board[x2][y2]=="TP" || board[x2][y2]=="CP" || board[x2][y2]=="DP" || board[x2][y2]=="PP" || board[x2][y2]=="RP"){
return false;
                                                                                                                   };
//DIAGONAL SUPERIOR DIREITA(+1, +1)
if(gap_v>0 && gap_h>0){
for(i=1; i<gap_v; ++i){
if(board[x1+i][y1+i]!="  "){
return false;
                           };
                      };
                      };

//DIAGONAL SUPERIOR ESQUERDA(+1, -1)
if(gap_v>0 && gap_h<0){
for(i=1; i<gap_v; ++i){
if(board[x1+i][y1-i]!="  "){
return false;
                           };
                      };
                      };

//DIAGONAL INFERIOR DIREITA(-1, +1)
if(gap_v<0 && gap_h>0){
for(i=1; i<abs(gap_v); ++i){
if(board[x1-i][y1+i]!="  "){
return false;
                           };
                           };
                      };

//DIAGONAL INFERIOR ESQUERDA(-1, -1)
if(gap_v<0 && gap_h>0){
for(i=1; i<abs(gap_v); ++i){
if(board[x1-i][y1-i]!="  "){
return false;
                           };
                           };
                      };
//CASO NENHUMA DAS CONDIÇÕES ACIMA SEJA SATISFEITA
return true;

                                                                           };

//TORRES DAS BRANCAS
bool chess_game::validate_white_rook_move(int x1, int y1, int x2, int y2){
//VARIÁVEIS LOCAIS
int i, j, gap_h, gap_v;
//AJUSTE DE VARIÁVEIS
gap_v=x2-x1;
gap_h=y2-y1;

//CHECANDO SE  AS COORDENADAS ESTÃO DENTRO DO LIMITE ACEITÁVEL
if(x1<0 || x1>7 || y1<0 || y1>7 || x2<0 || x2>7 || y2<0 || y2>7){
return false;
                                                                };
//TORRES SE MOVEM LINHA RETA
if(gap_v!=0 && gap_h!=0){
return false;
                        };

//CHECANDO POR OBSTRUÇÕES DE PEÇAS
//CASA DE DESTINO
if(board[x2][y2]=="TB" || board[x2][y2]=="CB" || board[x2][y2]=="DB" || board[x2][y2]=="BB" || board[x2][y2]=="PB" || board[x2][y2]=="RB"){
return false;
           };

//CIMA(+1, 0)
if(gap_v>0){
for(i=1; i<gap_v; ++i){
if(board[x1+i][y1]!="  "){
return false;
                         };
                      };
           };
//BAIXO(-1, 0)
if(gap_v<0){
for(i=0; i<abs(gap_v); ++i){
if(board[x1-i][y1]!="  "){
return false;
                         };
                           };
           };

//DIREITA(0, +1)
if(gap_h>0){
for(i=1; i<gap_h; ++i){
if(board[x1][y1+i]!="  "){
return false;
                         };
                      };
           };
//ESQUERDA(0, -1)
if(gap_h<0){
for(i=1; i<abs(gap_h); ++i){
if(board[x1][y1-i]!="  "){
return false;
                         };
                           };
           };
//CASO NÃO HAJA OBSTRUÇÕES
return true;
                                                                         };

//TORRES DAS NEGRAS
bool chess_game::validate_black_rook_move(int x1, int y1, int x2, int y2){
//VARIÁVEIS LOCAIS
int i, j, gap_h, gap_v;
//AJUSTE DE VARIÁVEIS
gap_v=x2-x1;
gap_h=y2-y1;

//CHECANDO SE  AS COORDENADAS ESTÃO DENTRO DO LIMITE ACEITÁVEL
if(x1<0 || x1>7 || y1<0 || y1>7 || x2<0 || x2>7 || y2<0 || y2>7){
return false;
                                                                };
//TORRES SE MOVEM LINHA RETA
if(gap_v!=0 && gap_h!=0){
return false;
                        };

//CHECANDO POR OBSTRUÇÕES DE PEÇAS
//CASA DE DESTINO
if(board[x2][y2]=="TP" || board[x2][y2]=="CP" || board[x2][y2]=="DP" || board[x2][y2]=="BP" || board[x2][y2]=="PP" || board[x2][y2]=="RP"){
return false;
           };

//CIMA(+1, 0)
if(gap_v>0){
for(i=1; i<gap_v; ++i){
if(board[x1+i][y1]!="  "){
return false;
                         };
                      };
           };
//BAIXO(-1, 0)
if(gap_v<0){
for(i=1; i<abs(gap_v); ++i){
if(board[x1-i][y1]!="  "){
return false;
                         };
                           };
           };

//DIREITA(0, +1)
if(gap_h>0){
for(i=1; i<gap_h; ++i){
if(board[x1][y1+i]!="  "){
return false;
                         };
                      };
           };
//ESQUERDA(0, -1)
if(gap_h<0){
for(i=1; i<abs(gap_h); ++i){
if(board[x1][y1-i]!="  "){
return false;
                         };
                           };
           };
//CASO NÃO HAJA OBSTRUÇÕES
return true;
                                                                                   };

//DAMA DAS BRANCAS
bool chess_game::validate_white_queen_move(int x1, int y1, int x2, int y2){
//VARIÁVEIS LOCAIS
int i, j, gap_h, gap_v;
bool result;

//AJUSTE DE VARIÁVEIS
gap_v=x2-x1;
gap_h=y2-y1;

//CHECANDO SE  AS COORDENADAS ESTÃO DENTRO DO LIMITE ACEITÁVEL
if(x1<0 || x1>7 || y1<0 || y1>7 || x2<0 || x2>7 || y2<0 || y2>7){
return false;
                                                                };
//MOVIMENTO EM LINHA RETA
if(gap_v==0 || gap_h==0)
result=validate_white_rook_move(x1, y1, x2, y2);
//MOVIMENTO NAS DIAGONAIS
if(gap_v!=0 && gap_h!=0)
result=validate_white_bishop_move(x1, y1, x2, y2);

return result;
                                                                          };

//DAMA DAS NEGRAS
bool chess_game::validate_black_queen_move(int x1, int y1, int x2, int y2){
//VARIÁVEIS LOCAIS
int i, j, gap_h, gap_v;
bool result;

//AJUSTE DE VARIÁVEIS
gap_v=x2-x1;
gap_h=y2-y1;

//CHECANDO SE  AS COORDENADAS ESTÃO DENTRO DO LIMITE ACEITÁVEL
if(x1<0 || x1>7 || y1<0 || y1>7 || x2<0 || x2>7 || y2<0 || y2>7){
return false;
                                                                };
//MOVIMENTO EM LINHA RETA
if(gap_v==0 || gap_h==0)
result=validate_black_rook_move(x1, y1, x2, y2);
//MOVIMENTO NAS DIAGONAIS
if(gap_v!=0 && gap_h!=0)
result=validate_black_bishop_move(x1, y1, x2, y2);

return result;
                                                                         };

//REI DAS BRANCAS
bool chess_game::validate_white_king_move(int x1, int y1, int x2, int y2){
//CHECANDO SE  AS COORDENADAS ESTÃO DENTRO DO LIMITE ACEITÁVEL
if(x1<0 || x1>7 || y1<0 || y1>7 || x2<0 || x2>7 || y2<0 || y2>7){
return false;
                                                                };

//REIS MOVEM-SE UMA CASA EM QUALQUER DIREÇÃO MAS NÃO PULAM PARA UMA CASA OCUPADA PELAS PRÓPRIAS PEÇAS
if(abs(x2-x1)<2 && abs(y2-y1)<2 && board[x2][y2]!="DB" && board[x2][y2]!="TB" && board[x2][y2]!="CB" && board[x2][y2]!="BB" && board[x2][y2]!="PB")
return true;

//CASO AS CONDIÇÕES ACIMA NÃO SEJAM SATISFEITAS
return false;
                                                                         };

//REI DAS NEGRAS
bool chess_game::validate_black_king_move(int x1, int y1, int x2, int y2){
//CHECANDO SE  AS COORDENADAS ESTÃO DENTRO DO LIMITE ACEITÁVEL
if(x1<0 || x1>7 || y1<0 || y1>7 || x2<0 || x2>7 || y2<0 || y2>7){
return false;
                                                                };

//REIS MOVEM-SE UMA CASA EM QUALQUER DIREÇÃO MAS NÃO PULAM PARA UMA CASA OCUPADA PELAS PRÓPRIAS PEÇAS
if(abs(x2-x1)<2 && abs(y2-y1)<2 && board[x2][y2]!="DP" && board[x2][y2]!="TP" && board[x2][y2]!="CP" && board[x2][y2]!="BP" && board[x2][y2]!="PP")
return true;

//CASO AS CONDIÇÕES ACIMA NÃO SEJAM SATISFEITAS
return false;
                                                                         };

//****************************************************************************************************************************
//FUNÇÕES QUE CHECAM SE UMA PEÇA ESTÁ CRAVADA
//BRANCAS
bool chess_game::white_piece_pinned(int x1, int y1, int x2, int y2){
//VARIÁVEIS LOCAIS
bool white_pin;

//REGISTRANDO O STATUS DO TABULEIRO
save_state();
//TESTANDO O TABULEIRO PRINCIPAL
//EXECUTANDO O MOVIMENTO
board[x2][y2]=board[x1][y1];
board[x1][y1]="  ";

//VERFICANDO SE O REI ESTÁ EM CHEQUE
white_king_status();
if(white_king_in_check==true)
white_pin=true;
if(white_king_in_check==false)
white_pin=false;

//RETORNANDO OS TABULEIROS DO JOGO AO SEU ESTADO NORMAL
restore_state();
white_king_in_check=false;//VALOR PADRÃO (SE O REI ESTIVER EM CHEQUE ESTE TESTE NÃO É REALIZADO)

//RESULTADO DO TESTE
return white_pin;
                                                                   };
//NEGRAS
bool chess_game::black_piece_pinned(int x1, int y1, int x2, int y2){
//VARIÁVEIS LOCAIS
bool black_pin;

//REGISTRANDO O STATUS DO TABULEIRO
save_state();
//TESTANDO O TABULEIRO PRINCIPAL
//EXECUTANDO O MOVIMENTO
board[x2][y2]=board[x1][y1];
board[x1][y1]="  ";

//VERFICANDO SE O REI ESTÁ EM CHEQUE
black_king_status();
if(black_king_in_check==true)
black_pin=true;
if(black_king_in_check==false)
black_pin=false;

//RETORNANDO OS TABULEIROS DO JOGO AO SEU ESTADO NORMAL
restore_state();
black_king_in_check=false;//VALOR PADRÃO (SE O REI ESTIVER EM CHEQUE ESTE TESTE NÃO É REALIZADO)

//RESULTADO DO TESTE
return black_pin;
                                                                   };
//****************************************************************************************************************************
//FUNÇÕES QUE CHECAM SE A CAPTURA EN PASSANT É POSSIVEL
//BRANCAS
bool chess_game::white_en_passant_checker(int x1, int y1, int x2, int y2){
/*CHECANDO SE AS CONDIÇÕES DE CAPTURA EM PASSANT SÃO SATISFEITAS PARA AS BRANCAS: PEÃO DAS NEGRAS ->(-2, 0) A PARTIR DA CASA INICIAL E HÁ UM PEÃO DAS BRANCAS NAS CASAS ADJACENTES ESQUERDA (0, -1) OU DIREITA (0, +1)*/

if(abs(x2-x1)==2 && board[x1][y1]=="PP" && (board[x2][y2+1]=="PB" || board[x2][y2+1]=="PB")){
white_en_passant=true;
                                                                                            };

return white_en_passant;
                                                                         };
//NEGRAS
bool chess_game::black_en_passant_checker(int x1, int y1, int x2, int y2){
/*CHECANDO SE AS CONDIÇÕES DE CAPTURA EM PASSANT SÃO SATISFEITAS PARA AS NEGRAS: PEÃO DAS BRANCAS ->(+2, 0) A PARTIR DA CASA INICIAL E HÁ UM PEÃO DAS BRANCAS NAS CASAS ADJACENTES ESQUERDA (0, -1) OU DIREITA (0, +1)*/

if(abs(x2-x1)==2 && board[x1][y1]=="PB"){
if(board[x2][y2+1]=="PP" || board[x2][y2+1]=="PP")
black_en_passant=true;
                                                   };
return black_en_passant;
                                                                         };

//****************************************************************************************************************************
//FUNÇÕES QUE EXECUTAM O ROQUE
//ROQUE CURTO
//BRANCAS
void chess_game::white_small_castle(){
//O JOGADOR SÓ PODE FAZER 1 ROQUE E NÃO PODE TER MOVIDO TORRE OU REI
if(white_castle==true || white_castle_checker1==false)
return;

//VARIÁVEIS LOCAIS
bool test1, test2;
//SALVANDO O STATUS DO TABULEIRO
save_state();
//TESTE1: CHECANDO SE O CAMINHO PARA O ROQUE ESTÁ LIVRE  E A PEÇAS ESTÃO EM CASAS INICIAIS
if(board[0][4]=="RB" && board[0][7]=="TB" && board[0][5]=="  " && board[0][6]=="  ")
test1=true;
else 
test1=false;

//CASO A CONDIÇÃO ACIMA NÃO SEJA SATISFEITA RETORNAR O TABULEIRO A SUA CONDIÇÃO INICIAL
if(test1==false){
white_castle=false;
restore_state();
return;
                };
//EXECUTANDO O MOVIMENTO COM O REI
//PASS0 1
board[0][5]="RB";
board[0][4]="  ";
//VERIFICANDO SE HÁ CHEQUES
white_king_status();
if(white_king_in_check==true){
test2=false;
goto not_castle;
                          }
else if(white_king_in_check==false)
test2=true;

//PASSO 2
board[0][6]="RB";
board[0][5]="  ";
//VERIFICANDO SE HÁ CHEQUES
white_king_status();
if(white_king_in_check==true){
test2=false;
goto not_castle;
                          }
else if(white_king_in_check==false)
test2=true;

//FINALIZANDO O ROQUE SE A CONDIÇÃO ACIMA FOR SATISFEITA
if(test2==true){
board[0][5]="TB";
board[0][7]="  ";
white_castle=true;
reset_board();
move_list.push_back("o-o");//ATUALIZANDO A LISTA DE MOVIMENTOS
white_castle=true;//ATUALIZANDO O STATUS DO ROQUE
               };

//CASO A CONDIÇÃO ACIMA NÃO SEJA SATISFEITA RETORNAR O TABULEIRO A SUA CONDIÇÃO INICIAL
not_castle:
if(test2==false){
white_castle=false;
white_king_in_check=false; //VALOR PADRÃO
restore_state();
return;
                };
                                     };

//NEGRAS
void chess_game::black_small_castle(){
//O JOGADOR SÓ PODE FAZER 1 ROQUE E NÃO PODE TER MOVIDO A TORRE OU O REI
if(black_castle==true || black_castle_checker1==false)
return;

//VARIÁVEIS LOCAIS
bool test1, test2;
//SALVANDO O STATUS DO TABULEIRO
save_state();
//TESTE1: CHECANDO SE O CAMINHO PARA O ROQUE ESTÁ LIVRE  E A PEÇAS ESTÃO EM CASAS INICIAIS
if(board[7][4]=="RP" && board[7][7]=="TP" && board[7][5]=="  " && board[7][6]=="  ")
test1=true;
else 
test1=false;

//CASO A CONDIÇÃO ACIMA NÃO SEJA SATISFEITA RETORNAR O TABULEIRO A SUA CONDIÇÃO INICIAL
if(test1==false){
black_castle=false;
restore_state();
return;
                };
//EXECUTANDO O MOVIMENTO COM O REI
//PASS0 1
board[7][5]="RP";
board[7][4]="  ";
//VERIFICANDO SE HÁ CHEQUES
black_king_status();
if(black_king_in_check==true){
test2=false;
goto not_castle;
                          }
else if(black_king_in_check==false)
test2=true;

//PASSO 2
board[7][6]="RP";
board[7][5]="  ";
//VERIFICANDO SE HÁ CHEQUES
black_king_status();
if(black_king_in_check==true){
test2=false;
goto not_castle;
                          }
else if(black_king_in_check==false)
test2=true;

//FINALIZANDO O ROQUE SE A CONDIÇÃO ACIMA FOR SATISFEITA
if(test2==true){
board[7][5]="TP";
board[7][7]="  ";
white_castle=true;
reset_board();
move_list.push_back("o-o");//ATUALIZANDO A LISTA DE MOVIMENTOS
black_castle=true;//ATUZALINDO A VARIÁVEL
               };

//CASO A CONDIÇÃO ACIMA NÃO SEJA SATISFEITA RETORNAR O TABULEIRO A SUA CONDIÇÃO INICIAL
not_castle:
if(test2==false){
white_castle=false;
white_king_in_check=false; //VALOR PADRÃO
restore_state();
return;
                };
                                     };


//ROQUE LONGO
//BRANCAS
void chess_game::white_long_castle(){
//O JOGADOR SÓ PODE FAZER 1 ROQUE E NÃO PODE TER MOVIDO TORRE OU REI
if(white_castle==true || white_castle_checker2==false)
return;

//VARIÁVEIS LOCAIS
bool test1, test2;
//SALVANDO O STATUS DO TABULEIRO
save_state();
//TESTE1: CHECANDO SE O CAMINHO PARA O ROQUE ESTÁ LIVRE  E A PEÇAS ESTÃO EM CASAS INICIAIS
if(board[0][4]=="RB" && board[0][0]=="TB" && board[0][1]=="  " && board[0][2]=="  " && board[0][3]=="  ")
test1=true;
else 
test1=false;

//CASO A CONDIÇÃO ACIMA NÃO SEJA SATISFEITA RETORNAR O TABULEIRO A SUA CONDIÇÃO INICIAL
if(test1==false){
white_castle=false;
restore_state();
return;
                };

//EXECUTANDO O MOVIMENTO COM O REI
//PASS0 1
board[0][3]="RB";
board[0][4]="  ";
//VERIFICANDO SE HÁ CHEQUES
white_king_status();
if(white_king_in_check==true){
test2=false;
goto not_castle;
                          }
else if(white_king_in_check==false)
test2=true;

//PASSO 2
board[0][2]="RB";
board[0][3]="  ";
//VERIFICANDO SE HÁ CHEQUES
white_king_status();
if(white_king_in_check==true){
test2=false;
goto not_castle;
                          }
else if(white_king_in_check==false)
test2=true;

//FINALIZANDO O ROQUE SE A CONDIÇÃO ACIMA FOR SATISFEITA
if(test2==true){
board[0][3]="TB";
board[0][0]="  ";
white_castle=true;
reset_board();
move_list.push_back("o-o-o");//ATUALIZANDO A LISTA DE MOVIMENTOS
white_castle=true;//ATUALIZANDO A VARIÁVEL
               };

//CASO A CONDIÇÃO ACIMA NÃO SEJA SATISFEITA RETORNAR O TABULEIRO A SUA CONDIÇÃO INICIAL
not_castle:
if(test2==false){
white_castle=false;
white_king_in_check=false; //VALOR PADRÃO
restore_state();
return;
                };
                                    };
//NEGRAS
void chess_game::black_long_castle(){
//O JOGADOR SÓ PODE FAZER 1 ROQUE E NÃO PODE TER MOVIDO TORRE OU REI
if(black_castle==true || black_castle_checker2==false)
return;

//VARIÁVEIS LOCAIS
bool test1, test2;
//SALVANDO O STATUS DO TABULEIRO
save_state();
//TESTE1: CHECANDO SE O CAMINHO PARA O ROQUE ESTÁ LIVRE  E A PEÇAS ESTÃO EM CASAS INICIAIS
if(board[7][4]=="RP" && board[7][0]=="TB" && board[7][1]=="  " && board[7][2]=="  " && board[7][3]=="  ")
test1=true;
else 
test1=false;

//CASO A CONDIÇÃO ACIMA NÃO SEJA SATISFEITA RETORNAR O TABULEIRO A SUA CONDIÇÃO INICIAL
if(test1==false){
black_castle=false;
restore_state();
return;
                };

//EXECUTANDO O MOVIMENTO COM O REI
//PASS0 1
board[7][3]="RP";
board[7][4]="  ";
//VERIFICANDO SE HÁ CHEQUES
black_king_status();
if(black_king_in_check==true){
test2=false;
goto not_castle;
                          }
else if(black_king_in_check==false)
test2=true;

//PASSO 2
board[7][2]="RP";
board[7][3]="  ";
//VERIFICANDO SE HÁ CHEQUES
black_king_status();
if(black_king_in_check==true){
test2=false;
goto not_castle;
                          }
else if(black_king_in_check==false)
test2=true;

//FINALIZANDO O ROQUE SE A CONDIÇÃO ACIMA FOR SATISFEITA
if(test2==true){
board[7][3]="TB";
board[7][0]="  ";
black_castle=true;
reset_board();
move_list.push_back("o-o-o");//ATUALIZANDO A LISTA DE MOVIMENTOS
black_castle=true;//ATUALIZANDO A VARIÁVEL
               };

//CASO A CONDIÇÃO ACIMA NÃO SEJA SATISFEITA RETORNAR O TABULEIRO A SUA CONDIÇÃO INICIAL
not_castle:
if(test2==false){
black_castle=false;
black_king_in_check=false; //VALOR PADRÃO
restore_state();
return;
                };
                                    };

//****************************************************************************************************************************
//FUNÇÕES PARA PROMOÇÃO DE UM PEÃO (FUNÇÃO INVOCADA APÓS A MOVIMENTAÇÃO DAS PEÇAS)
//BRANCAS 
void chess_game::promote_white_pawn(){
//VARIÁVEIS LOCAIS
string token;

//CHECANDO SE O PEÃO DAS BRANCAS ESTÁ NO RANK 7 (8ª LINHA)
if(row2!=7 || board[row2][column2]!="PB")
return;

//RECEBENDO INPUT DO USUÁRIO
cout<<"Jogador de brancas um peão será promovido!\nDigite:\n'DB' para promovê-lo para dama/'TB' para promovê-lo para torre\n'BB' para promovê-lo para bispo/'CB' para promovê-lo para cavalo\n:";
cin>>token;

//PROMOVENDO O PEÃO
if(token=="DB")
board[row2][column2]="DB";
if(token=="TB")
board[row2][column2]="TB";
if(token=="BB")
board[row2][column2]="BB";
if(token=="CB")
board[row2][column2]="CB";

                                     };
//NEGRAS
void chess_game::promote_black_pawn(){
//VARIÁVEIS LOCAIS
string token;

//CHECANDO SE O PEÃO DAS NEGRAS ESTÁ NO RANK 0 (1ª LINHA)
if(row2!=0 || board[row2][column2]!="PP")
return;

//RECEBENDO INPUT DO USUÁRIO
cout<<"Jogador de negras um peão será promovido!\nDigite:\n'DP' para promovê-lo para dama/'TP' para promovê-lo para torre\n'BP' para promovê-lo para bispo/'CP' para promovê-lo para cavalo\n:";
cin>>token;

//PROMOVENDO O PEÃO
if(token=="DP")
board[row2][column2]="DP";
if(token=="TP")
board[row2][column2]="TP";
if(token=="BP")
board[row2][column2]="BP";
if(token=="CP")
board[row2][column2]="CP";

                                     };

//***************************************************************************************************************************
//FUNÇÕES QUE REALIZAM A CAPTURA EN PASSANT (PARA ACIONAR ESSA FUNÇÃO DIGITE 'en' QUANDO LHE FOR SOLICITADO A CASA INICIAL NA FUNÇÃO PRINCIPAL DE MOVIMENTAÇÃO)
//BRANCAS
void chess_game::white_en_passant_capture(){
//RECEBENDO AS COORDENADAS DE MOVIMENTAÇÃO DAS PEÇAS DO USUÁRIO
index3();
index2();
//EXECUTANDO O MOVIMENTO DE CAPTURA EN PASSANT
board[row1][column1]="  ";
board[row2][column2]=board[row1][column1];
board[row2-1][column2]="  ";

nor_pawn_capture=0;//ATUALIZANDO VARIÁVEL
white_en_passant=false;//ATUALIZANDO VARIÁVEL

//REGISTRANDO O LANCE
move_list.push_back(initial_square);
move_list.push_back(final_square);

                                           };
//NEGRAS
void chess_game::black_en_passant_capture(){
//RECEBENDO AS COORDENADAS DE MOVIMENTAÇÃO DAS PEÇAS DO USUÁRIO
index3();
index2();
//EXECUTANDO O MOVIMENTO DE CAPTURA EN PASSANT
board[row1][column1]="  ";
board[row2][column2]=board[row1][column1];
board[row2+1][column2]="  ";

nor_pawn_capture=0;//ATUALIZANDO VARIÁVEL
black_en_passant=false;//ATUALIZANDO VARIÁVEL

//REGISTRANDO O LANCE
move_list.push_back(initial_square);
move_list.push_back(final_square);

                                           };

//**************************************************************************************************************************
//FUNÇÕES QUE REALIZAM O MOVIMENTO DE UMA PEÇA
//BRANCAS
void chess_game::white_to_move(){
//VERIFICANDO SE O REI DAS BRANCAS ESTÁ EM CHEQUE
white_king_status();
//CASO AFIRMATIVO VERIFICAR SE É CHEQUE MATE OU NÃO
if(white_king_in_check==true){
white_check_warning();
//CHECANDO O CHEQUE MATE
bool end_game=white_checkmate_checker();//VARIÁVEL LOCAL
if(checkmate==true){
checkmate_warning();
return;
                   };
                             };

//CASO NÃO SEJA CHEQUE MATE O JOGADOR DE BRANCAS REALIZA O SEU LANCE
white_move:
cout<<"Vez das brancas.\n";
//AVALIANDO O VALOR DAS PEÇAS DAS NEGRAS ANTES DO MOVIMENTO DAS BRANCAS
black_evaluation1=evaluate_black_pieces();

//RECEBENDO INPUT DO USUÁRIO
index1();
//EXECUTANDO MOVIMENTO ESPECIAIS
//CAPTURA EN PASSANT
if(initial_square=="en" && white_en_passant==true){
white_en_passant_capture();
return;
                                                  };
//EM CASO DE FALHA DA CAPTURA EN PASSANT INFORMAR AO USUÁRIO
if(initial_square=="en" && white_en_passant==false){
cout<<"Movimento inválido!\n";
goto white_move;
                                                   };

//ROQUE CURTO 
if(initial_square=="o-o")
white_small_castle();
//ROQUE LONGO
if(initial_square=="o-o-o")
white_long_castle();

//EM CASO DE FALHA NO CASO DO ROQUE INFORMAR AO USUÁRIO
if(initial_square=="o-o" || initial_square=="o-o-o"){
if(white_castle==false){
cout<<"Movimento inválido!\n";
goto white_move;
                       };
if(white_castle==true)//EM CASO DE SUCESSO NO ROQUE É A VEZ DAS NEGRAS
return;

                                                  };

//EXECUTANDO UM MOVIMENTO COMUM
if(initial_square!="o-o" && initial_square!="o-o-o" && initial_square!="en")
index2();

//REALIZANDO OS TESTES PARA VERIFICAR SE NÃO HÁ PEÇAS CRAVADAS, SE O MOVIMENTO É INCOMPÁTIVEL COM A MOVIMENTAÇÃO DAS PEÇAS OU SE O DAS BRANCAS PERMANECE EM CHEQUE
bool test1=white_piece_pinned(row1, column1, row2, column2);
bool test2;//VARIÁVEL LOCAL
//PEÃO
if(board[row1][column1]=="PB")
test2=validate_white_pawn_move(row1, column1, row2, column2);
//CAVALO
if(board[row1][column1]=="CB")
test2=validate_white_knight_move(row1, column1, row2, column2);
//BISPO
if(board[row1][column1]=="BB")
test2=validate_white_bishop_move(row1, column1, row2, column2);
//TORRE
if(board[row1][column1]=="TB")
test2=validate_white_rook_move(row1, column1, row2, column2);
//DAMA
if(board[row1][column1]=="DB")
test2=validate_white_queen_move(row1, column1, row2, column2);
//REI
if(board[row1][column1]=="RB")
test2=validate_white_king_move(row1, column1, row2, column2);

//CASO ALGUM DOS TESTES ACIMA FALHE, INFORMAR AO USUÁRIO
if(test1==true || test2==false){

//TESTE2, USE /**/ APÓS O TESTE
/*cout<<"test1 (pin): "<<test1<<"\n";
cout<<"test2 (legal move): "<<test2<<"\n";*/

cout<<"Movimento inválido!";
goto white_move;
                                };

//CASO OS TESTES SEJAM REALIZADOS COM SUCESSO O MOVIMENTO É REALIZADO
if(test1==false && test2==true){
//SALVANDO O STATUS DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO
board[row2][column2]=board[row1][column1];
board[row1][column1]="  ";

//CHECANDO  O REI DAS BRANCAS ESTÁ EM CHEQUE
white_king_status();

//TESTE3, USE UM /**/ APÓS O TESTE
/*cout<<"white_king_status"<< white_king_in_check<<"\n";*/

//EM CASO DE O REI DAS BRANCAS NÃO ESTAR EM CHEQUE FINALIZAR O LANCE
if(white_king_in_check==false){
//TESTE4, USE UM /**/ APÓS O TESTE
/*cout<<"OK\n";*/

//ATUALIZAR O TABULEIRO SECUNDÁRIO
reset_board();

//ATUALIZANDO A VARIÁVEL DE MOVIMENTO DE PEÕES
if(board[row1][column1]=="PB")
nor_pawn_capture=0;
else if(board[row1][column1]!="PB")
nor_pawn_capture++;

//VERIFICANDO SE HÁ PROMOÇÃO DE PEÃO DAS BRANCAS
if(board[row2][column2]=="PB" && row2==7)
promote_white_pawn();

//OBSERVANDO SE AS NEGRAS PODEM FAZER A CAPTURA EN PASSANT APÓS O MOVIMENTO DAS BRANCAS
bool test3 = black_en_passant_checker(row1, column1, row2, column2);
if(white_en_passant==true)
white_en_passant=false;//ATUALIZANDO VARIÁVEL

//CHECANDO SE HOUVE CAPTURA DE PEÇAS DAS NEGRAS
black_evaluation2=evaluate_black_pieces();
black_pieces_counter();

//ATUALIZAR VARIÁVEIS QUE PERMITEM A REALIZAÇÃO DO ROQUE
if(initial_square=="e1" || initial_square=="h1" )
white_castle_checker1=false;
if(initial_square=="e1" || initial_square=="a1" )
white_castle_checker2=false;

//REGISTRANDO O LANCE
move_list.push_back(initial_square);
move_list.push_back(final_square);

//FINALIZANDO A JOGADA
return;
                              };

//EM CASO DE O REI DAS BRANCAS CONTINUAR EM CHEQUE INFORMAR AO USUÁRIO
if(white_king_in_check==true){
cout<<"Movimento inválido!\nRei das brancas ainda em cheque!\n";
goto white_move;
                             }; 

                             };
                                };//


//NEGRAS
void chess_game::black_to_move(){
//VERIFICANDO SE O REI DAS NEGRAS ESTÁ EM CHEQUE
black_king_status();
//CASO AFIRMATIVO VERIFICAR SE É CHEQUE MATE OU NÃO
if(black_king_in_check==true){
black_check_warning();
//CHECANDO O CHEQUE MATE
bool end_game=black_checkmate_checker();//VARIÁVEL LOCAL
if(checkmate==true){
checkmate_warning();
return;
                  };
                             };

//CASO NÃO SEJA CHEQUE MATE O JOGADOR DE NEGRAS REALIZA O SEU LANCE
black_move:
cout<<"Vez das negras.\n";
//AVALIANDO O VALOR DAS PEÇAS DAS BRANCAS ANTES DO MOVIMENTO DAS NEGRAS
white_evaluation1=evaluate_white_pieces();

//RECEBENDO INPUT DO USUÁRIO
index1();
//EXECUTANDO MOVIMENTO ESPECIAIS
//CAPTURA EN PASSANT
if(initial_square=="en" && black_en_passant==true){
black_en_passant_capture();
return;
                                                  };
//EM CASO DE FALHA DA CAPTURA EN PASSANT INFORMAR AO USUÁRIO
if(initial_square=="en" && black_en_passant==false){
cout<<"Movimento inválido!\n";
goto black_move;
                                                   };

//ROQUE CURTO 
if(initial_square=="o-o")
black_small_castle();
//ROQUE LONGO
if(initial_square=="o-o-o")
black_long_castle();

//EM CASO DE FALHA NO CASO DO ROQUE INFORMAR AO USUÁRIO
if(initial_square=="o-o" || initial_square=="o-o-o"){
if(black_castle==false){
cout<<"Movimento inválido!\n";
goto black_move;
                       };
if(black_castle==true)//EM CASO DE SUCESSO NO ROQUE É A VEZ DAS BRANCAS
return;

                                                    };

//EXECUTANDO UM MOVIMENTO COMUM
if(initial_square!="o-o" && initial_square!="o-o-o" && initial_square!="en")
index2();

//REALIZANDO OS TESTES PARA VERIFICAR SE NÃO HÁ PEÇAS CRAVADAS, SE O MOVIMENTO É INCOMPÁTIVEL COM A MOVIMENTAÇÃO DAS PEÇAS OU SE O DAS NEGRAS PERMANECE EM CHEQUE
bool test1=black_piece_pinned(row1, column1, row2, column2);
bool test2;//VARIÁVEL LOCAL
//PEÃO
if(board[row1][column1]=="PP")
test2=validate_black_pawn_move(row1, column1, row2, column2);
//CAVALO
if(board[row1][column1]=="CP")
test2=validate_black_knight_move(row1, column1, row2, column2);
//BISPO
if(board[row1][column1]=="BP")
test2=validate_black_bishop_move(row1, column1, row2, column2);
//TORRE
if(board[row1][column1]=="TP")
test2=validate_black_rook_move(row1, column1, row2, column2);
//DAMA
if(board[row1][column1]=="DP")
test2=validate_black_queen_move(row1, column1, row2, column2);
//REI
if(board[row1][column1]=="RP")
test2=validate_black_king_move(row1, column1, row2, column2);

//TESTE USE UM /**/ APÓS O MESMO
/*cout<<"test1 (pin): "<<test1<<"\n";
cout<<"test2 (legal moves): "<<test2<<"\n";*/


//CASO ALGUM DOS TESTES ACIMA FALHE, INFORMAR AO USUÁRIO
if(test1==true || test2==false){
cout<<"Movimento inválido!";
goto black_move;
                               };

//CASO OS TESTES SEJAM REALIZADOS COM SUCESSO O MOVIMENTO É REALIZADO
if(test1==false && test2==true){
//SALVANDO O STATUS DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO
board[row2][column2]=board[row1][column1];
board[row1][column1]="  ";

//CHECANDO O REI DAS NEGRAS ESTÁ EM CHEQUE
black_king_status();

//EM CASO DE O REI DAS NEGRAS NÃO ESTAR EM CHEQUE FINALIZAR O LANCE
if(black_king_in_check==false){
//TESTE3, USE UM /**/ APÓS O TESTE
/*cout<<"OK black\n";*/

//ATUALIZAR O TABULEIRO SECUNDÁRIO
reset_board();

//ATUALIZANDO A VARIÁVEL DE MOVIMENTO DE PEÕES
if(board[row1][column1]=="PP")
nor_pawn_capture=0;
else if(board[row1][column1]!="PP")
nor_pawn_capture++;

//VERIFICANDO SE HÁ PROMOÇÃO DE PEÃO DAS NEGRAS
if(board[row2][column2]=="PP" && row2==0)
promote_black_pawn();


//OBSERVANDO SE AS BRANCAS PODEM FAZER A CAPTURA EN PASSANT APÓS O MOVIMENTO DAS NEGRAS
bool test3 = white_en_passant_checker(row1, column1, row2, column2);
if(black_en_passant==true)
black_en_passant=false;//ATUALIZANDO VARIÁVEL

//TESTE5, USE UM /**/ APÓS O TESTE
/*cout<<"white_en_passant"<< white_en_passant<<"\n";*/

//CHECANDO SE HOUVE CAPTURA DE PEÇAS DAS BRANCAS
white_evaluation2=evaluate_white_pieces();
white_pieces_counter();

//ATUALIZAR VARIÁVEIS QUE PERMITEM A REALIZAÇÃO DO ROQUE
if(initial_square=="e8" || initial_square=="h8" )
black_castle_checker1=false;
if(initial_square=="e8" || initial_square=="a8" )
black_castle_checker2=false;

//REGISTRANDO O LANCE
move_list.push_back(initial_square);
move_list.push_back(final_square);
//FINALIZANDO A JOGADA
return;
                              };

//EM CASO DE O REI DAS BRANCAS CONTINUAR EM CHEQUE INFORMAR AO USUÁRIO
if(black_king_in_check==true){
cout<<"Movimento inválido!\nRei das brancas ainda em cheque!\n";
goto black_move;
                             }; 

                             };
                                };//
