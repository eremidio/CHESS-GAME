//ESTE ARQUIVO CONTERÁ FUNÇÕES QUE VERIFICAM SE O REI ESTÃO EM CHEQUE (SOB ATAQUE)
//PRÉ REQUISITO PARA VERIFICAR A OCORRÊNCIA DE CHEQUE MATE E PARA TESTAR SE UMA PEÇA ESTÁ CRAVADA
//****************************************************************************************************************************

/*CABEÇALHO*/
#pragma once
#include<iostream>
#include"xadrez_classe.hpp"
using namespace std;


//****************************************************************************************************************************
//FUNÇÃO QUE CHECA SE O REI DAS BRANCAS ESTÁ EM CHEQUE
void chess_game::white_king_status(){
int i, j; //VARIÁVEIS DE ITERAÇÃO
white_king_in_check=false; //VALOR PADRÃO

//ENCONTRANDO A POSIÇÃO DO REI DAS BRANCAS
for(i=0; i<8; ++i){
for(j=0; j<8; ++j){
if(board[i][j]=="RB"){
white_king_row=i;
white_king_column=j;
break;

                     };
                  };
                  };

//VERFICANDO SE HÁ CHEQUES DE PEÃO
//DIAGONAL SUPERIOR DIREITA
if((white_king_row+1)>=0 && (white_king_row+1)<8 && (white_king_column+1)>=0 && (white_king_column+1)<8 && board[white_king_row+1][white_king_column+1]=="PP"){
white_king_in_check=true;
white_attacker_row=white_king_row+1;
white_attacker_column=white_king_column+1;
white_attacker="PP";
                                                    };
//DIAGONAL SUPERIOR ESQUERDA
if((white_king_row+1)>=0 && (white_king_row+1)<8 && (white_king_column-1)>=0 && (white_king_column-1)<8 && board[white_king_row+1][white_king_column-1]=="PP"){
white_king_in_check=true;
white_attacker_row=white_king_row+1;
white_attacker_column=white_king_column-1;
white_attacker="PP";
                                                    };

//CHEQUES DE CAVALO (8 POSSÍVEIS POSIÇÕES)
//(+2,+1)
if((white_king_row+2)>=0 && (white_king_row+2)<8 && (white_king_column+1)>=0 && (white_king_column+1)<8 && board[white_king_row+2][white_king_column+1]=="CP"){
white_king_in_check=true;
white_attacker_row=white_king_row+2;
white_attacker_column=white_king_column+1;
white_attacker="CP";
                                                    };
//(+1,+2)
if((white_king_row+1)>=0 && (white_king_row+1)<8 && (white_king_column+2)>=0 && (white_king_column+2)<8 && board[white_king_row+1][white_king_column+2]=="CP"){
white_king_in_check=true;
white_attacker_row=white_king_row+1;
white_attacker_column=white_king_column+2;
white_attacker="CP";
                                                    };
//(+2,-1)
if((white_king_row+2)>=0 && (white_king_row+2)<8 && (white_king_column-1)>=0 && (white_king_column-1)<8 && board[white_king_row+2][white_king_column-1]=="CP"){
white_king_in_check=true;
white_attacker_row=white_king_row+2;
white_attacker_column=white_king_column-1;
white_attacker="CP";
                                                    };
//(+1, -2)
if((white_king_row+1)>=0 && (white_king_row+1)<8 && (white_king_column-2)>=0 && (white_king_column-2)<8 && board[white_king_row+1][white_king_column-2]=="CP"){
white_king_in_check=true;
white_attacker_row=white_king_row+1;
white_attacker_column=white_king_column-2;
white_attacker="CP";
                                                    };
//(-2,+1)
if((white_king_row-2)>=0 && (white_king_row-2)<8 && (white_king_column+1)>=0 && (white_king_column+1)<8 && board[white_king_row-2][white_king_column+1]=="CP"){
white_king_in_check=true;
white_attacker_row=white_king_row-2;
white_attacker_column=white_king_column+1;
white_attacker="CP";
                                                    };
//(-1,+2)
if((white_king_row-1)>=0 && (white_king_row-1)<8 && (white_king_column+2)>=0 && (white_king_column+2)<8 && board[white_king_row-1][white_king_column+2]=="CP"){
white_king_in_check=true;
white_attacker_row=white_king_row-1;
white_attacker_column=white_king_column+2;
white_attacker="CP";
                                                    };
//(-2,-1)
if((white_king_row-2)>=0 && (white_king_row-2)<8 && (white_king_column-1)>=0 && (white_king_column-1)<8 && board[white_king_row-2][white_king_column-1]=="CP"){
white_king_in_check=true;
white_attacker_row=white_king_row-2;
white_attacker_column=white_king_column-1;
white_attacker="CP";
                                                    };
//(-1,-2)
if((white_king_row-1)>=0 && (white_king_row-1)<8 && (white_king_column-2)>=0 && (white_king_column-2)<8 && board[white_king_row-1][white_king_column-2]=="CP"){
white_king_in_check=true;
white_attacker_row=white_king_row-1;
white_attacker_column=white_king_column-2;
white_attacker="CP";
                                                    };

//CHEQUES DE BISPO OU DAMA
//DIAGONAL SUPERIOR DIREITA (+1, +1)
for(i=1; i<8; i++){
if((white_king_row+i)>7 || (white_king_column+i)>7)
break;
if(board[white_king_row+i][white_king_column+i]!="BP" && board[white_king_row+i][white_king_column+i]!="DP" && board[white_king_row+i][white_king_column+i]!="  ")
break;
if(board[white_king_row+i][white_king_column+i]=="BP" || board[white_king_row+i][white_king_column+i]=="DP"){
white_king_in_check=true;
white_attacker_row=white_king_row+i;
white_attacker_column=white_king_column+i;
white_attacker=board[white_king_row+i][white_king_column+i];
break;
                                                                                                            }; 
                  };

//DIAGONAL SUPERIOR ESQUERDA (+1, -1)
for(i=1; i<8; i++){
if((white_king_row+i)>7 || (white_king_column-i)<0)
break;
if(board[white_king_row+i][white_king_column-i]!="BP" && board[white_king_row+i][white_king_column-i]!="BP" && board[white_king_row+i][white_king_column-i]!="  ")
break;
if(board[white_king_row+i][white_king_column-i]=="BP" || board[white_king_row+i][white_king_column-i]=="DP"){
white_king_in_check=true;
white_attacker_row=white_king_row+i;
white_attacker_column=white_king_column-i;
white_attacker=board[white_king_row+i][white_king_column-i];
break;
                                                                                                            }; 
                  };
//DIAGONAL INFERIOR DIREITA(-1, +1)
for(i=1; i<8; i++){
if((white_king_row-i)<0 || (white_king_column+i)>7)
break;
if(board[white_king_row-i][white_king_column+i]!="BP" && board[white_king_row-i][white_king_column+i]!="DP" && board[white_king_row-i][white_king_column+i]!="  ")
break;
if(board[white_king_row-i][white_king_column+i]=="BP" || board[white_king_row-i][white_king_column+i]=="DP"){
white_king_in_check=true;
white_attacker_row=white_king_row-i;
white_attacker_column=white_king_column+i;
white_attacker=board[white_king_row-i][white_king_column+i];
break;
                                                                                                            }; 
                  };

//DIAGONA INFERIOR ESQUERDA (-1, -1)
for(i=1; i<8; i++){
if((white_king_row-i)<0 || (white_king_column-i)<0)
break;
if(board[white_king_row-i][white_king_column-i]!="BP" && board[white_king_row-i][white_king_column-i]!="DP" && board[white_king_row-i][white_king_column-i]!="  ")
break;
if(board[white_king_row-i][white_king_column-i]=="BP" || board[white_king_row-i][white_king_column-i]=="DP"){
white_king_in_check=true;
white_attacker_row=white_king_row-i;
white_attacker_column=white_king_column-i;
white_attacker=board[white_king_row-i][white_king_column-i];
break;
                                                                                                            }; 
                  };

//CHEQUES DE TORRE OU DAMA 
//CIMA (+1, 0)
for(i=1; i<8; i++){
if((white_king_row+i)>7)
break;
if(board[white_king_row+i][white_king_column]!="TP" && board[white_king_row+i][white_king_column]!="DP" && board[white_king_row+i][white_king_column]!="  ")
break;
if(board[white_king_row+i][white_king_column]=="TP" || board[white_king_row+i][white_king_column]=="DP"){
white_king_in_check=true;
white_attacker_row=white_king_row+i;
white_attacker_column=white_king_column;
white_attacker=board[white_king_row+i][white_king_column];
break;
                                                                                                        };

                  };
//BAIXO (-1, 0)
for(i=1; i<8; i++){
if((white_king_row-i)<0)
break;
if(board[white_king_row-i][white_king_column]!="TP" && board[white_king_row+i][white_king_column]!="DP" && board[white_king_row-i][white_king_column]!="  ")
break;
if(board[white_king_row-i][white_king_column]=="TP" || board[white_king_row-i][white_king_column]=="DP"){
white_king_in_check=true;
white_attacker_row=white_king_row-i;
white_attacker_column=white_king_column;
white_attacker=board[white_king_row-i][white_king_column];
break;
                                                                                                        };
                  };
//DIREITA (0, +1)
for(i=1; i<8; i++){
if((white_king_column+i)>7)
break;
if(board[white_king_row][white_king_column+i]!="TP" && board[white_king_row][white_king_column+i]!="DP" && board[white_king_row][white_king_column+i]!="  ")
break;
if(board[white_king_row][white_king_column+i]=="TP" || board[white_king_row][white_king_column+i]=="DP"){
white_king_in_check=true;
white_attacker_row=white_king_row;
white_attacker_column=white_king_column+i;
white_attacker=board[white_king_row][white_king_column+i];
break;
                                                                                                        };

                  };
//ESQUERDA (0, -1)
for(i=1; i<8; i++){
if((white_king_column-i)<0)
break;
if(board[white_king_row][white_king_column-i]!="TP" && board[white_king_row][white_king_column-i]!="DP" && board[white_king_row][white_king_column-i]!="  ")
break;
if(board[white_king_row][white_king_column-i]=="TP" || board[white_king_row][white_king_column-i]=="DP"){
white_king_in_check=true;
white_attacker_row=white_king_row;
white_attacker_column=white_king_column-i;
white_attacker=board[white_king_row][white_king_column-i];
break;
                                                                                                        };
                  };

                                    };//

//FUNÇÃO QUE CHECA SE O REI DAS NEGRAS ESTÁ EM CHEQUE
void chess_game::black_king_status(){
int i, j; //VARIÁVEIS DE ITERAÇÃO
black_king_in_check=false; //VALOR PADRÃO

//ENCONTRANDO A POSIÇÃO DO REI DAS NEGRAS
for(i=0; i<8; ++i){
for(j=0; j<8; ++j){
if(board[i][j]=="RP"){
black_king_row=i;
black_king_column=j;
break;

                     };
                  };
                  };

//VERFICANDO SE HÁ CHEQUES DE PEÃO
//DIAGONAL INFERIOR DIREITA
if((black_king_row-1)>=0 && (black_king_row-1)<8 && (black_king_column+1)>=0 && (black_king_column+1)<8 && board[black_king_row-1][black_king_column+1]=="PB"){
black_king_in_check=true;
black_attacker_row=black_king_row-1;
black_attacker_column=black_king_column+1;
black_attacker="PB";
                                                    };
//DIAGONAL INFERIOR ESQUERDA
if((black_king_row-1)>=0 && (black_king_row-1)<8 && (black_king_column-1)>=0 && (black_king_column-1)<8 && board[black_king_row-1][black_king_column-1]=="PB"){
black_king_in_check=true;
black_attacker_row=black_king_row-1;
black_attacker_column=black_king_column-1;
black_attacker="PB";
                                                    };

//CHEQUES DE CAVALO (8 POSSÍVEIS POSIÇÕES)
//(+2,+1)
if((black_king_row+2)>=0 && (black_king_row+2)<8 && (black_king_column+1)>=0 && (black_king_column+1)<8 && board[black_king_row+2][black_king_column+1]=="CB"){
black_king_in_check=true;
black_attacker_row=black_king_row+2;
black_attacker_column=black_king_column+1;
black_attacker="CB";
                                                    };
//(+1,+2)
if((black_king_row+1)>=0 && (black_king_row+1)<8 && (black_king_column+2)>=0 && (black_king_column+2)<8 && board[black_king_row+1][black_king_column+2]=="CB"){
black_king_in_check=true;
black_attacker_row=black_king_row+1;
black_attacker_column=black_king_column+2;
black_attacker="CB";
                                                    };
//(+2,-1)
if((black_king_row+2)>=0 && (black_king_row+2)<8 && (black_king_column-1)>=0 && (black_king_column-1)<8 && board[black_king_row+2][black_king_column-1]=="CB"){
black_king_in_check=true;
black_attacker_row=black_king_row+2;
black_attacker_column=black_king_column-1;
black_attacker="CB";
                                                    };
//(+1, -2)
if((black_king_row+1)>=0 && (black_king_row+1)<8 && (black_king_column-2)>=0 && (black_king_column-2)<8 && board[black_king_row+1][black_king_column-2]=="CB"){
black_king_in_check=true;
black_attacker_row=black_king_row+1;
black_attacker_column=black_king_column-2;
black_attacker="CB";
                                                    };
//(-2,+1)
if((black_king_row-2)>=0 && (black_king_row-2)<8 && (black_king_column+1)>=0 && (black_king_column+1)<8 && board[black_king_row-2][black_king_column+1]=="CB"){
black_king_in_check=true;
black_attacker_row=black_king_row-2;
black_attacker_column=black_king_column+1;
black_attacker="CB";
                                                    };
//(-1,+2)
if((black_king_row-1)>=0 && (black_king_row-1)<8 && (black_king_column+2)>=0 && (black_king_column+2)<8 && board[black_king_row-1][black_king_column+2]=="CB"){
black_king_in_check=true;
black_attacker_row=black_king_row-1;
black_attacker_column=black_king_column+2;
black_attacker="CB";
                                                    };
//(-2,-1)
if((black_king_row-2)>=0 && (black_king_row-2)<8 && (black_king_column-1)>=0 && (black_king_column-1)<8 && board[black_king_row-2][black_king_column-1]=="CB"){
black_king_in_check=true;
black_attacker_row=black_king_row-2;
black_attacker_column=black_king_column-1;
black_attacker="CB";
                                                    };
//(-1,-2)
if((black_king_row-1)>=0 && (black_king_row-1)<8 && (black_king_column-2)>=0 && (black_king_column-2)<8 && board[black_king_row-1][white_king_column-2]=="CB"){
black_king_in_check=true;
black_attacker_row=black_king_row-1;
black_attacker_column=black_king_column-2;
black_attacker="CB";
                                                    };

//CHEQUES DE BISPO OU DAMA
//DIAGONAL SUPERIOR DIREITA (+1, +1)
for(i=1; i<8; i++){
if((black_king_row+i)>7 || (black_king_column+i)>7)
break;
if(board[black_king_row+i][black_king_column+i]!="BB" && board[black_king_row+i][black_king_column+i]!="DB" && board[black_king_row+i][black_king_column+i]!="  ")
break;
if(board[black_king_row+i][black_king_column+i]=="BB" || board[black_king_row+i][black_king_column+i]=="DB"){
black_king_in_check=true;
black_attacker_row=black_king_row+i;
black_attacker_column=black_king_column+i;
black_attacker=board[black_king_row+i][black_king_column+i];
break;
                                                                                                            }; 
                  };

//DIAGONAL SUPERIOR ESQUERDA (+1, -1)
for(i=1; i<8; i++){
if((black_king_row+i)>7 || (black_king_column-i)<0)
break;
if(board[black_king_row+i][black_king_column-i]!="BB" && board[black_king_row+i][black_king_column-i]!="DB" && board[black_king_row+i][black_king_column-i]!="  ")
break;
if(board[black_king_row+i][black_king_column-i]=="BB" || board[black_king_row+i][black_king_column-i]=="DB"){
black_king_in_check=true;
black_attacker_row=black_king_row+i;
black_attacker_column=black_king_column-i;
black_attacker=board[black_king_row+i][black_king_column-i];
break;
                                                                                                            }; 
                  };
//DIAGONAL INFERIOR DIREITA(-1, +1)
for(i=1; i<8; i++){
if((black_king_row-i)<0 || (black_king_column+i)>7)
break;
if(board[black_king_row-i][black_king_column+i]!="BB" && board[black_king_row-i][black_king_column+i]!="DB" && board[black_king_row-i][black_king_column+i]!="  ")
break;
if(board[black_king_row-i][black_king_column+i]=="BB" || board[black_king_row-i][black_king_column+i]=="DB"){
black_king_in_check=true;
black_attacker_row=black_king_row-i;
black_attacker_column=black_king_column+i;
black_attacker=board[black_king_row-i][black_king_column+i];
break;
                                                                                                            }; 
                  };

//DIAGONA INFERIOR ESQUERDA (-1, -1)
for(i=1; i<8; i++){
if((black_king_row-i)<0 || (black_king_column-i)<0)
break;
if(board[black_king_row-i][black_king_column-i]!="BB" && board[black_king_row-i][black_king_column-i]!="DB" && board[black_king_row-i][black_king_column-i]!="  ")
break;
if(board[black_king_row-i][black_king_column-i]=="BB" || board[black_king_row-i][black_king_column-i]=="DB"){
black_king_in_check=true;
black_attacker_row=white_king_row-i;
black_attacker_column=white_king_column-i;
black_attacker=board[black_king_row-i][black_king_column-i];
break;
                                                                                                            }; 
                  };

//CHEQUES DE TORRE OU DAMA 
//CIMA (+1, 0)
for(i=1; i<8; i++){
if((black_king_row+i)>7)
break;
if(board[black_king_row+i][black_king_column]!="TB" && board[black_king_row+i][black_king_column]!="DB" && board[black_king_row+i][black_king_column]!="  ")
break;
if(board[black_king_row+i][black_king_column]=="TB" || board[black_king_row+i][black_king_column]=="DB"){
black_king_in_check=true;
black_attacker_row=black_king_row+i;
black_attacker_column=black_king_column;
black_attacker=board[black_king_row+i][black_king_column];
break;
                                                                                                        };

                  };
//BAIXO (-1, 0)
for(i=1; i<8; i++){
if((black_king_row-i)<0)
break;
if(board[black_king_row-i][black_king_column]!="TB" && board[black_king_row+i][black_king_column]!="DB" && board[black_king_row-i][black_king_column]!="  ")
break;
if(board[black_king_row-i][black_king_column]=="TB" || board[black_king_row-i][black_king_column]=="DB"){
black_king_in_check=true;
black_attacker_row=black_king_row-i;
black_attacker_column=black_king_column;
black_attacker=board[black_king_row-i][black_king_column];
break;
                                                                                                        };
                  };
//DIREITA (0, +1)
for(i=1; i<8; i++){
if((black_king_column+i)>7)
break;
if(board[black_king_row][black_king_column+i]!="TB" && board[black_king_row][black_king_column+i]!="DB" && board[black_king_row][black_king_column+i]!="  ")
break;
if(board[black_king_row][black_king_column+i]=="TB" || board[black_king_row][black_king_column+i]=="DB"){
black_king_in_check=true;
black_attacker_row=black_king_row;
black_attacker_column=black_king_column+i;
black_attacker=board[black_king_row][black_king_column+i];
break;
                                                                                                        };

                  };
//ESQUERDA (0, -1)
for(i=1; i<8; i++){
if((black_king_column-i)<0)
break;
if(board[black_king_row][black_king_column-i]!="TB" && board[black_king_row][black_king_column-i]!="DB" && board[black_king_row][black_king_column-i]!="  ")
break;
if(board[black_king_row][black_king_column-i]=="TB" || board[black_king_row][black_king_column-i]=="DB"){
black_king_in_check=true;
black_attacker_row=black_king_row;
black_attacker_column=black_king_column-i;
black_attacker=board[black_king_row][black_king_column-i];
break;
                                                                                                        };
                  };

                                    };//


//FUNÇÃO QUE INFORMA SE O REI DAS BRANCAS ESTÁ EM CHEQUE
void chess_game::white_check_warning(){
//ALERTA AO USUÁRIO DE CHEQUE
if(white_king_in_check==true)
cout<<"Rei das brancas em cheque!\n";
                                      };


//FUNÇÃO QUE INFORMA SE O REI DAS NEGRAS ESTÁ EM CHEQUE 
void chess_game::black_check_warning(){
//ALERTA AO USUÁRIO DE CHEQUE
if(black_king_in_check==true)
cout<<"Rei das negras em cheque!\n";
                                      };
