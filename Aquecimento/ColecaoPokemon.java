import java.util.*;

public class ColecaoPokemon 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        
        if(1 <= N && N <= (10*10*10))
        {
            int pokemons = 0;
            String aux = "";
            String S;
            
            for(int i = 0; i <= N; i++)
            {
                S = sc.nextLine();
                if(S.length() >= 1 && S.length() <= (10*10*10))
                {
                    if(aux.contains(S) != true)
                    {
                        aux += S;
                        pokemons++;
                    }
                }
            }
            int capturados = 151 - pokemons;
            System.out.println("Falta(m) " + capturados + " pomekon(s).");
        }

        sc.close();
    }
}
