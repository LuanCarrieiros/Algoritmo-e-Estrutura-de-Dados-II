import java.util.*;
public class Q04_AlteracaoAleatoria 
{
    // Método para trocar as letras
    public static String TrocaLetra(String str, char random1, char random2)
    {
        String modificada = "";
        int size = str.length();

        //System.out.println("Letras sorteadas: ");
        //System.out.println(random1);
        //System.out.println(random2);
        for (int i = 0; i < size; i++)
        {   
            char caractere = str.charAt(i);

            if(caractere == random1)
            {   
                modificada += random2;
            } else
            {
                modificada += caractere;
            }
        }
        return modificada;
    }

    public static boolean isEnd(String text) 
    {
        // Verifica se o texto tem comprimento 3 e os caracteres são 'F', 'I', 'M'
        return text.length() == 3 && text.charAt(0) == 'F' && text.charAt(1) == 'I' && text.charAt(2) == 'M';
    }
    public static void main(String[] args) 
    {   
        Scanner scanf = new Scanner(System.in); // declaracao e inicializacao do objeto de entrada
        String str_original = scanf.nextLine(); // leitura da entrada,
        Random gerador = new Random(); // declaracao e inicializacao do objeto random
        gerador.setSeed(4); 

        // repetindo o loop enquanto a minha entrada for diferente de FIM, chamando minha funcao isEnd e passando a string como parametro
        while (!isEnd(str_original)) 
        {   
            // as declaracoes foram feitas dentro do while, para cada nova linha, novas letras serem geradas
            char random1 = (char)('a' + (Math.abs(gerador.nextInt()) % 26)); // sintaxe para gerar apenas letras minusculas
            char random2 = (char)('a' + (Math.abs(gerador.nextInt()) % 26));
            System.out.println(TrocaLetra(str_original, random1, random2));
            str_original = scanf.nextLine();
        }
        
        scanf.close();
    }
}
