#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Declaração de variáveis
    char estado1, estado2;
    char cod1[5], cod2[5];
    char cidade1[50], cidade2[50];
    unsigned long int habitantes1, habitantes2;
    int pontost1, pontost2;
    float area1, area2;
    float pib1, pib2;
    float pibPerCapita1, pibPerCapita2;
    float densidade1, densidade2;

    // Coletando as informações da carta 1
    printf("\n\t\t Carta 1 \n");
    printf("Digite o estado da carta 1 (Letra entre A e H): ");
    scanf(" %c", &estado1);
    printf("Digite o código da carta 1 (ex:A01): ");
    scanf("%s", cod1);
    printf("Digite o nome da cidade da carta 1: ");
    scanf("%s", cidade1);
    printf("Digite o número de habitantes da cidade 1: ");
    scanf("%lu", &habitantes1);
    printf("Digite a área da cidade 1 em Km²: ");
    scanf("%f", &area1);
    printf("Digite o PIB da cidade 1 (Bilhões ex 1000000000): ");
    scanf("%f", &pib1);
    printf("Digite a quantidade de pontos turísticos da carta 1: ");
    scanf("%d", &pontost1);

    // Coletando as informações da carta 2
    printf("\n\t\t Carta 2 \n");
    printf("Digite o estado da carta 2 (Letra entre A e H): ");
    scanf(" %c", &estado2);
    printf("Digite o código da carta 2 (ex:A01): ");
    scanf("%s", cod2);
    printf("Digite o nome da cidade da carta 2: ");
    scanf("%s", cidade2);
    printf("Digite o número de habitantes da cidade 2: ");
    scanf("%lu", &habitantes2);
    printf("Digite a área da cidade 2 em Km²: ");
    scanf("%f", &area2);
    printf("Digite o PIB da cidade 2 (Bilhões ex 1000000000): ");
    scanf("%f", &pib2);
    printf("Digite a quantidade de pontos turísticos da carta 2: ");
    scanf("%d", &pontost2);

    // Cálculo do PIB per capita e densidade populacional
    pibPerCapita1 = pib1 / habitantes1;
    pibPerCapita2 = pib2 / habitantes2;
    densidade1 = habitantes1 / area1;
    densidade2 = habitantes2 / area2;

    int opcao1, opcao2;
    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos turísticos\n5 - Densidade demográfica\n");
    scanf("%d", &opcao1);
    
    do {
        printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
        scanf("%d", &opcao2);
    } while (opcao2 == opcao1);

    float valor1_c1, valor1_c2, valor2_c1, valor2_c2;
    switch (opcao1) {
        case 1: valor1_c1 = habitantes1; valor1_c2 = habitantes2; break;
        case 2: valor1_c1 = area1; valor1_c2 = area2; break;
        case 3: valor1_c1 = pib1; valor1_c2 = pib2; break;
        case 4: valor1_c1 = pontost1; valor1_c2 = pontost2; break;
        case 5: valor1_c1 = -densidade1; valor1_c2 = -densidade2; break;
    }
    switch (opcao2) {
        case 1: valor2_c1 = habitantes1; valor2_c2 = habitantes2; break;
        case 2: valor2_c1 = area1; valor2_c2 = area2; break;
        case 3: valor2_c1 = pib1; valor2_c2 = pib2; break;
        case 4: valor2_c1 = pontost1; valor2_c2 = pontost2; break;
        case 5: valor2_c1 = -densidade1; valor2_c2 = -densidade2; break;
    }

    float soma_c1 = valor1_c1 + valor2_c1;
    float soma_c2 = valor1_c2 + valor2_c2;

    printf("\nComparação das Cartas:\n");
    printf("%s: %.2f e %.2f (Total: %.2f)\n", cidade1, valor1_c1, valor2_c1, soma_c1);
    printf("%s: %.2f e %.2f (Total: %.2f)\n", cidade2, valor1_c2, valor2_c2, soma_c2);

    if (soma_c1 > soma_c2) {
        printf("%s venceu!\n", cidade1);
    } else if (soma_c2 > soma_c1) {
        printf("%s venceu!\n", cidade2);
    } else {
        printf("Empate!\n");
    }

    return 0;
}