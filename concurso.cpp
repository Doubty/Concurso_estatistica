#include <iostream>   // Incluido para usar as fun��es da biblioteca iostream
#include "concurso.h" // Incluido para usar as defini��es dos registros
#include <iomanip>     // Incluido para usar as fun��es setfill e setw
using namespace std;  // Incluido para abreviar o cin e cout

/* Fun��o para desenhar uma linha, recebe o caractere que deseja
para fazer a linha e a quantidade que ser� o tamanho */

void gerarTraco(char a, int num) {
	for (int i = 0; i < num; ++i) {
		cout << a;
	}

}

// Fun��o usada para realizar a subtra��o das vari�veis do tipo horario e retornar o resultado do tempo em minutos.
int operator-(horario a, horario b) {
	int hora = a.hora - b.hora;
	int minuto = a.minuto - b.minuto;
	return hora * 60 + minuto;
	// retornando a quantidade de minutos
}

// Fun��o para ler a partir do cin o tipo horario
istream & operator>>(istream& is, horario& c)
{
	is >> c.hora;
	char str;
	// vari�vel criada para ler o ":"
	is >> str;
	// realiza a leitura dos ":"
	is >> c.minuto;
	return is;
}

// Fun��o para imprimir a partir do cout o tipo horario
ostream & operator<<(ostream& os, horario c)
{
	// a fun��o setfill � usada para colocar o caractere "0" em um n�mero que esteja com apenas uma casa, 
	// isso � limitado pela setw onde � colocado at� preencher 2 casas.
	os << setfill('0') << setw(2);
	os << c.hora;
	cout <<":";
	os << setfill('0') << setw(2);
	os << c.minuto;
	os << setfill(' ') << setw(0);
	
	return os;
}
// Fun��o para gerar o resumo de cada quest�o do participante. Mostrando todos os dados das quest�es.
void gerarResumoParticipante(questoes  a[], int qtdQ) {
	char letra = 'A';
	for (int i = 0; i < qtdQ; i++) {
		
		cout << "\t" << letra << " " << "(" << (a+i)->grauDificuldade << ")" << " " << (a + i)->inicio << " as " << (a + i)->fim 
		<< " ("	<< (a + i)->fim - (a + i)->inicio << " min)" << endl;
		letra++;
	}
}

// Fun��o para gerar a m�dia de cada quest�o. Realizando a m�dia de dificuldade e tempo.
mediaPart gerarMedia(questoes a[], int tam, int indice, int passo) {
	mediaPart media;
	// Inicializei as vari�veis do registro media com "0" para n�o come�ar com lixo da mem�ria e dar erro.
	media.grauDificuldade = 0;
	media.tempo.hora = 0;
	media.tempo.minuto = 0;
	// loop para realizar o somat�rio de grau de dificuldade, hora e minuto do participante.
	for (int i = indice; i < tam;i+=passo) {
		media.grauDificuldade += (a + i)->grauDificuldade;
		media.tempo.hora += (a + i)->fim.hora - (a + i)->inicio.hora;
		media.tempo.minuto += (a + i)->fim.minuto - (a + i)->inicio.minuto;
	}

	// Gerando as m�dias apartir da divis�o dos somat�rios pela quantidade de quest�es do tipo A por exemplo, que no caso, � igual ao n�mero do passo
	media.grauDificuldade = media.grauDificuldade /passo;
	media.tempo.hora = media.tempo.hora / passo;
	media.tempo.minuto = media.tempo.minuto / passo;
	media.tempo.minuto += media.tempo.hora*60; // retornando o tempo total em minutos
	// Retorno do registro media.
	return media;
	
}




