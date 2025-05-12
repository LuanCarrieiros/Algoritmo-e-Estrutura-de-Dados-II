import helpers.Carregador;
import helpers.Personagem;
import helpers.SortUtils;

import java.io.IOException;
import java.util.List;
import java.util.Scanner;

public class Q16_SortByDateOfBirthParcial {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        List<Personagem> personagens = Carregador.carregar("tmp/characters.csv");

        // Ler IDs até "FIM"
        List<Personagem> subset = new java.util.ArrayList<>();
        String line;
        while (!(line = sc.nextLine()).equals("FIM")) {
            for (Personagem p : personagens) {
                if (p.getId().equals(line)) {
                    subset.add(p);
                    break;
                }
            }
        }

        // Ordena apenas os top 10 por data de nascimento (insertion sort parcial)
        SortUtils.insercaoParcial(subset, 10);

        // Imprime os 10 primeiros ordenados
        subset.stream()
                .limit(10)
                .forEach(Personagem::imprimir);

        sc.close();
    }
}
