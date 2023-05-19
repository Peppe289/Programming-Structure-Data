#include <stdlib.h>
#include <bst.h>
#include <item.h>

struct node
{
    struct node *left;
    struct node *right;
    Item value;
};

BST newBST()
{
    return NULL;
}

int isEmptyBST(BST bst)
{
    if (bst == NULL)
        return 1;
    return 0;
}

BST getLeft(BST bst)
{
    if (!isEmptyBST(bst))
        return bst->left;
    return NULL;
}

BST getRight(BST bst)
{
    if (!isEmptyBST(bst))
        return bst->right;
    return NULL;
}

Item getItem(BST bst)
{
    if (!isEmptyBST(bst))
        return bst->value;
    return NULL;
}

Item search(BST bst, Item el)
{
    if (isEmptyBST(bst))
        return NULL;
    if (cmpItem(bst->value, el) == 0)
        return bst->value;
    else if (cmpItem(el, bst->value) < 0)
        return search(bst->left, el);
    else
        return search(bst->right, el);
}
Item min(BST bst)
{
    if (isEmptyBST(bst))
        return NULL;
    while (bst->left != NULL)
        bst = bst->left;
    return bst->value;
}

Item max(BST bst)
{
    if (isEmptyBST(bst))
        return NULL;
    while (bst->right != NULL)
        bst = bst->right;
    return bst->value;
}

void insertBST(BST *bst, Item el)
{
    if (isEmptyBST(*bst))
    {
        (*bst) = malloc(sizeof(struct node));
        (*bst)->right = NULL;
        (*bst)->left = NULL;
        (*bst)->value = el;
    }
    else if (cmpItem(el, (*bst)->value) < 0)
        insertBST(&((*bst)->left), el);
    else if (cmpItem(el, (*bst)->value) > 0)
        insertBST(&((*bst)->right), el);
}

Item deleteBST(BST *bst, Item el)
{
    if (isEmptyBST(*bst))
        return NULL;

    int dif;
    dif = cmpItem(el, (*bst)->value);
    if (dif < 0)
        return deleteBST(&((*bst)->left), el);
    if (dif > 0)
        return deleteBST(&((*bst)->right), el);
    else
    {
        if (isEmptyBST((*bst)->left))
        {
            BST tmp = *bst;
            Item v = tmp->value;
            *bst = (*bst)->right;
            free(tmp);
            return v;
        }
        else if (isEmptyBST((*bst)->right))
        {
            BST tmp = *bst;
            Item v = tmp->value;
            *bst = (*bst)->left;
            free(tmp);
            return v;
        }
        else
        {
            Item mx;
            mx = max((*bst)->left);
            Item a = (*bst)->value;
            (*bst)->value = mx;
            deleteBST(&((*bst)->left), mx);
            return a;
        }
    }
}

#if 0
void printPerLevel(BST bst){
	
}
#endif

/**
 * Restituisce il livello in cui è stato trovato l'elemento
 */
int searchInLevel(BST bst, Item el)
{

    int cmp;
    int ret = -1;

    if (isEmptyBST(bst))
        return ret;

    cmp = cmpItem(el, bst->value);

    if (cmp < 0)
    {
        /**
         * Se il valore è minore controlla il sotto-albero
         * sinistro (dove ci saranno valori minori).
         */
        ret = searchInLevel(bst->left, el);
    }
    else if (cmp > 0)
    {
        /**
         * Se il valore è maggiore controlla il sotto-albero
         * destro (dove ci saranno valori maggiori).
         */
        ret = searchInLevel(bst->right, el);
    }
    else
    {
        /**
         * Valore trovato. Restituisci la profondità della ricerca.
         * Il valore 0 indica la radice del sottoalbero.
         *
         * Salendo su nella ricorsione il valore verrà incrementato.
         * Questo ci garantisce che se il numero si trova alla
         * radice avrà valore 0 e non 1 e così via per restare coerenti
         * con la definizione di livelli enumerati da 0 a L - 1.
         */
        return 0;
    }

    /**
     * Se l'elemento non è stato trovato allora ritorna sempre -1
     * altrimenti incrementa il valore della profondità.
     */
    return ret != -1 ? 1 + ret : -1;
}

int cmpbst(BST data_1, BST data_2)
{

    int right = 0, left = 0;

    if (isEmptyBST(data_1) && isEmptyBST(data_2))
    {
        /**
         * Controlla se entrambi gli alberi sono vuoti
         * (o finiti in caso di sottoalberi).
         *
         * I valori devono essere uguali ed entrambi true.
         */
        return 1;
    }
    else if (isEmptyBST(data_1) || isEmptyBST(data_2))
    {
        /**
         * I valori non sono coerenti. Un albero ha finito e l'altro no.
         * Gli alberi non sono uguali.
         */
        return 0;
    }

    /**
     * Controlla se i valori contenuti sono uguali.
     */
    if (cmpItem(data_1->value, data_2->value) == 0)
    {
        /**
         * Se i valori sono uguali controlla il nodo sinisto
         * e il nodo destro e il loro esito.
         *
         * Se gli alberi non sono ugali verrà restituito 0.
         */
        left = cmpbst(data_1->left, data_2->left);
        right = cmpbst(data_1->right, data_2->right);
    }

    /**
     * Se gli alberi sono uguali entrambi i valori sono true,
     * quindi restituirà 1 altrimenti 0.
     */
    return right && left;
}