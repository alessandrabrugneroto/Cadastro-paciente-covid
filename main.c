//bibliotecas---------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include<time.h>
#define SIZE 1000
#define limpar_tela "cls"
#define limpar_tela "clear"
//--------------------------------------------------------------------------------------------------------------

//variaveis do sistemas----------------------------------------------------------------------------------------------
typedef struct paciente{
int id;
char nome[50];
char cpf[50];
char email[SIZE][50];
char telefone[50];
char datanasc[50];
char datadiag[SIZE][50];
char comorbidade[50];

}t_paciente;

typedef struct endereco{
char rua[20];
int numero[SIZE];
char cidade[20];
char cep[SIZE];
}enderecoPac;
//------------------------------------------------------------------------------------------------------------------

void cadastro();
void calculaIdade();
//-------------------------------------------------------------------------------------------------------------------

typedef struct{
char login[30];
char senha [30];
}funcionario;
funcionario f[1];
//------------------------------------------------------------------------------------------------------------------

//principal--------------------------------------------------------------------------------------------------------
int main(int argc, char *argv[]){
//Inicio do login
char login[30];
char senha[30];
int op;

strcpy(f[0].login,"paccovid");
strcpy(f[0].senha, "123");

printf("\n\t\tlogin:\t");
scanf("%s", login);
printf("\n\t\tsenha:\t");
scanf("%s", senha);

if ((strcmp(login,f[0].login)==0) && (strcmp(senha,f[0].senha)==0)){
    printf("\n\n\t\t\tUsuário logado! Seja bem vindo!!!\t\n\n");
}

else{
    printf("Login e/ou senha incorretos!");
       exit(0);
//limpa tela---------------------------------------------------------------------------------
    fseek(stdin, 0, SEEK_END);
}
 system(limpar_tela);
 //-------------------------------------------------------------------------------

//final do login------------------------------------------------------------------
printf("\n\n\t\t\t----- Sistema PacCovid ------\t\t\n\n\n");
printf("\n  Cadastro de Paciente\n");

cadastro();
system("cls");

printf("\n\n\t\t\tCalculo da Idade do paciente\n\n");
calculaIdade();
system("cls");
return 0;
}

//------------------------------limpa tela---------------------------------

 //---------------------------------------------------------------------
 //Começo do menu do sistema---------------------------------------------------------
//Funçoes do sistema----------------------------------------------------------------------------------------------

//função cadastro------------------------------------------------------------------------------------------------
void cadastro(){
    int op;

FILE *arq_pacientes = fopen("pac.txt", "a");

if(arq_pacientes== NULL)
	{
		printf("\nFalha ao abrir arquivo(s)!\n");
		exit(1); // aborta o programa
	}


	int cont_bytes = 0;

	// cont irá guardar o número total de bytes
	// seta o ponteiro do arquivo para o final do arquivo
	fseek(arq_pacientes, 0, SEEK_END);

	// pegamos a quantidade de bytes com a função ftell
	cont_bytes = ftell(arq_pacientes);

	t_paciente pac;
	enderecoPac ep;

	if(cont_bytes == 0)
	{
		// se for 0, então não existe cliente cadastrado
		// coloco o ID começando de 1
		pac.id = 1;
	}
	else
	{
		t_paciente ultimo_paciente;

// utilizo a função fseek para posicionar o arquivo
		// cont_bytes - sizeof(t_cliente) serve para posicionar
		// para que possamos pegar o último cliente cadastrado
		fseek(arq_pacientes, cont_bytes - sizeof(t_paciente), SEEK_SET);


		// ler o cliente
		fread(&ultimo_paciente, sizeof(t_paciente), 1, arq_pacientes);


		// o ID do cliente é o ID do último cliente acrescido em 1
		pac.id = ultimo_paciente.id + 1;
	}

    do{

        printf("\nDigite o nome: \t");
        scanf("%s",&pac.nome);
        fgets(pac.nome,50,stdin);
        setbuf(stdin,NULL);
        fprintf(arq_pacientes, "%s", pac.nome);

        printf("\nDigite o cpf:\t");
        scanf("%d", &pac.cpf);
        fprintf(arq_pacientes, "%s", pac.cpf);

        printf("\nDigite o telefone:\t");
        scanf("%d", &pac.telefone);
        fprintf(arq_pacientes, "%s", pac.telefone);

        printf("\n\n\t\t\t\t\Digite o endereço:\t\n");

        printf("\nDigite a rua:\t");
        scanf("%s", &ep.rua);
        fgets(ep.rua,20,stdin);
        setbuf(stdin,NULL);
        fprintf(arq_pacientes, "%s", ep.rua);

        printf("\nDigite o numero da residencia:\t");
        scanf("%d",&ep.numero);
        fprintf(arq_pacientes, "%d", ep.numero);

        printf("\nDigite a cidade:\t");
        scanf("%s", &ep.cidade);
        fgets(ep.cidade,20,stdin);
        setbuf(stdin,NULL);
        fprintf(arq_pacientes, "%s", ep.cidade);

        printf("\nDigite o cep:\t");
        scanf("%s", &ep.cep);
        fprintf(arq_pacientes, "%s", ep.cep);



        printf("\nDigite a data de nascimento:\t");
        scanf("%s", &pac.datanasc);
        fgets(pac.datanasc,50,stdin);
        setbuf(stdin,NULL);
        fprintf(arq_pacientes, "%s", pac.datanasc);

        printf("\nDigite o email:\t");
        scanf("%s", &pac.email);
        fprintf(arq_pacientes, "%s", pac.email);

        printf("\nDigite a data de diagnostico:\t");
        scanf("%s", &pac.datadiag);
        fgets(pac.datadiag,50,stdin);
        setbuf(stdin,NULL);
        fprintf(arq_pacientes, "%s", pac.datadiag);

        printf("\nDigite a comorbidade:\t");
        scanf("%s", &pac.comorbidade);
        fgets(pac.comorbidade,50,stdin);
        setbuf(stdin,NULL);
        fprintf(arq_pacientes, "%s", pac.comorbidade);
        printf("Paciente Cadastrado");
	// escreve no arquivo
	fwrite(&pac, sizeof(t_paciente), 1, arq_pacientes);

	fclose(arq_pacientes);

fseek(stdin, 0, SEEK_END);


printf("\nDigite 1 para continuar ou outro valor para sair!\t\n");
scanf("%d", &op);
fseek(stdin, 0, SEEK_END);

    }while(op == 1);
    fseek(arq_pacientes, 0, SEEK_END);
}

void calculaIdade(){
      int op;
    FILE *arq_pacientes = fopen("covid.txt", "a+b");

    if(arq_pacientes== NULL)
	{
		printf("\nFalha ao abrir arquivo(s)!\n");
		exit(1); // aborta o programa
	}


	int cont_bytes = 0;

	// cont irá guardar o número total de bytes
	// seta o ponteiro do arquivo para o final do arquivo
	fseek(arq_pacientes, 0, SEEK_END);

	// pegamos a quantidade de bytes com a função ftell
	cont_bytes = ftell(arq_pacientes);

	t_paciente pac;

	if(cont_bytes == 0)
	{
		// se for 0, então não existe cliente cadastrado
		// coloco o ID começando de 1
		pac.id = 1;
	}
	else
	{
		t_paciente ultimo_paciente;

// utilizo a função fseek para posicionar o arquivo
		// cont_bytes - sizeof(t_cliente) serve para posicionar
		// para que possamos pegar o último cliente cadastrado
		fseek(arq_pacientes, cont_bytes - sizeof(t_paciente), SEEK_SET);


		// ler o cliente
		fread(&ultimo_paciente, sizeof(t_paciente), 1, arq_pacientes);


		// o ID do cliente é o ID do último cliente acrescido em 1
		pac.id = ultimo_paciente.id + 1;
	}
enderecoPac ep;
//Calculo da idade do paciente

 do{

int diahoje, dianasc;
  int meshoje, mesnasc;
  int anohoje, anonasc;
  int dia, mes, ano,diferenca;

  diahoje = 0;  // dia atual
  dianasc = 0;  //dia de nascimento
  meshoje = 0;  // mes atual
  mesnasc = 0;  // mes de nascimento
  anohoje = 0;  // ano atual
  anonasc = 0;  // ano de nascimento
  diferenca =   365*anohoje + 30*meshoje + diahoje
              - 365*anonasc - 30*mesnasc - dianasc;

  ano = diferenca/365;
  diferenca = diferenca%365;

  mes = diferenca/30;
  diferenca = diferenca%30;

  dia = diferenca;


  // Entrada de dados
  printf("%s","\n\nPor favor, desta maneira (29 01 1990) informe a data de hoje:\t");
  scanf(" %d%d%d", &diahoje, &meshoje, &anohoje);
  printf(" \n\n\t%2d/%2d/%3d\n\n", diahoje, meshoje, anohoje);

  printf("%s","\n\nPor favor, desta maneira (29 01 1990) informe a data de nascimento do paciente:\n\t");
  scanf(" %d%d%d", &dianasc, &mesnasc, &anonasc);
  printf("\n\n\t\t%2d/%2d/%3d\n\n", dianasc, mesnasc, anonasc);

  if(diferenca > 65){
    printf("\n\tEstá no grupo de risco!\t\n");
    scanf("%d", &diferenca);
    fprintf(arq_pacientes, "%s", ep.cep);
    fprintf(arq_pacientes, "%d", diferenca);
  }else{
  printf("\n\tNão está no grupo de risco!\t\n\n\n");
  }

  // Calculando dados recebidos

 //Resultado do calculo
  printf("%s %d %s %d %s %d %s","\n\tIdade do paciente:", ano, "ano(s)", mes, "mes(es)", dia, "dia(s).\n");
// escreve no arquivo
	fwrite(&pac, sizeof(t_paciente), 1, arq_pacientes);

	fclose(arq_pacientes);

printf("\nDigite 1 para continuar ou outro valor para sair!\t\n");
scanf("%d", &op);
fseek(stdin, 0, SEEK_END);

    }while(op == 1);
    fseek(arq_pacientes, 0, SEEK_END);
}