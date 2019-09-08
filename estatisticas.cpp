#include <iostream>  // Incluido para usar as funções da biblioteca iostream
#include <string>   //  Incluida para usar o tipo string
#include "concurso.h"; // Incluido para usar as definições dos registros e funções
#include <iomanip>  // Incluido para usar as funções setfill e setw
using namespace std;  // Incluido para abreviar o cin e cout std::cout

int main() {

	
	// Variáveis para armazenar o número de partipantes e questões respectivamente.
	int numPart = 0;
	int numQuest = 0;
	// função para gerar a linha
	gerarTraco('*', 43);

	cout << endl;
	cout << "Concurso de programacao" << endl;
	cout << endl;
	cout << "Qual o numero de participantes? ";
	cin >> numPart;
	// recebendo o número de participantes.
	cout << "Qual o numero de questoes? ";
	cin >> numQuest;
	// recebendo o número de questões.
	cout << endl;
	// função para gerar a linha
	gerarTraco('*', 43);
	cout << endl;

	questoes * vetorQuestoes = new questoes[numPart*numQuest]; 
	// criação do vetor dinâmico de registros para as questões
	participante * vetorParticpante = new participante[numPart];
	// criação do vetor dinâmico de registros para os particpantes
	cout << endl;

	// Variável para fazer a contagem do vetorQuestoes
	int cont = 0;

	/* Loop para receber os dados enquanto o vetorQuestoes não for preenchido
	os outros loops são usados para receber o participante e pegar as respostas 
	das questões
	*/
	while (cont<numPart*numQuest) {
		
		// Loop para o controle e receber os dados dos participantes
		for (int i = 0; i < numPart; i++) {
			/* Aqui é onde o ponteiro do vetorParticipante aponta para o endereço de cada questão 
			que os participantes começam.
			*/
		 	(vetorParticpante + i)->questPont = (vetorQuestoes + cont);
			// Função para gerar um traco de acordo com o caractere e tamanho informado
			gerarTraco('-', 13);
			cout << endl;
			// Aqui há a leitura dos nomes dos participantes para o vetorParticipante
			cout << "Participante: ";
			cin >> (vetorParticpante + i)->nome;
			gerarTraco('-', 13);
			cout << endl;

			// Loop para o controle e receber os dados das questões
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
	// formataçao incluindo linhas e quebra de linhas
	gerarTraco('*', 43);
	cout << endl;
	gerarTraco('-', 23);
	cout << endl;
	cout << "Resumo por Participante" << endl;
	gerarTraco('-', 23);
	cout << endl;
	// Loop pra realizar o resumo das questões de cada participante apartir da função gerarResumoParticipante()
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
	// Loop usado para gerar o resumo por questão de cada participante
	for (i=0; i < numQuest; i++) {
		cout << "Questao " << letra << ": "<< endl;
		for (int j = 0; j < numPart;j++) {
			cout << "\t" << (vetorParticpante + j)->nome << " " << "(" << (vetorParticpante + j)->questPont[i].grauDificuldade << ")" << " " <<
				(vetorParticpante + j)->questPont[i].inicio << " as " << (vetorParticpante + j)->questPont[i].fim
				<< " (" << (vetorParticpante + j)->questPont[i].fim - (vetorParticpante + j)->questPont[i].inicio << " min)" << endl;
		}
		letra++;
	}
	// formataçao para gerar linhas e quebra de linhas
	gerarTraco('-', 18);
	cout << "\n\n";
	gerarTraco('-', 12);
	cout << endl;
	// Aqui será gerado as estatísticas
	cout << "Estatisticas" << endl;
	gerarTraco('-', 12);
	cout << endl;
	

	cout.setf(ios::fixed); // Essa função foi usada para colocar as médias de dificuldade e tempo com precisão de 2 casas." cout << fixed" não tava dando certo.
	cout.precision(2); // Precisão de até 2 casas decimais após a virgula
	letra = 'A';
	// Inicializando as variáveis com 0 para que não ocorra erro com o lixo da memória.
	float mediaConcursoDif = 0;
	float mediaConcursoTempo = 0;

	// loop usado para gerar as estatísticas
	for (int i = 0; i < numQuest; i++) {
		cout << "Questao " << letra << ": Dificuldade (" << gerarMedia(vetorQuestoes, numPart*numQuest, i, numQuest).grauDificuldade
			<< ") - Tempo (" << gerarMedia(vetorQuestoes, numPart*numQuest, i, numQuest).tempo.minuto << " minutos) " << endl;
		letra++;
		mediaConcursoDif += gerarMedia(vetorQuestoes, numPart*numQuest, i, numQuest).grauDificuldade;
		mediaConcursoTempo += gerarMedia(vetorQuestoes, numPart*numQuest, i, numQuest).tempo.minuto;
		// somatório para realizar a estatistica do concurso e depois tirar a média pela divisão.
	}
	
	mediaConcursoDif /= numPart;
	mediaConcursoTempo /= numPart;
	// Obtendo a estatistica do curso apartir da divisão pelo número de participantes o somatório das médias.
	// Estatística do concurso
	cout << "Concurso:  Dificuldade (" << mediaConcursoDif << ") - tempo (" << mediaConcursoTempo << " minutos)\n" << endl;
	gerarTraco('*', 53);
	cout << endl;

	delete [] vetorQuestoes; // Liberando a memória alocada pelo vetor de questões
	delete [] vetorParticpante; // Liberando a memória alocada pelo vetor de participantes
	// fim do programa :)
	system("pause");
	return 0;
}