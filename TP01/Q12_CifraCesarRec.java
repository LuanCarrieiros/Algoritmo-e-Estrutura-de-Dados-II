import java.util.*;

public class Q12_CifraCesarRec 
{
    // Método para criptografar uma mensagem usando a cifra de César
    public static String criptografar(String str, int chave, int index) {
        
        String cifrado = "";

        // Se chegamos ao final da string, retornamos uma string vazia
        if (index == str.length()) {
            return "";
        }

        char caractere = str.charAt(index); // pegando caracter posicao por posicao, recursivamente
        int codigo = (int) caractere; // casting de char para int
    
            // Verifica se o caractere é um caractere imprimível da tabela ASCII
            if (codigo >= 32 && codigo <= 126) {
                // Aplica a cifra de César para o caractere
                codigo = (codigo - 32 + chave) % 95 + 32;
                cifrado += (char) codigo;
            } else {
                // Caso o caractere não seja um caractere imprimível, mantém o mesmo
                cifrado += caractere;
            }

        // Concatena o caractere cifrado com o resultado da criptografia do restante da string
        return cifrado + criptografar(str, chave, index + 1);
    }

    public static boolean isEnd(String text) 
    {
        // Verifica se o texto tem comprimento 3 e os caracteres são 'F', 'I', 'M'
        return text.length() == 3 && text.charAt(0) == 'F' && text.charAt(1) == 'I' && text.charAt(2) == 'M';
    }


    public static void main(String[] args) {
        // declaracoes
        int chave = 3;
        Scanner scanf = new Scanner(System.in);
        String strOriginal = scanf.nextLine();
        String cifrada;
        
        // repetindo o loop enquanto a minha entrada for diferente de FIM, chamando minha funcao isEnd e passando a string como parametro
        while(!isEnd(strOriginal))
        {
            cifrada = criptografar(strOriginal, chave, 0);
            System.out.println(cifrada);
            strOriginal = scanf.nextLine();
        }

        scanf.close();
    }
}
