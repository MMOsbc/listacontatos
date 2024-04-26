#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main() {
    ListaDeContatos listaContatos;
    listaContatos.qtd = 0;
    int escolha;

    while (1) {
        printf("\nEscolha uma opção:\n");
        printf("1. Cadastrar Contato\n");
        printf("2. Listar Contatos\n");
        printf("3. Salvar Contatos em Arquivo\n");
        printf("4. Carregar Contatos de Arquivo\n");
        printf("5. Sair\n");
        printf("Digite o número da opção desejada: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                cadastrarContatos(&listaContatos);
                break;
            case 2:
                listarContatos(listaContatos);
                break;
            case 3:
                salvarContatos(listaContatos, "contatos.bin");
                break;
            case 4:
                carregarContatos(&listaContatos, "contatos.bin");
                break;
            case 5:
                printf("Que pena que escolheu sair. Até breve!\n");
                return 0; // Encerra o programa
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}