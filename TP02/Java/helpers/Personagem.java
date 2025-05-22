package Java.helpers;

import java.util.List;
import java.util.ArrayList;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;

public class Personagem { // classe personagem
    private String id;
    private String name;
    private List<String> alternate_names;
    private String house;
    private String ancestry;
    private String species;
    private String patronus;
    private boolean hogwartsStaff;
    private boolean hogwartsStudent;
    private String actorName;
    private boolean alive;
    private LocalDate dateOfBirth;
    private int yearOfBirth;
    private String eyeColour;
    private String gender;
    private String hairColour;
    private boolean wizard;

    public Personagem() { // construtor vazio
        this.id = "";
        this.name = "";
        this.alternate_names = new ArrayList<>();
        this.house = "";
        this.ancestry = "";
        this.species = "";
        this.patronus = "";
        this.hogwartsStaff = false;
        this.hogwartsStudent = false;
        this.actorName = "";
        this.alive = false;
        this.dateOfBirth = LocalDate.now();
        this.yearOfBirth = 0;
        this.eyeColour = "";
        this.gender = "";
        this.hairColour = "";
        this.wizard = false;
    }

    // construtor
    public Personagem(String id, String name, List<String> alternate_names, String house, String ancestry,
            String species,
            String patronus, boolean hogwartsStaff, boolean hogwartsStudent, String actorName, boolean alive,
            LocalDate dateOfBirth,
            int yearOfBirth, String eyeColour, String gender, String hairColour, boolean wizard) {
        this.id = id;
        this.name = name;
        this.alternate_names = alternate_names;
        this.house = house;
        this.ancestry = ancestry;
        this.species = species;
        this.patronus = patronus;
        this.hogwartsStaff = hogwartsStaff;
        this.hogwartsStudent = hogwartsStudent;
        this.actorName = actorName;
        this.alive = alive;
        this.dateOfBirth = dateOfBirth;
        this.yearOfBirth = yearOfBirth;
        this.eyeColour = eyeColour;
        this.gender = gender;
        this.hairColour = hairColour;
        this.wizard = wizard;
    }

    // ajustar a data para impressao, recebe uma var do tipo LocalDate e retona a
    // string, isso é apenas para imprimir no formato certo
    public String ajustarFormatoData(LocalDate dateOfBirth) {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy");
        return dateOfBirth.format(formatter);
    }

    // receber uma string do tipo data e retorna uma do tipo LocalDate
    public LocalDate parseData(String dateOfBirth2) throws DateTimeParseException {
        DateTimeFormatter formatter;
        formatter = DateTimeFormatter.ofPattern("dd-M-yyyy");
        try {
            return LocalDate.parse(dateOfBirth2, formatter);
        } catch (DateTimeParseException e) {
            System.out.println("Erro ao analisar a data: " + e.getMessage());
        }
        return null;
    }

    // método para ler, serve para ler a string inteira, converter os tipos, tratar
    // e adicionar ao personagem
    public void ler(String str) {

        String[] armazenamento = str.split(";"); // lendo a string inteira e separando cada indice por " ; "
        // atribuindo a variavel correta cada indice do vetor de string
        String id = armazenamento[0];
        String name = armazenamento[1];
        String alternate_names2 = armazenamento[2];
        String house = armazenamento[3];
        String ancestry = armazenamento[4];
        String species = armazenamento[5];
        String patronus = armazenamento[6];
        String hogwartsStaff2 = armazenamento[7];
        String hogwartsStudent2 = armazenamento[8];
        String actorName = armazenamento[9];
        String alive2 = armazenamento[10];
        String dateOfBirth2 = armazenamento[12];
        String yearOfBirth2 = armazenamento[13];
        String eyeColour = armazenamento[14];
        String gender = armazenamento[15];
        String hairColour = armazenamento[16];
        String wizard2 = armazenamento[17];
        if (wizard2.equals("VERDADEIRO")) {
            wizard = true;
        } else {
            wizard = false;
        }
        if (alive2.equals("VERDADEIRO")) {
            alive = true;
        } else {
            alive = false;
        }
        if (hogwartsStaff2.equals("VERDADEIRO")) {
            hogwartsStaff = true;
        } else
            hogwartsStaff = false;
        if (hogwartsStudent2.equals("VERDADEIRO")) {
            hogwartsStudent = true;
        } else
            hogwartsStudent = false;
        // convertendo as strings que deveriam ser do tipo boolean e int para o tipo
        // correto
        // boolean hogwartsStaff = Boolean.parseBoolean(hogwartsStaff2);
        // boolean hogwartsStudent = Boolean.parseBoolean(hogwartsStudent2);
        // boolean alive = Boolean.parseBoolean(alive2);
        // boolean wizard = Boolean.parseBoolean(wizard2);
        int yearOfBirth = Integer.parseInt(yearOfBirth2);
        LocalDate dateOfBirth = parseData(dateOfBirth2);
        // pré-tratamento para adicionar na lista, dando replace nos cochetes pelas
        // chaves e eliminando o '
        String alternate_names3 = alternate_names2.replace("[", "{");
        alternate_names3 = alternate_names3.replace("]", "}");
        alternate_names3 = alternate_names3.replace("'", "");
        String[] armazenamentoLista = alternate_names3.split(", "); // lendo a string inteira novamente, separando por
                                                                    // ", "
        List<String> alternate_names = new ArrayList<>(); // criando a lista

        // para cada item do armazenamento da Lista, remover os espaços em branco e em
        // seguida, adicionar esse item na lista de nomes alternativos
        for (String item : armazenamentoLista) {
            String parte = item.trim();
            alternate_names.add(parte);
        }
        // settando os valores ao personagem
        setId(id);
        setName(name);
        setAlternate_names(alternate_names);
        setHouse(house);
        setAncestry(ancestry);
        setSpecies(species);
        setPatronus(patronus);
        setHogwartsStaff(hogwartsStaff);
        setHogwartsStudent(hogwartsStudent);
        setActorName(actorName);
        setAlive(alive);
        setDateOfBirth(dateOfBirth);
        setYearOfBirth(yearOfBirth);
        setEyeColour(eyeColour);
        setGender(gender);
        setHairColour(hairColour);
        setWizard(wizard);
    }

    // metodo clone para clonar um objeto do tipo personagem
    public Personagem clone() {
        return new Personagem(id, name, new ArrayList<>(alternate_names), house, ancestry, species,
                patronus, hogwartsStaff, hogwartsStudent, actorName, alive, dateOfBirth,
                yearOfBirth, eyeColour, gender, hairColour, wizard);
    }

    // imprimir os atributos de um personagem
    public void imprimir() {
        System.out.println("[" + id + " ## " + name + " ## " + String.join(", ", alternate_names) + " ## " + house
                + " ## " + ancestry
                + " ## " + species + " ## " + patronus + " ## " + hogwartsStaff + " ## " + hogwartsStudent + " ## "
                + actorName
                + " ## " + alive + " ## " +
                ajustarFormatoData(dateOfBirth) + " ## " + yearOfBirth + " ## " + eyeColour + " ## " + gender + " ## "
                + hairColour + " ## " + wizard + "]");
    }

    // abaixo todos os getters and setters
    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public List<String> getAlternate_names() {
        return alternate_names;
    }

    public void setAlternate_names(List<String> alternate_names) {
        this.alternate_names = alternate_names;
    }

    public String getHouse() {
        return house;
    }

    public void setHouse(String house) {
        this.house = house;
    }

    public String getAncestry() {
        return ancestry;
    }

    public void setAncestry(String ancestry) {
        this.ancestry = ancestry;
    }

    public String getSpecies() {
        return species;
    }

    public void setSpecies(String species) {
        this.species = species;
    }

    public String getPatronus() {
        return patronus;
    }

    public void setPatronus(String patronus) {
        this.patronus = patronus;
    }

    public boolean getHogwartsStaff() {
        return hogwartsStaff;
    }

    public void setHogwartsStaff(boolean hogwartsStaff) {
        this.hogwartsStaff = hogwartsStaff;
    }

    public boolean getHogwartsStudent() {
        return hogwartsStudent;
    }

    public void setHogwartsStudent(boolean hogwartsStudent) {
        this.hogwartsStudent = hogwartsStudent;
    }

    public String getActorName() {
        return actorName;
    }

    public void setActorName(String actorName) {
        this.actorName = actorName;
    }

    public boolean isAlive() {
        return alive;
    }

    public void setAlive(boolean alive) {
        this.alive = alive;
    }

    public LocalDate getDateOfBirth() {
        return dateOfBirth;
    }

    public void setDateOfBirth(LocalDate dateOfBirth) {
        this.dateOfBirth = dateOfBirth;
    }

    public int getYearOfBirth() {
        return yearOfBirth;
    }

    public void setYearOfBirth(int yearOfBirth) {
        this.yearOfBirth = yearOfBirth;
    }

    public String getEyeColour() {
        return eyeColour;
    }

    public void setEyeColour(String eyeColour) {
        this.eyeColour = eyeColour;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public String getHairColour() {
        return hairColour;
    }

    public void setHairColour(String hairColour) {
        this.hairColour = hairColour;
    }

    public boolean isWizard() {
        return wizard;
    }

    public void setWizard(boolean wizard) {
        this.wizard = wizard;
    }
}