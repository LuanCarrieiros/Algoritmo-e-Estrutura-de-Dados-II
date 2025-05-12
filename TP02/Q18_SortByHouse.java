import helpers.Carregador;
import helpers.Personagem;
import helpers.SortUtils;
import java.io.IOException;
import java.util.List;
import java.util.Scanner;

public class Q18_SortByHouse {
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

        // Ordena por casa completo (quicksort parcial com k=size)
        SortUtils.quickSortPartial(subset, subset.size());

        // Imprime ordenado
        subset.forEach(Personagem::imprimir);
        sc.close();
    }
}
