#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <locale.h>  


void print_trofeu () { 
    printf("\nParabéns! Você ganhou!\n\n");
    printf("        ___________\n");
    printf("       '._==_==_=_.\n");
    printf("       .-\\:      /-.\n");
    printf("      | (|:.     |) |\n");
    printf("       '-|:.     |-'\n");
    printf("         \\::.    /\n");
    printf("          '::. .'\n");
    printf("            ) (\n");
    printf("          _.' '._\n");
    printf("         `\"\"\"\"\"\"\"`\n");
}

void print_perdeu () { 
    printf("\nVocê perdeu!, não fique triste, pode tentar novamente.\n\n");
}

int main() {
	setlocale(LC_ALL, "Portuguese"); 
	
    char tecla, continuar = 's'; 
    int escolha_usuario, escolha_computador, chances = 3; 
    
    printf("Bem-vindo ao jogo JOKENPÔ, bora se divertir, vamos começar:\n");

    while (continuar == 's') { 
    	while (chances > 0) {
    		printf("\nESCOLHA UMA OPÇÃO:\n ");
	        printf("\n (1)Pedra\n");
	        printf("\n (2)Papel\n");
	        printf("\n (3)Tesoura\n");
	        scanf("%d", &escolha_usuario); 
	        
	        if (escolha_usuario < 1 || escolha_usuario > 3) { 
	            printf("\nEscolha inválida!\nEscolha apenas 1, 2 ou 3.\n");
	            continue; 
	        }
	        
	        srand(time(NULL));
	        escolha_computador = 1;
	        
	        printf("\nVocê escolheu: ");
	        switch (escolha_usuario) {
	            case 1:
	                printf("Pedra\n");
	                break;
	            case 2:
	                printf("Papel\n");
	                break;
	            case 3:
	                printf("Tesoura\n");
	                break;
	        }
	        
	        printf("\nO computador escolheu: ");
	        switch (escolha_computador) {
	            case 1:
	                printf("Pedra\n");
	                break;
	            case 2:
	                printf("Papel\n");
	                break;
	            case 3:
	                printf("Tesoura\n");
	                break;
	        }
	        
	        if (escolha_usuario == escolha_computador) {
	            printf("\nEmpate!\n");
	        } else if ((escolha_usuario == 1 && escolha_computador == 3) ||
	                   (escolha_usuario == 2 && escolha_computador == 1) ||
	                   (escolha_usuario == 3 && escolha_computador == 2)) {
	            chances = 0;
	            print_trofeu();
	            printf("\nVocê deseja jogar novamente? Digite 's' para continuar ou 'n' para sair: \n"); 
	            scanf(" %c", &continuar);
	            if (continuar == 's' || continuar == 'S') { 
		        	chances = 3;
		        }
	        } else {
	            print_perdeu();
	            chances--; 
	            if (chances == 0) { 
	                printf("Você deseja tentar novamente? Digite 's' para continuar ou 'n' para sair: \n");
	                scanf(" %c", &continuar);
	                if (continuar == 's' || continuar == 'S') { 
		        		chances = 3;
		        	}
	            }
	    	}
		}
	}
    
	printf("\nFim de jogo!\n");
	return 0;
}
