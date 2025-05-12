import MyIO.*;

import java.util.*;
class Q07_html {

    // Função que procura uma string dentro de outra string
    public static int howMuchString(String search, String line) {
        int amount = 0;
        if (search != null && line != null) {
            int lengthLine = line.length();
            int lengthSearch = search.length();

            for (int i = 0; i < lengthLine; i++) {
                int j = 0;
                boolean isPresent = true;
                if (search.charAt(j) == line.charAt(i)) {
                    j++;
                    i++;
                    while (j < lengthSearch && i < lengthLine && isPresent) {
                        if (search.charAt(j) != line.charAt(i)) {
                            isPresent = false;
                        }
                        j++;
                        i++;
                    }
                    if (isPresent) {
                        amount++;
                    }
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

    // Função que retorna se o char é consoante minúscula ou não
    public static boolean isConsonantLower(char letter) {
        return (('a' < letter && letter <= 'z') && (letter != 'a' &&
                letter != 'e' && letter != 'i' && letter != 'o' && letter != 'u'
                && letter != '\u00E1' && letter != '\u00FA' && letter != '\u00E9' && letter != '\u00ED'
                && letter != '\u00F3' && letter != '\u00E3' && letter != '\u00F5' && letter != '\u00E2'
                && letter != '\u00EA' && letter != '\u00EE' && letter != '\u00F4' && letter != '\u00FB'
                && letter != '\u00E0' && letter != '\u00E8' && letter != '\u00EC' && letter != '\u00F2'
                && letter != '\u00F9'));
    }

    // Metodo que conta quantas consoantes minusculas estão presentes na linha
    public static int howMuchConsonantsLower(String line) {
        int amount = 0;
        if (line != null) {
            int length = line.length();
            for (int i = 0; i < length; i++) {
                if (isConsonantLower(line.charAt(i))) {
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
        String resp = "", line;

        try {
            url = new URL(endereco);
            is = url.openStream(); // throws an IOException
            br = new BufferedReader(new InputStreamReader(is));

            while ((line = br.readLine()) != null) {
                resp += line + "\n";
            }
        } catch (MalformedURLException mue) {
            mue.printStackTrace();
        } catch (IOException ioe) {
            ioe.printStackTrace();
        }

        try {
            is.close();
        } catch (IOException ioe) {
            // nothing to see here

        }

        return resp;
    }

    public static void main(String[] args) {

        String pageName = MyIO.readLine("");
        String address = MyIO.readString("");
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

        while (!equals(pageName, "FIM")) {
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
                    + howMuchChar(u_circumflex, html) + ") consoante(" + howMuchConsonantsLower(html)
                    + ") <br>(" + howMuchString("<br>", html) + ") <table>("
                    + howMuchString("<table>", html) + ") " + pageName);

            pageName = MyIO.readLine("");
            if (!equals(pageName, "FIM")) {
                address = MyIO.readString("");
            }

        }
    }
}