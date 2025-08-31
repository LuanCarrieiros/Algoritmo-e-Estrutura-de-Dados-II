import java.util.*;

public class Q06_Is {
    public static void main(String[] args) 
    {
        Scanner scanf = new Scanner(System.in);
        String str = scanf.nextLine();

        while(!isEnd(str))
        {
            System.out.print(isOnlyVowels(str) ? "SIM " : "NAO ");
            System.out.print(isOnlyConsonant(str) ? "SIM " : "NAO ");
            System.out.print(isOnlyInteger(str) ? "SIM " : "NAO ");
            System.out.println(isOnlyFloat(str) ? "SIM" : "NAO");
            str = scanf.nextLine();
        }
        
        scanf.close();
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
     * Verifica se a string contém apenas vogais ASCII (regra 12)
     * @param str string a ser verificada
     * @return true se contém apenas vogais, false caso contrário
     */
	public static boolean isOnlyVowels(String str)
	{
		int length = str.length(); // tamanho da string
		boolean result = true;
		
		for(int i = 0; i < length && result; i++)
		{
			// result = true se todas as posicoes da string caírem em pelo menos uma das vogais, caso contrario, falso
			result = (str.charAt(i) == 'a' || str.charAt(i) == 'A' || str.charAt(i) == 'e' 
                   || str.charAt(i) == 'E' || str.charAt(i) == 'i' || str.charAt(i) == 'I' 
				   || str.charAt(i) == 'o' || str.charAt(i) == 'O' || str.charAt(i) == 'u' 
                   || str.charAt(i) == 'U');
		}
		return (result);
	}

    //Função que passa por toda string para ver se todos os valores são consoantes ou não
	public static boolean isOnlyConsonant(String str)
	{
		int length = str.length();
		boolean result = true;
		
		for(int i = 0; i < length && result; i++)
		{
			// teste se é letra maiuscula ou minuscula e se é vogal
			char currentChar = str.charAt(i);
			boolean isLowerCase = ('a' <= currentChar && currentChar <= 'z');
			boolean isUpperCase = ('A' <= currentChar && currentChar <= 'Z');
			boolean isVowel = (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' ||
							   currentChar == 'o' || currentChar == 'u' || currentChar == 'A' ||
							   currentChar == 'E' || currentChar == 'I' || currentChar == 'O' ||
							   currentChar == 'U');
							
			result = (isLowerCase || isUpperCase) && !isVowel; // resulta verdadeiro se for letra e nao for vogal
		}
		return (result); 
	}

	public static boolean isOnlyInteger(String str)
	{
		int length = str.length();
		boolean result = true;

		for(int i = 0; i < length && result; i++)
		{
			char currentChar = str.charAt(i);
			result = (currentChar >= '0' && currentChar <= '9'); // retorna verdadeiro se o todos os valores do char em cada index forem de um inteiro
		}
		return (result);
	}

	public static boolean isOnlyFloat(String str)
	{
		int length = str.length();
		boolean result = true;
		int dots = 0;

		for (int i = 0; i < length && result; i++)
		{
			char currentChar = str.charAt(i);
			result = (currentChar >= '0' && currentChar <= '9'); // // retorna verdadeiro se o todos os valores do char em cada index forem de um inteiro

			if(currentChar == '.' || currentChar == ',') // teste para checar se é um ponto ou vírgula
			{
				dots++; // se esse numero ultrapassar 2, não é float, é outra coisa
				result = true;
			}
		}

		return (result && dots < 2);
	}

}
