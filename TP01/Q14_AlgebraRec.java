import java.util.Scanner;

class Q14_AlgebraRec {
    
    // Método para substituir uma parte da string com outra string
    private static String fillingNewSplittedPart(String str, String split, String result) {
        String newString = ""; // String para armazenar a nova string resultante
        boolean flag = false; // Flag para indicar se a substring foi encontrada
        int count = 0; // Contador para verificar se a substring foi encontrada completamente
        
        // Percorre a string str
        for(int i = 0; i < str.length(); i++) {
            count = 0; 
            // Verifica se a substring split ocorre em str
            if(str.charAt(i) == split.charAt(0) && flag == false) {
                // Verifica se a substring split ocorre completamente
                for(int j = 0; j < split.length(); j++) {
                    if(str.charAt(j + i) == split.charAt(j)) { 
                        count++; // Incrementa o contador
                    } else { 
                        count = 0; 
                    }
                }
                // Se a substring split foi encontrada completamente, substitui com result
                if(count == split.length()) {
                    flag = true;
                    newString += result.charAt(0);
                    i += count - 1; 
                } else {
                    newString += str.charAt(i);
                }
            } else {
                newString += str.charAt(i);
            } 
        }
        return newString; // Retorna a nova string resultante
    } 

    // Método para resolver operações lógicas unárias
    private static String resolvingOperation(String str) {
        String resolved = "1"; // Valor padrão de retorno
        
        // Verifica o tipo de operação lógica
        if(str.charAt(0) == 38) { // Operação AND
            for(int i = 0; i < str.length(); i++) {
                if(str.charAt(i) == 48) { // Se qualquer caractere for '0', o resultado é '0'
                    resolved = "0";
                }
            } 
        }
        
        if(str.charAt(0) == 124) { // Operação OR
            int count = 0;
            for(int i = 0; i < str.length(); i++) {
                if(str.charAt(i) != 49) { // Conta o número de caracteres diferentes de '1'
                    count++;
                }
            }
            // Se todos os caracteres forem diferentes de '1', o resultado é '0'
            if(count == str.length()) {
                resolved = "0";
            }
        }
        
        if(str.charAt(0) == 33) { // Operação NOT
            for(int i = 0; i < str.length(); i++) {
                if(str.charAt(i) == 49) { // Se qualquer caractere for '1', o resultado é '0'
                    resolved = "0";
                }
                if(str.charAt(i) == 48) { // Se qualquer caractere for '0', o resultado é '1'
                    resolved = "1";
                }
            }
        }
        
        return resolved; // Retorna o resultado da operação
    } 
    
    // Método para obter uma substring até ')'
    private static String getSplittedString(String str) {
        String split = ""; // String para armazenar a substring
        boolean finished = false; // Flag para indicar o término da busca
        int i = 0; // Índice para percorrer a string str
        
        // Enquanto não terminar a busca
        while(!finished) {
            // Verifica se o caractere atual é o final da substring
            if(str.charAt(i) == 41) {
                split += str.charAt(i); // Adiciona o caractere à substring
                finished = true; // Marca o término da busca
            } else { 
                split += str.charAt(i); // Adiciona o caractere à substring
            }

            // Verifica se alcançou o final da string str
            if(i == str.length() - 1) { 
                i = 0; // Reinicia a busca do início da string
            } else { 
                i += 1; // Move para o próximo caractere
            }
        }
        return split; // Retorna a substring encontrada
    } 

    // Verifica se a expressão está completa
    private static boolean isComplete(String str) {
        int count = 0; // Contador de parênteses abertos
        for(int i = 0; i < str.length(); i++) {
            if(str.charAt(i) == 40) { // Se encontrar um parêntese aberto
                count++; // Incrementa o contador
            }
            if(count > 1) { // Se encontrar mais de um parêntese aberto
                return false; // A expressão não está completa
            }
        }
        return true; // A expressão está completa
    } 

    // Resolve as operações lógicas na expressão
    private static String logicalOperations(String str) {
        String split = "", result = ""; // Strings para armazenar a substring e o resultado da operação
        boolean resp = false; // Flag para indicar se a operação foi resolvida completamente
        int i = 0; // Índice para percorrer a string str
        
        // Enquanto a operação não for resolvida completamente
        while(!resp) { 
            split = ""; // Limpa a string split
            
            // Verifica se há operações lógicas
            if(str.charAt(i) == 38 || str.charAt(i) == 124 || str.charAt(i) == 33) {
                // Obtém a substring a partir do índice atual até o final da string
                for(int j = i; j < str.length(); j++) {
                    split += str.charAt(j); // Adiciona o caractere à substring
                }
                // Se a expressão estiver completa, resolve a operação
                if(isComplete(split)) {
                    split = getSplittedString(split); // Obtém a substring até ')'
                    result = resolvingOperation(split); // Resolve a operação
                    str = fillingNewSplittedPart(str, split, result); // Substitui a substring na string original
                    i = str.length() - 1; // Move o índice para o final da string
                }
            }
            // Move para o próximo caractere
            if(i != str.length() - 1) {
                i += 1;
            }		
            
            // Verifica se alcançou o final da string
            if(i == str.length() - 1) { 
                i = 0; // Reinicia a busca do início da string
            }
            // Verifica se a string possui apenas um caractere
            if(str.length() == 1) { 
                resp = true; // A operação foi resolvida completamente
            } 
        }		
        return str; // Retorna a expressão resolvida
    } 
    
    // Substitui caracteres especiais ('a', 'o', 'n') por operadores lógicos ('&', '|', '!')
    private static String replaceLogicalOperations(String str) {
        String split = ""; // String para armazenar a nova string com os operadores lógicos substituídos
        for(int i = 0; i < str.length(); i++) {
            // Substitui 'a' por '&', 'o' por '|' e 'n' por '!'
            if(str.charAt(i) == 97) { 
                split += "&"; // Adiciona '&' à nova string
                i+= 2; // Move o índice para o próximo caractere
            } else if(str.charAt(i) == 111) { 
                split += "|"; // Adiciona '|' à nova string
                i += 1; // Move o índice para o próximo caractere
            } else if(str.charAt(i) == 110) { 
                split += "!"; // Adiciona '!' à nova string
                i += 2; // Move o índice para o próximo caractere
            } else if(str.charAt(i) == 32) {  
                // Ignora o caractere de espaço em branco
            } else { 
                split += str.charAt(i); // Adiciona o caractere à nova string
            }
        }
        return split; // Retorna a nova string com os operadores lógicos substituídos
    } 

    // Substitui variáveis por seus valores
    private static String replaceVariableValues(String str) {
        String split = ""; // String para armazenar a nova string com as variáveis substituídas
        char A = ' ', B = ' ', C = ' '; // Variáveis para armazenar os valores
        int i = 0; // Índice para percorrer a string str
        
        // Determina os valores das variáveis
        if(str.charAt(0) == 51) {   
            A = str.charAt(2); // Valor da variável A
            B = str.charAt(4); // Valor da variável B
            C = str.charAt(6); // Valor da variável C
            i = 8; // Move o índice para o próximo caractere
        } else if(str.charAt(0) == 50) {
            A = str.charAt(2); // Valor da variável A
            B = str.charAt(4); // Valor da variável B
            i = 6; // Move o índice para o próximo caractere
        } else if(str.charAt(0) == 49) {
            A = str.charAt(2); // Valor da variável A
            i = 4; // Move o índice para o próximo caractere
        }
        // Substitui as variáveis pelos seus valores
        for(int j = i; j < str.length(); j++) {
            if(str.charAt(j) == 65) { 
                split += A; // Adiciona o valor de A à nova string
            } else if(str.charAt(j) == 66) { 
                split += B; // Adiciona o valor de B à nova string
            } else if(str.charAt(j) == 67) { 
                split += C; // Adiciona o valor de C à nova string
            } else { 
                split += str.charAt(j); // Adiciona o caractere à nova string
            }
        }
        return split; // Retorna a nova string com as variáveis substituídas
    } 

    // Método principal que inicia a resolução da expressão
    private static String initializer(String str) {
        String returned = ""; // String para armazenar o resultado final
        
        returned = replaceVariableValues(str); // Substitui as variáveis pelos seus valores
        returned = replaceLogicalOperations(returned); // Substitui os caracteres especiais pelos operadores lógicos
        returned = logicalOperations(returned); // Resolve as operações lógicas na expressão
        
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
        } while(!(isFim(entradas[numeroEntradas++]))); // Verifica se é o fim da entrada e incrementa o contador de entradas
        numeroEntradas--;  // Decrementa o contador de entradas

        // Para cada entrada, resolve a expressão e imprime o resultado
        for(int i = 0; i < numeroEntradas; i++) {
            System.out.println(initializer(entradas[i])); // Chama o método initializer para resolver a expressão
        }
        sc.close();
    }
}