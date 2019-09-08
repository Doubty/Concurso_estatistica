#include <iostream>  // Incluido para usar as fun��es da biblioteca iostream
#include <string>   //  Incluida para usar o tipo string
#include "concurso.h"; // Incluido para usar as defini��es dos registros e fun��es
#include <iomanip>  // Incluido para usar as fun��es setfill e setw
using namespace std;  // Incluido para abreviar o cin e cout std::cout

int main() {

	
	// Vari�veis para armazenar o n�mero de partipantes e quest�es respectivamente.
	int numPart = 0;
	int numQuest = 0;
	// fun��o para gerar a linha
	gerarTraco('*', 43);

	cout << endl;
	cout << "Concurso de programacao" << endl;
	cout << endl;
	cout << "Qual o numero de participantes? ";
	cin >> numPart;
	// recebendo o n�mero de participantes.
	cout << "Qual o numero de questoes? ";
	cin >> numQuest;
	// recebendo o n�mero de quest�es.
	cout << endl;
	// fun��o para gerar a linha
	gerarTraco('*', 43);
	cout << endl;

	questoes * vetorQuestoes = new questoes[numPart*numQuest]; 
	// cria��o do vetor din�mico de registros para as quest�es
	participante * vetorParticpante = new participante[numPart];
	// cria��o do vetor din�mico de registros para os particpantes
	cout << endl;

	// Vari�vel para fazer a contagem do vetorQuestoes
	int cont = 0;

	/* Loop para receber os dados enquanto o vetorQuestoes n�o for preenchido
	os outros loops s�o usados para receber o participante e pegar as respostas 
	das quest�es
	*/
	while (cont<numPart*numQuest) {
		
		// Loop para o controle e receber os dados dos participantes
		for (int i = 0; i < numPart; i++) {
			/* Aqui � onde o ponteiro do vetorParticipante aponta para o endere�o de cada quest�o 
			que os participantes come�am.
			*/
		 	(vetorParticpante + i)->questPont = (vetorQuestoes + cont);
			// Fun��o para gerar um traco de acordo com o caractere e tamanho informado
			gerarTraco('-', 13);
			cout << endl;
			// Aqui h� a leitura dos nomes dos participantes para o vetorParticipante
			cout << "Participante: ";
			cin >> (vetorParticpante + i)->nome;
			gerarTraco('-', 13);
			cout << endl;

			// Loop para o controle e receber os dados das quest�es
			for (int j = 0; j < numQuest; j++) {
				char letra = 'A';
				letra += j;
				cout << "Questao " << letra << endl;
				cout << "\tDificuldade: ";
				cin >> (vetorQuestoes + cont)->grauDificuldade;
				cout << "\tInicio: ";
				cin >> (vetorQuestoes + cont)->inicio;
				cout << "\tFim: ";
				cin >> (vetorQuestoes + cont)->fim;
				cont++;
			}
			
			gerarTraco('-', 13);
			cout << endl;
			cout << endl;
			
		}

	}
	// formata�ao incluindo linhas e quebra de linhas
	gerarTraco('*', 43);
	cout << endl;
	gerarTraco('-', 23);
	cout << endl;
	cout << "Resumo por Participante" << endl;
	gerarTraco('-', 23);
	cout << endl;
	// Loop pra realizar o resumo das quest�es de cada participante apartir da fun��o gerarResumoParticipante()
	for (int i = 0; i < numPart; i++) {
		cout << (vetorParticpante + i)->nome << ":" << endl;
		gerarResumoParticipante((vetorParticpante + i)->questPont, numQuest);
	}
	gerarTraco('-', 18);
	cout << "\n\n";
	gerarTraco('-', 18);
	cout << endl;
	cout << "Resumo por Questao" << endl;
	gerarTraco('-', 18);
	cout << endl;
	char letra = 'A';
	int i;
	// Loop usado para gerar o resumo por quest�o de cada participante
	for (i=0; i < numQuest; i++) {
		cout << "Questao " << letra << ": "<< endl;
		for (int j = 0; j < numPart;j++) {
			cout << "\t" << (vetorParticpante + j)->nome << " " << "(" << (vetorParticpante + j)->questPont[i].grauDificuldade << ")" << " " <<
				(vetorParticpante + j)->questPont[i].inicio << " as " << (vetorParticpante + j)->questPont[i].fim
				<< " (" << (vetorParticpante + j)->questPont[i].fim - (vetorParticpante + j)->questPont[i].inicio << " min)" << endl;
		}
		letra++;
	}
	// formata�ao para gerar linhas e quebra de linhas
	gerarTraco('-', 18);
	cout << "\n\n";
	gerarTraco('-', 12);
	cout << endl;
	// Aqui ser� gerado as estat�sticas
	cout << "Estatisticas" << endl;
	gerarTraco('-', 12);
	cout << endl;
	

	cout.setf(ios::fixed); // Essa fun��o foi usada para colocar as m�dias de dificuldade e tempo com precis�o de 2 casas." cout << fixed" n�o tava dando certo.
	cout.precision(2); // Precis�o de at� 2 casas decimais ap�s a virgula
	letra = 'A';
	// Inicializando as vari�veis com 0 para que n�o ocorra erro com o lixo da mem�ria.
	float mediaConcursoDif = 0;
	float mediaConcursoTempo = 0;

	// loop usado para gerar as estat�sticas
	for (int i = 0; i < numQuest; i++) {
		cout << "Questao " << letra << ": Dificuldade (" << gerarMedia(vetorQuestoes, numPart*numQuest, i, numQuest).grauDificuldade
			<< ") - Tempo (" << gerarMedia(vetorQuestoes, numPart*numQuest, i, numQuest).tempo.minuto << " minutos) " << endl;
		letra++;
		mediaConcursoDif += gerarMedia(vetorQuestoes, numPart*numQuest, i, numQuest).grauDificuldade;
		mediaConcursoTempo += gerarMedia(vetorQuestoes, numPart*numQuest, i, numQuest).tempo.minuto;
		// somat�rio para realizar a estatistica do concurso e depois tirar a m�dia pela divis�o.
	}
	
	mediaConcursoDif /= numPart;
	mediaConcursoTempo /= numPart;
	// Obtendo a estatistica do curso apartir da divis�o pelo n�mero de participantes o somat�rio das m�dias.
	// Estat�stica do concurso
	cout << "Concurso:  Dificuldade (" << mediaConcursoDif << ") - tempo (" << mediaConcursoTempo << " minutos)\n" << endl;
	gerarTraco('*', 53);
	cout << endl;

	delete [] vetorQuestoes; // Liberando a mem�ria alocada pelo vetor de quest�es
	delete [] vetorParticpante; // Liberando a mem�ria alocada pelo vetor de participantes
	// fim do programa :)
	system("pause");
	return 0;
}