import java.util.*;
public class Q04_AlteracaoAleatoria 
{
    /**
     * Método para trocar todas as ocorrências de uma letra por outra na string
     * @param str string original
     * @param random1 letra a ser substituída
     * @param random2 letra substituta
     * @return string com substituições realizadas
     */
    public static String TrocaLetra(String str, char random1, char random2)
    {
        String modificada = "";
        int size = str.length();

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

    /**
     * Verifica se a string é "FIM"
     * @param text string a ser verificada
     * @return true se for "FIM", false caso contrário
     */
    public static boolean isEnd(String text) 
    {
        return text.length() == 3 && text.charAt(0) == 'F' && text.charAt(1) == 'I' && text.charAt(2) == 'M';
    }

    public static void main(String[] args) 
    {   
        Scanner scanf = new Scanner(System.in);
        String str_original = scanf.nextLine();
        Random gerador = new Random();
        gerador.setSeed(4); // Seed correta conforme enunciado

        while (!isEnd(str_original)) 
        {   
            char random1 = (char)('a' + (Math.abs(gerador.nextInt()) % 26));
            char random2 = (char)('a' + (Math.abs(gerador.nextInt()) % 26));
            
            System.out.println(TrocaLetra(str_original, random1, random2));
            str_original = scanf.nextLine();
        }
        
        scanf.close();
    }
}
