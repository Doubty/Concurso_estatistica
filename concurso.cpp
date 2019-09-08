#include <iostream>   // Incluido para usar as funções da biblioteca iostream
#include "concurso.h" // Incluido para usar as definições dos registros
#include <iomanip>     // Incluido para usar as funções setfill e setw
using namespace std;  // Incluido para abreviar o cin e cout

/* Função para desenhar uma linha, recebe o caractere que deseja
para fazer a linha e a quantidade que será o tamanho */

void gerarTraco(char a, int num) {
	for (int i = 0; i < num; ++i) {
		cout << a;
	}

}

// Função usada para realizar a subtração das variáveis do tipo horario e retornar o resultado do tempo em minutos.
int operator-(horario a, horario b) {
	int hora = a.hora - b.hora;
	int minuto = a.minuto - b.minuto;
	return hora * 60 + minuto;
	// retornando a quantidade de minutos
}

// Função para ler a partir do cin o tipo horario
istream & operator>>(istream& is, horario& c)
{
	is >> c.hora;
	char str;
	// variável criada para ler o ":"
	is >> str;
	// realiza a leitura dos ":"
	is >> c.minuto;
	return is;
}

// Função para imprimir a partir do cout o tipo horario
ostream & operator<<(ostream& os, horario c)
{
	// a função setfill é usada para colocar o caractere "0" em um número que esteja com apenas uma casa, 
	// isso é limitado pela setw onde é colocado até preencher 2 casas.
	os << setfill('0') << setw(2);
	os << c.hora;
	cout <<":";
	os << setfill('0') << setw(2);
	os << c.minuto;
	os << setfill(' ') << setw(0);
	
	return os;
}
// Função para gerar o resumo de cada questão do participante. Mostrando todos os dados das questões.
void gerarResumoParticipante(questoes  a[], int qtdQ) {
	char letra = 'A';
	for (int i = 0; i < qtdQ; i++) {
		
		cout << "\t" << letra << " " << "(" << (a+i)->grauDificuldade << ")" << " " << (a + i)->inicio << " as " << (a + i)->fim 
		<< " ("	<< (a + i)->fim - (a + i)->inicio << " min)" << endl;
		letra++;
	}
}

// Função para gerar a média de cada questão. Realizando a média de dificuldade e tempo.
mediaPart gerarMedia(questoes a[], int tam, int indice, int passo) {
	mediaPart media;
	// Inicializei as variáveis do registro media com "0" para não começar com lixo da memória e dar erro.
	media.grauDificuldade = 0;
	media.tempo.hora = 0;
	media.tempo.minuto = 0;
	// loop para realizar o somatório de grau de dificuldade, hora e minuto do participante.
	for (int i = indice; i < tam;i+=passo) {
		media.grauDificuldade += (a + i)->grauDificuldade;
		media.tempo.hora += (a + i)->fim.hora - (a + i)->inicio.hora;
		media.tempo.minuto += (a + i)->fim.minuto - (a + i)->inicio.minuto;
	}

	// Gerando as médias apartir da divisão dos somatórios pela quantidade de questões do tipo A por exemplo, que no caso, é igual ao número do passo
	media.grauDificuldade = media.grauDificuldade /passo;
	media.tempo.hora = media.tempo.hora / passo;
	media.tempo.minuto = media.tempo.minuto / passo;
	media.tempo.minuto += media.tempo.hora*60; // retornando o tempo total em minutos
	// Retorno do registro media.
	return media;
	
}




