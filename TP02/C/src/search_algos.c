#include "../include/search_algos.h"
#include "../include/common.h"
#include "../include/linked_list.h" // Para getElementByID
#include "../include/personagem.h"  // Para Personagem
#include "../include/utils.h"      // Para equals, isBigger

// Método para fazer uma pesquisa binária
bool binarySearch (StringArray armazenamentoIDs, String searched, int left, int right, ListPersonagem *List, Log *log)
{
    bool found = false;
    int middle;
    Personagem personagem;

    // É importante que o 'armazenamentoIDs' esteja ordenado para a busca binária.
    // O original do código C comentava uma linha de quicksort que talvez se aplicasse a isso.
    // Se 'armazenamentoIDs' não estiver ordenado, a busca binária não funcionará corretamente.

    while(left <= right)
    {
        middle = (left + right) / 2;
        // As comparações aqui devem ser baseadas nos IDs ou Nomes que estão em 'armazenamentoIDs',
        // não necessariamente nos campos alternativos ou outros campos da Personagem que não estão sendo ordenados.
        // Se a busca binária é para 'armazenamentoIDs' (que contém IDs), a comparação principal deve ser com o ID.
        // Se 'searched' é um nome, 'armazenamentoIDs' precisa estar ordenado por nome.

        // O trecho original da busca binária é um pouco complexo e potencialmente incorreto
        // para uma busca binária padrão baseada em um único critério de ordenação.
        // Vou adaptar para uma busca binária por ID ou Nome, assumindo que 'armazenamentoIDs' está ordenado pelo critério 'searched' se 'searched' é um nome.

        // A linha original 'personagem = getElementByID(armazenamentoIDs[middle], List);'
        // pode ser lenta se a lista encadeada for grande.
        // Para uma busca binária eficiente, o vetor 'armazenamentoIDs' *deve* estar ordenado.

        // Assumindo que 'armazenamentoIDs' contém IDs e 'searched' é um ID:
        log->comparacoes++;
        int cmp_result = strcmp(armazenamentoIDs[middle], searched);

        if(cmp_result == 0) // Encontrou o ID
        {
            // O seu original também verificava outros campos do personagem.
            // Isso não é busca binária de ID, mas sim uma busca binária que, ao encontrar o ID,
            // tenta ver se o nome do personagem ou nomes alternativos também correspondem ao 'searched'.
            // Isso faz com que a busca binária seja "por ID ou nome" e é incomum para uma busca binária.
            // Para manter a funcionalidade original (mas com a observação de que é atípico para busca binária):

            personagem = getElementByID(armazenamentoIDs[middle], List); // Pega a personagem para verificar outros nomes
            if (equals(personagem.name, searched) ||
                (personagem.alternative_names != NULL && personagem.alternative_names->size > 0 &&
                 (equals(personagem.alternative_names->element[0], searched)
                  || (personagem.alternative_names->size > 1 && equals(personagem.alternative_names->element[1], searched))
                  || (personagem.alternative_names->size > 2 && equals(personagem.alternative_names->element[2], searched))
                  || (personagem.alternative_names->size > 3 && equals(personagem.alternative_names->element[3], searched))
                  || (personagem.alternative_names->size > 4 && equals(personagem.alternative_names->element[4], searched))
                  || (personagem.alternative_names->size > 5 && equals(personagem.alternative_names->element[5], searched))
                  || (personagem.alternative_names->size > 6 && equals(personagem.alternative_names->element[6], searched)))))
            {
                 found = true;
                 left = right + 1; // Termina a busca
            } else {
                // Se o ID foi encontrado mas o nome/alternativos não batem,
                // significa que o 'searched' é um nome que não corresponde a este ID.
                // A busca binária de IDs não pode ser usada para encontrar nomes
                // a menos que o array 'armazenamentoIDs' esteja ordenado por nome.
                // Aqui, o algoritmo está tentando fazer uma busca binária de IDs e uma busca sequencial de nomes.
                // Para simplificar e fazer uma busca binária *de IDs*:
                // found = true; // Descomente esta linha se a busca binária for *apenas* por ID.
                // left = right + 1;
                // E remova todo o 'if' interno
                // Ou, se a intenção é buscar nomes, 'armazenamentoIDs' deve ser ordenado por nome.
                left = middle + 1; // Se o ID não é o que buscamos pelo nome, avançar
            }

        } else if (cmp_result < 0) // searched é maior (o que está no meio é menor)
        {
            left = middle + 1;
        } else // searched é menor (o que está no meio é maior)
        {
            right = middle - 1;
        }
    }
    return ( found );
}