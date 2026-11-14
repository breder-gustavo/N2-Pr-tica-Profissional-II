#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    system("chcp 65001 >nul");
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    char nome[50];
    double kwh = 0;
    double tarifa = 0;

    printf("Digite o primeiro nome do cliente: ");
    scanf("%s", nome);

    printf("Digite a quantidade de kWh consumidos: ");
    scanf("%lf", &kwh);

    if (kwh < 0) {
        printf("O consumo de energia elétrica não pode ser negativo.\n");
        return 0;
    }

    if (kwh <= 100) {
        tarifa = 0.60;
    } else if (kwh < 0) { 
      printf("O consumo de energia elétrica não pode ser negativo.\n");  
    } else if (kwh <= 200) { 
        tarifa = 0.75;
    } else {
        tarifa = 0.90;
    }

    double valorConta = kwh * tarifa;

    printf("\n--- Resumo ---\n");
    printf("Cliente: %s\n", nome);
    printf("Consumo: %.2f kWh\n", kwh);
    printf("Tarifa aplicada: R$ %.2f\n", tarifa);
    printf("O valor da conta de energia elétrica é: R$ %.2f\n", valorConta);

    return 0;
}