package Java;

import Java.helpers.Carregador;
import Java.helpers.Personagem;
import java.io.IOException;
import java.util.List;
import java.util.Scanner;
import Java.helpers.SearchUtils;

public class Q03_SearchByName {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        List<Personagem> personagens = Carregador.carregar("java/tmp/characters.csv");
        SearchUtils.searchByName(personagens, sc);
        sc.close();
    }
}
