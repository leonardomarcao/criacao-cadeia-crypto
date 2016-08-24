#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h> 
#include <conio.h> 
#include <time.h>

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
    printf("|        CRIAÇÃO EM CADEIA - CRYPTO        |\n");
    printf("|      Criptografia baseada em vetores     |\n");
    printf("|      Copyright 2016 @ Leonardo Marcão    |\n");
    printf(" ------------------------------------------\n");
    menu();
    return 0;
}

//function menu
void menu() {
    int op;
    printf("\nEscolha uma das operações abaixo: \n");
    printf(" ------------------------------------------\n");
    printf("|        1. Conectar ao financeiro        |\n");
    printf("|        2. Desconectar do financeiro     |\n");
    printf("|        3. Sair                          |\n");
    printf(" ------------------------------------------\n");
    scanf("%d", & op);
    switch (op) {
    case 1:
        system("cls");
        conectToFin();
        break;
    case 2:
        system("cls");
        desconectFin();
        break;
    case 3:
        printf("\nCaso tenha conectado ao financeiro, não se esqueça de desconectar.\n");
        printf("O financeiro será desconectado automaticamente ao desligar o computador.\n");
        printf("Precione qualquer tecla para sair. \n");
        getch();
        system("exit");
    default:
        printf("Operação incorreta! Precione qualquer tecla para retornar!\n");
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

	// For some reason you need to convert the values ​​returned by the hands
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
int cryptoSecurity() {

	int chance = 3, pass;
    char dateForCheck[100];
    sprintf(dateForCheck, "%s", date());    

    printf(" ------------------------------------------\n");
    printf("|        CRIAÇÃO EM CADEIA - CRYPTO        |\n");
    printf("|           ACESSO AO FINANCEIRO           |\n");
    printf(" ------------------------------------------\n");

    if (chance > 0){
    	printf("Digite a senha para conectar ao financeiro: \n");
    	scanf("%d", &pass);

    	//verify password
    	if (pass == dateForCheck){
    		//password entered is correct
    		return 1;
    	}else{
    		printf("Senha digitada é incorreta! Você possui mais %d chances\n", chance);
    		//password entered is incorrect
    		chance--;
    		system("cls");
    		return 0;
    	}
    }else{
    	printf("O limite de chances esgotou! Programa será finalizado por segurança.\n");
    	getch();    	
    	system("exit");
    }

    getch();

}

//function for connect to financial
void conectToFin() {	
    if (cryptoSecurity() == 1){
    	system("net use F: \\FIN /user:FINANCEIRO Okane6162");
    	printf("Conectado com sucesso!\n");
    	printf("Por favor, não se esqueça de desconectar.\n");
    	printf("O financeiro será desconectado automaticamente ao desligar o computador.\n");
        printf("Precione qualquer tecla para sair. \n");
        getch();
        system("exit");
    }else{
    	cryptoSecurity();
    }

}

//function for disconnect to financial
void desconectFin() {
	system("net use /delete F:");
}
