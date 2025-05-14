public class Lab01 {
    public static void main(String [] args)
    {
        String str = MyIO.readLine();

        while(!str.equals("FIM"))
        {
            MyIO.println(CountCapitalLetters(str));
            str = MyIO.readLine();
        }
    }
    
    public static int CountCapitalLetters (String text)
    {
        int size = text.length();
        int number_CapLetters = 0;

        for(int i = 0; i < size; i++)
        {
            if(text.charAt(i) >= 'A' && text.charAt(i) <= 'Z')
            {
                number_CapLetters++;
            }
        }

        return number_CapLetters;
    }
}