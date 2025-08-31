import java.util.*;

public class Q01_Palindromo {
    public static void main(String[] args) 
    {   
        Scanner scanf = new Scanner(System.in);
        String str = scanf.nextLine();
        
        while (!str.equals("FIM"))
        {   
            if(isPalindrome(str))
            {
                System.out.println("SIM");
            } else 
            {
                System.out.println("NAO");
            }
            str = scanf.nextLine();
        }
        
        scanf.close();
    }

    /**
     * Verifica se uma string é palíndromo
     * @param str string a ser verificada
     * @return true se for palíndromo, false caso contrário
     */ 
    public static boolean isPalindrome (String str) 
    {
        int length = str.length();
        // loop para analisar se a string é um palindromo
        for (int i = 0; i < length / 2; i++)
        {
            if (str.charAt(i) != str.charAt(length - i - 1)) // // se a posicao index for diferente do tamanho - index - 1, o laço contato termina e retorna falso
            {
                return false;
            }
        }

        return true;
    }
}