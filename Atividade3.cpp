#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Fun��o para verificar se o formato da placa � v�lido
int validarPlaca(char *placa) {
    int i;
    int comprimento = strlen(placa);

    if (comprimento != 8 && comprimento != 7) {
        return 0; // Formato inv�lido
    }

    // Verifica os primeiros tr�s caracteres
    for (i = 0; i < 3; i++) {
        if (!isalpha(placa[i])) {
            return 0; // Formato inv�lido
        }
    }

    // Verifica o quarto caractere (h�fen ou letra)
    if (placa[3] != '-' && !isalpha(placa[3])) {
        return 0; // Formato inv�lido
    }

    // Verifica os caracteres restantes
    for (i = 4; i < comprimento; i++) {
        if (!isdigit(placa[i])) {
            return 0; // Formato inv�lido
        }
    }

    return 1; // Formato v�lido
}

// Fun��o para validar o dia da semana
int validarDia(char *dia) {
    char *diasValidos[] = {"SEGUNDA-FEIRA", "TERCA-FEIRA", "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO", "DOMINGO"};
    int i;

    for (i = 0; i < 7; i++) {
        if (strcmp(dia, diasValidos[i]) == 0) {
            return 1; // Dia v�lido
        }
    }

    return 0; // Dia inv�lido
}

int main() {
    char placa[9];
    char dia[15];

    // Entrada de dados
    printf("Digite a placa do veiculo: ");
    scanf("%s", placa);

    printf("Digite o dia da semana: ");
    scanf("%s", dia);

    // Validar a placa
    if (!validarPlaca(placa)) {
        printf("Placa invalida\n");
        return 1;
    }

    // Validar o dia da semana
    if (!validarDia(dia)) {
        printf("Dia da semana invalido\n");
        return 1;
    }

    // Verificar se a placa pode circular no dia informado
    int ultimoDigito = placa[strlen(placa) - 1] - '0';
    int proibicao = (ultimoDigito / 2) * 2;

    if (strcmp(dia, "SABADO") == 0 || strcmp(dia, "DOMINGO") == 0 || ultimoDigito == proibicao) {
        printf("%s pode circular %s\n", placa, dia);
    } else {
        printf("%s nao pode circular %s\n", placa, dia);
    }

    return 0;
}




 


