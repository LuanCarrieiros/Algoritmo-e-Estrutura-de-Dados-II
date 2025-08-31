import java.util.*;
public class Q15_IsRec {
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();

        // repetindo o loop enquanto a minha entrada for diferente de FIM, chamando minha funcao isEnd e passando a string como parametro
        while(!isEnd(str))
        {
            System.out.print(isOnlyVowels(str, 0) ? "SIM " : "NAO ");
            System.out.print(isOnlyConsonant(str, 0) ? "SIM " : "NAO ");
            System.out.print(isOnlyInteger(str, 0) ? "SIM " : "NAO ");
            System.out.println(isOnlyFloat(str, 0, 0) ? "SIM" : "NAO");
            str = sc.nextLine();
        }

        sc.close();
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

    /**
     * Verifica se a string contém apenas vogais de forma recursiva
     * @param str string a ser verificada
     * @param index índice atual para recursão
     * @return true se contém apenas vogais, false caso contrário
     */
	public static boolean isOnlyVowels(String str, int index)
	{
		int length = str.length();
		
        if ( length == 0 )
        {
            return false;
        }

        if ( index == length )
        {
            return true;
        }
        
        if( str.charAt(index) == 'a' || str.charAt(index) == 'A' || str.charAt(index) == 'e' 
         || str.charAt(index) == 'E' || str.charAt(index) == 'i' || str.charAt(index) == 'I' 
         || str.charAt(index) == 'o' || str.charAt(index) == 'O' || str.charAt(index) == 'u' 
         || str.charAt(index) == 'U' )
        {
            return isOnlyVowels(str, index + 1);
        } else
        {
            return false;
        }
	}

    /**
     * Verifica se a string contém apenas consoantes de forma recursiva
     * @param str string a ser verificada
     * @param index índice atual para recursão
     * @return true se contém apenas consoantes, false caso contrário
     */
	public static boolean isOnlyConsonant(String str, int index)
	{

        int length = str.length();
		
        if ( length == 0 )
        {
            return false;
        }

        if ( index == length )
        {
            return true;
        }
        
        // teste se é letra maiuscula ou minuscula e se é vogal
		char currentChar = str.charAt(index);
		boolean isLowerCase = ('a' <= currentChar && currentChar <= 'z');
		boolean isUpperCase = ('A' <= currentChar && currentChar <= 'Z');
		boolean isVowel = (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' ||
						   currentChar == 'o' || currentChar == 'u' || currentChar == 'A' ||
						   currentChar == 'E' || currentChar == 'I' || currentChar == 'O' ||
						   currentChar == 'U');

        if((isLowerCase || isUpperCase) && !isVowel)
        {
            return isOnlyConsonant(str, index + 1);
        } else
        {
            return false;
        }
	}

    /**
     * Verifica se a string contém apenas dígitos numéricos de forma recursiva
     * @param str string a ser verificada
     * @param index índice atual para recursão
     * @return true se contém apenas dígitos, false caso contrário
     */
	public static boolean isOnlyInteger(String str, int index)
	{
		int length = str.length();
		boolean result = true;

        if ( length == 0 )
        {
            return false;
        }

        if ( index == length )
        {
            return true;
        }

		char currentChar = str.charAt(index);
		result = (currentChar >= '0' && currentChar <= '9'); // retorna verdadeiro se o todos os valores do char em cada index forem de um inteiro
		

        if(result)
        {
            return isOnlyInteger(str, index + 1); // chamada recursiva, enquanto index for menor que length
        } else
        {
            return false;
        }

	}

    /**
     * Verifica se a string representa um número decimal de forma recursiva
     * @param str string a ser verificada
     * @param dots número de pontos decimais encontrados
     * @param index índice atual para recursão
     * @return true se representa um número decimal válido, false caso contrário
     */
	public static boolean isOnlyFloat(String str, int dots, int index)
	{
		int length = str.length();
		
        if ( length == 0 )
        {
            return false;
        }

        if (dots > 1)
        {
            return false;
        }

        if ( index == length )
        {
            return true;
        }
	
		char currentChar = str.charAt(index);

		if(currentChar >= '0' && currentChar <= '9') // se é dígito
		{
			return isOnlyFloat(str, dots, index + 1);
		} else if (currentChar == '.' || currentChar == ',') // se é separador decimal
        {
            return isOnlyFloat(str, dots + 1, index + 1);
        } else
        {
            return false;
        }
	}

}
