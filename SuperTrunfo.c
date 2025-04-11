#include <stdio.h>

int main (){
	
	
	//variaveis da carta 1 °3°
	char pais1;
	char codigo_carta1 [4];
	char nome_pais1 [26];
	unsigned long int populacao1;
	float area1;
	float pib1;
	int qt_pontos_turisticos1;
	float DensidadePopulacional1;
	float PIBperCapita1;
	
		
	//variaveis da carta 2 °3°
	char pais2;
	char codigo_carta2 [4];
	char nome_pais2 [26];
	unsigned long int populacao2;
	float area2;
	float pib2;
	int qt_pontos_turisticos2;
	float DensidadePopulacional2;
	float PIBperCapita2;

	
	//variaveis para o resultado da comparação entre as cartas
	float superpoder1, superpoder2;

	//variavel da escolha de atributo
	int escolhaAtributo1, escolhaAtributo2;	
	
	
	//pedindo para o usuário realizar tal ação e o scanf armazená-la :)
	//carta 1
	printf("\n\n");
	printf("Insira a seguir as informações para a Carta 1! \n\n");
	
	printf("Digite uma letra de A a H para representar o país: ");
	scanf(" %c", &pais1);
	
	printf("Digite a letra do país seguida de um número de 01 a 04 (ex: A03): ");
	scanf("%s", codigo_carta1);
	
	printf("Digite o nome do país: ");
	scanf("%s", nome_pais1);
	
	printf("Digite o número de habitantes do país: ");
	scanf("%lu", &populacao1);
	
	printf("Digite a área do país em quilômetros quadrados: ");
	scanf("%f", &area1);
	
	printf("Digite o PIB do país: ");
	scanf("%f", &pib1);
	
	printf("Informe quantos pontos turísticos têm no país: ");
	scanf("%d", &qt_pontos_turisticos1);
	printf("\n\n\n");
	
	
	//pedindo para o usuário realizar tal ação e o scanf armazená-la :)
	//carta 2
	printf("Agora insira a seguir as informações para a carta 2! \n\n");
	
	printf("Digite uma letra de A a H para representar o país: ");
	scanf(" %c", &pais2);
	
	printf("Digite a letra do país seguida de um número de 01 a 04 (ex: A03):");
	scanf("%s", codigo_carta2);
	
	printf("Digite o nome do país: ");
	scanf("%s", nome_pais2);
	
	printf("Digite o número de habitantes do país: ");
	scanf("%lu", &populacao2);
	
	printf("Digite a área do país em quilômetros quadrados: ");
	scanf("%f", &area2);
	
	printf("Digite o PIB do país: ");
	scanf("%f", &pib2);
	
	printf("Informe quantos pontos turísticos têm no país: ");
	scanf("%d", &qt_pontos_turisticos2);
	printf("\n\n\n\n");


	
	//atribuindo resultado do pib em bilhões
	pib1 *= 1e9;
	pib2 *= 1e9;
	
	//calculando a desidade populacional e o pib per capita carta 1
	DensidadePopulacional1 = populacao1 / area1;
	PIBperCapita1 = pib1 / populacao1;
	
	//calculando a desidade populacional e o pib per capita carta 2
	DensidadePopulacional2 = populacao2 / area2;
	PIBperCapita2 = pib2 / populacao2;
	
	
	//calculando superpoder
	superpoder1 = (populacao1 / 1000.0) + area1 + (pib1 / 1e9) + qt_pontos_turisticos1 + PIBperCapita1 + (1.0 / DensidadePopulacional1);

	superpoder2 = (populacao2 / 1000.0) + area2 + (pib2 / 1e9) + qt_pontos_turisticos2 + PIBperCapita2 + (1.0 / DensidadePopulacional2);



	//perguntando ao jogador qual o primeiro atributo ele quer que compare
	printf("Escolha o primeiro atributo a ser comparado. \n\n");
    printf("1. População\n");
	printf("2. Área\n");
	printf("3. PIB\n");
	printf("4. Pontos turísticos\n");
	printf("5. Densidade Populacional (lembre-se: a carta com o menor valor, vence!)\n");
	printf("6. PIB per Capita\n");
    printf("Opção (1, 2, 3, 4, 5 ou 6): ");
    scanf("%d", &escolhaAtributo1);
	printf("\n\n");

	//perguntando ao jogador qual o segundo atributo ele quer que compare
	printf("Escolha o segundo atributo (número diferente, por favor). \n\n");
    if (escolhaAtributo1 != 1) printf("1. População\n");
	if (escolhaAtributo1 != 2) printf("2. Área\n");
	if (escolhaAtributo1 != 3) printf("3. PIB\n");
	if (escolhaAtributo1 != 4) printf("4. Pontos turísticos\n");
	if (escolhaAtributo1 != 5) printf("5. Densidade Populacional (lembre-se: a carta com o menor valor, vence!)\n");
	if (escolhaAtributo1 != 6) printf("6. PIB per Capita\n");
    printf("Opção (1, 2, 3, 4, 5 ou 6): ");
    scanf("%d", &escolhaAtributo2);
	printf("\n\n\n");

	//verificando se foi inserido o mesmo número duas vezes
	if (escolhaAtributo1 == escolhaAtributo2) {
		printf("Você escolheu o mesmo atributo duas vezes, então foi ajustado automaticamente.\n");

		//procura um número diferente de forma rápida
		escolhaAtributo2 = (escolhaAtributo1 != 1) ? 1 : 2;
		printf("Primeiro: %d, Segundo (auto): %d\n", escolhaAtributo1, escolhaAtributo2);
	}


	//entrando com switch para fazer o que o jogador pediu anteriormente ^^
	//comparando quem venceu + saída de dados do que o jogador pediu (escolha do atributo 1)!!!
	switch (escolhaAtributo1)
	{
	case 1:
		//atributo população
		printf("Comparação de cartas (Atributo: População): \n\n");

		printf("Carta 1 - (%s) População: %lu\n", nome_pais1, populacao1);
		printf("Carta 2 - (%s) População: %lu\n", nome_pais2, populacao2);
		//
		if(populacao1 > populacao2) {
			printf("Resultado: Carta 1 (%s) venceu! \n\n\n\n", nome_pais1);
		} else if (populacao1 < populacao2) {
				printf("Resultado: Carta 2 (%s) venceu! \n\n\n\n", nome_pais2);
			}   else {
					printf("Resultado: Empate! \n\n\n\n");
				}
	break;
	
	case 2:
		//atributo area
		printf("Comparação de cartas (Atributo: Área): \n\n");

		printf("Carta 1 - (%s) Área: %.2f\n", nome_pais1, area1);
		printf("Carta 2 - (%s) Área: %.2f\n", nome_pais2, area2);
		//
		if(area1 > area2) {
			printf("Resultado: Carta 1 (%s) venceu! \n\n\n\n", nome_pais1);
		}   else if(area1 < area2) {
				printf("Resultado: Carta 2 (%s) venceu! \n\n\n\n", nome_pais2);
			}   else {
					printf("Resultado: Empate! \n\n\n\n");
				}
	break;

	case 3:
		//atributo pib
		printf("Comparação de cartas (Atributo: PIB): \n\n");

		printf("Carta 1 - (%s) PIB: %.2f\n", nome_pais1, pib1);
		printf("Carta 2 - (%s) PIB: %.2f\n", nome_pais2, pib2);
		//
		if(pib1 > pib2) {
			printf("Resultado: Carta 1 (%s) venceu! \n\n\n\n", nome_pais1);
		}   else if(pib1 < pib2) {
				printf("Resultado: Carta 2 (%s) venceu! \n\n\n\n", nome_pais2);
			}   else {
					printf("Resultado: Empate! \n\n\n\n");
				}	
	break;

	case 4:
		//atributo pontos turisticos
		printf("Comparação de cartas (Atributo: Pontos Turísticos): \n\n");

		printf("Carta 1 - (%s) Pontos Turísticos: %d\n\n", nome_pais1, qt_pontos_turisticos1);
		printf("Carta 2 - (%s) Pontos Turísticos: %d\n\n", nome_pais2, qt_pontos_turisticos2);
		//
		if(qt_pontos_turisticos1 > qt_pontos_turisticos2) {
			printf("Resultado: Carta 1 (%s) venceu! \n\n\n\n", nome_pais1);
		}    else if(qt_pontos_turisticos1 < qt_pontos_turisticos2) {
				printf("Resultado: Carta 2 (%s) venceu! \n\n\n\n", nome_pais2);
			}   else {
					printf("Resultado: Empate! \n\n\n\n");
				}
	break;

	case 5:
		//atributo densidade populacional
		printf("Comparação de cartas (Atributo: Densidade Populacional): \n\n");

		printf("Carta 1 - (%s) Densidade populacional: %.2f\n", nome_pais1, DensidadePopulacional1);
		printf("Carta 2 - (%s) Densidade populacional: %.2f\n", nome_pais2, DensidadePopulacional2);
		//
		if(DensidadePopulacional1 < DensidadePopulacional2) {
			printf("Resultado: Carta 1 (%s) venceu! \n\n\n\n", nome_pais1);
		} 	else if(DensidadePopulacional1 > DensidadePopulacional2) {
					printf("Resultado: Carta 2 (%s) venceu! \n\n\n\n", nome_pais2);
			} 	else {
					printf("Resultado: Empate! \n\n\n");
				}
	break;

	case 6:
		//atributo pib per capita
		printf("Comparação de cartas (Atributo: PIB per Capita): \n\n");

		printf("Carta 1 - (%s) PIB per Capita: %.2f\n", nome_pais1, PIBperCapita1);
		printf("Carta 2 - (%s) PIB per Capita: %.2f\n", nome_pais2, PIBperCapita2);
		//
		if(PIBperCapita1 > PIBperCapita2) {
			printf("Resultado: Carta 1 (%s) venceu! \n\n\n\n", nome_pais1);
		}   else if(PIBperCapita1 < PIBperCapita2) {
				printf("Resultado: Carta 2 (%s) venceu! \n\n\n\n", nome_pais2);
			}   else {
					printf("Resultado: Empate! \n\n\n\n");
				}
	break;
	
	default:
		printf("Opa! Parece que você digitou um caracter inválido. Tente novamente digitando apenas um número de 1 a 6.");
		break;
	}

	

	//comparando quem venceu + saída de dados do que o jogador pediu (escolha do atributo 2)!!!
	switch (escolhaAtributo2)
	{
	case 1:
		//atributo população
		printf("Comparação de cartas (Atributo: População): \n\n");

		printf("Carta 1 - (%s) População: %lu\n", nome_pais1, populacao1);
		printf("Carta 2 - (%s) População: %lu\n", nome_pais2, populacao2);
		//
		if(populacao1 > populacao2) {
			printf("Resultado: Carta 1 (%s) venceu! \n\n\n\n", nome_pais1);
		} else if (populacao1 < populacao2) {
				printf("Resultado: Carta 2 (%s) venceu! \n\n\n\n", nome_pais2);
			}   else {
					printf("Resultado: Empate! \n\n\n\n");
				}
	break;
	
	case 2:
		//atributo area
		printf("Comparação de cartas (Atributo: Área): \n\n");

		printf("Carta 1 - (%s) Área: %.2f\n", nome_pais1, area1);
		printf("Carta 2 - (%s) Área: %.2f\n", nome_pais2, area2);
		//
		if(area1 > area2) {
			printf("Resultado: Carta 1 (%s) venceu! \n\n\n\n", nome_pais1);
		}   else if(area1 < area2) {
				printf("Resultado: Carta 2 (%s) venceu! \n\n\n\n", nome_pais2);
			}   else {
					printf("Resultado: Empate! \n\n\n\n");
				}
	break;

	case 3:
		//atributo pib
		printf("Comparação de cartas (Atributo: PIB): \n\n");

		printf("Carta 1 - (%s) PIB: %.2f\n", nome_pais1, pib1);
		printf("Carta 2 - (%s) PIB: %.2f\n", nome_pais2, pib2);
		//
		if(pib1 > pib2) {
			printf("Resultado: Carta 1 (%s) venceu! \n\n\n\n", nome_pais1);
		}   else if(pib1 < pib2) {
				printf("Resultado: Carta 2 (%s) venceu! \n\n\n\n", nome_pais2);
			}   else {
					printf("Resultado: Empate! \n\n\n\n");
				}	
	break;

	case 4:
		//atributo pontos turisticos
		printf("Comparação de cartas (Atributo: Pontos Turísticos): \n\n");

		printf("Carta 1 - (%s) Pontos Turísticos: %d\n\n", nome_pais1, qt_pontos_turisticos1);
		printf("Carta 2 - (%s) Pontos Turísticos: %d\n\n", nome_pais2, qt_pontos_turisticos2);
		//
		if(qt_pontos_turisticos1 > qt_pontos_turisticos2) {
			printf("Resultado: Carta 1 (%s) venceu! \n\n\n\n", nome_pais1);
		}    else if(qt_pontos_turisticos1 < qt_pontos_turisticos2) {
				printf("Resultado: Carta 2 (%s) venceu! \n\n\n\n", nome_pais2);
			}   else {
					printf("Resultado: Empate! \n\n\n\n");
				}
	break;

	case 5:
		//atributo densidade populacional
		printf("Comparação de cartas (Atributo: Densidade Populacional): \n\n");

		printf("Carta 1 - (%s) Densidade populacional: %.2f\n", nome_pais1, DensidadePopulacional1);
		printf("Carta 2 - (%s) Densidade populacional: %.2f\n", nome_pais2, DensidadePopulacional2);
		//
		if(DensidadePopulacional1 < DensidadePopulacional2) {
			printf("Resultado: Carta 1 (%s) venceu! \n\n\n\n", nome_pais1);
		} 	else if(DensidadePopulacional1 > DensidadePopulacional2) {
					printf("Resultado: Carta 2 (%s) venceu! \n\n\n\n", nome_pais2);
			} 	else {
					printf("Resultado: Empate! \n\n\n");
				}
	break;

	case 6:
		//atributo pib per capita
		printf("Comparação de cartas (Atributo: PIB per Capita): \n\n");

		printf("Carta 1 - (%s) PIB per Capita: %.2f\n", nome_pais1, PIBperCapita1);
		printf("Carta 2 - (%s) PIB per Capita: %.2f\n", nome_pais2, PIBperCapita2);
		//
		if(PIBperCapita1 > PIBperCapita2) {
			printf("Resultado: Carta 1 (%s) venceu! \n\n\n\n", nome_pais1);
		}   else if(PIBperCapita1 < PIBperCapita2) {
				printf("Resultado: Carta 2 (%s) venceu! \n\n\n\n", nome_pais2);
			}   else {
					printf("Resultado: Empate! \n\n\n\n");
				}
	break;
	
	default:
		printf("Opa! Parece que você digitou um caracter inválido. Tente novamente digitando apenas um número de 1 a 6.");
		break;
	}

	
	//Comparando quem venceu o jogo!
	if (superpoder1 > superpoder2) {
		printf("Somando todos os pontos de cada uma das cartas, a carta 1 (%s) venceu o jogo com (%.2f) pontos! :p", nome_pais1, superpoder1);
	}	else if (superpoder1 < superpoder2) {
			printf("Somando todos os pontos de cada uma das cartas, a carta 2 (%s) venceu o jogo com (%.2f) pontos! :p", nome_pais2, superpoder2);
		}	else {
				printf("Que legal! Houve um empate!");
			}

}
