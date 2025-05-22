package Java.helpers;

import java.io.IOException;
import java.util.List;

/**
 * Implementações de algoritmos de ordenação com Timer.
 */
public class SortUtils {

    /** Selection Sort completo, log em 816676_selecao.txt */
    public static void selecao(String[] vetor) throws IOException {
        Timer t = new Timer("816676_selecao.txt");
        int n = vetor.length;
        for (int i = 0; i < n; i++) {
            int menor = i;
            for (int j = i + 1; j < n; j++) {
                t.comparacao();
                if (vetor[j].compareTo(vetor[menor]) < 0) {
                    menor = j;
                }
            }
            String tmp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = tmp;
            t.movimentacao(3);
        }
        t.logAndReset();
    }

    /** Selection Sort parcial, log em 816676_selecaoParcial.txt */
    public static void selecaoParcial(String[] vetor, int l) throws IOException {
        Timer t = new Timer("816676_selecaoParcial.txt");
        int n = vetor.length;
        for (int i = 0; i < l && i < n; i++) {
            int menor = i;
            for (int j = i + 1; j < n; j++) {
                t.comparacao();
                if (vetor[j].compareTo(vetor[menor]) < 0) {
                    menor = j;
                }
            }
            String tmp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = tmp;
            t.movimentacao(3);
        }
        t.logAndReset();
    }

    /** Insertion Sort completo, log em 816676_insercao.txt */
    public static void insercao(List<Personagem> list) throws IOException {
        Timer t = new Timer("816676_insercao.txt");
        int n = list.size();
        for (int i = 1; i < n; i++) {
            Personagem pivot = list.get(i).clone();
            int j = i - 1;
            while (j >= 0) {
                t.comparacao();
                if (Utils.desempateYearOfBirth(pivot, list.get(j)) < 0) {
                    list.set(j + 1, list.get(j));
                    t.movimentacao(1);
                    j--;
                } else {
                    break;
                }
            }
            list.set(j + 1, pivot);
        }
        t.logAndReset();
    }

    /** Insertion Sort parcial, log em 816676_insercaoParcial.txt */
    public static void insercaoParcial(List<Personagem> list, int l) throws IOException {
        Timer t = new Timer("816676_insercaoparcial.txt");
        int n = list.size();
        for (int i = 1; i < l && i < n; i++) {
            Personagem pivot = list.get(i).clone();
            int j = i - 1;
            while (j >= 0) {
                t.comparacao();
                if (Utils.desempateYearOfBirth(pivot, list.get(j)) < 0) {
                    list.set(j + 1, list.get(j));
                    t.movimentacao(1);
                    j--;
                } else {
                    break;
                }
            }
            list.set(j + 1, pivot);
        }
        t.logAndReset();
    }

    /** Heap Sort, log em 816676_heapSort.txt */
    public static void heapSort(List<Personagem> list) throws IOException {
        Timer t = new Timer("816676_heapSort.txt");
        int n = list.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            buildHeap(list, n, i, t);
        }
        for (int i = n - 1; i > 0; i--) {
            Personagem tmp = list.get(0);
            list.set(0, list.get(i));
            list.set(i, tmp);
            t.movimentacao(3);
            buildHeap(list, i, 0, t);
        }
        t.logAndReset();
    }

    private static void buildHeap(List<Personagem> list, int size, int root, Timer t) {
        int largest = root;
        int l = 2 * root + 1;
        int r = 2 * root + 2;
        if (l < size) {
            t.comparacao();
            if (Utils.desempateHairColour(list.get(l), list.get(largest)) > 0) {
                largest = l;
            }
        }
        if (r < size) {
            t.comparacao();
            if (Utils.desempateHairColour(list.get(r), list.get(largest)) > 0) {
                largest = r;
            }
        }
        if (largest != root) {
            Personagem tmp = list.get(root);
            list.set(root, list.get(largest));
            list.set(largest, tmp);
            t.movimentacao(3);
            buildHeap(list, size, largest, t);
        }
    }

    /** Merge Sort completo, log em 816676_mergeSort.txt */
    public static void mergeSort(List<Personagem> list) throws IOException {
        Timer t = new Timer("816676_mergeSort.txt");
        mergeSortRec(list, 0, list.size() - 1, t);
        t.logAndReset();
    }

    private static void mergeSortRec(List<Personagem> list, int esq, int dir, Timer t) {
        if (esq < dir) {
            int meio = (esq + dir) / 2;
            mergeSortRec(list, esq, meio, t);
            mergeSortRec(list, meio + 1, dir, t);
            intercalar(list, esq, meio, dir, t);
        }
    }

    private static void intercalar(List<Personagem> list, int esq, int meio, int dir, Timer t) {
        int n1 = meio - esq + 1;
        int n2 = dir - meio;
        Personagem[] left = new Personagem[n1];
        Personagem[] right = new Personagem[n2];
        for (int i = 0; i < n1; i++) {
            left[i] = list.get(esq + i);
        }
        for (int j = 0; j < n2; j++) {
            right[j] = list.get(meio + 1 + j);
        }
        int i = 0, j = 0, k = esq;
        while (i < n1 && j < n2) {
            t.comparacao();
            if (Utils.desempateYearOfBirth(left[i], right[j]) <= 0) {
                list.set(k++, left[i++]);
            } else {
                list.set(k++, right[j++]);
            }
            t.movimentacao(1);
        }
        while (i < n1) {
            list.set(k++, left[i++]);
            t.movimentacao(1);
        }
        while (j < n2) {
            list.set(k++, right[j++]);
            t.movimentacao(1);
        }
    }

    /** Quicksort Parcial (top k), log em 816676_quickSortParcial.txt */
    public static void quickSortPartial(List<Personagem> list, int k) throws IOException {
        Timer t = new Timer("816676_quickSortParcial.txt");
        quickSortRec(list, 0, list.size() - 1, k, t);
        t.logAndReset();
    }

    private static void quickSortRec(List<Personagem> list, int esq, int dir, int k, Timer t) {
        if (esq >= dir)
            return;
        int i = esq, j = dir;
        Personagem pivot = list.get((esq + dir) / 2);
        while (i <= j) {
            while (true) {
                t.comparacao();
                if (Utils.desempateHouse(pivot, list.get(i)) > 0)
                    i++;
                else
                    break;
            }
            while (true) {
                t.comparacao();
                if (Utils.desempateHouse(pivot, list.get(j)) < 0)
                    j--;
                else
                    break;
            }
            if (i <= j) {
                Personagem tmp = list.get(i);
                list.set(i, list.get(j));
                list.set(j, tmp);
                t.movimentacao(3);
                i++;
                j--;
            }
        }
        if (esq < j)
            quickSortRec(list, esq, j, k, t);
        if (i < k)
            quickSortRec(list, i, dir, k, t);
    }

    /** Counting Sort completo */
    public static void countingSort(List<Personagem> list) throws IOException {
        Timer t = new Timer("816676_countingsort.txt");
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        for (Personagem p : list) {
            min = Math.min(min, p.getYearOfBirth());
            max = Math.max(max, p.getYearOfBirth());
        }
        int range = max - min + 1;
        int[] count = new int[range];
        for (Personagem p : list)
            count[p.getYearOfBirth() - min]++;
        for (int i = 1; i < range; i++)
            count[i] += count[i - 1];
        Personagem[] sorted = new Personagem[list.size()];
        for (int i = list.size() - 1; i >= 0; i--) {
            int idx = list.get(i).getYearOfBirth() - min;
            sorted[--count[idx]] = list.get(i);
        }
        for (int i = 1; i < sorted.length; i++) {
            while (i > 0 && sorted[i - 1].getYearOfBirth() == sorted[i].getYearOfBirth()
                    && sorted[i - 1].getName().compareTo(sorted[i].getName()) > 0) {
                t.comparacao();
                t.comparacao();
                t.movimentacao(3);
                Personagem tmp = sorted[i - 1];
                sorted[i - 1] = sorted[i];
                sorted[i] = tmp;
                i--;
            }
        }
        for (int i = 0; i < list.size(); i++)
            list.set(i, sorted[i]);
        t.logAndReset();
    }
}
