#include <string> // Incluida para usar o tipo string
using namespace std; // Incluido para usar a forma curta do string 

// Defini��o dos registros usados
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
// fim da defini��o dos registros.
// Estar tudo ok, nas fun��es.
// Prot�tipos das fun��es usadas
void gerarTraco(char a, int num); // Fun��o para desenhar as linhas
int operator-(horario a, horario b); // Fun��o para subtrair vari�veis do tipo horario
istream & operator>>(istream&, horario&); // Fun��o para ler a partir do cin o tipo horario
ostream & operator<<(ostream&, horario);  // Fun��o para imprimir a partir do cout o tipo horario
void gerarResumoParticipante(questoes a[], int qtdQ); // Fun��o usada para gerar o resumo por participante
mediaPart gerarMedia(questoes a[], int tam, int indice, int passo); // Fun��o usada para gerar a m�dia dos participantes por quest�o
