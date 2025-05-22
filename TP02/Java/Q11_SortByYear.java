package Java;
import Java.helpers.Carregador;
import Java.helpers.Personagem;
import Java.helpers.SortUtils;

import java.io.IOException;
import java.util.List;
import java.util.Scanner;

public class Q11_SortByYear {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        List<Personagem> personagens = Carregador.carregar("java/tmp/characters.csv");

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

        // Ordena por ano de nascimento usando Counting Sort
        SortUtils.countingSort(subset);

        // Imprime todos os personagens ordenados
        subset.forEach(Personagem::imprimir);
        sc.close();
    }
}