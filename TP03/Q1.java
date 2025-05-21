public class Q1 {

    class Arvore {
        No raizArv;

        public Arvore() {
            raizArv = null;
        }
    }

    class No {
        char letra;
        No esq, dir;
        No2 raiz;

        public No(char letra) {
            this(letra, null, null, null);
        }

        public No(char letra, No esq, No dir, No2 raiz) {
            this.letra = letra;
            this.esq = esq;
            this.dir = dir;
            this.raiz = raiz;
        }
    }

    class No2 {
        String palavra;
        No2 esq, dir;

        public No2(String palavra) {
            this(palavra, null, null);
        }

        public No2(String palavra, No2 esq, No2 dir) {
            this.palavra = palavra;
            this.esq = esq;
            this.dir = dir;
        }
    }

    private Arvore arvoreLetras;

    public Q1() {
        arvoreLetras = new Arvore();
    }

    public void inserirLetra(char letra) throws Exception {
        try {
            arvoreLetras.raizArv = inserirLetraRec(arvoreLetras.raizArv, letra);
        } catch (Exception e) {
            System.out.println("Erro ao inserir letra: " + e.getMessage());
        }
    }

    private No inserirLetraRec(No atual, char letra) throws Exception {
        if (atual == null)
            atual = new No(letra);
        else if (letra < atual.letra)
            atual.esq = inserirLetraRec(atual.esq, letra);
        else if (letra > atual.letra)
            atual.dir = inserirLetraRec(atual.dir, letra);
        else
            throw new Exception("Erro, letra já existe.\n");
        return atual;
    }

    public void inserirPalavra(String palavra) throws Exception {
        char primeiraLetra = palavra.charAt(0);
        No noLetra = buscarNoLetra(arvoreLetras.raizArv, primeiraLetra);

        if (noLetra == null) {
            throw new Exception("Letra '" + primeiraLetra + "' não encontrada na árvore de letras.");
        }

        noLetra.raiz = inserirPalavraRec(noLetra.raiz, palavra);
    }

    private No2 inserirPalavraRec(No2 no2, String palavra) throws Exception {
        if (no2 == null)
            no2 = new No2(palavra);
        else if (palavra.compareTo(no2.palavra) < 0)
            no2.esq = inserirPalavraRec(no2.esq, palavra);
        else if (palavra.compareTo(no2.palavra) > 0)
            no2.dir = inserirPalavraRec(no2.dir, palavra);
        else
            throw new Exception("Palavra já existe.\n");
        return no2;
    }

    private No buscarNoLetra(No no, char letra) {
        if (no == null)
            return null;
        if (letra == no.letra)
            return no;
        else if (letra < no.letra)
            return buscarNoLetra(no.esq, letra);
        else
            return buscarNoLetra(no.dir, letra);
    }

    public int contarPalavras(char primeiro, char ultimo) {
        return contarPalavras(primeiro, ultimo, arvoreLetras.raizArv);
    }

    private int contarPalavras(char primeiro, char ultimo, No no) {
        if (no == null)
            return 0;
        int count = 0;

        if (no.letra == primeiro) {
            count += contarPalavrasFinal(no.raiz, ultimo);
        }

        count += contarPalavras(primeiro, ultimo, no.esq);
        count += contarPalavras(primeiro, ultimo, no.dir);
        return count;
    }

    private int contarPalavrasFinal(No2 raiz, char ultimo) {
        if (raiz == null)
            return 0;
        int count = 0;

        if (raiz.palavra.charAt(raiz.palavra.length() - 1) == ultimo)
            count++;
        count += contarPalavrasFinal(raiz.esq, ultimo);
        count += contarPalavrasFinal(raiz.dir, ultimo);
        return count;
    }

    public void caminharCentral() {
        System.out.print("[ ");
        caminharCentralRec(arvoreLetras.raizArv);
        System.out.print("]");
    }

    private void caminharCentralRec(No raiz) {
        if (raiz != null) {
            caminharCentralRec(raiz.esq);
            System.out.print(raiz.letra + " ");
            caminharCentralRec(raiz.dir);
        }
    }

    public void imprimirPalavrasPorLetra() {
        imprimirPalavrasPorLetraRec(arvoreLetras.raizArv);
    }

    private void imprimirPalavrasPorLetraRec(No no) {
        if (no != null) {
            imprimirPalavrasPorLetraRec(no.esq);
            System.out.print("\n" + no.letra + ": ");
            imprimirPalavrasNo2(no.raiz);
            imprimirPalavrasPorLetraRec(no.dir);
        }
    }

    private void imprimirPalavrasNo2(No2 no2) {
        if (no2 != null) {
            imprimirPalavrasNo2(no2.esq);
            System.out.print(no2.palavra + " ");
            imprimirPalavrasNo2(no2.dir);
        }
    }

    public static void main(String[] args) {
        try {
            Q1 q1 = new Q1();

            q1.inserirLetra('a');
            q1.inserirLetra('b');
            q1.inserirLetra('c');
            q1.inserirLetra('h');
            q1.inserirLetra('g');
            q1.inserirLetra('f');

            q1.caminharCentral();

            q1.inserirPalavra("abacaxi");
            q1.inserirPalavra("azeite");
            q1.inserirPalavra("alicate");

            q1.inserirPalavra("bolao");
            q1.inserirPalavra("bala");
            q1.inserirPalavra("balao");

            q1.inserirPalavra("cachorro");
            q1.inserirPalavra("cai");
            q1.inserirPalavra("cateto");

            q1.inserirPalavra("arateto");
            q1.inserirPalavra("acateto");
            q1.inserirPalavra("atesteto");

            System.out.println();
            q1.imprimirPalavrasPorLetra();

            char primeiro = 'a';
            char ultimo = 'o';

            int count = q1.contarPalavras(primeiro, ultimo);
            System.out.println("\nNúmero de palavras que começam com '" + primeiro + "' e terminam com '" + ultimo + "': " + count);

        } catch (Exception e) {
            System.out.println("Erro: " + e.getMessage());
        }
    }
}
