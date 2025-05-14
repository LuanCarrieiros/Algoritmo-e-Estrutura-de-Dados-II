import java.util.*;

public class Combinador{
    public static void main(String[] args) {
        Scanner scanf = new Scanner(System.in);

        while(scanf.hasNext())
        {
            String str1 = scanf.next();
            String str2 = scanf.next();

            System.out.println(Combinador.combine(str1, str2));
        }
        scanf.close();
    }

    public static char[] combine(String str1, String str2)
    {
        char [] res = new char[str1.length() + str2.length()];
        int i = 0;
        int j = 0;

        while (i < str1.length() && i < str2.length())
        {
            res[j++] = str1.charAt(i);
            res[j++] = str2.charAt(i++);
        }

        if (str1.length() > str2.length())
        {   
            for(; i < str1.length(); i++, j++)
            {
                res[j] = str1.charAt(i);
            }
        } else {

            for(; i < str2.length(); i++, j++)
            {
                res[j] = str2.charAt(i);
            }
        }                                                                                               
        return res;
    }
}