# Esercizi di programmazione
Qui puoi trovare esercizi di programmazione svolti e corretti da memory leak e problemi di prestazioni. Ogni esercizio commentato nel miglior modo possibile.

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
