package helpers;

import java.io.IOException;
import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Utilitários para busca de personagens e registro de estatísticas (Q01 e Q03).
 */
public class SearchUtils {

    /**
     * Q01: busca por ID até ler "FIM".
     */
    public static void searchById(List<Personagem> personagens, Scanner sc) {
        String id;
        while (!(id = sc.nextLine()).equals("FIM")) {
            for (Personagem p : personagens) {
                if (p.getId().equals(id)) {
                    p.imprimir();
                    break;
                }
            }
        }
    }

    /**
     * Q03: busca por nome até ler "FIM" e registra tempo/comparações.
     */
    public static void searchByName(List<Personagem> personagens, Scanner sc) throws IOException {
        List<String> ids = new ArrayList<>();
        String line;
        while (!(line = sc.nextLine()).equals("FIM")) {
            ids.add(line);
        }

        Timer t = new Timer("816676_sequencial.txt");
        String query;
        while (!(query = sc.nextLine()).equals("FIM")) {
            boolean found = false;
            for (Personagem p : personagens) {
                t.comparacao();
                if (p.getName().equals(query) || p.getAlternate_names().contains(query)) {
                    found = ids.contains(p.getId());
                    break;
                }
            }
            System.out.println(found ? "SIM" : "NAO");
        }
        t.logAndReset();
    }
}
