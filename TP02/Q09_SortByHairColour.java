import helpers.Carregador;
import helpers.Personagem;
import java.io.IOException;
import java.util.List;
import java.util.Scanner;
import helpers.SortUtils;

public class Q09_SortByHairColour {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        List<Personagem> personagens = Carregador.carregar("tmp/characters.csv");

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
        SortUtils.heapSort(subset);
        subset.forEach(Personagem::imprimir);
        sc.close();
    }
}
