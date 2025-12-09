
#include <stdio.h>

//definição da estrutura Aluno com typedef para ser mais eficiente ao chamá-lo
typedef struct { 
 char nome[50]; 
 int matricula; 
 float notas[3]; 
 float media; 
} Aluno; 
//função para cadastrar alunos
void cadastrarAlunos(Aluno *alunos, int *quantidadeAlunos) {
	//condicional utilizada para realizar o cadastro de um aluno por vez tendo limite de 5 alunos
    if (*quantidadeAlunos < 5) {
        printf("----- CADASTRAR ALUNO (ATE 5 ALUNOS)-----\n");
        printf("Informe o nome do aluno: \n");
        scanf("%s", alunos[*quantidadeAlunos].nome);
        printf("Informe a matricula do aluno: \n");
        scanf("%d", &alunos[*quantidadeAlunos].matricula);
        
        printf("Informe a primeira nota do aluno: \n");
        scanf("%f", &alunos[*quantidadeAlunos].notas[0]);
        printf("Informe a segunda nota do aluno: \n");
        scanf("%f", &alunos[*quantidadeAlunos].notas[1]);
        printf("Informe a terceira nota do aluno: \n");
        scanf("%f", &alunos[*quantidadeAlunos].notas[2]);
        
        printf("Aluno cadastrado com sucesso!\n");
        (*quantidadeAlunos)++;
        
    } else {
    	printf("Erro! Voce atingiu a quantidade maxima de cadastro.\n");
	}
}
//função para calcular as medias dos alunos cadastrados com suas respectivas notas armazenandas e imprimir na tela
void calcularMedias(Aluno *alunos, int quantidadeAlunos){
	//se escolher calcular a media antes de cadastrar pelo menos um aluno vai acontecer erro(mas sem fechar o sistema):
    if (quantidadeAlunos == 0) {
    	printf("Erro! Nenhum aluno cadastrado.");
    	return;
	}
	//imprime na tela apos passar pela verificacao, coloquei antes do for para nao repetir todas as 
	//vezes que exigir o funcionamento do loop
	printf("\n----- CALCULAR MEDIA DOS ALUNOS CADASTRADOS -----\n");
    for (int i = 0; i < quantidadeAlunos; i++) {
    	float soma = 0;
    	//utilizdo 'soma' para receber e acumular o valor das notas do vetor
    	soma += *(alunos[i].notas + 0);
    	soma += *(alunos[i].notas + 1);
    	soma += *(alunos[i].notas + 2);
    	// realiza o calculo
    	alunos[i].media = soma / 3;
    	
    	printf("\nMedia do aluno %s eh: %.2f.\n", alunos[i].nome, alunos[i].media);
    	
	}
	printf("\nCalculo concluido com sucesso!\n");
}; 
//calcula a media da turma com base nos dados armazenados
float calcularMediaTurma(Aluno *alunos, int quantidadeAlunos) {
	float somaTotalMedia = 0;
	
	//enquanto percorre o vetor, 'somaTotalMedia' acumula o valor da media de cada aluno
	for (int i = 0; i < quantidadeAlunos; i++) {
		somaTotalMedia += alunos[i].media;
	}
	//se tiver ao menos 1 aluno cadastrado vai retornar o resultado da expressao abaixo como media da turma
	if (quantidadeAlunos > 0) {
		return somaTotalMedia / quantidadeAlunos;
	} else {
		return 0;
	}
}; 
//função para exibir relatorio completo
void exibirRelatorio(Aluno *alunos, int quantidadeAlunos) {
	//se escolher opcao de exibir relatorio sem ter aluno cadastrado:
	if (quantidadeAlunos == 0) {
		printf("\nNao ha aluno cadastrado para gerar relatorio!\n");
		return;
	}
	
	calcularMedias(alunos, quantidadeAlunos);
	
	printf("\n----- RELATORIO COMPLETO -----\n");
	
	//definições das variaveis utilizando como pivo a media do primeiro aluno cadastrado
	float maiorMedia = alunos[0].media;
	float menorMedia = alunos[0].media;
	int qntdAprovados = 0;
	
	//percorre pela media de todos os alunos cadastrado
	for (int i = 0; i < quantidadeAlunos; i++) {
		//condicional para a verificação da maior media 
		if (alunos[i].media > maiorMedia) {
			maiorMedia = alunos[i].media;
		}
		//condicional para a verificacao da menor media
		if (alunos[i].media < menorMedia) {
			menorMedia = alunos[i].media;
		}
		//incrementa 1 em qntdAprovados se algum aluno tiver a media maior que 7 (como solicitado, Silvana)
		if (alunos[i].media >= 7) {
			qntdAprovados++;
		}
		//imprime na tela os dados conforme percorre os vetores
		printf("\nAluno: %s.\n", alunos[i].nome);
		printf("\nmatricula: %d.", alunos[i].matricula);
		printf("\nMedia: %.2f.\n", alunos[i].media);
	}
	//atribui a variavel o resultado da função de calcular media da turma
	float mediaGeral = calcularMediaTurma(alunos, quantidadeAlunos);
	
	//resumo breve do relatorio com somente o necessario
	printf("\n---- RESUMO GERAL DO RELATORIO ----\n");
    printf("Media Geral da Turma:  %.2f\n", mediaGeral);
    printf("Maior Media:           %.2f\n", maiorMedia);
    printf("Menor Media:           %.2f\n", menorMedia);
    printf("Quantidade Aprovados:  %d\n", qntdAprovados);
    printf("\nRELATORIOS GERADOS COM SUCESSO!\n");
}; 
//ATE QUE ENFIM... NA MAIN. A'MAIN'!(AMEM).
int main()
{
	//define vetor para 5 alunos
    Aluno alunos[5];
    int quantidadeAlunos = 0;
    int opcao;
    
    //do while para imprimir na tela, depois verificar
    do {
        printf("\n");
        printf("\n----- Faculdade TechEdu -----\n");
        printf("1 - CADASTRAR ALUNO\n");
        printf("2 - CALCULAR MEDIAS INDIVIDUAIS\n");
        printf("3 - EXIBIR RELATORIO COMPLETO\n");
        printf("0 - SAIR DO PROGRAMA\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        //verificar a opcao que o usuario digitar
        switch (opcao) {
            case 1:
                cadastrarAlunos (alunos, &quantidadeAlunos);
                break;
            case 2:
				calcularMedias(alunos, quantidadeAlunos);
                break;
            case 3:
            	exibirRelatorio(alunos, quantidadeAlunos);
                break;
            case 0:
            	printf("\nSaindo...");
            	break;
            //nao utilizei 'default' para o programa reexecutar automaticamente quando o usuario nao escolher umas das opcoes acima
            
        }
    } while (opcao != 0);
    printf("\nPrograma finalizado com sucesso!");
    return 0;
}
