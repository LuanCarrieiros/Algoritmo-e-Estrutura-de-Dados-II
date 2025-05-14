import java.util.*;

public class OddOrEven 
{
    public static void main(String args[]) 
    {
        Scanner scanf = new Scanner(System.in);
        int number;
        do 
        {
            number = scanf.nextInt();
            if (number != 0) {
                if (isOdd(number)) 
                {
                    System.out.println("I");
                } else 
                {
                    System.out.println("P");
                }
            }
        } while (number != 0);
        scanf.close();
    }

    public static boolean isOdd(int number) {
        return (number % 2 != 0);
    }
}
