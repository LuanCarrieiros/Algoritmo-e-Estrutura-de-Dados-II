import helpers.Carregador;
import helpers.Personagem;
import helpers.SortUtils;

import java.io.IOException;
import java.util.List;
import java.util.Scanner;

public class Q15_SortByNameParcial {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        List<Personagem> personagens = Carregador.carregar("tmp/characters.csv");

        // Ler IDs até "FIM"
        List<String> ids = new java.util.ArrayList<>();
        String line;
        while (!(line = sc.nextLine()).equals("FIM")) {
            ids.add(line);
        }

        // Extrair nomes
        String[] nomes = ids.stream()
            .map(id -> personagemNameById(personagens, id))
            .toArray(String[]::new);

        // Ordena apenas top 10 nomes (seleção parcial)
        SortUtils.selecaoParcial(nomes, 10);

        // Imprime os 10 primeiros
        for (int i = 0; i < Math.min(10, nomes.length); i++) {
            String nome = nomes[i];
            personagens.stream()
                .filter(p -> p.getName().equals(nome))
                .findFirst()
                .ifPresent(Personagem::imprimir);
        }
        sc.close();
    }

    private static String personagemNameById(List<Personagem> list, String id) {
        return list.stream()
                   .filter(p -> p.getId().equals(id))
                   .findFirst()
                   .map(Personagem::getName)
                   .orElse("");
    }
}
