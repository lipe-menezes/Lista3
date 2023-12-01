#include <stdio.h>

int main() {

    int num_meses;
    double aporte_mensal, taxa_juros, montante_total = 0;


    //printf("Digite o número de meses poupando e investindo (entre 1 e 240): ");
    scanf("%d", &num_meses);

   // printf("Digite o aporte mensal (entre 1 e 5000): ");
    scanf("%lf", &aporte_mensal);

    //printf("Digite a taxa de retorno mensal dos investimentos (entre 0.01 e 0.2): ");
    scanf("%lf", &taxa_juros);

    for (int mes = 1; mes <= num_meses; ++mes) {
        montante_total = (montante_total + aporte_mensal) * (1 + taxa_juros);

        printf("Montante ao fim do mes %d: R$ %.2lf\n", mes, montante_total);
    }

    return 0;
}


