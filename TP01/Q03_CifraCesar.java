import java.util.*;

public class Q03_CifraCesar {

    public static String criptografar(String str, int chave) {
        String cifrado = "";
        int size = str.length();

        for (int i = 0; i < size; i++) {
            char caractere = str.charAt(i); // pegando caracter posicao por posicao
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
        }
    
        return cifrado;
    }


    public static boolean isEnd(String text) {
        // Verifica se o texto tem comprimento 3 e os caracteres são 'F', 'I', 'M'
        return text.length() == 3 && text.charAt(0) == 'F' && text.charAt(1) == 'I' && text.charAt(2) == 'M';
    }

    public static void main(String[] args) {
        // declaracoes 
        int chave = 3; 
        Scanner reader = new Scanner(System.in);
        String strOriginal = reader.nextLine();
        String cifrada;

        // repetindo o loop enquanto a minha entrada for diferente de FIM, chamando minha funcao isEnd e passando a string como parametro
        while (!isEnd(strOriginal)) {
            cifrada = criptografar(strOriginal, chave);
            System.out.println(cifrada);
            strOriginal = reader.nextLine();

        }

        reader.close();
    }
}
