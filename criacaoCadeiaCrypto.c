#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h> 
#include <conio.h> 
#include <time.h>
#include <string.h>

//prototypes
void menu();
void conectToFin();
void desconectFin();
void cryptoSecurity();
char * date(void);
char * format(int number);

//function main
int main() {
    setlocale(LC_ALL, "Portuguese");
    printf(" ------------------------------------------\n");
    printf("|        CRIA��O EM CADEIA - CRYPTO        |\n");
    printf("|      Copyright 2016 @ Leonardo Marc�o    |\n");
    printf(" ------------------------------------------\n");
    menu();
    return 0;
}

//function menu
void menu() {
    int op;
    printf("\nEscolha uma das opera��es abaixo: \n");
    printf(" ------------------------------------------\n");
    printf("|        1. Conectar ao financeiro        |\n");
    printf("|        2. Desconectar do financeiro     |\n");
    printf("|        3. Sair                          |\n");
    printf(" ------------------------------------------\n");
    scanf("%d", & op);
    switch (op) {
    case 1:
        system("cls");
        cryptoSecurity();
        break;
    case 2:
        printf("Desconectado com sucesso!\n");
        printf("Precione qualquer tecla para sair. \n");
        getch();                
        desconectFin();        
        break;
    case 3:
        printf("\nCaso tenha conectado ao financeiro, n�o se esque�a de desconectar.\n");
        printf("O financeiro ser� desconectado automaticamente ao desligar o computador.\n");
        printf("Precione qualquer tecla para sair. \n");
        getch();
        system("exit");
    default:
        printf("Opera��o incorreta! Precione qualquer tecla para retornar!\n");
        getch();
        system("cls");
        main();
        break;
    }
}

//function for format date - used in funcion date
char * format(int number) {
    char * retorno, ret[100];
    int i;

    if (number < 10) {
        sprintf(ret, "0%d", number);
        retorno = ret;
        return retorno;
    } else {
        sprintf(ret, "%d", number);
        retorno = ret;
        return retorno;
    }
}

//function return date
char * date(void) {
    int dia, mes, ano;
    char var1[100], var2[100], var3[100], var4[100], * dataPtr;
    struct tm * local;
    time_t t;

    t = time(NULL);
    local = localtime( & t);

    dia = local -> tm_mday;
    mes = local -> tm_mon + 1;
    ano = local -> tm_year + 1900;

	// For some reason you need to convert the values ??returned by the hands
    // The function in variables of type char    
    sprintf(var1, "%s", format(dia));
    sprintf(var2, "%s", format(mes));
    sprintf(var3, "%s", format(ano));
    
	// Create the data return variable and creates a pointer to that variable       
    sprintf(var4, "%s%s%s", var2, var1, var3);

	// Return date with a pointer
    dataPtr = var4;
    return dataPtr;
}

//function for cryptografh using date 
void cryptoSecurity() {

	int chance = 3, i, t = 0;
    char dateForCheck[100], pass[100];
    sprintf(dateForCheck, "%s", date());    

    while ((pass != dateForCheck)){
        if (chance != 0){
            printf(" ------------------------------------------\n");
            printf("|        CRIA��O EM CADEIA - CRYPTO        |\n");
            printf("|           ACESSO AO FINANCEIRO           |\n");
            printf("|    N�MERO DE TENTATIVAS RESTANTES: %d     |\n", chance);
            printf(" ------------------------------------------\n");
            
            printf("Digite a senha para conectar ao financeiro: \n");
            scanf("%s", &pass);

            if (((strcmp(dateForCheck, pass)) == 0)){
                //password entered is correct
                printf("\n\n ------------------------------------------\n");
                printf("|        CRIA��O EM CADEIA - CRYPTO        |\n");
                printf("|             ACESSO PERMETIDO             |\n");                
                printf(" ------------------------------------------\n");
                conectToFin();
                break;                         
            }else{
            	chance--;
                printf("Senha digitada � incorreta! Voc� possui mais %d chance (s). \nPrecione qualquer tecla para tentar novamente!\n", chance);
                getch();
                //password entered is incorrect                
                system("cls");
            }
        }else{            
            printf("O limite de chances esgotou! \nVoc� ser� desconectado e programa ser� finalizado por motivos de seguran�a!\n");            
            getch();                
            desconectFin(); 
            break;
        }
    }
}

//function for connect to financial
void conectToFin() {	    	
        system("NET USE \\fin\\adm1$ Okane6162 /USER:FINANCEIRO /PERSISTENT:no");
    	printf("\nConectado com sucesso!\n");
    	printf("Por favor, n�o se esque�a de desconectar.\n");
    	printf("O financeiro ser� desconectado automaticamente ao desligar o computador.\n");        
        getch();           
        system("explorer \\\\fin\\adm1$");     
        system("exit");
}

//function for disconnect to financial
void desconectFin() { 
    system("NET USE \\fin\\ADM1$ /DELETE ");
    system("NET USE \\FIN\\IPC$ /DELETE");
    system("NET USE \\FIN /DELETE");
    ststem("cmdkey /delete:fin");
    system("exit"); 
}

