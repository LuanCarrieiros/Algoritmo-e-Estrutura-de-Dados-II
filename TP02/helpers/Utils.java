package helpers;

public class Utils {
    /**
     * Verifica se a string é "FIM".
     */
    public static boolean isEnd(String text) {
        return text != null && text.length() == 3
            && text.charAt(0) == 'F'
            && text.charAt(1) == 'I'
            && text.charAt(2) == 'M';
    }

    /**
     * Desempate por data de nascimento e, em caso de empate, por nome.
     */
    public static int desempate(Personagem p1, Personagem p2) {
        int valor = p1.getDateOfBirth().compareTo(p2.getDateOfBirth());
        return valor != 0 ? valor : p1.getName().compareTo(p2.getName());
    }

    /**
     * Desempate por casa e, em caso de empate, por nome.
     */
    public static int desempateHouse(Personagem p1, Personagem p2) {
        int house = p1.getHouse().compareTo(p2.getHouse());
        return house != 0 ? house : p1.getName().compareTo(p2.getName());
    }

    /**
     * Desempate por cor de cabelo e, em caso de empate, por nome.
     */
    public static int desempateHairColour(Personagem p1, Personagem p2) {
        int valor = p1.getHairColour().compareTo(p2.getHairColour());
        return valor != 0 ? valor : p1.getName().compareTo(p2.getName());
    }

    /**
     * Desempate por ano de nascimento e, em caso de empate, por nome.
     */
    public static int desempateYearOfBirth(Personagem p1, Personagem p2) {
        int valor = Integer.compare(p1.getYearOfBirth(), p2.getYearOfBirth());
        return valor != 0 ? valor : p1.getName().compareTo(p2.getName());
    }
}
