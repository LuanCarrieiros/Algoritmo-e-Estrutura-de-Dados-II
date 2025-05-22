package Java;

import Java.helpers.Personagem;
import Java.helpers.Carregador;

import java.io.IOException;
import java.util.List;
import java.util.Scanner;
import Java.helpers.SearchUtils;

public class Q01_SearchById {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        List<Personagem> personagens = Carregador.carregar("java/tmp/characters.csv");
        SearchUtils.searchById(personagens, sc);
        sc.close();
    }
}
