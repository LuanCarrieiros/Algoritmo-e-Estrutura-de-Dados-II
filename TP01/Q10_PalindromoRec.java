import java.util.*;

public class Q10_PalindromoRec {
    public static void main(String[] args) {
        Scanner scanf = new Scanner(System.in);
        String str = scanf.nextLine();

        // loop para continuar recebendo strings ate que a palavra "FIM" seja digitada,
        // é feito um while ao inves de um do while para evitar que o programa imprima
        // mais uma linha, informando se é palindromo ou nao, após digitar "FIM"
        while (!str.equals("FIM")) {
            if (isPalindrome(str, 0, str.length() - 1)) 
            {
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }
            str = scanf.nextLine();
        }
        scanf.close();
    }

    /**
     * Verifica se uma string é palíndromo de forma recursiva
     * @param str string a ser verificada
     * @param start índice inicial
     * @param end índice final
     * @return true se for palíndromo, false caso contrário
     */
    public static boolean isPalindrome(String str, int start, int end) {
        // Caso base: se start for maior ou igual a end, significa que a string foi totalmente verificada
        if (start >= end) {
            return true;
        }

        // Verifica se os caracteres nas posições start e end são iguais
        if (str.charAt(start) != str.charAt(end)) 
        {
            return false;
        }

        // Chamada recursiva: verifica os caracteres seguintes
        return isPalindrome(str, start + 1, end - 1);
    }
}
