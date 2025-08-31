import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;

class Q07_html {

    // Função que procura uma string dentro de outra string
    public static int howMuchString(String search, String line) {
        int amount = 0;
        if (search != null && line != null && search.length() > 0) {
            int lengthLine = line.length();
            int lengthSearch = search.length();

            for (int i = 0; i <= lengthLine - lengthSearch; i++) {
                boolean isPresent = true;
                for (int j = 0; j < lengthSearch && isPresent; j++) {
                    if (search.charAt(j) != line.charAt(i + j)) {
                        isPresent = false;
                    }
                }
                if (isPresent) {
                    amount++;
                }
            }
        }
        return amount;
    }

    // Função que retorna a igualdade entre duas strings
    public static boolean equals(String word1, String word2) {
        boolean result = true;
        int length = word1.length();
        if (length != word2.length()) {
            result = false;
        } else {

            for (int i = 0; i < length && result; i++) {
                result = (word1.charAt(i) == word2.charAt(i));
            }
        }
        return (result);
    }

    // Função que retorna o quanto um simbolo está presente
    public static int howMuchChar(char symbol, String line) {
        int amount = 0;
        if (line != null) {
            int length = line.length();
            for (int i = 0; i < length; i++) {
                if (line.charAt(i) == symbol) {
                    amount++;
                }
            }
        }

        return (amount);
    }

    /**
     * Verifica se é consoante ASCII (regra 12 do enunciado)
     * Considera apenas caracteres ASCII entre 'a'-'z' e 'A'-'Z'
     */
    public static boolean isConsonantASCII(char letter) {
        return ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) &&
               !(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' ||
                 letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U');
    }

    /**
     * Conta consoantes ASCII conforme regra 12 do enunciado
     */
    public static int howMuchConsonants(String line) {
        int amount = 0;
        if (line != null) {
            int length = line.length();
            for (int i = 0; i < length; i++) {
                if (isConsonantASCII(line.charAt(i))) {
                    amount++;
                }
            }
        }
        return amount;
    }

    @SuppressWarnings("deprecation")
    public static String getHtml(String endereco) {
        URL url;
        InputStream is = null;
        BufferedReader br;
        String resp = "";
        int lineCount = 0;
        final int MAX_LINES = 1000; // Limit to prevent infinite reading

        try {
            // Adiciona protocolo se não existir
            if (!endereco.startsWith("http://") && !endereco.startsWith("https://")) {
                endereco = "http://" + endereco;
            }
            
            url = new URL(endereco);
            is = url.openStream(); // throws an IOException
            br = new BufferedReader(new InputStreamReader(is));

            String line;
            while ((line = br.readLine()) != null && lineCount < MAX_LINES) {
                resp += line + "\n";
                lineCount++;
            }
            
            br.close();
        } catch (Exception e) {
            // Qualquer erro - retorna string vazia para não quebrar o processamento
            return "";
        }

        try {
            if (is != null) {
                is.close();
            }
        } catch (IOException ioe) {
            // nothing to see here
        }

        return resp;
    }

    public static void main(String[] args) {
        java.util.Scanner scanf = new java.util.Scanner(System.in);
        String linha = scanf.nextLine();
        String html;

        // letras acentuadas
        char a_acute = (char) 225; // á
        char e_acute = (char) 233; // é
        char i_acute = (char) 237; // í
        char o_acute = (char) 243; // ó
        char u_acute = (char) 250; // ú
        char a_grave = (char) 224; // à
        char e_grave = (char) 232; // è
        char i_grave = (char) 236; // ì
        char o_grave = (char) 242; // ò
        char u_grave = (char) 249; // ù
        char a_tilde = (char) 227; // ã
        char o_tilde = (char) 245; // õ
        char a_circumflex = (char) 226; // â
        char e_circumflex = (char) 234; // ê
        char i_circumflex = (char) 238; // î
        char o_circumflex = (char) 244; // ô
        char u_circumflex = (char) 251; // û

        while (!equals(linha, "FIM")) {
            // Parse da linha: primeira palavra é endereço, resto é nome da página
            int firstSpace = linha.indexOf(' ');
            String address = (firstSpace != -1) ? linha.substring(0, firstSpace) : linha;
            String pageName = (firstSpace != -1) ? linha.substring(firstSpace + 1) : "";
            
            html = getHtml(address);
            System.out.println("a(" + howMuchChar('a', html) + ") e(" + howMuchChar('e', html) + ") i("
                    + howMuchChar('i', html) + ") o(" + howMuchChar('o', html) + ") u("
                    + howMuchChar('u', html) + ") " + a_acute + "(" + howMuchChar(a_acute, html) + ") "
                    + e_acute + "(" + howMuchChar(e_acute, html) + ") " + i_acute + "("
                    + howMuchChar(i_acute, html) + ") " + o_acute + "(" + howMuchChar(o_acute, html)
                    + ") " + u_acute + "(" + howMuchChar(u_acute, html) + ") " + a_grave + "("
                    + howMuchChar(a_grave, html) + ") " + e_grave + "(" + howMuchChar(e_grave, html)
                    + ") " + i_grave + "(" + howMuchChar(i_grave, html) + ") " + o_grave + "("
                    + howMuchChar(o_grave, html) + ") " + u_grave + "(" + howMuchChar(u_grave, html)
                    + ") " + a_tilde + "(" + howMuchChar(a_tilde, html) + ") " + o_tilde + "("
                    + howMuchChar(o_tilde, html) + ") " + a_circumflex + "("
                    + howMuchChar(a_circumflex, html) + ") " + e_circumflex + "("
                    + howMuchChar(e_circumflex, html) + ") " + i_circumflex + "("
                    + howMuchChar(i_circumflex, html) + ") " + o_circumflex + "("
                    + howMuchChar(o_circumflex, html) + ") " + u_circumflex + "("
                    + howMuchChar(u_circumflex, html) + ") consoante(" + howMuchConsonants(html)
                    + ") <br>(" + howMuchString("<br>", html) + ") <table>("
                    + howMuchString("<table>", html) + ") " + pageName);

            linha = scanf.nextLine();
        }
        
        scanf.close();
    }
}