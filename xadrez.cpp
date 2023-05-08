//VAMOS CRIAR UM JOGO DE XADREZ EM C++
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o xadrez xadrez.cpp
//****************************************************************************************************************************

/*CABEÇALHO*/
#include<iostream>
#include<string>
#include"xadrez_texto.hpp"
#include"xadrez_classe.hpp"
#include"xadrez_metodos_tabuleiro.hpp"
#include"xadrez_metodos_cheques.hpp"
#include"xadrez_metodos_pecas.hpp"
#include"xadrez_metodos_chequemate.hpp"
#include"xadrez_metodos_empate.hpp"
#include"xadrez_metodos_mainloop.hpp"
using namespace std;

//FUNÇÃO PRINCIPAL
int main(){
//VARIÁVEIS LOCAIS
string token;
//APRESENTAÇÃO DO JOGO
introduction();
how_to_play();
//INSTANCIANDO UM OBJETO DA CLASSE
chess_game chess;
restart:
//AJUSTANDO O JOGO EM SUA CONFIGURAÇÃO INICIAL
chess.setup_game();
//LOOP PRINCIPAL DO JOGO
chess.mainloop();

//REINICIANDO A PARTIDA
cout<<"Jogadores você desejam realizar outra partida?\n(Digite 's' para jogar outra partida ou 'n' para encerrar a aplicação)\n";
cin>>token;
if(token=="s")
goto restart;

//FINALIZANDO A APLICAÇÃO
credits();
end_text();
return 0;
          }
