# Esercizi di programmazione
Qui puoi trovare esercizi di programmazione svolti e corretti da memory leak e problemi di prestazioni. Ogni esercizio commentato nel miglior modo possibile.

VSCode: configurazione automatica
---
Puoi configurare automatica VSCode per il debug utilizzando lo script `conf.sh` presente nella direcotry. Esegui il comando nella directory del tuo progetto:

```bash
bash -c "$(curl -fsSL https://raw.githubusercontent.com/Peppe289/Programming-C/main/conf.sh)"
```

Per poter utilizzare questo script devi aver installato `curl` sul tuo sistema.

### Informazioni utili

Lo script `conf.sh` confiura nel root del tuo progetto settaggi utili per VSCode. Tra i flag di build:
- -lm : Flag per math.h (libreria dinamica)
- -g : Utile per il debug
- -O3 : La migliore ottimizzazione che puoi trovare. [Approfondisci](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html)
- -Wall e -Wextra : Per un debug totale in fase di compilazione
- -fstack-usage : Per controllare lo spazio occupato dalla memoria statica.

*Attenzione : Questa configurazione compila su un singolo file. Se vuoi cambiare questo modifica il file `.vscode/tasks.json`* 


Strumenti usati per il controllo
---

- Editor di testo : `VSCode`
- Compilatore : `gcc 12.y.y`
- Debugging memoria : `valgrind` 

Valgrind
---
Approfondisci l'uso di [valgrind sul loro sito](https://valgrind.org/). 
I flag che utilizzo:

```shell
--tool=memcheck --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes -s
```
GCC flag
---
Per il controllo di eventuali possibili problemi di sintassi uso `-Wall`. Per il controllo dell'uso dello stack `-fstack-usage`. <br>
Ogni diverse versioni di C hanno diversi usi sul alcune cose. Per capire la differenza tra una funzione e un'altra basta cambiare versione da far usare a GCC con il flag: `-std=X` dove `X` è la versione.
