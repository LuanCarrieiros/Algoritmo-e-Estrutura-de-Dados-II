import java.io.*;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.*;
import java.util.Locale;

public class Q08_Arquivo {
    public static void main(String args[]) throws Exception {
        Scanner scanf = new Scanner(System.in);
        RandomAccessFile Arq = null; // declarando o arquivo como null antes do try para ter certeza que foi fechado ao final do programa
        try {
            // declaracao de variaveis  
            Arq = new RandomAccessFile("Questao08.txt", "rw"); 
            
            int size = scanf.nextInt();
            int i = 0;
            float numero;
            
            // leitura dos valores e escrita no arquivo
            for (i = 0; i < size; i++) {
                String input = scanf.next().replace(',', '.');
                float value = Float.parseFloat(input);
                Arq.writeFloat(value);
            }

            Arq.close();

            // reabrindo o arquivo e lendo de tras para frente
            Arq = new RandomAccessFile("Questao08.txt", "r");

            DecimalFormatSymbols symbols = new DecimalFormatSymbols(Locale.US);
            symbols.setDecimalSeparator(',');
            DecimalFormat formatter = new DecimalFormat("0.###", symbols);

            for (i = size - 1; i >= 0; i--) {
                Arq.seek(i * 4); // o tamanho de cada float é de 4 bytes
                numero = Arq.readFloat();
                
                // Se é um número inteiro, mostra sem vírgula
                if (numero == (int) numero) {
                    System.out.println((int) numero);
                } else {
                    String formatted = formatter.format(numero);
                    // Remove zeros desnecessários no final
                    formatted = formatted.replaceAll(",0+$", "");
                    System.out.println(formatted);
                }
            }
            
            Arq.close();

        // exceptions que podem ocorrer    
        } catch (FileNotFoundException e) {
            System.err.println(("Arquivo inexistente: " + e.getMessage()));
        } catch (IOException e) {
            System.err.println("Erro de I/O: " + e.getMessage());
    
        } finally { // usando o finally para garantir que o arquivo foi fechado
            if (Arq != null) {
                try {
                    Arq.close();
                    scanf.close();
                } catch (IOException e) {
                    System.err.println("Erro ao fechar o arquivo: " + e.getMessage());
                }
            }
        }
    }
}