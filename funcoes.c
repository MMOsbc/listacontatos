#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

void cadastrarContatos(ListaDeContatos *lt) {
    if (lt->qtd >= 255) {
        printf("A lista de contatos está cheia. Não é possível cadastrar mais contatos\n");
        return;
    }

    Contato novoContato;

    printf("Número de cadastro: ");
    scanf("%lf", &novoContato.id); // Usando %lf para ler um double

    printf("Telefone: ");
    scanf("%s", novoContato.telefone); // Lendo como uma string

    printf("Nome (até 20 caracteres): ");
    scanf("%s", novoContato.nome); // Lendo como uma string

    printf("Sobrenome (até 50 caracteres): ");
    scanf("%s", novoContato.sobrenome); // Lendo como uma string

    lt->contatos[lt->qtd] = novoContato;
    lt->qtd++;

    printf("Contato cadastrado com sucesso!\n");
}

void listarContatos(ListaDeContatos lt) {
    if (lt.qtd == 0) {
        printf("A lista de contatos está vazia.\n");
        return;
    }

    printf("Lista de Contatos:\n");

    for (int i = 0; i < lt.qtd; i++) {
        printf("ID %d:\n", i + 1);
        printf("ID: %.0lf\n", lt.contatos[i].id); // Corrigindo para %.0lf para imprimir um double como um inteiro
        printf("Telefone: %s\n", lt.contatos[i].telefone);
        printf("Nome: %s\n", lt.contatos[i].nome);
        printf("Sobrenome: %s\n", lt.contatos[i].sobrenome);
        printf("\n");
    }
}

void carregarContatos(ListaDeContatos*lt, const char *arquivo) {
    FILE *file = fopen(arquivo, "rb");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo de contatos.\n");
        return;
    }

    fread(&(lt->qtd), sizeof(int), 1, file);

    if (lt->qtd > 255) {
        printf("Erro: O número de contatos no arquivo é maior do que o limite permitido.\n");
        fclose(file);
        return;
    }

    fread(lt->contatos, sizeof(Contato), lt->qtd, file); // Corrigindo para lt->contatos

    fclose(file);
    printf("Contatos carregados com sucesso a partir do arquivo: %s\n", arquivo);
}

void salvarContatos(ListaDeContatos lt, const char *arquivo) {
    FILE *file = fopen(arquivo, "wb");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para salvar Contatos.\n");
        return;
    }

    fwrite(&(lt.qtd), sizeof(int), 1, file);
    fwrite(lt.contatos, sizeof(Contato), lt.qtd, file); // Corrigindo para lt.contatos

    fclose(file);
    printf("Contatos salvos com sucesso no arquivo: %s\n", arquivo);
}

void deletarContato(ListaDeContatos *lt) {
    int posicao = -1;
    char telefone[15];
    printf("Digite o número de telefone do contato que deseja deletar: ");
    scanf("%s", telefone);

    // Procurar o contato pelo telefone
    for (int i = 0; i < lt->qtd; i++) {
        if (strcmp(lt->contatos[i].telefone, telefone) == 0) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        printf("Contato com o telefone %s não encontrado.\n", telefone);
        return;
    }

    // Remover o contato encontrando deslocando os contatos restantes para a esquerda
    for (int i = posicao; i < lt->qtd - 1; i++) {
        lt->contatos[i] = lt->contatos[i + 1];
    }

    lt->qtd--;

    printf("Contato com o telefone %s deletado com sucesso.\n", telefone);
}
