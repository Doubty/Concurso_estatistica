#include <string> // Incluida para usar o tipo string
using namespace std; // Incluido para usar a forma curta do string 

// Definição dos registros usados
struct horario {
	float hora;
    float minuto;
};

struct questoes {
	int grauDificuldade;
	horario inicio;
	horario fim;
};

struct mediaPart {
	float grauDificuldade;
	horario tempo;
};

struct participante {
	string nome;
	questoes * questPont;

};
// fim da definição dos registros.
// Estar tudo ok, nas funções.
// Protótipos das funções usadas
void gerarTraco(char a, int num); // Função para desenhar as linhas
int operator-(horario a, horario b); // Função para subtrair variáveis do tipo horario
istream & operator>>(istream&, horario&); // Função para ler a partir do cin o tipo horario
ostream & operator<<(ostream&, horario);  // Função para imprimir a partir do cout o tipo horario
void gerarResumoParticipante(questoes a[], int qtdQ); // Função usada para gerar o resumo por participante
mediaPart gerarMedia(questoes a[], int tam, int indice, int passo); // Função usada para gerar a média dos participantes por questão
