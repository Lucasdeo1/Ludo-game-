#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct{
	char cor[10];
	int peao;
}jogador;

void menu();
int players();
jogador*alocaJogador();
jogador*dadosjogadores();
int dado();
void game();

int main(){	
	srand(time(NULL));
	jogador *p;
	menu();
	int quant = players();
	p = alocaJogador(quant);
	p= dadosjogadores(p,quant);
	game(p,quant);
	return 0;	
}

void menu(){	
	int op;
	printf("*******************BEM-VINDOS AO JOGO LUDO*******************\n");
	printf("\n                         MENU:\n                         1-Start game\n                         2-Exit");
	scanf("%d",&op);
	//system("pause");
	system("cls");	
}

int players(){
	int i,op;
	printf("Digite a quantidade de jogadores:");
	scanf("%d",&op);
	return op;
}

jogador*alocaJogador(int quant){
	jogador *x = ( jogador*) malloc ( quant*sizeof ( jogador ));
	if(x == NULL){
		exit(1);
	}
	return x;	
}

jogador*dadosjogadores(jogador*x,int quant){
	int i;
	printf("Cada numero representa uma cor:\n1-verde\n2-amarelo\n3-vermelho\n4azul\n");
	for(i=0;i<quant;i++){
		printf("Digite o numero do jogador");
		scanf("%d",&x[i].peao);
		printf("Digite a cor do peao ");
		scanf("%s",&x[i].cor);
		printf("jogador %d de cor %s\n\n",x[i].peao,x[i].cor);
	}
	system("pause");
	system("cls");
	return x;	
}

int dado(){
	int z = rand()%6+1;
	printf("DADO = %d",z);
	return z;
}

void game(jogador*x,int quant){
	int i,op,rodada=0,j,k,dados;
	
	int tab[15][15] =  		/*0*/{{1,1,1,1,1,1,0,0,0,2,2,2,2,2,2},
							/*1*/{1,1,1,1,1,1,0,5,2,2,2,2,2,2,2},
							/*2*/{1,1,1,1,1,1,0,5,0,2,2,2,2,2,2},
							/*3*/{1,1,1,1,1,1,0,5,0,2,2,2,2,2,2},
							/*4*/{1,1,1,1,1,1,0,5,0,2,2,2,2,2,2},
							/*5*/{1,1,1,1,1,1,0,5,0,2,2,2,2,2,2},
							/*6*/{0,1,0,0,0,0,0,6,0,0,0,0,0,0,0},
							/*7*/{0,5,5,5,5,5,6,6,6,5,5,5,5,5,0},
							/*8*/{0,0,0,0,0,0,0,6,0,0,0,0,0,4,0},
							/*9*/{3,3,3,3,3,3,0,5,0,4,4,4,4,4,4},
						   /*10*/{3,3,3,3,3,3,0,5,0,4,4,4,4,4,4},
						   /*11*/{3,3,3,3,3,3,0,5,0,4,4,4,4,4,4},
						   /*12*/{3,3,3,3,3,3,0,5,0,4,4,4,4,4,4},
						   /*13*/{3,3,3,3,3,3,3,5,0,4,4,4,4,4,4},
						   /*14*/{3,3,3,3,3,3,0,0,0,4,4,4,4,4,4}};
							   /* 0 1 2 3 4 5 6 7 8 91011121314*/
	do{
		
		for(k=0;k<quant;k++){
			printf("\npeao %d de cor %s aperte tecle 1 para jogar dado:",x[k].peao,x[k].cor);
			scanf("%d",&op);
			if(op == 1){
				dados = dado();
				printf("\n");
				printf("digite a casa que o peao vai estar de acordo com o valor que saiu no dado:");
				
				printf("\nescolha uma linha:");
			    scanf("%d",&i);
			    
				printf("\nescolha uma coluna:");
			    scanf("%d",&j);
			    
				printf("\nDigite o numero que ira ocupar essa casa:");
			    scanf("%d",&tab[i][j]);
			    
			    for(i=0;i<15;i++){
			        printf("\n");
			        for(j=0;j<15;j++){
			            printf("%3d",tab[i][j]);
			            if(tab[7][6]==x[i].peao || tab[7][8]==x[i].peao || tab[6][7]==x[i].peao || tab[8][7]==x[i].peao){
						            
							          printf("\n*********************************************");  
									  printf("\n");
									  printf("\nWW     WW     WW IIIIIIIIIIIII NNN         NNN ");
									  printf("\n WW   WWWW   WW      IIIII     NNN NNN     NNN ");
									  printf("\n  WW WW  WW WW       IIIII     NNN     NNN NNN ");
									  printf("\n   WW     WW     IIIIIIIIIIIII NNN         NNN "); 
									  printf("\n*********************************************"); 
			            	 		printf("\n\njogador %d de cor %s ganhou",x[i].peao,x[i].cor);
			            	 		exit(1);
						}
						else{
							
			            			
						}
					}
				}
			}
		}
	}while(op!=1);
		rodada++;
		printf("\nrodada %d terminada\n\n",rodada);	
}


