import helpers.Carregador;
import helpers.Personagem;
import java.io.IOException;
import java.util.List;
import java.util.Scanner;
import helpers.SearchUtils;

public class Q01_SearchById {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        List<Personagem> personagens = Carregador.carregar("tmp/characters.csv");
        SearchUtils.searchById(personagens, sc);
        sc.close();
    }
}
