#include <stdio.h>
#include <string.h>
#include <item.h>
#include <stack.h>
#include <stdlib.h>

struct stack
{
    Item *elements;
    int top;
    int dim;
};

/*************************************************
***************** inline func ********************
**************************************************/

INLINE_STATIC
int isOpen(char ch)
{
    return (ch == '(') || (ch == '[') || (ch == '{');
}

INLINE_STATIC
int isClosed(char ch)
{
    return (ch == ']') || (ch == '}') || (ch == ')');
}

INLINE_STATIC
int isCorresponding(char ch1, char ch2)
{
    return (ch1 == ch2 - 1) || (ch1 == ch2 - 2);
}

/*************************************************
**************************************************/

static int isBalanced(char *exp)
{
    /**
     * stack per caricare le parentesi aperte.
     */
    Stack stackdata = newStack();
    /**
     * pointer al primo elemento dello stack. serve per il confronto.
     */
    char *ch;
    int ret;
    int i;

    for (i = 0; i < (int)strlen(exp); i++)
    {
        /**
         * Prendi il primo valore dello stack per poi confrontarlo.
         */
        ch = (char *)top(stackdata);

        /**
         * Se il char è una parentesi aperta allora carica nello stack
         * per il confronto successivo.
         */
        if (isOpen(exp[i]))
        {
            push(stackdata, &exp[i]);
            continue;
        }

        /**
         * Se il char non è una parentesi chiusa torna alla condizione.
         */
        if (!isClosed(exp[i]))
            continue;

        /**
         * Se lo stack è vuoto e il valore di char è una parentesi
         * chiusa allora non è bilanciato a prescindere.
         */
        if (ch == NULL)
        {
            ret = 0;
            goto exit;
        }

        /**
         * Se la parentesi chiusa corrisponde al primo elemento
         * dello stack allora fai il pop. Il gruppo è bilanciato.
         */
        if (isCorresponding(*ch, exp[i]))
        {
            pop(stackdata);
        }
        else
        {
            /**
             * Se è una parentesi chiusa ma non corrisponde
             * alla testa dello stack allora possiamo dire
             * che già non è bilanciato.
             */
            ret = 0;
            goto exit;
        }
    }

    /**
     * Se lo stack è vuoto allora tutti i pop sono stati fatti.
     * Allora è bilanciato.
     */
    ret = isEmptyStack(stackdata);

exit:
    free(stackdata->elements);
    free(stackdata);

    return ret;
}

/**
 * Prende in input e alloca dinamicamente la stringa.
 * Il valore di ritorno è la stringa.
 *
 * Il vantaggio di questa funzione è il poter prendere gli spazi.
 */
static char *inputString()
{
    char *ret = NULL;
    char tmp;
    int size = 0;

    do
    {
        tmp = (char)getchar();
        ret = realloc(ret, (unsigned long int)(++size) * sizeof(char));
        ret[size - 1] = tmp;
    } while (tmp != '\n');

    ret[size - 1] = '\0';

    return ret;
}

/**
 * E' possibile prendere l'input sia da argv sia interno al programma.
 */
int main(int argc, char **argv)
{
    char *exp;

    if (argc == 1)
    {
        printf("Inserisci l'espressione: ");
        exp = inputString();
    }
    else
    {
        exp = argv[1];
    }

    if (isBalanced(exp))
        printf("L'espressione è bilanciata\n");
    else
        printf("L'espressione non è bilanciata\n");

    if (argc == 1)
        free(exp);

    return 0;
}
