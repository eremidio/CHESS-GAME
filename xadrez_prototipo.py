#VAMOS IMPLEMENTAR UM JOGO DE XADREZ EM PYTHON
#USAREMOS UMA INTERFACE DE TEXTO PARA REPRESENTAR O TABULEIRO E PARA INTERAÇÃO DOS USUÁRIOS
#EXCUTAR ESTE SCRIPT COM O COMANDO: python3 xadrez.py

'''NOTAS GERAIS'''
#1. USAREMOS UM ARRAY 8X8 (ÍNDICES DE 0 A 7 PARA REPRESENTAR O TABULEIRO DO JOGO DE XADREZ) USANDO SEMPRE A CONVENÇÃO ESQUERDA -> DIREITA, BAIXO -> CIMA EM ORDEM CRESCENTE DE INDEXES. X SERÁ A PRIMEIRA COORDENADA (ITERANDO SOBRE LINHAS) E Y A SEGUNDA COORDENADA (ITERANDO SOBRE COLUNAS).
#2. CASAS VAZIAS NO TABULEIRO SERÃO DENOTADAS POR '  '
#3. USAREMOS VARIÁVEIS GLOBAIS EM TODAS AS FUNÇÕES
#4. ORDEM DAS JOGADAS DEVE OBDECER A SEGUINTE REGRA: SE CHEQUE -> LIVRE-SE DO CHEQUE OU CHEQUE MATE/FIM DE JOGO, CASO O REI NÃO ESTEJA EM CHEQUE O JOGADOR PODE FAZER UM MOVIMENTO VÁLIDO DE ACORDO COM AS REGRAS DE MOVIMENTAÇÃO DAS PEÇAS



#*****************************************************************************************************************************
#
#
#0: IMPORTANDO BIBLIOTECAS


#*****************************************************************************************************************************
#
#
#1: VARIÁVEIS USADAS NO PROGRAMA (USE A PALAVRA CHAVE global PARA USAR ESTAS VARIÁVEIS EM UMA FUNÇÃO)

#O TABULEIRO SERÁ IMPLEMENTADO COMO UM ARRAY 8X8, USAREMOS UM ARRAY AUXILIAR PARA EXECUÇÃO DE MOVIMENTOS
board1:list=[[' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],]

board2:list=[[' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],]

#VARIÁVEIS PARA CONTROLAR A ORDEM DO MOVIMENTO DAS PEÇAS
white:bool=True
black:bool=False
move_made:bool=False

#VARIÁVEIS PARA CONTROLAR A CAPTURA DE PEÇAS BRANCAS E PRETAS
white_value:int=0
black_value:int=0

#COORDENADAS QUE SERÃO USDADAS PARA EXECUÇÃO DO MOVIMENTO DAS PEÇAS
x1:int=0 #POSIÇÃO INICIAL
y1:int=0
x2:int=0 #POSIÇÃO FINAL
y2:int=0

#VARIÁVEIS USADAS PARA DETERMINAR SE UM JOGADOR ESTÁ EM CHEQUE
white_in_check:bool=False
black_in_check:bool=False

#VARIÁVEIS USADAS PARA SE CHECAR SE EXISTEM PEÇAS CRAVADAS
white_pin_check:bool=False
black_pin_check:bool=False

#VARIÁVEIS USADAS PARA SABER SE HOUVE PROMOÇÃO OU NÃO DE UM PEÃO
white_promotion:bool=False
black_promotion:bool=False

#VARIÁVEIS USADAS PARA SE DETERMINAR A POSSIBILIDADE DE CAPTURA EM PASSANT
white_en_passant:bool=False
black_en_passant:bool=False

#VARIÁVEL QUE DETERMINA SE HOUVE CHEQUE MATE OU NÃO
checkmate:bool = False

#VARIÁVEL QUE DETERMINA SE HOUVE EMPATE OU NÃO
draw_game:bool = False

#VARIÁVEL PARA ALOCAR OS MOVIMENTOS (POSIÇÃO INICIAL E POSIÇÃO FINAL DA JOGADA)
moves:list=[] #LISTA DE MOVIMENTOS (VAMOS ESTOCAR STRINGS COMO 'a7', 'a6', etc;)

#VARIÁVEL PARA SE ALOCAR O NÚMERO DE LANCES QUE NÃO SÃO DE PEÃO OU DE CAPTURA
no_pawn_capture_counting:int = 0

#*****************************************************************************************************************************
#
#
#2:FUNÇÃO QUE PRINTA O TABULEIRO DO JOGO DE XADREZ NA TELA

def position():
 '''Função que exibe a posição atual das peças do tabuleiro de xadrez'''
 global board1

 print('+------+------+------+------+------+------+------+------+  ')
 print('|      |      |      |      |      |      |      |      |  ')
 print('|  {}  |  {}  |  {}  |  {}  |  {}  |  {}  |  {}  |  {}  | 8'.format(board1[7][0], board1[7][1], board1[7][2], board1[7][3], board1[7][4], board1[7][5], board1[7][6], board1[7][7]))
 print('|      |      |      |      |      |      |      |      |  ')
 print('+------+------+------+------+------+------+------+------+  ')
 print('|      |      |      |      |      |      |      |      |  ')
 print('|  {}  |  {}  |  {}  |  {}  |  {}  |  {}  |  {}  |  {}  | 7'.format(board1[6][0], board1[6][1], board1[6][2], board1[6][3], board1[6][4], board1[6][5], board1[6][6], board1[6][7]))
 print('|      |      |      |      |      |      |      |      |  ')
 print('+------+------+------+------+------+------+------+------+  ')
 print('|      |      |      |      |      |      |      |      |  ')
 print('|  {}  |  {}  |  {}  |  {}  |  {}  |  {}  |  {}  |  {}  | 6'.format(board1[5][0], board1[5][1], board1[5][2], board1[5][3], board1[5][4], board1[5][5], board1[5][6], board1[5][7]))
 print('|      |      |      |      |      |      |      |      |  ')
 print('+------+------+------+------+------+------+------+------+  ')
 print('|      |      |      |      |      |      |      |      |  ')
 print('|  {}  |  {}  |  {}  |  {}  |  {}  |  {}  |  {}  |  {}  | 5'.format(board1[4][0], board1[4][1], board1[4][2], board1[4][3], board1[4][4], board1[4][5], board1[4][6], board1[4][7]))
 print('|      |      |      |      |      |      |      |      |  ')
 print('+------+------+------+------+------+------+------+------+  ')
 print('|      |      |      |      |      |      |      |      |  ')
 print('|  {}  |  {}  |  {}  |  {}  |  {}  |  {}  |  {}  |  {}  | 4'.format(board1[3][0], board1[3][1], board1[3][2], board1[3][3], board1[3][4], board1[3][5], board1[3][6], board1[3][7]))
 print('|      |      |      |      |      |      |      |      |  ')
 print('+------+------+------+------+------+------+------+------+  ')
 print('|      |      |      |      |      |      |      |      |  ')
 print('|  {}  |  {}  |  {}  |  {}  |  {}  |  {}  |  {}  |  {}  | 3'.format(board1[2][0], board1[2][1], board1[2][2], board1[2][3], board1[2][4], board1[2][5], board1[2][6], board1[2][7]))
 print('|      |      |      |      |      |      |      |      |  ')
 print('+------+------+------+------+------+------+------+------+  ')
 print('|      |      |      |      |      |      |      |      |  ')
 print('|  {}  |  {}  |  {}  |  {}  |  {}  |  {}  |  {}  |  {}  | 2'.format(board1[1][0], board1[1][1], board1[1][2], board1[1][3], board1[1][4], board1[1][5], board1[1][6], board1[1][7]))
 print('|      |      |      |      |      |      |      |      |  ')
 print('+------+------+------+------+------+------+------+------+  ')
 print('|      |      |      |      |      |      |      |      |  ')
 print('|  {}  |  {}  |  {}  |  {}  |  {}  |  {}  |  {}  |  {}  | 1'.format(board1[0][0], board1[0][1], board1[0][2], board1[0][3], board1[0][4], board1[0][5], board1[0][6], board1[0][7]))
 print('|      |      |      |      |      |      |      |      |  ')
 print('+------+------+------+------+------+------+------+------+  ')
 print('   a      b       c      d      e      f      g      h     ')

#*****************************************************************************************************************************
#
#
#3:TEXTO INTRODUTÓRIO E EXPLICAÇÃO DE COMO O PROGRAMA DEVE SER USADO

print('\n')
print('\033[94m'+'\033[01m'+' CCCCC  HH   HH EEEEEEE  SSSSS   SSSSS  '+'\033[0;0m')
print('\033[94m'+'\033[01m'+'CC    C HH   HH EE      SS      SS      '+'\033[0;0m')
print('\033[94m'+'\033[01m'+'CC      HHHHHHH EEEEE    SSSSS   SSSSS  '+'\033[0;0m')
print('\033[94m'+'\033[01m'+'CC    C HH   HH EE           SS      SS '+'\033[0;0m')
print('\033[94m'+'\033[01m'+' CCCCC  HH   HH EEEEEEE  SSSSS   SSSSS  '+'\033[0;0m')
print('\n')
print('\033[01m'+'Bem vindo ao jogo de xadrez!\nEsperamos que você se divirta!!!'+'\033[0;0m')
print('\033[01m'+'Vamos jogar este jogo num tabuleiro 8x8:'+'\033[0;0m')

stop=input()

#Gerando a malha quadrada 8x8 que irá alocar as peças no tabuleiro de xadrez
print('+------+------+------+------+------+------+------+------+  ')
print('|      |      |      |      |      |      |      |      |  ')
print('|      |      |      |      |      |      |      |      | 8')
print('|      |      |      |      |      |      |      |      |  ')
print('+------+------+------+------+------+------+------+------+  ')
print('|      |      |      |      |      |      |      |      |  ')
print('|      |      |      |      |      |      |      |      | 7')
print('|      |      |      |      |      |      |      |      |  ')
print('+------+------+------+------+------+------+------+------+  ')
print('|      |      |      |      |      |      |      |      |  ')
print('|      |      |      |      |      |      |      |      | 6')
print('|      |      |      |      |      |      |      |      |  ')
print('+------+------+------+------+------+------+------+------+  ')
print('|      |      |      |      |      |      |      |      |  ')
print('|      |      |      |      |      |      |      |      | 5')
print('|      |      |      |      |      |      |      |      |  ')
print('+------+------+------+------+------+------+------+------+  ')
print('|      |      |      |      |      |      |      |      |  ')
print('|      |      |      |      |      |      |      |      | 4')
print('|      |      |      |      |      |      |      |      |  ')
print('+------+------+------+------+------+------+------+------+  ')
print('|      |      |      |      |      |      |      |      |  ')
print('|      |      |      |      |      |      |      |      | 3')
print('|      |      |      |      |      |      |      |      |  ')
print('+------+------+------+------+------+------+------+------+  ')
print('|      |      |      |      |      |      |      |      |  ')
print('|      |      |      |      |      |      |      |      | 2')
print('|      |      |      |      |      |      |      |      |  ')
print('+------+------+------+------+------+------+------+------+  ')
print('|      |      |      |      |      |      |      |      |  ')
print('|      |      |      |      |      |      |      |      | 1')
print('|      |      |      |      |      |      |      |      |  ')
print('+------+------+------+------+------+------+------+------+  ')
print('   a      b       c      d      e      f      g      h     ')
print('\n')

stop=input()

print('\033[01m'+'Eis as regras de como usar esta aplicação:\nPara executar o movimento de uma peça você deve especificar a posição inicial e a posição final das casas do tabuleiro que caracterizam o movimento\nusando a notação de coordenadas do tabuleiro acima como "a1", "b7", etc.\nA notação "o-o" será usada para denotar o pequeno roque e a notação "o-o-o" denota o grande roque, movimentos especiais do jogo.\nInsira estes comandos para execução do roque quando lhe for solicitado a casa inicial na qual está a peça a ser movida\nAs peças de cada jogador são especificadas por uma sigla contendo o primeira letra do nome e a cor da peça:\nPB-> peão branco, CB-> cavalo branco, BB-> bispo branco, TB-> Torre branca, DB-> dama branca, RB-> rei branco\nPP-> peão preto, CP-> cavalo preto, BP-> bispo preto, TP-> Torre preta, DP-> dama preta, RP-> rei preta.\nEm caso de promoção de peões o usuário deverá usar a notação acima para especificar para qual peça o peão será promovido.\nQuando aparecer o símbolo ":::" digite a palavra "draw" para propor empate ao adversário ou aperte enter para continuar.\nAs regras básicas do jogo e a movimentação básica das peças estão disponíveis nos links:\nhttps://pt.wikipedia.org/wiki/Leis_do_xadrez e https://pt.wikipedia.org/wiki/Xadrez\n'+'\033[0;0m')
                                       
#*****************************************************************************************************************************
#
#
#4: AJUSTANDO O TABULEIRO DE XADREZ EM SUA CONFIGURAÇÃO INICIAL:
stop=input()

print('\n')
print('Eis o tabuleiro de xadrez em sua configuração inicial')
board1[0][0]='TB' #PEÇAS BRANCAS 
board1[0][1]='CB'
board1[0][2]='BB'
board1[0][3]='DB'
board1[0][4]='RB'
board1[0][5]='BB'
board1[0][6]='CB'
board1[0][7]='TB'
board1[1][0]='PB'
board1[1][1]='PB'
board1[1][2]='PB'
board1[1][3]='PB'
board1[1][4]='PB'
board1[1][5]='PB'
board1[1][6]='PB'
board1[1][7]='PB'
board1[6][0]='PP' #PEÇAS PRETAS
board1[6][1]='PP'
board1[6][2]='PP'
board1[6][3]='PP'
board1[6][4]='PP'
board1[6][5]='PP'
board1[6][6]='PP'
board1[6][7]='PP'
board1[7][0]='TP'
board1[7][1]='CP'
board1[7][2]='BP'
board1[7][3]='DP'
board1[7][4]='RP'
board1[7][5]='BP'
board1[7][6]='CP'
board1[7][7]='TP'

#AJUSTANDO AS DEMAIS CASAS DO TABULEIRO
for i in range(8):
 for j in range(8):
  if(board1[i][j]==' '):
   board1[i][j]='  ' #CASAS VAZIAS SERÃO DENOTADAS POR UM DUPLO ESPAÇO VAZIO

#PRINTANDO O TABULEIRO NA TELA
position()

#*****************************************************************************************************************************
#
#
#5: FUNÇÃO QUE RETORNA OS INDEXES CORRESPONDENTES A UMA POSIÇÃO NO TABULEIRO DE XADREZ

def index(string:str)->(int, int):
 '''Função que retorna dois indexes correpondentes a uma posição no jogo de xadrez'''
 x:int=0
 y:int=0
 pos:list=list(string)
 if(pos[0]=='a'): #PRIMEIRA COORDENADA
  x=0
 if(pos[0]=='b'):
  x=1
 if(pos[0]=='c'):
  x=2
 if(pos[0]=='d'):
  x=3
 if(pos[0]=='e'):
  x=4
 if(pos[0]=='f'):
  x=5
 if(pos[0]=='g'):
  x=6
 if(pos[0]=='h'):
  x=7

 y=int(pos[1])-1 #SEGUNDA COORDENADA

 return x, y

'''TESTE DA FUNÇÃO DE INDEXAÇÃO DE POSIÇÕES, USE UM # APÓS O TESTE'''
#x1, y1=index('g1')
#x2, y2=index('f3')
#print(x1, y1)
#print(x2, y2)
#x1, y1=index('d7')
#x2, y2=index('d5')
#print(x1, y1)
#print(x2, y2)

#*****************************************************************************************************************************
#
#
#6: FUNÇÃO QUE AVALIA  O VALOR DAS PEÇAS DO JOGADOR DE BRANCAS E DE PRETAS

def get_white_value()->int:
 '''Função que avalia o valor de peças das brancas'''
 global white_value
 global board1

 soma:int=0

 for i in range(8):
  for j in range(8):
   if(board1[i][j]=='PB'):
    soma+=100
   if(board1[i][j]=='CB'):
    soma+=300
   if(board1[i][j]=='BB'):
    soma+=400
   if(board1[i][j]=='TB'):
    soma+=500
   if(board1[i][j]=='DB'):
    soma+=900
   if(board1[i][j]=='RB'):
    soma+=10000
 white_value=soma
 return white_value

def get_black_value()->int:
 '''Função que avalia o valor de peças das brancas'''
 global black_value
 global board1

 soma:int=0

 for i in range(8):
  for j in range(8):
   if(board1[i][j]=='PP'):
    soma+=100
   if(board1[i][j]=='CP'):
    soma+=300
   if(board1[i][j]=='BP'):
    soma+=400
   if(board1[i][j]=='TP'):
    soma+=500
   if(board1[i][j]=='DP'):
    soma+=900
   if(board1[i][j]=='RP'):
    soma+=10000

 black_value=soma
 return black_value

'''TESTE DA FUNÇÃO DE INDEXAÇÃO DE CONTAGEM DO VALOR DE PEÇAS, USE UM # APÓS O TESTE'''
#get_black_value()
#get_white_value()
#print("Branco: ", white_value)
#print("Preto: ", black_value)


#*****************************************************************************************************************************
#
#
#7:FUNÇÕES QUE VALIDAM O MOVIMENTO DAS PEÇAS (SE É POSSÍVEL MOVER UMA PEÇA)

#7.1: PEÕES
#7.1.1: BRANCAS
def validate_white_pawn_move()->bool:
 '''Função que checa se o movimento de peão proposto pelas brancas é válido'''
 global x1
 global x2
 global y2
 global y1
 global board1
 global black_en_passant

 #CHECANDO SE O LIMITE DO TABULEIRO É RESPEITADO
 if(x1>0 or x1<7 or x2>0 or x2<7 or y1>0 or y1<7 or y2>0 or y2<7):
  print("Movimento inválido!")
  return False
 #CHECANDO SE O PEÃO BRANCO ESTÁ NA CASA INICIAL
 if(x1==1 and abs(x1-x2)<3  and y1==y2 and board1[x2][y2]=='  '):
  #CHECANDO SE AS PRETAS PODERÃO FAZER CAPTURA EN PASSANT APÓS O LANCE DAS BRANCAS
  if((y2-1)>=0 and (y2-1)<=7 and abs(x1-x2)==2 and board1[x2][y2-1]=='PP'):
   black_en_passant=True
  if((y2+1)>=0 and (y2+1)<=7 and abs(x1-x2)==2 and board1[x2][y2-1]=='PP'):
   black_en_passant=True
  return True
 #CASO GERAL 
 elif(x1>1 and abs(x1-x2)==1  and y1==y2 and board1[x2][y2]=='  '):
  return True
 #POSSIBILIDADE DE CAPTURAS
 elif(abs(x2-x1)==1  and abs(y2-y1)==1):
  if(board1[x2][y2]=='PP' or board1[x2][y2]=='TP' or board1[x2][y2]=='CP' or board1[x2][y2]=='BP' or board1[x2][y2]=='DP'):
   return True
 else:
  print("Movimento inválido!")
  return False


#7.1.2: NEGRAS
def validate_black_pawn_move()->bool:
 '''Função que checa se o movimento de peão proposto pelas brancas é válido'''
 global x1
 global x2
 global y2
 global y1
 global board1
 global white_en_passant
 #CHECANDO SE O LIMITE DO TABULEIRO É RESPEITADO
 if(x1>0 or x1<7 or x2>0 or x2<7 or y1>0 or y1<7 or y2>0 or y2<7):
  print("Movimento inválido!")
  return False
 #CHECANDO SE O PEÃO BRANCO ESTÁ NA CASA INICIAL
 if(x1==6 and abs(x1-x2)<3  and y1==y2 and board1[x2][y2]=='  '):
  #CHECANDO SE AS BRANCAS PODERÃO FAZER CAPTURA EN PASSANT APÓS O LANCE DAS PRETAS
  if((y2-1)>=0 and (y2-1)<=7 and abs(x1-x2)==2 and board1[x2][y2-1]=='PB'):
   white_en_passant=True
  if((y2+1)>=0 and (y2+1)<=7 and abs(x1-x2)==2 and board1[x2][y2-1]=='PB'):
   white_en_passant=True
  return True
 #CASO GERAL 
 elif(x1<6 and abs(x1-x2)==1  and y1==y2 and board1[x2][y2]=='  '):
  return True
 #POSSIBILIDADE DE CAPTURAS
 elif(abs(x2-x1)==1  and abs(y2-y1)==1):
  if(board1[x2][y2]=='PB' or board1[x2][y2]=='TB' or board1[x2][y2]=='CB' or board1[x2][y2]=='BP' or board1[x2][y2]=='DB'):
   return True
 else:
  print("Movimento inválido!")
  return False

#7.2: CAVALOS
#7.2.1: BRANCAS
def validate_white_knight_move()->bool:
 '''Função que valida o movimento de um cavalo das brancas.'''
 global x1
 global x2
 global y2
 global y1
 global board1

 #CHECANDO SE O LIMITE DO TABULEIRO É RESPEITADO
 if(x1>0 or x1<7 or x2>0 or x2<7 or y1>0 or y1<7 or y2>0 or y2<7):
  print("Movimento inválido!")
  return False
 #UM CAVALO FAZ UM MOVIMENTO EM L (2 NUMA DIREÇÃO E 1 NA PERPENDICULAR) E NÃO POUSA SOBRE UMA PEÇA PRÓPRIA
 if(abs(x2-x1)==1 and abs(y2-y1)==2):
  if(board1[x2][y2]!='PB' and board1[x2][y2]!='TB' and board1[x2][y2]!='CB' and board1[x2][y2]!='BB' and board1[x2][y2]!='DB' and board1[x2][y2]!='RB'):
   return True
 elif(abs(x2-x1)==2 and abs(y2-y1)==1):
  if(board1[x2][y2]!='PB' and board1[x2][y2]!='TB' and board1[x2][y2]!='CB' and board1[x2][y2]!='BB' and board1[x2][y2]!='DB' and board1[x2][y2]!='RB'):
   return True
 else:
  print("Movimento inválido!")
  return False

#7.2.2: NEGRAS
def validate_black_knight_move()->bool:
 '''Função que valida o movimento de um cavalo das brancas.'''
 global x1
 global x2
 global y2
 global y1
 global board1

 #CHECANDO SE O LIMITE DO TABULEIRO É RESPEITADO
 if(x1>0 or x1<7 or x2>0 or x2<7 or y1>0 or y1<7 or y2>0 or y2<7):
  print("Movimento inválido!")
  return False
 #UM CAVALO FAZ UM MOVIMENTO EM L (2 NUMA DIREÇÃO E 1 NA PERPENDICULAR) E NÃO POSUSA SOBRE UMA PEÇA PRÓPRIA
 if(abs(x2-x1)==1 and abs(y2-y1)==2):
  if(board1[x2][y2]!='PP' and board1[x2][y2]!='TP' and board1[x2][y2]!='CP' and board1[x2][y2]!='BP' and board1[x2][y2]!='DP' and board1[x2][y2]!='RP'):
   return True
 elif(abs(x2-x1)==2 and abs(y2-y1)==1):
  if(board1[x2][y2]!='PP' and board1[x2][y2]!='TP' and board1[x2][y2]!='CP' and board1[x2][y2]!='BP' and board1[x2][y2]!='DP' and board1[x2][y2]!='RP'):
   return True
 else:
  print("Movimento inválido!")
  return False
  
#7.3: BISPOS
#7.3.1: BRANCAS
def validate_white_bishop_move()->bool:
 '''Função que valida o movimento do bispo das brancas.'''
 global x1
 global x2
 global y2
 global y1
 global board1

 #CHECANDO SE O LIMITE DO TABULEIRO É RESPEITADO
 if(x1>0 or x1<7 or x2>0 or x2<7 or y1>0 or y1<7 or y2>0 or y2<7):
  print("Movimento inválido!")
  return False
 #VARIÁVEIS LOCAIS
 gap_h:int=(y2-y1)
 gap_v:int=(x2-x1)
 #BISPOS ANDAM NA DIAGONAL
 if(abs(gap_h)!=abs(gap_v)):
  print("Movimento inválido!")
  return False
 #CHECANDO SE HÁ ALGUMA OBSTRUÇÃO DE PEÇAS PRÓPRIAS NAS QUATRO DIAGONAIS
 if(gap_h>0 and gap_v>0): #DIAGONAL DIREIRA PARA CIMA
  for i in range(gap_h+1):
   if(board1[x1+i][y1+i]=='PB' or board1[x1+i][y1+i]=='TB' or board1[x1+i][y1+i]=='CB' or board1[x1+i][y1+i]=='DB' or  board1[x1+i][y1+i]=='RB'):
    print("Movimento inválido!")
    return False
 if(gap_h<0 and gap_v>0): #DIAGONAL ESQUERDA PARA CIMA
  for i in range(abs(gap_h)+1):
   if(board1[x1+i][y1-i]=='PB' or board1[x1+i][y1-i]=='TB' or board1[x1+i][y1-i]=='CB' or board1[x1+i][y1-i]=='DB' or  board1[x1+i][y1-i]=='RB'):
    print("Movimento inválido!")
    return False
 if(gap_h>0 and gap_v<0): #DIAGONAL DIREIRA PARA BAIXO
  for i in range(gap_h+1):
   if(board1[x1-i][y1+i]=='PB' or board1[x1-i][y1+i]=='TB' or board1[x1-i][y1+i]=='CB' or board1[x1-i][y1+i]=='DB' or  board1[x1-i][y1+i]=='RB'):
    print("Movimento inválido!")
    return False
 if(gap_h<0 and gap_v<0): #DIAGONAL ESQUERDA PARA BAIXO
  for i in range(abs(gap_h)+1):
   if(board1[x1-i][y1-i]=='PB' or board1[x1-i][y1-i]=='TB' or board1[x1-i][y1-i]=='CB' or board1[x1-i][y1-i]=='DB' or  board1[x1-i][y1-i]=='RB'):
    print("Movimento inválido!")
    return False

 #CHECANDO SE HÁ ALGUMA OBSTRUÇÃO DE PEÇAS ADVERSÁRIAS NAS QUATRO DIAGONAIS
 if(gap_h>0 and gap_v>0): #DIAGONAL DIREIRA PARA CIMA
  for i in range(gap_h):
   if(board1[x1+i][y1+i]=='PP' or board1[x1+i][y1+i]=='TP' or board1[x1+i][y1+i]=='CP' or board1[x1+i][y1+i]=='BP' or board1[x1+i][y1+i]=='DP' or  board1[x1+i][y1+i]=='RP'):
    print("Movimento inválido!")
    return False
 if(gap_h<0 and gap_v>0): #DIAGONAL ESQUERDA PARA CIMA
  for i in range(abs(gap_h)):
   if(board1[x1+i][y1-i]=='PP' or board1[x1+i][y1-i]=='TP' or board1[x1+i][y1-i]=='CP' or board1[x1+i][y1-i]=='BP' or board1[x1+i][y1-i]=='DP' or  board1[x1+i][y1-i]=='RP'):
    print("Movimento inválido!")
    return False
 if(gap_h>0 and gap_v<0): #DIAGONAL DIREIRA PARA BAIXO
  for i in range(gap_h):
   if(board1[x1-i][y1+i]=='PP' or board1[x1-i][y1+i]=='TP' or board1[x1-i][y1+i]=='CP' or board1[x1-i][y1+i]=='BP' or board1[x1-i][y1+i]=='DP' or  board1[x1-i][y1+i]=='RP'):
    print("Movimento inválido!")
    return False
 if(gap_h<0 and gap_v<0): #DIAGONAL ESQUERDA PARA BAIXO
  for i in range(abs(gap_h)):
   if(board1[x1-i][y1-i]=='PP' or board1[x1-i][y1-i]=='TP' or board1[x1-i][y1-i]=='CP' or board1[x1-i][y1-i]=='BP' or board1[x1-i][y1-i]=='DP' or  board1[x1-i][y1-i]=='RP'):
    print("Movimento inválido!")
    return False
 #CASO NENHUMA DAS CONDIÇÕES ACIMA SEJA SATISFEITA, VALIDAR O MOVIMENTO
 return True


#7.3.2: NEGRAS
def validate_black_bishop_move()->bool:
 '''Função que valida o movimento do bispo das brancas.'''
 global x1
 global x2
 global y2
 global y1
 global board1

 #CHECANDO SE O LIMITE DO TABULEIRO É RESPEITADO
 if(x1>0 or x1<7 or x2>0 or x2<7 or y1>0 or y1<7 or y2>0 or y2<7):
  print("Movimento inválido!")
  return False
 #VARIÁVEIS LOCAIS
 gap_h:int=(y2-y1)
 gap_v:int=(x2-x1)
 #BISPOS ANDAM NA DIAGONAL
 if(abs(gap_h)!=abs(gap_v)):
  print("Movimento inválido!")
  return False
 #CHECANDO SE HÁ ALGUMA OBSTRUÇÃO DE PEÇAS PRÓPRIAS NAS QUATRO DIAGONAIS
 if(gap_h>0 and gap_v>0): #DIAGONAL DIREIRA PARA CIMA
  for i in range(gap_h+1):
   if(board1[x1+i][y1+i]=='PP' or board1[x1+i][y1+i]=='TP' or board1[x1+i][y1+i]=='CP' or board1[x1+i][y1+i]=='DP' or  board1[x1+i][y1+i]=='RP'):
    print("Movimento inválido!")
    return False
 if(gap_h<0 and gap_v>0): #DIAGONAL ESQUERDA PARA CIMA
  for i in range(abs(gap_h)+1):
   if(board1[x1+i][y1-i]=='PP' or board1[x1+i][y1-i]=='TP' or board1[x1+i][y1-i]=='CP' or board1[x1+i][y1-i]=='DP' or  board1[x1+i][y1-i]=='RP'):
    print("Movimento inválido!")
    return False
 if(gap_h>0 and gap_v<0): #DIAGONAL DIREIRA PARA BAIXO
  for i in range(gap_h+1):
   if(board1[x1-i][y1+i]=='PP' or board1[x1-i][y1+i]=='TP' or board1[x1-i][y1+i]=='CP' or board1[x1-i][y1+i]=='DP' or  board1[x1-i][y1+i]=='RP'):
    print("Movimento inválido!")
    return False
 if(gap_h<0 and gap_v<0): #DIAGONAL ESQUERDA PARA BAIXO
  for i in range(abs(gap_h)+1):
   if(board1[x1-i][y1-i]=='PP' or board1[x1-i][y1-i]=='TP' or board1[x1-i][y1-i]=='CP' or board1[x1-i][y1-i]=='DP' or  board1[x1-i][y1-i]=='RP'):
    print("Movimento inválido!")
    return False

 #CHECANDO SE HÁ ALGUMA OBSTRUÇÃO DE PEÇAS ADVERSÁRIAS NAS QUATRO DIAGONAIS
 if(gap_h>0 and gap_v>0): #DIAGONAL DIREIRA PARA CIMA
  for i in range(gap_h):
   if(board1[x1+i][y1+i]=='PB' or board1[x1+i][y1+i]=='TB' or board1[x1+i][y1+i]=='CB' or board1[x1+i][y1+i]=='BB' or board1[x1+i][y1+i]=='DB' or  board1[x1+i][y1+i]=='RB'):
    print("Movimento inválido!")
    return False
 if(gap_h<0 and gap_v>0): #DIAGONAL ESQUERDA PARA CIMA
  for i in range(abs(gap_h)):
   if(board1[x1+i][y1-i]=='PB' or board1[x1+i][y1-i]=='TB' or board1[x1+i][y1-i]=='CB' or board1[x1+i][y1-i]=='BB' or board1[x1+i][y1-i]=='DB' or  board1[x1+i][y1-i]=='RB'):
    print("Movimento inválido!")
    return False
 if(gap_h>0 and gap_v<0): #DIAGONAL DIREIRA PARA BAIXO
  for i in range(gap_h):
   if(board1[x1-i][y1+i]=='PB' or board1[x1-i][y1+i]=='TB' or board1[x1-i][y1+i]=='CB' or board1[x1-i][y1+i]=='BB' or board1[x1-i][y1+i]=='DB' or  board1[x1-i][y1+i]=='RB'):
    print("Movimento inválido!")
    return False
 if(gap_h<0 and gap_v<0): #DIAGONAL ESQUERDA PARA BAIXO
  for i in range(abs(gap_h)):
   if(board1[x1-i][y1-i]=='PB' or board1[x1-i][y1-i]=='TB' or board1[x1-i][y1-i]=='CB' or board1[x1-i][y1-i]=='BB' or board1[x1-i][y1-i]=='DB' or  board1[x1-i][y1-i]=='RB'):
    print("Movimento inválido!")
    return False
 #CASO NENHUMA DAS CONDIÇÕES ACIMA SEJA SATISFEITA, VALIDAR O MOVIMENTO
 return True


#7.4: TORRES
#7.4.1: BRANCAS
def validate_white_rook_move()->bool:
 '''Função que valida o movimento da torre das brancas.'''
 global x1
 global x2
 global y2
 global y1
 global board1

 #CHECANDO SE O LIMITE DO TABULEIRO É RESPEITADO
 if(x1>0 or x1<7 or x2>0 or x2<7 or y1>0 or y1<7 or y2>0 or y2<7):
  print("Movimento inválido!")
  return False
 #VARIÁVEIS LOCAIS
 gap_h:int=(y2-y1)
 gap_v:int=(x2-x1)
 #TORRE ANDA EM LINHA RETA
 if(gap_v!=0 and gap_v!=0):
  print("Movimento inválido!")
  return False
 #CHECANDO POR OBSTRUÇÕES DE PRÓPRIAS PEÇAS E PEÇAS ADVERSÁRIAS
 #MOVIMENTO NA HORIZONTAL
 #ESQUERDA
 if(gap_v==0 and gap_h<0):
  for i in range(abs(gap_h)+1):
   if(board1[x1][y1-i]=='RB' or board1[x1][y1-i]=='TB' or board1[x1][y1-i]=='BB' or board1[x1][y1-i]=='CB' or board1[x1][y1-i]=='DB'):
    print("Movimento inválido!")
    return False
  for i in range(abs(gap_h)):
   if(board1[x1][y1-i]=='RP' or board1[x1][y1-i]=='TP' or board1[x1][y1-i]=='BP' or board1[x1][y1-i]=='CP' or board1[x1][y1-i]=='DP'):
    print("Movimento inválido!")
    return False
 #DIREITA
 if(gap_v==0 and gap_h>0):
  for i in range(gap_h+1):
   if(board1[x1][y1+i]=='RB' or board1[x1][y1+i]=='TB' or board1[x1][y1+i]=='BB' or board1[x1][y1+i]=='CB' or board1[x1][y1+i]=='DB'):
    print("Movimento inválido!")
    return False
  for i in range(gap_h):
   if(board1[x1][y1+i]=='RP' or board1[x1][y1+i]=='TP' or board1[x1][y1+i]=='BP' or board1[x1][y1+i]=='CP' or board1[x1][y1+i]=='DP'):
    print("Movimento inválido!")
    return False
 #MOVIMENTO NA VERTICAL
 #CIMA
 if(gap_v>0 and gap_h==0):
  for i in range(gap_v+1):
   if(board1[x1+i][y1]=='RB' or board1[x1+i][y1]=='TB' or board1[x1+i][y1]=='BB' or board1[x1+i][y1]=='CB' or board1[x1+i][y1]=='DB'):
    print("Movimento inválido!")
    return False
  for i in range(gap_v):
   if(board1[x1+i][y1]=='RP' or board1[x1+i][y1]=='TP' or board1[x1+i][y1]=='BP' or board1[x1+i][y1]=='CP' or board1[x1+i][y1]=='DP'):
    print("Movimento inválido!")
    return False
 #BAIXO
 if(gap_v<0 and gap_h==0):
  for i in range(abs(gap_v)+1):
   if(board1[x1-i][y1]=='RB' or board1[x1-i][y1]=='TB' or board1[x1-i][y1]=='BB' or board1[x1-i][y1]=='CB' or board1[x1-i][y1]=='DB'):
    print("Movimento inválido!")
    return False
  for i in range(abs(gap_v)):
   if(board1[x1-i][y1]=='RP' or board1[x1-i][y1]=='TP' or board1[x1-i][y1]=='BP' or board1[x1-i][y1]=='CP' or board1[x1-i][y1]=='DP'):
    print("Movimento inválido!")
    return False
 #CASO NENHUMA DAS CONDIÇÕES ACIMA SEJA SATISFEITA
 return True

#7.4.2: NEGRAS
def validate_black_rook_move()->bool:
 '''Função que valida o movimento da torre das brancas.'''
 global x1
 global x2
 global y2
 global y1
 global board1

 #CHECANDO SE O LIMITE DO TABULEIRO É RESPEITADO
 if(x1>0 or x1<7 or x2>0 or x2<7 or y1>0 or y1<7 or y2>0 or y2<7):
  print("Movimento inválido!")
  return False
 #VARIÁVEIS LOCAIS
 gap_h:int=(y2-y1)
 gap_v:int=(x2-x1)
 #TORRE ANDA EM LINHA RETA
 if(gap_v!=0 and gap_v!=0):
  print("Movimento inválido!")
  return False
 #CHECANDO POR OBSTRUÇÕES DE PRÓPRIAS PEÇAS E PEÇAS ADVERSÁRIAS
 #MOVIMENTO NA HORIZONTAL
 #ESQUERDA
 if(gap_v==0 and gap_h<0):
  for i in range(abs(gap_h)+1):
   if(board1[x1][y1-i]=='RP' or board1[x1][y1-i]=='TP' or board1[x1][y1-i]=='BP' or board1[x1][y1-i]=='CP' or board1[x1][y1-i]=='DP'):
    print("Movimento inválido!")
    return False
  for i in range(abs(gap_h)):
   if(board1[x1][y1-i]=='RB' or board1[x1][y1-i]=='TB' or board1[x1][y1-i]=='BB' or board1[x1][y1-i]=='CB' or board1[x1][y1-i]=='DB'):
    print("Movimento inválido!")
    return False
 #DIREITA
 if(gap_v==0 and gap_h>0):
  for i in range(gap_h+1):
   if(board1[x1][y1+i]=='RP' or board1[x1][y1+i]=='TP' or board1[x1][y1+i]=='BP' or board1[x1][y1+i]=='CP' or board1[x1][y1+i]=='DP'):
    print("Movimento inválido!")
    return False
  for i in range(gap_h):
   if(board1[x1][y1+i]=='RB' or board1[x1][y1+i]=='TB' or board1[x1][y1+i]=='BB' or board1[x1][y1+i]=='CB' or board1[x1][y1+i]=='DB'):
    print("Movimento inválido!")
    return False
 #MOVIMENTO NA VERTICAL
 #CIMA
 if(gap_v>0 and gap_h==0):
  for i in range(gap_v+1):
   if(board1[x1+i][y1]=='RP' or board1[x1+i][y1]=='TP' or board1[x1+i][y1]=='BP' or board1[x1+i][y1]=='CP' or board1[x1+i][y1]=='DP'):
    print("Movimento inválido!")
    return False
  for i in range(gap_v):
   if(board1[x1+i][y1]=='RB' or board1[x1+i][y1]=='TB' or board1[x1+i][y1]=='BB' or board1[x1+i][y1]=='CB' or board1[x1+i][y1]=='DB'):
    print("Movimento inválido!")
    return False
 #BAIXO
 if(gap_v<0 and gap_h==0):
  for i in range(abs(gap_v)+1):
   if(board1[x1-i][y1]=='RP' or board1[x1-i][y1]=='TP' or board1[x1-i][y1]=='BP' or board1[x1-i][y1]=='CP' or board1[x1-i][y1]=='DP'):
    print("Movimento inválido!")
    return False
  for i in range(abs(gap_v)):
   if(board1[x1-i][y1]=='RB' or board1[x1-i][y1]=='TB' or board1[x1-i][y1]=='BB' or board1[x1-i][y1]=='CB' or board1[x1-i][y1]=='DB'):
    print("Movimento inválido!")
    return False
 #CASO NENHUMA DAS CONDIÇÕES ACIMA SEJA SATISFEITA
 return True

#7.5: DAMAS (A DAMA É UMA COMBINAÇÃO DE TORRE E BISPO)
#7.5.1: BRANCAS
def validate_white_queen_move()->bool:
 '''Função que valida o movimento de uma dama das brancas.'''
 global x1
 global x2
 global y2
 global y1
 global board1

 #CHECANDO SE O LIMITE DO TABULEIRO É RESPEITADO
 if(x1>0 or x1<7 or x2>0 or x2<7 or y1>0 or y1<7 or y2>0 or y2<7):
  print("Movimento inválido!")
  return False
 #VARIÁVEIS LOCAIS
 gap_h:int=(y2-y1)
 gap_v:int=(x2-x1)
 #MOVIMENTO EM LINHA RETA
 if(gap_h==0 or gap_v==0):
  validate_white_rook_move()
  if(validate_white_rook_move()==True):
   return True
  elif(validate_white_rook_move()==False):
   return False
 #MOVIMENTO EM DIAGONAL 
 if(gap_h!=0 and gap_v!=0):
  validate_white_bishop_move()
  if(validate_white_bishop_move()==True):
   return True
  elif(validate_white_bishop_move()==False):
   return False

#7.5.2: NEGRAS
def validate_black_queen_move()->bool:
 '''Função que valida o movimento de uma dama das negras.'''
 global x1
 global x2
 global y2
 global y1
 global board1

 #CHECANDO SE O LIMITE DO TABULEIRO É RESPEITADO
 if(x1>0 or x1<7 or x2>0 or x2<7 or y1>0 or y1<7 or y2>0 or y2<7):
  print("Movimento inválido!")
  return False
 #VARIÁVEIS LOCAIS
 gap_h:int=(y2-y1)
 gap_v:int=(x2-x1)
 #MOVIMENTO EM LINHA RETA
 if(gap_h==0 or gap_v==0):
  validate_black_rook_move()
  if(validate_black_rook_move()==True):
   return True
  elif(validate_black_rook_move()==False):
   return False
 #MOVIMENTO EM DIAGONAL 
 if(gap_h!=0 and gap_v!=0):
  validate_black_bishop_move()
  if(validate_black_bishop_move()==True):
   return True
  elif(validate_black_bishop_move()==False):
   return False

#7.6: REIS
#7.6.1: BRANCAS
def validate_white_king_move()->bool:
 '''Função que valida o movimento do rei das brancas.'''
 global x1
 global x2
 global y2
 global y1
 global board1

 #CHECANDO SE O LIMITE DO TABULEIRO É RESPEITADO
 if(x1>0 or x1<7 or x2>0 or x2<7 or y1>0 or y1<7 or y2>0 or y2<7):
  print("Movimento inválido!")
  return False
 #O REI MOVE-SE UMA CASA EM QUALQUER DIREÇÃO:
 if(abs(x2-x1)<2 and abs(y2-y1)<2 and board1[x2][y2]=='  '):
  return True
 else:
  print("Movimento inválido!")
  return False

#7.6.2: NEGRAS
def validate_black_king_move()->bool:
 '''Função que valida o movimento do rei das negras.'''
 global x1
 global x2
 global y2
 global y1
 global board1

 #CHECANDO SE O LIMITE DO TABULEIRO É RESPEITADO
 if(x1>0 or x1<7 or x2>0 or x2<7 or y1>0 or y1<7 or y2>0 or y2<7):
  print("Movimento inválido!")
  return False
 #O REI MOVE-SE UMA CASA EM QUALQUER DIREÇÃO:
 if(abs(x2-x1)<2 and abs(y2-y1)<2 and board1[x2][y2]=='  '):
  return True
 else:
  print("Movimento inválido!")
  return False


#*****************************************************************************************************************************
#
#
#8:FUNÇÕES QUE CHECAM SE OS REIS ESTÃO EM CHEQUE
#8.1.1: BRANCAS
def white_king_in_check()->bool:
 '''Função que calcula se o rei das brancas está em cheque.'''
 global board1
 global white_in_check
 
 #VARIÁVEIS LOCAIS
 x:int = 0
 y:int = 0
 white_in_check=False #VALOR PADRÃO

 #ENCONTRANDO A POSIÇÃO DO REI DA BRANCAS 
 for i in range(8):
  for j in range(8):
   if(board1[i][j]!='RB'):
    continue
   elif (board1[i][j]=='RB'):
    x=i #LINHA ONDE ESTÁ O REI
    y=j #COLUNA ONDE ESTÁ O REI

 #CHECANDO SE HÁ CHEQUES DE PEÃO
  #DIAGONAL SUPERIOR DIREITA
 if((x+1)>0 and (x+1)<8 and (y+1)>0 and (y+1)<8 and board1[x+1][y+1]=='PP'):
  white_in_check=True
  #DIAGONAL SUPERIOR ESQUERDA
 if((x+1)>0 and (x+1)<8 and (y-1)>0 and (y-1)<8 and board1[x+1][y-1]=='PP'):
  white_in_check=True
 #CHECANDO SE HÁ CHEQUES DE CAVALO (8 POSSÍVEIS POSIÇÕES)
 if((x+2)>0 and (x+2)<8 and (y+1)>0 and (y+1)<8 and board1[x+2][y+1]=='CP'):
  white_in_check=True
 if((x+1)>0 and (x+1)<8 and (y+2)>0 and (y+2)<8 and board1[x+1][y+2]=='CP'):
  white_in_check=True
 if((x-2)>0 and (x-2)<8 and (y-1)>0 and (y-1)<8 and board1[x-2][y-1]=='CP'):
  white_in_check=True
 if((x-1)>0 and (x-1)<8 and (y-2)>0 and (y-2)<8 and board1[x-1][y-2]=='CP'):
  white_in_check=True
 if((x+2)>0 and (x+2)<8 and (y-1)>0 and (y-1)<8 and board1[x+2][y-1]=='CP'):
  white_in_check=True
 if((x+1)>0 and (x+1)<8 and (y-2)>0 and (y-2)<8 and board1[x+1][y-2]=='CP'):
  white_in_check=True
 if((x-2)>0 and (x-2)<8 and (y+1)>0 and (y+1)<8 and board1[x-2][y+1]=='CP'):
  white_in_check=True
 if((x-1)>0 and (x-1)<8 and (y+2)>0 and (y+2)<8 and board1[x-1][y+2]=='CP'):
  white_in_check=True

 #CHECANDO SE HÁ CHEQUES DE BISPO OU DAMA
 #DIAGONAL SUPERIOR DIREITA (+1, +1)
  for i in range(8):
   if((x+i)>7 or (y+i)>7):
    break
   if(board1[x+i][y+i]!='BP' and board1[x+i][y+i]!='DP' and board1[x+i][y+i]!='  '):
     break
   if(board1[x+i][y+i]=='BP' or board1[x+i][y+i]=='DP'):
    white_in_check=True
    break
 #DIAGONAL SUPERIOR ESQUERDA (+1, -1)
  for i in range(8):
   if((x+i)>7 or (y-i)<0):
    break
   if(board1[x+i][y-i]!='BP' and board1[x+i][y-i]!='DP' and board1[x+i][y-i]!='  '):
     break
   if(board1[x+i][y-i]=='BP' or board1[x+i][y-i]=='DP'):
    white_in_check=True
    break
 #DIAGONAL INFERIOR DIREITA (-1, +1)
  for i in range(8):
   if((x-i)<0 or (y+i)>7):
    break
   if(board1[x-i][y+i]!='BP' and board1[x-i][y+i]!='DP' and board1[x-i][y+i]!='  '):
     break
   if(board1[x-i][y+i]=='BP' or board1[x-i][y+i]=='DP'):
    white_in_check=True
    break

 #DIAGONAL INFERIOR ESQUERDA (-1, -1)
  for i in range(8):
   if((x-i)<0 or (y-i)<0):
    break
   if(board1[x-i][y-i]!='BP' and board1[x-i][y-i]!='DP' and board1[x-i][y-i]!='  '):
     break
   if(board1[x-i][y-i]=='BP' or board1[x-i][y-i]=='DP'):
    white_in_check=True
    break
 #CHECANDO SE HÁ CHEQUES DE TORRE OU DAMA
 #DIREITA(0, +1)
  for i in range(8):
   if((y+i)>7):
    break
   if(board1[x][y+i]!='TP' and board1[x][y+i]!='DP' and board1[x][y+i]!='  '):
    break
   if(board1[x][y+i]=='TP' or board1[x][y+i]=='DP'):
    white_in_check=True
    break
 #ESQUERDA(0, -1)
  for i in range(8):
   if((y-i)<0):
    break
   if(board1[x][y-i]!='TP' and board1[x][y-i]!='DP' and board1[x][y-i]!='  '):
    break
   if(board1[x][y-i]=='TP' or board1[x][y-i]=='DP'):
    white_in_check=True
    break
 #CIMA (+1, 0)
  for i in range(8):
   if((x+i)>7):
    break
   if(board1[x+i][y]!='TP' and board1[x+i][y]!='DP' and board1[x+i][y]!='  '):
    break 
   if(board1[x+i][y]=='TP' or board1[x+i][y]=='DP'):
    white_in_check=True
    break
 #BAIXO(-1, 0)
  for i in range(8):
   if((x-i)<0):
    break
   if(board1[x-i][y]!='TP' and board1[x-i][y]!='DP' and board1[x-i][y]!='  '):
    break
   if(board1[x-i][y]=='TP' or board1[x-i][y]=='DP'):
    white_in_check=True
    break

 #VALOR RETORNADO
 if(white_in_check==True):
  print("Brancas em cheque!")
 return white_in_check

#8.1.2: NEGRAS
def black_king_in_check()->bool:
 '''Função que calcula se o rei das negras está em cheque.'''
 global board1
 global black_in_check
 
 #VARIÁVEIS LOCAIS
 x:int = 0
 y:int = 0
 black_in_check=False #VALOR PADRÃO

 #ENCONTRANDO A POSIÇÃO DO REI DA NEGRAS 
 for i in range(8):
  for j in range(8):
   if(board1[i][j]!='RP'):
    continue
   elif (board1[i][j]=='RP'):
    x=i #LINHA ONDE ESTÁ O REI
    y=j #COLUNA ONDE ESTÁ O REI

 #CHECANDO SE HÁ CHEQUES DE PEÃO
  #DIAGONAL INFERIOR DIREITA
 if((x-1)>0 and (x-1)<8 and (y+1)>0 and (y+1)<8 and board1[x-1][y+1]=='PB'):
  black_in_check=True
  #DIAGONAL INFERIOR ESQUERDA
 if((x-1)>0 and (x-1)<8 and (y-1)>0 and (y-1)<8 and board1[x-1][y-1]=='PB'):
  black_in_check=True
 #CHECANDO SE HÁ CHEQUES DE CAVALO (8 POSSÍVEIS POSIÇÕES)
 if((x+2)>0 and (x+2)<8 and (y+1)>0 and (y+1)<8 and board1[x+2][y+1]=='CB'):
  black_in_check=True
 if((x+1)>0 and (x+1)<8 and (y+2)>0 and (y+2)<8 and board1[x+1][y+2]=='CB'):
  black_in_check=True
 if((x-2)>0 and (x-2)<8 and (y-1)>0 and (y-1)<8 and board1[x-2][y-1]=='CB'):
  black_in_check=True
 if((x-1)>0 and (x-1)<8 and (y-2)>0 and (y-2)<8 and board1[x-1][y-2]=='CB'):
  black_in_check=True
 if((x+2)>0 and (x+2)<8 and (y-1)>0 and (y-1)<8 and board1[x+2][y-1]=='CB'):
  black_in_check=True
 if((x+1)>0 and (x+1)<8 and (y-2)>0 and (y-2)<8 and board1[x+1][y-2]=='CB'):
  black_in_check=True
 if((x-2)>0 and (x-2)<8 and (y+1)>0 and (y+1)<8 and board1[x-2][y+1]=='CB'):
  black_in_check=True
 if((x-1)>0 and (x-1)<8 and (y+2)>0 and (y+2)<8 and board1[x-1][y+2]=='CB'):
  black_in_check=True

 #CHECANDO SE HÁ CHEQUES DE BISPO OU DAMA
 #DIAGONAL SUPERIOR DIREITA (+1, +1)
  for i in range(8):
   if((x+i)>7 or (y+i)>7):
    break
   if(board1[x+i][y+i]!='BB' and board1[x+i][y+i]!='DB' and board1[x+i][y+i]!='  '):
    break
   if(board1[x+i][y+i]=='BB' or board1[x+i][y+i]=='DB'):
    black_in_check=True
    break
 #DIAGONAL SUPERIOR ESQUERDA (+1, -1)
  for i in range(8):
   if((x+i)>7 or (y-i)<0):
    break
   if(board1[x+i][y-i]!='BB' and board1[x+i][y-i]!='DB' and board1[x+i][y-i]!='  '):
    break
   if(board1[x+i][y-i]=='BB' or board1[x+i][y-i]=='DB'):
    black_in_check=True
    break
 #DIAGONAL INFERIOR DIREITA (-1, +1)
  for i in range(8):
   if((x-i)<0 or (y+i)>7):
    break
   if(board1[x-i][y+i]!='BB' and board1[x-i][y+i]!='DB' and board1[x-i][y+i]!='  '):
    break
   if(board1[x-i][y+i]=='BB' or board1[x-i][y+i]=='DB'):
    black_in_check=True
    break

 #DIAGONAL INFERIOR ESQUERDA (-1, -1)
  for i in range(8):
   if((x-i)<0 or (y-i)<0):
    break
   if(board1[x-i][y-i]!='BB' and board1[x-i][y-i]!='DB' and board1[x-i][y-i]!='  '):
    break
   if(board1[x-i][y-i]=='BB' or board1[x-i][y-i]=='DB'):
    black_in_check=True
    break
 #CHECANDO SE HÁ CHEQUES DE TORRE OU DAMA
 #DIREITA(0, +1)
  for i in range(8):
   if((y+i)>7):
    break
   if(board1[x][y+i]!='TB' and board1[x][y+i]!='DB' and board1[x][y+i]!='  '):
    break
   if(board1[x][y+i]=='TB' or board1[x][y+i]=='DB'):
    black_in_check=True
    break
 #ESQUERDA(0, -1)
  for i in range(8):
   if((y-i)<0):
    break
   if(board1[x][y-i]!='TB' and board1[x][y-i]!='DB' and board1[x][y-i]!='  '):
    break
   if(board1[x][y-i]=='TB' or board1[x][y-i]=='DB'):
    black_in_check=True
    break
 #CIMA (+1, 0)
  for i in range(8):
   if((x+i)>7):
    break
   if(board1[x+i][y]!='TB' and board1[x+i][y]!='DB' and board1[x+i][y]!='  '):
    break
   if(board1[x+i][y]=='TB' or board1[x+i][y]=='DB'):
    black_in_check=True
    break
 #BAIXO(-1, 0)
  for i in range(8):
   if((x-i)<0):
    break
   if(board1[x-i][y]!='TB' and board1[x-i][y]!='DB' and board1[x-i][y]!='  '):
    break
   if(board1[x-i][y]=='TB' or board1[x-i][y]=='DB'):
    black_in_check=True
    break

 #VALOR RETORNADO
 if(black_in_check==True):
  print("Negras em cheque!")
 return black_in_check

#8.2: FUNÇÃO QUE CHECA SE AS PEÇAS ESTÃO CRAVADAS
#8.2.1: BRANCAS
def white_pin_checker()->bool:
 '''Função que checa se uma peças das brancas estão cravadas'''
 global board1
 global board2
 global white_pin_check
 global x1
 global x2
 global y2
 global y1

 white_pin_check=False #VALOR PADRÃO
 
 #COPIANDO O TABULEIRO 1 
 board2=board1
 board2=board2 #ATUALIZANDO A VARIÁVEL E SALVANDO O STATUS CORRENTE 
 
 #EXECUTANDO O MOVIMENTO
 board1[x2][y2]= board1[x1][y1]
 if(white_king_in_check()==False):
  white_pin_check=False
 if(white_king_in_check()==True):
  white_pin_check=True
 
 #RESETANDO OS TABULEIROS
 board1=board2
 board1=board1 #ATUALIZANDO A VARIÁVEL
 board2=[[' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],]
 board2=board2 #ATUALIZANDO A VARIÁVEL

 #RETORNANDO O RESULTADO
 if(white_pin_check==True):
  return True
 if(white_pin_check==False):
  return False
 
#8.2.2:NEGRAS
def black_pin_checker()->bool:
 '''Função que checa se uma peças das brancas estão cravadas'''
 global board1
 global board2
 global black_pin_check
 global x1
 global x2
 global y2
 global y1

 black_pin_check=False #VALOR PADRÃO
 
 #COPIANDO O TABULEIRO 1 
 board2=board1
 board2=board2 #ATUALIZANDO A VARIÁVEL E SALVANDO O STATUS CORRENTE 
 
 #EXECUTANDO O MOVIMENTO
 board1[x2][y2]= board1[x1][y1]
 if(black_king_in_check()==False):
  black_pin_check=False
 if(black_king_in_check()==True):
  black_pin_check=True
 
 #RESETANDO OS TABULEIROS
 board1=board2
 board1=board1 #ATUALIZANDO A VARIÁVEL
 board2=[[' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],]
 board2=board2 #ATUALIZANDO A VARIÁVEL

 #RETORNANDO O RESULTADO
 if(black_pin_check==True):
  return True
 if(black_pin_check==False):
  return False

 
#*****************************************************************************************************************************
#
#
#9:FUNÇÕES QUE CHECAM SE HÁ A POSSIBILIDADE DE ESCAPAR DO CHEQUE COM MOVIMENTO DO REI OU DE UMA PEÇA OU SE É CHEQUE MATE
#9.1: FUNÇÃO QUE CALCULA A POSSIBILIDADE DE SE ESCAPAR DO QUE CALCULA COM UM MOVIMENTO DE REI
#9.1.1: BRANCAS
def white_king_move_escape_check()->bool:
 '''Função para se se checar se é possível escapar do cheque mate com um movimento de rei'''
 global checkmate
 global board1
 pass #A IMPLEMENTAR

#9.1.2: NEGRAS
def black_king_move_escape_check()->bool:
 '''Função para se se checar se é possível escapar do cheque mate com um movimento de rei das negras'''
 global checkmate
 global board1
 pass #A IMPLEMENTAR

#9.2: FUNÇÃO QUE CALCULA A POSSIBILIDADE DE SE ESCAPAR DO CHEQUE COM MOVIMENTO DE UMA PEÇA
#9.2.1: BRANCAS
def white_piece_move_escape_check()->bool:
 '''Função para se se checar se é possível escapar do cheque mate com um movimento de peças'''
 global checkmate
 global board1
 pass #A IMPLEMENTAR

#9.2.2: NEGRAS
def black_piece_move_escape_check()->bool:
 '''Função para se se checar se é possível escapar do cheque mate com um movimento de peças'''
 global checkmate
 global board1
 pass #A IMPLEMENTAR

#9.3: FUNÇÃO QUE CHECA SE O CHEQUE É UM CHEQUE MATE OU NÃO
def checkmate_checker()->bool:
 '''Função para calcular se houve cheque mate'''
 global white_in_check
 global black_in_check
 global checkmate
 
 if(white_in_check==True):
  white_king_move_escape_check()
  white_piece_move_escape_check()
 if(black_in_check==True):
  black_king_move_escape_check()
  black_piece_move_escape_check()
 return checkmate
 
#*****************************************************************************************************************************
#
#
#10:FUNÇÕES QUE DETERMINAM SE HOUVE UMA CAPTURA DE PEÇA

#AS DUAS PARCELAS DEVEM CONTER A AVALIAÇÃO DA PEÇAS ANTES E DEPOIS DO MOVIMENTO DAS NEGRAS
def white_piece_captured(n1:int, n2:int):
 '''Função que determina se uma peça das brancas foi capturada'''
 global  no_pawn_capture_counting

 piece_evaluation:int = n1-n2
 if(piece_evaluation==100):
  no_pawn_capture_counting = 0
  print('Um peão das brancas foi capturado!')
 if(piece_evaluation==300):
  no_pawn_capture_counting = 0
  print('Um cavalo das brancas foi capturado!')
 if(piece_evaluation==400):
  no_pawn_capture_counting = 0
  print('Um bispo das brancas foi capturado!')
 if(piece_evaluation==500):
  no_pawn_capture_counting = 0
  print('Uma torre das brancas foi capturada!')
 if(piece_evaluation==900):
  no_pawn_capture_counting = 0
  print('Uma dama das brancas foi capturada!')


#AS DUAS PARCELAS DEVEM CONTER A AVALIAÇÃO DA PEÇAS ANTES E DEPOIS DO MOVIMENTO DAS BRANCAS
def black_piece_captured(n1:int, n2:int):
 '''Função que determina se uma peça das pretas foi capturada'''
 global no_pawn_capture_counting

 piece_evaluation:int = n1-n2
 if(piece_evaluation==100):
  no_pawn_capture_counting = 0
  print('Um peão das negras foi capturado!')
 if(piece_evaluation==300):
  no_pawn_capture_counting = 0
  print('Um cavalo das negras foi capturado!')
 if(piece_evaluation==400):
  no_pawn_capture_counting = 0
  print('Um bispo das negras foi capturado!')
 if(piece_evaluation==500):
  no_pawn_capture_counting = 0
  print('Uma torre das negras foi capturada!')
 if(piece_evaluation==900):
  no_pawn_capture_counting = 0
  print('Uma dama das negras foi capturada!')



#*****************************************************************************************************************************
#
#
#11:FUNÇÕES QUE PROMOVEM UM PEÃO
#11.1: BRANCAS
def promote_white_pawn():
 '''Função que promove um peão das brancas'''
 global board1
 global white_promotion
 global x2 #COORDENADA DA CASA DE PROMOÇÃO
 global y2 #COORDENADA DA CASA DE PROMOÇÃO (PEÕS BRANCOS SÃO PROMOVIDOS NO RANK 7)

 
 if(white_promotion==True):
  new_piece=str(input('Digite "DB" para promover o peão a dama, "TB" para promover o peão a torre, "CB" para promovê-lo a cavalo e "BB" para promovê-lo a bispo:  '))
  if(new_piece=='DB'):
   board1[x2][y2]='DB'
  if(new_piece=='BB'):
   board1[x2][y2]='BB'
  if(new_piece=='CB'):
   board1[x2][y2]='CB'
  if(new_piece=='TB'):
   board1[x2][y2]='TB'
 #REAJUSTANDO A VARIÁVEL DE PROMOÇÃO DE PEÃO DAS BRANCAS
 white_promotion=False

#11.2: NEGRAS
def promote_black_pawn():
 '''Função que promove um peão das brancas'''
 global board1
 global black_promotion
 global x2 #COORDENADA DA CASA DE PROMOÇÃO
 global y2 #COORDENADA DA CASA DE PROMOÇÃO (PEÕS BRANCOS SÃO PROMOVIDOS NO RANK 7)

 
 if(black_promotion==True):
  new_piece=str(input('Digite "DP" para promover o peão a dama, "TP" para promover o peão a torre, "CP" para promovê-lo a cavalo e "BP" para promovê-lo a bispo:  '))
  if(new_piece=='DP'):
   board1[x2][y2]='DP'
  if(new_piece=='BP'):
   board1[x2][y2]='BP'
  if(new_piece=='CP'):
   board1[x2][y2]='CP'
  if(new_piece=='TP'):
   board1[x2][y2]='TP'
 #REAJUSTANDO A VARIÁVEL DE PROMOÇÃO DE PEÃO DAS BRANCAS
 black_promotion=False

#*****************************************************************************************************************************
#
#
#12:FUNÇÕES QUE EXECUTAM UM MOVIMENTO DE PEÇA
#12.1:PEÃO
#12.1.1: MOVIMENTO COMUM
#12.1.1.1: BRANCAS
def white_pawn_move():
 '''Função que executa um movimento de peão das brancas'''
 global board1
 global x1
 global x2
 global y2
 global y1
 global white_promotion
 global no_pawn_capture_counting

 #EXECUTANDO O MOVIMENTO DA PEÇA
 board1[x2][y2]= board1[x1][y1]
 board1[x1][y1]= '  '
 no_pawn_capture_counting=0 #ATUALIZANDO VARIÁVEIS
 
 #CHECANDO SE HÁ ALGUMA SITUAÇÃO DE PROMOÇÃO DO PEÃO
 if(x2==7):
  white_promotion=True
 promote_white_pawn()


#12.1.1.2: NEGRAS
def black_pawn_move():
 '''Função que executa um movimento de peão das brancas'''
 global board1
 global x1
 global x2
 global y2
 global y1
 global black_promotion
 global no_pawn_capture_counting

 #EXECUTANDO O MOVIMENTO DA PEÇA
 board1[x2][y2]= board1[x1][y1]
 board1[x1][y1]= '  '
 no_pawn_capture_counting=0 #ATUALIZANDO VARIÁVEIS
 
 #CHECANDO SE HÁ ALGUMA SITUAÇÃO DE PROMOÇÃO DO PEÃO
 if(x2==0):
  black_promotion=True
 promote_black_pawn()

#12.1.2: CAPTURA EN PASSANT
#12.1.2.1: BRANCAS
def white_capture_en_passant():
 '''Função que executa a captura de um peão en passant de brancas'''
 global board1
 global x1
 global x2
 global y2
 global y1
 global no_pawn_capture_counting

 #ESQUADRINHANDO O TABULEIRO PARA ENCONTRAR O PEÃO A SER CAPTURADO
 if(y1-1>=0 and board1[x1][y1-1]=='PP'):
  x2=x1+1
  y2=y1-1
 if(y1+1<8 and board1[x1][y1+1]=='PP'):
  x2=x1+1
  y2=y1+1

 #EXECUTANDO O MOVIMENTO DA PEÇA
 board1[x2][y2]= board1[x1][y1]
 board1[x1][y1]= '  '
 board1[x2-1][y2]= '  '
 no_pawn_capture_counting=0 #ATUALIZANDO VARIÁVEIS

#12.1.2.2: NEGRAS
def black_capture_en_passant():
 '''Função que executa a captura de um peão en passant de negras'''
 global board1
 global x1
 global x2
 global y2
 global y1
 global no_pawn_capture_counting

 #ESQUADRINHANDO O TABULEIRO PARA ENCONTRAR O PEÃO A SER CAPTURADO
 if(y1-1>=0 and board1[x1][y1-1]=='PB'):
  x2=x1-1
  y2=y1-1
 if(y1+1<8 and board1[x1][y1+1]=='PB'):
  x2=x1-1
  y2=y1+1

 #EXECUTANDO O MOVIMENTO DA PEÇA
 board1[x2][y2]= board1[x1][y1]
 board1[x1][y1]= '  '
 board1[x2+1][y2]= '  '
 no_pawn_capture_counting=0 #ATUALIZANDO VARIÁVEIS

#12.2: CAVALO
#12.2.1: BRANCAS
def white_knight_move():
 '''Função que executa um movimento do cavalo de brancas'''
 global board1
 global x1
 global x2
 global y2
 global y1

 #EXECUTANDO O MOVIMENTO DA PEÇA
 board1[x2][y2]= board1[x1][y1]
 board1[x1][y1]= '  '

#12.2.2: NEGRAS
def black_knight_move():
 '''Função que executa um movimento do cavalo de negras'''
 global board1
 global x1
 global x2
 global y2
 global y1

 #EXECUTANDO O MOVIMENTO DA PEÇA
 board1[x2][y2]= board1[x1][y1]
 board1[x1][y1]= '  '

#12.3: BISPO
#12.3.1: BRANCAS
def white_bishop_move():
 '''Função que executa um movimento de bispo de brancas'''
 global board1
 global x1
 global x2
 global y2
 global y1

 #EXECUTANDO O MOVIMENTO DA PEÇA
 board1[x2][y2]= board1[x1][y1]
 board1[x1][y1]= '  '

#12.3.2: NEGRAS
def black_bishop_move():
 '''Função que executa um movimento de bispo de negras'''
 global board1
 global x1
 global x2
 global y2
 global y1

 #EXECUTANDO O MOVIMENTO DA PEÇA
 board1[x2][y2]= board1[x1][y1]
 board1[x1][y1]= '  '

#12.4: TORRE
#12.4.1: BRANCAS
def white_rook_move():
 '''Função que executa um movimento de torre de brancas'''
 global board1
 global x1
 global x2
 global y2
 global y1

 #EXECUTANDO O MOVIMENTO DA PEÇA
 board1[x2][y2]= board1[x1][y1]
 board1[x1][y1]= '  '

#12.4.2: NEGRAS
def black_rook_move():
 '''Função que executa um movimento de torre de negras'''
 global board1
 global x1
 global x2
 global y2
 global y1

 #EXECUTANDO O MOVIMENTO DA PEÇA
 board1[x2][y2]= board1[x1][y1]
 board1[x1][y1]= '  '

#12.5: DAMA
#12.5.1: BRANCAS
def white_queen_move():
 '''Função que executa um movimento de rainha de brancas'''
 global board1
 global x1
 global x2
 global y2
 global y1

 #EXECUTANDO O MOVIMENTO DA PEÇA
 board1[x2][y2]= board1[x1][y1]
 board1[x1][y1]= '  '

#12.5.2: NEGRAS
def black_queen_move():
 '''Função que executa um movimento de rainha de negras'''
 global board1
 global x1
 global x2
 global y2
 global y1

 #EXECUTANDO O MOVIMENTO DA PEÇA
 board1[x2][y2]= board1[x1][y1]
 board1[x1][y1]= '  '

#12.6: REI
#12.6.1: BRANCAS
def white_king_move():
 '''Função que executa um movimento de rei de brancas'''
 global board1
 global x1
 global x2
 global y2
 global y1

 #EXECUTANDO O MOVIMENTO DA PEÇA
 board1[x2][y2]= board1[x1][y1]
 board1[x1][y1]= '  '

#12.5.2: NEGRAS
def black_king_move():
 '''Função que executa um movimento de rei de negras'''
 global board1
 global x1
 global x2
 global y2
 global y1

 #EXECUTANDO O MOVIMENTO DA PEÇA
 board1[x2][y2]= board1[x1][y1]
 board1[x1][y1]= '  '

#12.7: ROQUE
#12.7.1: ROQUE CURTO
#12.7.1.1: BRANCAS
def white_small_castle():
 '''Função que executa o pequeno roque das peças brancas'''
 global board1
 global moves

 #CHECANDO SE O PEÃO E A TORRE FORAM MOVIDOS
 for i in range(len(moves)):
  if(moves[i]=='e1' or moves[i]=='h1'):
   return
 #CHECANDO SE O CAMINHO DO REI ATÉ A TORRE ESTÁ OK
  if(board1[0][5]!='  ' or board1[0][6]!='  '):
   return
 #CHECANDO SE O REI FICA EM CHEQUE DURANTE O TRAJETO DO ROCK
 #PASSO 1:
 board1[0][4]='  '
 board1[0][5]='RB'
 if(white_king_in_check()==True): #DESFAZENDO O LANCE EM CASO DE CHEQUE
  board1[0][4]='RB'
  board1[0][5]='  '
  return
 #PASSO 2:
 board1[0][5]='  '
 board1[0][6]='RB'
 if(white_king_in_check()==True): #DESFAZENDO O LANCE EM CASO DE CHEQUE
  board1[0][4]='RB'
  board1[0][6]='  '
  return
 #CASO NENHUMA DAS CONDIÇÕES ACIMA SEJA SATISFEITA A TORRE VAI PARA A POSIÇÃO DO REI
 board1[0][7]='  '
 board1[0][4]='TB'

#12.7.1.2: NEGRAS
def black_small_castle():
 '''Função que executa o pequeno roque das peças negras'''
 global board1
 global moves

 #CHECANDO SE O PEÃO E A TORRE FORAM MOVIDOS
 for i in range(len(moves)):
  if(moves[i]=='e8' or moves[i]=='h8'):
   return
 #CHECANDO SE O CAMINHO DO REI ATÉ A TORRE ESTÁ OK
  if(board1[7][5]!='  ' or board1[7][6]!='  '):
   return
 #CHECANDO SE O REI FICA EM CHEQUE DURANTE O TRAJETO DO ROCK
 #PASSO 1:
 board1[7][4]='  '
 board1[7][5]='RP'
 if(black_king_in_check()==True): #DESFAZENDO O LANCE EM CASO DE CHEQUE
  board1[7][4]='RP'
  board1[7][5]='  '
  return
 #PASSO 2:
 board1[7][5]='  '
 board1[7][6]='RP'
 if(black_king_in_check()==True): #DESFAZENDO O LANCE EM CASO DE CHEQUE
  board1[7][4]='RP'
  board1[7][6]='  '
  return
 #CASO NENHUMA DAS CONDIÇÕES ACIMA SEJA SATISFEITA A TORRE VAI PARA A POSIÇÃO DO REI
 board1[7][7]='  '
 board1[7][4]='TP'

#12.7.2: ROQUE LONGO
#12.7.2.1: BRANCAS
def white_long_castle():
 '''Função que executa o grande roque das peças brancas'''
 global board1
 global moves

 #CHECANDO SE O PEÃO E A TORRE FORAM MOVIDOS
 for i in range(len(moves)):
  if(moves[i]=='e1' or moves[i]=='a1'):
   return
 #CHECANDO SE O CAMINHO DO REI ATÉ A TORRE ESTÁ LIVRE
  if(board1[0][1]!='  ' or board1[0][2]!='  ' or board1[0][3]!='  '):
   return
 #CHECANDO SE O REI FICA EM CHEQUE DURANTE O TRAJETO DO ROCK
 #PASSO 1:
 board1[0][4]='  '
 board1[0][3]='RB'
 if(white_king_in_check()==True): #DESFAZENDO O LANCE EM CASO DE CHEQUE
  board1[0][4]='RB'
  board1[0][3]='  '
  return
 #PASSO 2:
 board1[0][3]='  '
 board1[0][2]='RB'
 if(white_king_in_check()==True): #DESFAZENDO O LANCE EM CASO DE CHEQUE
  board1[0][4]='RB'
  board1[0][2]='  '
  return
 #CASO NENHUMA DAS CONDIÇÕES ACIMA SEJA SATISFEITA A TORRE VAI PARA A POSIÇÃO DO REI
 board1[0][0]='  '
 board1[0][4]='TB'


#12.7.2.2: NEGRAS
def black_long_castle():
 '''Função que executa o grande roque das peças negras'''
 global board1
 global moves

 #CHECANDO SE O PEÃO E A TORRE FORAM MOVIDOS
 for i in range(len(moves)):
  if(moves[i]=='e8' or moves[i]=='a8'):
   return
 #CHECANDO SE O CAMINHO DO REI ATÉ A TORRE ESTÁ LIVRE
  if(board1[7][1]!='  ' or board1[7][2]!='  ' or board1[7][3]!='  '):
   return
 #CHECANDO SE O REI FICA EM CHEQUE DURANTE O TRAJETO DO ROCK
 #PASSO 1:
 board1[7][4]='  '
 board1[7][3]='RB'
 if(black_king_in_check()==True): #DESFAZENDO O LANCE EM CASO DE CHEQUE
  board1[7][4]='RB'
  board1[7][3]='  '
  return
 #PASSO 2:
 board1[7][3]='  '
 board1[7][2]='RB'
 if(black_king_in_check()==True): #DESFAZENDO O LANCE EM CASO DE CHEQUE
  board1[7][4]='RB'
  board1[7][2]='  '
  return
 #CASO NENHUMA DAS CONDIÇÕES ACIMA SEJA SATISFEITA A TORRE VAI PARA A POSIÇÃO DO REI
 board1[7][0]='  '
 board1[7][4]='TB'

#12.8: FUNÇÃO GERAL
#12.8.1: BRANCAS
def white_move():
 '''Função que executa o movimento de brancas'''
 global board1
 global black
 global white
 global move_made
 global white_pin_check
 global white_en_passant
 global moves
 global x1
 global y1
 global x2
 global y2
 
 move_made = False #AJUSTE DE VARIÁVEL
 
 #AJUSTANDO AS VARIÁVEIS QUE CONTROLAM A ORDEM DAS JOGADAS
 black=True
 white=False

 #RECEBENDO O INPUT DO USUÁRIO
 print('Brancas.')
 initial_square:str=str(input('Jogador digite as coordenadas (letra+número) da casa onde está a peça que você deseja mover: '))

 #REALIZANDO O ROQUE
 if(initial_square=='o-o'):
  white_small_castle()
  moves.append(initial_square) #ADICIONANDO O REGISTRO A LISTA DE MOVIMENTOS
  moves=moves #ATUALIZANDO A LISTA
  white_en_passant=False
  move_made = True
  return   
 if(initial_square=='o-o-o'):
  white_long_castle()
  moves.append(initial_square) #ADICIONANDO O REGISTRO A LISTA DE MOVIMENTOS
  moves=moves #ATUALIZANDO A LISTA
  white_en_passant=False
  move_made = True
  return 

 #RECEBENDO O INPUT DO USUÁRIO
 final_square:str=str(input('Jogador digite as coordenadas (letra+número) da casa na qual esta peça ser posta: '))

 x1, y1=index(initial_square) #CALCULANDO AS COORDENADAS DA CASA INICIAL
 x2, y2=index(final_square) #CALCULANDO AS COORDENADAS DA CASA FINAL

 #CHECANDO SE A PEÇA ESTÁ CRAVADA
 white_pin_checker()
 if(white_pin_check==True):
  print("Movimento inválido!")
  move_made = False
  return
 
 #REALIZANDO O MOVIMENTO DE PEÇA
 #PEÕES
 #MOVIMENTO COM POSSIBILIDADE DE CAPTURA EM PASSANT
 if(white_en_passant==True and board1[x1][y1]=='PB'):
  if(y1!=y2):
   white_capture_en_passant()
  if(y1==y2 and validate_white_pawn_move()==True):
   white_pawn_move()
  moves.append(initial_square) #ADICIONANDO O REGISTRO A LISTA DE MOVIMENTOS
  moves.append(final_square) 
  moves=moves #ATUALIZANDO A LISTA
  white_en_passant=False
  move_made = True
 #MOVIMENTO COMUM DE PEÃO
 if(white_en_passant==False and board1[x1][y1]=='PB' and validate_white_pawn_move()==True):
  white_pawn_move()
  moves.append(initial_square) #ADICIONANDO O REGISTRO A LISTA DE MOVIMENTOS
  moves.append(final_square) 
  moves=moves #ATUALIZANDO A LISTA
  white_en_passant=False
  move_made = True

 #MOVIMENTO DE CAVALO
 if(board1[x1][y1]=='CB' and validate_white_knight_move()==True):
  white_knight_move()
  moves.append(initial_square) #ADICIONANDO O REGISTRO A LISTA DE MOVIMENTOS
  moves.append(final_square) 
  moves=moves #ATUALIZANDO A LISTA
  white_en_passant=False
  move_made = True
  
 #MOVIMENTO DE BISPO 
 if(board1[x1][y1]=='BB' and validate_white_bishop_move()==True):
  white_bishop_move()
  moves.append(initial_square) #ADICIONANDO O REGISTRO A LISTA DE MOVIMENTOS
  moves.append(final_square) 
  moves=moves #ATUALIZANDO A LISTA
  white_en_passant=False
  move_made = True
  
 #MOVIMENTO DE TORRE
 if(board1[x1][y1]=='TB' and validate_white_rook_move()==True):
  white_rook_move()
  moves.append(initial_square) #ADICIONANDO O REGISTRO A LISTA DE MOVIMENTOS
  moves.append(final_square) 
  moves=moves #ATUALIZANDO A LISTA
  white_en_passant=False
  move_made = True

 #MOVIMENTO DE DAMA
 if(board1[x1][y1]=='DB' and validate_white_queen_move()==True):
  white_queen_move()
  moves.append(initial_square) #ADICIONANDO O REGISTRO A LISTA DE MOVIMENTOS
  moves.append(final_square) 
  moves=moves #ATUALIZANDO A LISTA
  white_en_passant=False
  move_made = True

 #MOVIMENTO DE REI  
 if(board1[x1][y1]=='RB' and validate_white_king_move()==True):
  white_king_move()
  moves.append(initial_square) #ADICIONANDO O REGISTRO A LISTA DE MOVIMENTOS
  moves.append(final_square) 
  moves=moves #ATUALIZANDO A LISTA
  white_en_passant=False
  move_made = True

#12.8.2: NEGRAS
def black_move():
 '''Função que executa o movimento de negras'''
 global board1
 global black
 global white
 global move_made
 global black_pin_check
 global black_en_passant
 global moves
 global x1
 global y1
 global x2
 global y2
 
 move_made = False #AJUSTE DE VARIÁVEL

 #AJUSTANDO AS VARIÁVEIS QUE CONTROLAM A ORDEM DAS JOGADAS
 black=False
 white=True

 #RECEBENDO O INPUT DO USUÁRIO
 print('Pretas.')
 initial_square:str=str(input('Jogador digite as coordenadas (letra+número) da casa onde está a peça que você deseja mover: '))

 #REALIZANDO O ROQUE
 if(initial_square=='o-o'):
  black_small_castle()
  moves.append(initial_square) #ADICIONANDO O REGISTRO A LISTA DE MOVIMENTOS
  moves=moves #ATUALIZANDO A LISTA
  black_en_passant=False
  move_made = True
  return   
 if(initial_square=='o-o-o'):
  black_long_castle()
  moves.append(initial_square) #ADICIONANDO O REGISTRO A LISTA DE MOVIMENTOS
  moves=moves #ATUALIZANDO A LISTA
  black_en_passant=False
  move_made = True
  return 

 #RECEBENDO O INPUT DO USUÁRIO
 final_square:str=str(input('Jogador digite as coordenadas (letra+número) da casa na qual esta peça ser posta: '))

 x1, y1=index(initial_square) #CALCULANDO AS COORDENADAS DA CASA INICIAL
 x2, y2=index(final_square) #CALCULANDO AS COORDENADAS DA CASA FINAL

 #CHECANDO SE A PEÇA ESTÁ CRAVADA
 black_pin_checker()
 if(black_pin_check==True):
  print("Movimento inválido!")
  move_made = False
  return
 
 #REALIZANDO O MOVIMENTO DE PEÇA
 #PEÕES
 #MOVIMENTO COM POSSIBILIDADE DE CAPTURA EM PASSANT
 if(black_en_passant==True and board1[x1][y1]=='PP'):
  if(y1!=y2):
   black_capture_en_passant()
  if(y1==y2 and validate_black_pawn_move()==True):
   black_pawn_move()
  moves.append(initial_square) #ADICIONANDO O REGISTRO A LISTA DE MOVIMENTOS
  moves.append(final_square) 
  moves=moves #ATUALIZANDO A LISTA
  black_en_passant=False
  move_made = True
 #MOVIMENTO COMUM DE PEÃO
 if(black_en_passant==False and board1[x1][y1]=='PP' and validate_black_pawn_move()==True):
  black_pawn_move()
  moves.append(initial_square) #ADICIONANDO O REGISTRO A LISTA DE MOVIMENTOS
  moves.append(final_square) 
  moves=moves #ATUALIZANDO A LISTA
  black_en_passant=False
  move_made = True

 #MOVIMENTO DE CAVALO
 if(board1[x1][y1]=='CP' and validate_black_knight_move()==True):
  black_knight_move()
  moves.append(initial_square) #ADICIONANDO O REGISTRO A LISTA DE MOVIMENTOS
  moves.append(final_square) 
  moves=moves #ATUALIZANDO A LISTA
  black_en_passant=False
  move_made = True
  
 #MOVIMENTO DE BISPO 
 if(board1[x1][y1]=='BP' and validate_black_bishop_move()==True):
  black_bishop_move()
  moves.append(initial_square) #ADICIONANDO O REGISTRO A LISTA DE MOVIMENTOS
  moves.append(final_square) 
  moves=moves #ATUALIZANDO A LISTA
  black_en_passant=False
  move_made = True
  
 #MOVIMENTO DE TORRE
 if(board1[x1][y1]=='TP' and validate_black_rook_move()==True):
  black_rook_move()
  moves.append(initial_square) #ADICIONANDO O REGISTRO A LISTA DE MOVIMENTOS
  moves.append(final_square) 
  moves=moves #ATUALIZANDO A LISTA
  black_en_passant=False
  move_made = True

 #MOVIMENTO DE DAMA
 if(board1[x1][y1]=='DP' and validate_black_queen_move()==True):
  black_queen_move()
  moves.append(initial_square) #ADICIONANDO O REGISTRO A LISTA DE MOVIMENTOS
  moves.append(final_square) 
  moves=moves #ATUALIZANDO A LISTA
  black_en_passant=False
  move_made = True

 #MOVIMENTO DE REI  
 if(board1[x1][y1]=='RP' and validate_white_king_move()==True):
  black_king_move()
  moves.append(initial_square) #ADICIONANDO O REGISTRO A LISTA DE MOVIMENTOS
  moves.append(final_square) 
  moves=moves #ATUALIZANDO A LISTA
  black_en_passant=False
  move_made = True

#*****************************************************************************************************************************
#
#
#13:FUNÇÃO QUE CALCULA O EMPATE DA PARTIDA (EMPATE POR REPETIÇÃO, REGRA DOS 50 LANCES E POR COMUM ACORDO)
#EMPATE DE COMUM ACORDO (A SER CHAMADO DA FUNÇÃO DE REALIZAÇÃO DOS LANCES)
def common_agreement_draw()->bool:
 '''Função de proposição de empate por comum acordo'''
 global draw_game

 answer:str=str(input('Jogador você aceita a proposta de empate de seu adversário?\nDigite "s" para aceitar ou "n" para recusar:  '))
 if(answer=="s"):
  draw_game=True
 if(answer!="s"):
  draw_game=False
 return draw_game
 
#EMPATE PELA REGRA DOS 50 LANCES
def fifth_rule_draw()->bool:
 '''Função que define o empate pela regra dos 50 lances'''
 global no_pawn_capture_counting
 global draw_game

 if(no_pawn_capture_counting>50):
  draw_game=True
 else:
  draw_game=False
 return draw_game

#EMPATE POR REPETIÇÃO
def repetition_draw()->bool:
 '''Função que calcula o empate por repetição'''
 global moves
 global draw_game

 if(len(moves)>12):
  if(moves[len(moves)-1]==moves[len(moves)-5] and moves[len(moves)-1]==moves[len(moves)-9] and moves[len(moves)-2]==moves[len(moves)-6] and moves[len(moves)-2]==moves[len(moves)-10] and moves[len(moves)-3]==moves[len(moves)-7] and moves[len(moves)-3]==moves[len(moves)-11] and moves[len(moves)-4]==moves[len(moves)-8] and moves[len(moves)-4]==moves[len(moves)-12]):
   draw_game=True
  else:
   draw_game=False
 return draw_game

#*****************************************************************************************************************************
#
#
#14:LOOP PRINCIPAL DO JOGO

#LOOP PRINCIPAL
while True:
 #CHECANDO SE A REGRA DOS 50 LANCES FOI SATISFEITA
 fifth_rule_draw()
 if(draw_game==True):
  break
 
 #BRANCAS
 #PROPOSIÇÃO DE EMPATE POR COMUM ACORDO
 draw_proposal_white:str=str(input(':::'))
 if(draw_proposal_white=='draw'):
  common_agreement_draw()
 if(draw_game==True):
  break

 #CHECANDO SE AS BRANCAS ESTÃO EM CHEQUE
 white_king_in_check()
 if(white_in_check==True):
  checkmate_checker()
 #CASO DE CHEQUE MATE ENCERRAR O JOGO
 if(checkmate==True):
  break

 #AVALIAÇÃO INICIAL DO VALOR DAS PEÇAS DAS NEGRAS
 black_evaluation1:int=get_black_value()

 #CASO O REI NÃO ESTEJA EM CHEQUE FAZER UM MOVIMENTO VÁLIDO
 while(move_made==False):
  white_move()
  position() #MOSTRAR O STATUS ATUAL DO TABULEIRO

 #CHECAR POR CAPTURA DE PEÇAS DAS NEGRAS
 black_evaluation2:int=get_black_value()
 black_piece_captured(black_evaluation1, black_evaluation2)

 #AJUSTAR VARIÁVEL PARA MOVIMENTO DAS NEGRAS
 move_made=False
 
 #CHECANDO A OCORRẼNCIA DE EMPATE POR REPETIÇÃO APÓS O MOVIMENTO DAS BRANCAS
 repetition_draw()
 if(draw_game==True):
  break
  
 
 #NEGRAS
 #PROPOSIÇÃO DE EMPATE POR COMUM ACORDO
 draw_proposal_black:str=str(input(':::'))
 if(draw_proposal_black=='draw'):
  common_agreement_draw()
 if(draw_game==True):
  break

 #CHECANDO SE AS NEGRAS ESTÃO EM CHEQUE
 black_king_in_check()
 if(black_in_check==True):
  checkmate_checker()
 #CASO DE CHEQUE MATE ENCERRAR O JOGO
 if(checkmate==True):
  break

 #AVALIAÇÃO INICIAL DO VALOR DAS PEÇAS DAS BRANCAS
 white_evaluation1:int=get_white_value()

 #CASO O REI NÃO ESTEJA EM CHEQUE FAZER UM MOVIMENTO VÁLIDO
 while(move_made==False and white==False and black==True):
  black_move()
  position() #MOSTRAR O STATUS ATUAL DO TABULEIRO

 #CHECAR POR CAPTURA DE PEÇAS DAS NEGRAS
 white_evaluation2:int=get_white_value()
 white_piece_captured(white_evaluation1, white_evaluation2)

 #AJUSTAR VARIÁVEL PARA MOVIMENTO DAS NEGRAS
 move_made=False

 #CHECANDO A OCORRẼNCIA DE EMPATE POR REPETIÇÃO APÓS O MOVIMENTO DAS NEGRAS
 repetition_draw()
 if(draw_game==True):
  break
   
#*****************************************************************************************************************************
#
#
#15: ENCERRAMENTO
#CRÉDITOS
print('\033[95m'+ '\nEscrito por Elias Rodrigues Emídio.\n'+'\033[0;0m')

#MENSAGEM FINAL

print('\033[34m'+'\033[06m'+'\033[01m'+' OOOOO  BBBBB   RRRRRR  IIIII   GGGG    AAA   DDDDD    OOOOO     PPPPPP   OOOOO  RRRRRR'+'\033[0;0m')  
print('\033[34m'+'\033[06m'+'\033[01m'+'OO   OO BB   B  RR   RR  III   GG  GG  AAAAA  DD  DD  OO   OO    PP   PP OO   OO RR   RR '+'\033[0;0m')
print('\033[34m'+'\033[06m'+'\033[01m'+'OO   OO BBBBBB  RRRRRR   III  GG      AA   AA DD   DD OO   OO    PPPPPP  OO   OO RRRRRR  '+'\033[0;0m')
print('\033[34m'+'\033[06m'+'\033[01m'+'OO   OO BB   BB RR  RR   III  GG   GG AAAAAAA DD   DD OO   OO    PP      OO   OO RR  RR  '+'\033[0;0m')
print('\033[34m'+'\033[06m'+'\033[01m'+' OOOO0  BBBBBB  RR   RR IIIII  GGGGGG AA   AA DDDDDD   OOOO0     PP       OOOO0  RR   RR '+'\n\033[0;0m')
                                                                                         
                                                                                       
                                                                                         
                                                                                         
                                                                                         
                                                                                         
                                                                                         
print('\033[34m'+'\033[06m'+'\033[01m'+'                   JJJ  OOOOO    GGGG    AAA   RRRRRR     !!!    !!!    !!!      '+'\033[0;0m')        
print('\033[34m'+'\033[06m'+'\033[01m'+'                   JJJ OO   OO  GG  GG  AAAAA  RR   RR    !!!    !!!    !!!   '+'\033[0;0m')           
print('\033[34m'+'\033[06m'+'\033[01m'+'                   JJJ OO   OO GG      AA   AA RRRRRR     !!!    !!!    !!!  '+'\033[0;0m')            
print('\033[34m'+'\033[06m'+'\033[01m'+'               JJ  JJJ OO   OO GG   GG AAAAAAA RR  RR                             '+'\033[0;0m')       
print('\033[34m'+'\033[06m'+'\033[01m'+'                JJJJJ   OOOO0   GGGGGG AA   AA RR   RR    !!!    !!!    !!!  '+'\n\n\033[0;0m')

 

