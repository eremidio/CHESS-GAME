//ESTE ARQUIVO CONTÉM A DEFINIÇÃO DA CLASSE DO JOGO DE XADREZ
//****************************************************************************************************************************

/*CABEÇALHO*/
#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//****************************************************************************************************************************
//DEFINIÇÃO DA CLASSE DO JOGO

class chess_game{
public:
//MEMBROS DA CLASSE
string board[8][8];//TABULEIRO PRINCIPAL
string secondary_board[8][8];//TABULEIRO SECUNDÁRIO
int row1, row2, column1, column2; //COORDENADAS DAS CASAS DA PEÇA (INICIAL--:> 1, FINAL --:>2)
int nor_pawn_capture;//VÁRIAVEL USANDA PARA SE CONTABILIZAR CAPTURA DE PEÇAS OU AVANÇOS DE PEÃO
string initial_square, final_square;//STRINGS QUE ALOCAM AS POSIÇÕES DAS PEÇAS
int white_evaluation1, white_evaluation2, black_evaluation1, black_evaluation2;//VALORES DAS PEÇAS DE AMBOS DOS JOGADORES
vector<string> move_list;//LISTA QUE ALOCA O MOVIMENTO DAS PEÇAS
bool white_king_in_check, black_king_in_check;//VARIÁVEL QUE INDICA SE O REI ESTÁ EM CHEQUE OU NÃO
string white_attacker, black_attacker; //SÍMBOLO DAS PEÇAS QUE ATACAM O (APLICAM CHEQUE AO) REI
int white_king_row, white_king_column, white_attacker_row, white_attacker_column;//COORDENADAS USADAS ṔARA CHECAR SE O REI DAS BRANCAS ESTÁ EM CHEQUE
int black_king_row, black_king_column, black_attacker_row, black_attacker_column;//COORDENADAS USADAS ṔARA CHECAR SE O REI DAS NEGRAS ESTÁ EM CHEQUE
bool checkmate; //VARIÁVEL QUE DETERMINAR A CONDIÇÃO DE CHEQUE MATE
bool draw_game;//VARIÁVEL QUE VERFICA SE HOUVE EMPATE NO JOGO
bool resignation;//VARIÁVEL QUE PERMITE AO USUÁRIO DESISTIR DE UMA PARTIDA
bool white_en_passant, black_en_passant;//VARIÁVEIS PARA PERMITIR A CAPTURA EN PASSANT
bool white_castle, black_castle;//VARIÁVEIS QUE DEFINEM SE O ROQUE FOI OU NÃO REALIZADO PELOS JOGADORES
bool white_castle_checker1, white_castle_checker2, black_castle_checker1, black_castle_checker2;//VARIÁVEIS QUE CHECAM SE É POSSÍVEL OU NÃO FAZER O ROQUE CURTO(:-->1) OU LONGO(:-->2)
bool white_turn, black_turn; //VARIÁVEIS USADAS PARA SE DECIDIR A ORDEM DAS JOGADAS

//CONSTRUTOR E DESTRUIDORES
~chess_game();

//MÉTODOS DA CLASSE
//FUNÇÔES DE USO GERAL
void set_default_values();//FUNÇÃO QUE AJUSTA VARIÁVEIS EM SEUS VALORES INICIAIS
//TABULEIRO
void set_board();//FUNÇÃO QUE AJUSTA A CONFIGURAÇÃO INICIAL DOS TABULEIROS
void reset_board();//FUNÇÃO PARA RESETAR OS TABULEIROS SECUNDÁRIOS 
void print_board();//FUNÇÃO PARA PRINTAR O TABULEIRO
void index1();//FUNÇÃO QUE CALCULA AS COORDENADAS DE UMA CASA NO TABULEIRO
void index2();//FUNÇÃO QUE CALCULA AS COORDENADAS DE UMA CASA NO TABULEIRO
void index3();//FUNÇÃO QUE CALCULA AS COORDENADAS DE UMA CASA NO TABULEIRO (CAPTURA EN PASSANT)
int evaluate_white_pieces();//FUNÇÃO PARA SE AVALIAR O VALOR DAS PEÇAS DAS BRANCAS
int evaluate_black_pieces();// "      "    "   " "   "   "    "    "    "  NEGRAS 
void white_pieces_counter();//FUNÇÃO QUE CHECA SE HOUVE CAPTURA DE ALGUMA PEÇA DAS BRANCAS
void black_pieces_counter();// "      "     "   "   "       "    "     "    "   "  NEGRAS  
void save_state(); //FUNÇÃO QUE CÓPIA O TABULEIRO PRINCIPAL NO TABULEIRO SECUNDÁRIO
void restore_state();//FUNÇÃO QUE RETORNA O ESTADO SALVO NO TABULEIRO SECUNDÁRIO NO TABULEIRO PRINCIPAL E RESETA O TABULEIRO SECUNDÁRIO
void partially_restore_state();//FUNÇÃO QUE RETORNA O ESTADO SALVO NO TABULEIRO SECUNDÁRIO NO TABULEIRO PRINCIPAL (CHEQUEMATE)

//CHEQUE
void white_king_status();//FUNÇÃO QUE CHECA SE OS REIS DA BRANCA ESTÃO EM CHEQUE
void black_king_status();//  "     "    "    "  "  "    " NEGRAS   "    "   "
void white_check_warning();//FUNÇÃO QUE INFORMA SE O REI DAS BRANCAS ESTÁ EM CHEQUE 
void black_check_warning();//  "     "    "      " "  "   "  NEGRAS    "   "   "

//FUNÇÕES QUE VALIDAM A MOVIMENTAÇÃO DAS PEÇAS
bool validate_white_pawn_move(int, int, int, int);
bool validate_black_pawn_move(int, int, int, int);
bool validate_white_knight_move(int, int, int, int);
bool validate_black_knight_move(int, int, int, int);
bool validate_white_bishop_move(int, int, int, int);
bool validate_black_bishop_move(int, int, int, int);
bool validate_white_rook_move(int, int, int, int);
bool validate_black_rook_move(int, int, int, int);
bool validate_white_queen_move(int, int, int, int);
bool validate_black_queen_move(int, int, int, int);
bool validate_white_king_move(int, int, int, int);
bool validate_black_king_move(int, int, int, int);

//FUNÇÕES QUE CALCULAM SE UMA PEÇA ESTÁ CRAVADA OU NÃO (REALIZANDO UM TESTE)
bool white_piece_pinned(int, int, int, int);
bool black_piece_pinned(int, int, int, int);
bool white_piece_pinned_checkmate(int, int, int, int);//TESTE DE CHEQUEMATE
bool black_piece_pinned_checkmate(int, int, int, int);

//FUNÇÕES QUE VALIDAM A CAPTURA EN PASSANT
bool white_en_passant_checker(int, int, int, int);
bool black_en_passant_checker(int, int, int, int);

//FUNÇÕES QUE EXECUTAM O ROQUE
void white_small_castle();
void white_long_castle();
void black_small_castle();
void black_long_castle();

//FUNÇÕES PARA PROMOÇÃO DE UM PEÃO
void promote_white_pawn();
void promote_black_pawn(); 

//FUNÇÕES QUE EXECUTAM A CAPTURA EM PASSANT
void white_en_passant_capture();
void black_en_passant_capture();

//FUNÇÃO QUE EXECUTAM O MOVIMENTO DE UMA PEÇA
void white_to_move();
void black_to_move();


//CHEQUE MATE
bool white_check_piece_escape();
bool black_check_piece_escape();
bool white_check_king_escape();
bool black_check_king_escape();
bool white_checkmate_checker();
bool black_checkmate_checker();
void checkmate_warning();

//FUNÇÕES QUE CHECAM SE HOUVE EMPATE NO JOGO
void common_agreement_draw();//COMUM ACORDO
void fifth_rule_draw();//REGRA DOS 50 LANCES
void repetition_draw();//EMPATE POR REPETIÇÃO
void white_stalemate_draw();//EMPATE POR AFOGAMENTO
void black_stalemate_draw();//   "    "      "   
void insufficient_material_draw();//EMPATE POR FALTA DE MATERIAL
void draw_warning();//FUNÇÃO QUE ALERTA O USUÁRIO DA OCORRÊNCIA DE EMPATE

//FUNÇÃO QUE PERMITE AO JOGADOR ENCERRAR O JOGO POR DESISTÊNCIA
void resignate();

//SETUP E LOOP PRINCIPAL DO JOGO
void setup_game();
void mainloop();

                };

//****************************************************************************************************************************
//CONSTRUTORES E DESTRUIDORES DA CLASSE

//CONSTRUTOR
void chess_game::set_default_values(){
//VARIÁVEIS LOCAIS
int i, j;
//AJUSTE DOS TABULEIROS
for(i=0; i<8; ++i){
for(j=0; j<8; ++j){
board[i][j]="  ";
secondary_board[i][j]="  ";
                  };
                  };

//LISTA DE LANCES
move_list.clear();

//AJUSTE DE DEMAIS VARIÁVEIS
row1=0;
row2=0;
column1=0;
column2=0;
white_evaluation1=0;
white_evaluation2=0;
black_evaluation1=0;
black_evaluation2=0;
nor_pawn_capture=0;
white_king_in_check=false;
black_king_in_check=false;
white_king_row=0;
white_king_column=0;
white_attacker_row=0;
white_attacker_column=0;
black_king_row=0;
black_king_column=0;
black_attacker_row=0;
black_attacker_column=0;
white_attacker="";
black_attacker="";
checkmate=false;
draw_game=false;
white_en_passant=false;
black_en_passant=false;
white_turn=false;
black_turn=false;
white_castle=false;
black_castle=false;
white_castle_checker1=true;
white_castle_checker2=true;
black_castle_checker1=true;
black_castle_checker2=true;
resignation=false;

                                   };

//DESTRUIDOR
chess_game::~chess_game(){
move_list.clear();
                         };
