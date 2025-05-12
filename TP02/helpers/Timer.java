package helpers;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * Timer para contagem de comparações, movimentações e tempo de execução (precisão de microssegundos).
 *
 * Os arquivos de log serão salvos na pasta "logs/" do projeto.
 */
public class Timer {
    private long startTime;
    private int comparacoes;
    private int movimentacoes;
    private final String logFileName;

    public Timer(String logFileName) {
        this.logFileName = logFileName;
        this.startTime = System.nanoTime();
        this.comparacoes = 0;
        this.movimentacoes = 0;
    }

    public void comparacao() {
        comparacoes++;
    }

    public void movimentacao(int count) {
        movimentacoes += count;
    }

    public void logAndReset() {
        long elapsedNanos = System.nanoTime() - startTime;
        double elapsedSeconds = elapsedNanos / 1_000_000_000.0;

        // Garante que a pasta de logs exista
        File logsDir = new File("logs");
        if (!logsDir.exists()) {
            logsDir.mkdirs();
        }

        String fullPath = "logs/" + logFileName;
        try (PrintWriter writer = new PrintWriter(new FileWriter(fullPath))) {
            writer.printf(
                "Matricula: 816676\tTempo de execucao: %.6f\tNumero de comparacoes: %d\tNumero de movimentacoes: %d%n",
                elapsedSeconds, comparacoes, movimentacoes
            );
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
