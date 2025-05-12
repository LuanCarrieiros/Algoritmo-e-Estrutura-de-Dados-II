import java.util.Scanner;

public class Q14_AlgebraRec {
    
    // Método para substituir uma parte da string com outra string de forma recursiva
    private static String fillingNewSplittedPart(String str, String split, String result, int i) {
        if (i >= str.length()) {
            return ""; // Se atingir o final da string, retorna uma string vazia
        }
        
        // Verifica se a substring split ocorre em str a partir da posição atual
        if (str.charAt(i) == split.charAt(0) && !isSubstringFound(str, split, i)) {
            // Se a substring split foi encontrada completamente, substitui com result
            if (isSubstringFound(str, split, i)) {
                return result.charAt(0) + fillingNewSplittedPart(str, split, result, i + split.length()); 
            } else {
                return str.charAt(i) + fillingNewSplittedPart(str, split, result, i + 1);
            }
        } else {
            return str.charAt(i) + fillingNewSplittedPart(str, split, result, i + 1);
        }
    } 

    // Método auxiliar para verificar se a substring ocorre completamente em str a partir de uma posição específica
    private static boolean isSubstringFound(String str, String split, int i) {
        int count = 0;
        // Verifica se a substring split ocorre completamente
        for (int j = 0; j < split.length(); j++) {
            if (str.charAt(j + i) == split.charAt(j)) {
                count++; // Incrementa o contador
            } else {
                count = 0; // Reinicia o contador se não houver correspondência
            }
        }
        return count == split.length(); // Retorna true se a substring for encontrada completamente
    }

    // Método para resolver operações lógicas unárias de forma recursiva
    private static String resolvingOperation(String str, int i) {
        // Valor padrão de retorno
        String resolved = "1";
        
        // Verifica o tipo de operação lógica
        if (str.charAt(0) == 38) { // Operação de negação
            if (i < str.length()) {
                if (str.charAt(i) == 48) { // Se qualquer caractere for '0', o resultado é '0'
                    resolved = "0";
                }
                return resolved + resolvingOperation(str, i + 1);
            }
        }
        
        if (str.charAt(0) == 124) { // Operação de negação
            if (i < str.length()) {
                int count = 0;
                if (str.charAt(i) != 49) { // Conta o número de caracteres diferentes de '1'
                    count++;
                }
                // Se todos os caracteres forem diferentes de '1', o resultado é '0'
                if (count == str.length()) {
                    resolved = "0";
                }
                return resolved + resolvingOperation(str, i + 1);
            }
        }
        
        if (str.charAt(0) == 33) { // Operação de negação
            if (i < str.length()) {
                if (str.charAt(i) == 49) { // Se qualquer caractere for '1', o resultado é '0'
                    resolved = "0";
                }
                if (str.charAt(i) == 48) { // Se qualquer caractere for '0', o resultado é '1'
                    resolved = "1";
                }
                return resolved + resolvingOperation(str, i + 1);
            }
        }
        
        return resolved; // Retorna o resultado da operação
    } 
    
    // Método para obter uma substring até ')' de forma recursiva
    private static String getSplittedString(String str, int i, String split) {
        if (i >= str.length()) {
            return ""; // Se atingir o final da string, retorna uma string vazia
        }
        
        // Verifica se o caractere atual é o final da substring
        if (str.charAt(i) == 41) {
            return split + str.charAt(i); // Adiciona o caractere à substring e retorna
        } else {
            return split + str.charAt(i) + getSplittedString(str, i + 1, split); // Adiciona o caractere à substring e continua a busca
        }
    } 

    // Verifica se a expressão está completa de forma recursiva
    private static boolean isComplete(String str, int i, int count) {
        if (i >= str.length()) {
            return count <= 1; // Retorna true se houver no máximo um parêntese aberto
        }
        
        if (str.charAt(i) == 40) { // Se encontrar um parêntese aberto
            count++; // Incrementa o contador
        }
        
        return isComplete(str, i + 1, count); // Chama recursivamente com o próximo caractere
    } 

    // Resolve as operações lógicas na expressão de forma recursiva
    private static String logicalOperations(String str, int i) {
        String split = "", result = ""; // Strings para armazenar a substring e o resultado da operação
        
        // Verifica se a string está vazia ou o índice ultrapassou o tamanho da string
        if (i >= str.length()) {
            return ""; // Retorna uma string vazia
        }
        
        split = ""; // Limpa a string split
        
        // Verifica se há operações lógicas
        if (str.charAt(i) == 38 || str.charAt(i) == 124 || str.charAt(i) == 33) {
            // Obtém a substring a partir do índice atual até o final da string
            split = getSplittedString(str, i, split);
            
            // Se a expressão estiver completa, resolve a operação
            if (isComplete(split, 0, 0)) {
                split = getSplittedString(split, 0, ""); // Obtém a substring até ')'
                result = resolvingOperation(split, 1); // Resolve a operação
                str = fillingNewSplittedPart(str, split, result, i); // Substitui a substring na string original
                i = str.length() - 1; // Move o índice para o final da string
            }
        }
        
        return str.charAt(i) + logicalOperations(str, i + 1); // Continua a busca pelos caracteres recursivamente
    } 
    
    // Substitui caracteres especiais ('a', 'o', 'n') por operadores lógicos ('&', '|', '!')
    private static String replaceLogicalOperations(String str, int i) {
        String split = ""; // String para armazenar a nova string com os operadores lógicos substituídos
        
        // Verifica se a string está vazia ou o índice ultrapassou o tamanho da string
        if (i >= str.length()) {
            return ""; // Retorna uma string vazia
        }
        
        // Substitui 'a' por '&', 'o' por '|' e 'n' por '!'
        if (str.charAt(i) == 97) { 
            split += "&"; // Adiciona '&' à nova string
            i += 2; // Move o índice para o próximo caractere
        } else if (str.charAt(i) == 111) { 
            split += "|"; // Adiciona '|' à nova string
            i += 1; // Move o índice para o próximo caractere
        } else if (str.charAt(i) == 110) { 
            split += "!"; // Adiciona '!' à nova string
            i += 2; // Move o índice para o próximo caractere
        } else if (str.charAt(i) == 32) {  
            // Ignora o caractere de espaço em branco
        } else { 
            split += str.charAt(i); // Adiciona o caractere à nova string
        }
        
        return split + replaceLogicalOperations(str, i + 1); // Continua a busca pelos caracteres recursivamente
    } 

    // Substitui variáveis por seus valores de forma recursiva
    private static String replaceVariableValues(String str, int i, char A, char B, char C) {
        if (i >= str.length()) {
            return ""; // Se atingir o final da string, retorna uma string vazia
        }
        
        String split = ""; // String para armazenar a nova string com as variáveis substituídas
        
        // Substitui as variáveis pelos seus valores
        if (str.charAt(i) == 65) {
            split += A; // Adiciona o valor de A à nova string
        } else if (str.charAt(i) == 66) {
            split += B; // Adiciona o valor de B à nova string
        } else if (str.charAt(i) == 67) {
            split += C; // Adiciona o valor de C à nova string
        } else {
            split += str.charAt(i); // Adiciona o caractere à nova string
        }
        
        return split + replaceVariableValues(str, i + 1, A, B, C); // Continua a busca pelos caracteres recursivamente
    } 

    // Método principal que inicia a resolução da expressão
    private static String initializer(String str, char A, char B, char C) {
        String returned = ""; // String para armazenar o resultado final
        
        returned = replaceVariableValues(str, 0, A, B, C); // Substitui as variáveis pelos seus valores
        returned = replaceLogicalOperations(returned, 0); // Substitui os caracteres especiais pelos operadores lógicos
        returned = logicalOperations(returned, 0); // Resolve as operações lógicas na expressão
        
        return returned; // Retorna o resultado final da expressão
    } 

    // Verifica se é o fim da entrada
    private static boolean isFim(String str) {
        return (str.length() == 1 && str.charAt(0) == 48); // Retorna verdadeiro se a string possui apenas um caractere '0'
    }

    // Método principal que lê a entrada e imprime os resultados
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Objeto Scanner para ler a entrada
        String[] entradas = new String[1000]; // Array para armazenar as entradas
        int numeroEntradas = 0; // Variável para contar o número de entradas
        
        // Lê as entradas até encontrar o fim da entrada
        do {
            entradas[numeroEntradas] = sc.nextLine(); // Lê a entrada atual
        } while (!(isFim(entradas[numeroEntradas++]))); // Verifica se é o fim da entrada e incrementa o contador de entradas
        numeroEntradas--;  // Decrementa o contador de entradas

        // Para cada entrada, resolve a expressão e imprime o resultado
        for (int i = 0; i < numeroEntradas; i++) {
            // Extrai os valores das variáveis da entrada atual
            char A = entradas[i].charAt(2);
            char B = entradas[i].charAt(4);
            char C = (entradas[i].charAt(0) == 51) ? entradas[i].charAt(6) : ' ';
            
            // Chama o método initializer para resolver a expressão
            System.out.println(initializer(entradas[i], A, B, C)); 
        }
        sc.close();
    }
}
