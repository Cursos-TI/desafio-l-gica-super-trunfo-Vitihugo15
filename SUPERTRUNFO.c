#include <stdio.h>
#include <string.h>

#define NUM_PAISES 8
#define NUM_CIDADES 4

typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    char pontos_turisticos[100];
} Cidade;

typedef struct {
    char nome[50];
    Cidade cidades[NUM_CIDADES];
} Pais;

void exibir_cidade(Cidade cidade) {
    printf("Cidade: %s\n", cidade.nome);
    printf("População: %d\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("PIB: %.2f bilhões\n", cidade.pib);
    printf("Pontos Turísticos: %s\n", cidade.pontos_turisticos);
    printf("\n");
}

void exibir_pais(Pais pais) {
    printf("País: %s\n", pais.nome);
    for (int i = 0; i < NUM_CIDADES; i++) {
        exibir_cidade(pais.cidades[i]);
    }
}

void comparar_cidades(Cidade cidade1, Cidade cidade2, char nomePais1[], char nomePais2[]) {
    // Comparar população
    if (cidade1.populacao > cidade2.populacao) {
        printf("%s (%s) tem população maior que %s (%s)\n",
               cidade1.nome, nomePais1, cidade2.nome, nomePais2);
    } else if (cidade1.populacao < cidade2.populacao) {
        printf("%s (%s) tem população menor que %s (%s)\n",
               cidade1.nome, nomePais1, cidade2.nome, nomePais2);
    } else {
        printf("%s (%s) tem a mesma população que %s (%s)\n",
               cidade1.nome, nomePais1, cidade2.nome, nomePais2);
    }

    // Comparar área
    if (cidade1.area > cidade2.area) {
        printf("%s (%s) tem área maior que %s (%s)\n",
               cidade1.nome, nomePais1, cidade2.nome, nomePais2);
    } else if (cidade1.area < cidade2.area) {
        printf("%s (%s) tem área menor que %s (%s)\n",
               cidade1.nome, nomePais1, cidade2.nome, nomePais2);
    } else {
        printf("%s (%s) tem a mesma área que %s (%s)\n",
               cidade1.nome, nomePais1, cidade2.nome, nomePais2);
    }

    // Comparar PIB
    if (cidade1.pib > cidade2.pib) {
        printf("%s (%s) tem PIB maior que %s (%s)\n",
               cidade1.nome, nomePais1, cidade2.nome, nomePais2);
    } else if (cidade1.pib < cidade2.pib) {
        printf("%s (%s) tem PIB menor que %s (%s)\n",
               cidade1.nome, nomePais1, cidade2.nome, nomePais2);
    } else {
        printf("%s (%s) tem o mesmo PIB que %s (%s)\n",
               cidade1.nome, nomePais1, cidade2.nome, nomePais2);
    }
}

int main() {
    Pais paises[NUM_PAISES] = {
        {"Brasil", {
            {"São Paulo", 12325232, 1521.11, 678.90, "Avenida Paulista, Parque Ibirapuera"},
            {"Rio de Janeiro", 6747815, 1200.27, 345.67, "Cristo Redentor, Pão de Açúcar"},
            {"Belo Horizonte", 2521564, 331.40, 123.45, "Praça da Liberdade, Mercado Central"},
            {"Salvador", 2872347, 693.80, 234.56, "Pelourinho, Farol da Barra"}
        }},
        {"Estados Unidos", {
            {"Nova York", 8419600, 783.84, 1777.00, "Estátua da Liberdade, Central Park"},
            {"Los Angeles", 39776830, 1302.15, 1046.00, "Hollywood, Santa Monica"},
            {"Chicago", 2716000, 606.42, 689.00, "Millennium Park, Willis Tower"},
            {"Houston", 2325502, 1651.00, 503.00, "Space Center Houston, Museum District"}
        }},
        {"Japão", {
            {"Tóquio", 13929286, 2187.66, 1877.00, "Senso-ji, Shibuya Crossing"},
            {"Osaka", 2691000, 223.00, 681.00, "Castelo de Osaka, Dotonbori"},
            {"Quioto", 1475000, 827.90, 321.00, "Fushimi Inari, Kinkaku-ji"},
            {"Yokohama", 3726167, 437.38, 456.00, "Minato Mirai, Chinatown"}
        }},
        {"França", {
            {"Paris", 2140526, 105.40, 850.00, "Torre Eiffel, Louvre"},
            {"Marselha", 870018, 240.62, 123.00, "Vieux-Port, Notre-Dame de la Garde"},
            {"Lyon", 515695, 47.87, 234.00, "Basílica de Fourvière, Vieux Lyon"},
            {"Toulouse", 479553, 118.30, 345.00, "Capitole de Toulouse, Cité de l'Espace"}
        }},
        {"Alemanha", {
            {"Berlim", 3664088, 891.68, 789.00, "Portão de Brandemburgo, Muro de Berlim"},
            {"Hamburgo", 1841179, 755.22, 456.00, "Elbphilharmonie, Speicherstadt"},
            {"Munique", 1488202, 310.43, 567.00, "Marienplatz, Oktoberfest"},
            {"Colônia", 1085664, 405.02, 345.00, "Catedral de Colônia, Museu Ludwig"}
        }},
        {"China", {
            {"Xangai", 24870895, 6340.50, 1234.00, "Bund, Jardim Yuyuan"},
            {"Pequim", 21710000, 16410.54, 987.00, "Cidade Proibida, Grande Muralha"},
            {"Guangzhou", 14904400, 7434.40, 876.00, "Canton Tower, Ilha Shamian"},
            {"Shenzhen", 12528300, 1997.47, 765.00, "Window of the World, Dafen Village"}
        }},
        {"Índia", {
            {"Mumbai", 12442373, 603.40, 987.00, "Gateway of India, Marine Drive"},
            {"Delhi", 11007835, 1484.00, 876.00, "Templo de Akshardham, Qutub Minar"},
            {"Bangalore", 8443675, 709.50, 765.00, "Palácio de Bangalore, Lalbagh"},
            {"Hyderabad", 6993262, 650.00, 654.00, "Charminar, Golconda Fort"}
        }},
        {"Rússia", {
            {"Moscou", 12615882, 2511.00, 987.00, "Praça Vermelha, Kremlin"},
            {"São Petersburgo", 5398064, 1439.00, 876.00, "Museu Hermitage, Catedral de São Isaac"},
            {"Novosibirsk", 1625631, 502.70, 765.00, "Teatro de Ópera e Balé, Zoológico de Novosibirsk"},
            {"Ekaterinburg", 1493749, 468.00, 654.00, "Igreja sobre o Sangue, Torre Vysotsky"}
        }}
    };

    // Exibir todos os países e cidades
    for (int i = 0; i < NUM_PAISES; i++) {
        exibir_pais(paises[i]);
    }

    // Seleção das cidades
    int pais1, cidade1, pais2, cidade2;

    printf("\nEscolha a primeira cidade:\n");
    printf("País (0 a %d): ", NUM_PAISES - 1);
    scanf("%d", &pais1);
    printf("Cidade (0 a %d): ", NUM_CIDADES - 1);
    scanf("%d", &cidade1);

    printf("\nEscolha a segunda cidade:\n");
    printf("País (0 a %d): ", NUM_PAISES - 1);
    scanf("%d", &pais2);
    printf("Cidade (0 a %d): ", NUM_CIDADES - 1);
    scanf("%d", &cidade2);

    // Comparar as cidades escolhidas
    printf("\nComparando %s (%s) com %s (%s):\n",
           paises[pais1].cidades[cidade1].nome, paises[pais1].nome,
           paises[pais2].cidades[cidade2].nome, paises[pais2].nome);
    comparar_cidades(paises[pais1].cidades[cidade1], paises[pais2].cidades[cidade2],
                     paises[pais1].nome, paises[pais2].nome);

    return 0;

}
