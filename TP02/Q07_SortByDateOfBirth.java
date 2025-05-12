import helpers.Carregador;
import helpers.Personagem;
import helpers.SortUtils;

import java.io.IOException;
import java.util.List;
import java.util.Scanner;

/**
 * Q07: Ordena personagens por data de nascimento usando Insertion Sort.
 */
public class Q07_SortByDateOfBirth {
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

        // Ordena por data de nascimento usando Insertion Sort
        SortUtils.insercao(subset);

        // Imprime personagens ordenados
        subset.forEach(Personagem::imprimir);
        sc.close();
    }
}
