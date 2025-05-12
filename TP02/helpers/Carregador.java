package helpers;

import java.io.*;
import java.nio.charset.Charset;
import java.util.*;

public class Carregador {
    public static List<Personagem> carregar(String caminho) throws IOException {
        List<Personagem> list = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(
                new FileReader(caminho, Charset.forName("UTF-8")))) {
            br.readLine(); // cabeçalho
            String line;
            while ((line = br.readLine()) != null) {
                Personagem p = new Personagem();
                p.ler(line);
                list.add(p);
            }
        }
        return list;
    }
}