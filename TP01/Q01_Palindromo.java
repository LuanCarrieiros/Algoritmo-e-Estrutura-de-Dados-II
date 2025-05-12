import java.util.*;

public class Q01_Palindromo {
    public static void main(String[] args) 
    {   
       
        Scanner scanf = new Scanner(System.in);
        // leitura da entrada
        String str = scanf.nextLine();
        
        // loop para continuar recebendo strings ate que a palavra "FIM" seja digitada, é feito um while ao inves de um do while para evitar que o programa imprima mais uma linha, informando se é palindromo ou nao, após digitar "FIM"
        while (!str.equals("FIM"))
        {   
            // condicional para testar se o resultado foi verdadeiro ou falso
            if(isPalindrome(str))
            {
                System.out.println("SIM");
            } else 
            {
                System.out.println("NAO");
            }
            // releitura para continuar analisando novas entradas
            str = scanf.nextLine();
        }
        scanf.close();
    }

    // método booleano que retorna verdadeiro ou falso após analisar a string que recebeu por parametro 
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