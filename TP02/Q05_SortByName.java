import helpers.Carregador;
import helpers.Personagem;
import java.io.IOException;
import java.util.List;
import java.util.Scanner;
import helpers.SortUtils;

public class Q05_SortByName {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        List<Personagem> personagens = Carregador.carregar("tmp/characters.csv");

        // Ler IDs
        List<String> ids = new java.util.ArrayList<>();
        String line;
        while (!(line = sc.nextLine()).equals("FIM")) {
            ids.add(line);
        }
        // Extrair nomes
        String[] nomes = new String[ids.size()];
        for (int i = 0; i < ids.size(); i++) {
            for (Personagem p : personagens) {
                if (p.getId().equals(ids.get(i))) {
                    nomes[i] = p.getName();
                    break;
                }
            }
        }
        SortUtils.selecao(nomes);
        // Imprimir ordenado
        for (String nome : nomes) {
            for (Personagem p : personagens) {
                if (p.getName().equals(nome)) {
                    p.imprimir();
                    break;
                }
            }
        }
        sc.close();
    }
}
