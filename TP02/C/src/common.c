#include "../include/common.h"

// --------------------------- CLASSE TIMER ---------------------------
void TimerStart(Timer* timer) {
	timer->startTime = clock();
}

void TimerStop(Timer* timer) {
	timer->endTime = clock();
}

double TimerTime(Timer* timer) {
	timer->totalTime = ((double)(timer->endTime - timer->startTime)) / CLOCKS_PER_SEC;
    timer->totalTime *= 1000; // Converte para milissegundos, se necessário para a leitura do log
	return timer->totalTime;
}

Timer newTimer() {
	// ATENÇÃO: Corrigido para inicializar todos os campos e evitar o warning "missing initializer"
	Timer timer = { .startTime = 0, .endTime = 0, .totalTime = 0,
                    .Start = TimerStart, .Stop = TimerStop, .Time = TimerTime };
	return timer;
}

void RegistroPesquisa(literal fileName, Timer timer, Log log) {
	FILE* file = fopen(fileName, "w");
	if (file == NULL) {
        perror("Erro ao abrir o arquivo de log de pesquisa");
        return;
    }

	fprintf(file, "Matrícula: 816676\t");
	fprintf(file, "Tempo de execução: %fs\t", timer.Time(&timer) / 1000.0); // Converte de ms para s para o log
	fprintf(file, "Número de comparações: %d", log.comparacoes);

	fclose(file);
}

void RegistroOrdenacao(literal fileName, Timer timer, Log log) {
	FILE* file = fopen(fileName, "w");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo de log de ordenação");
        return;
    }

	fprintf(file, "Matrícula: 816676\t");
	fprintf(file, "Tempo de execução: %fs\t", timer.Time(&timer) / 1000.0); // Converte de ms para s para o log
	fprintf(file, "Número de comparações: %d\t", log.comparacoes);
	fprintf(file, "Número de movimentações: %d", log.movimentacoes);
	fclose(file);
}

Log newLog() {
	// ATENÇÃO: Corrigido para inicializar todos os campos e evitar o warning "missing initializer"
	Log log = { .comparacoes = 0, .movimentacoes = 0,
                .RegistroPesquisa = RegistroPesquisa, .RegistroOrdenacao = RegistroOrdenacao };
	return log;
}