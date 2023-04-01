#include <stdlib.h>
#include <stdio.h>
#include "song.h"
#include "playlist.h"
#include "list.h"
#include "item.h"
#include <string.h>

struct playlist
{
	char *name;
	List songs;
};

struct song
{
	char *title;
	char *artist;
	/**
	 * Modifica sulla traccia.
	 * Utilizzo del float per la virgola.
	 */
	float duration;
};

List songList(Playlist data) {
	return data->songs;
}

/**
 * Ogni Playlist contiene un nome e punta ad un indirizzo
 * di una struct che contiene la dimensione (ovvero il numero di canzoni)4
 * e la prima canzone.
 * 
 * Crea quindi la memoria heap di Playlist e poi l'inizio della
 * lista delle canzoni.
 */
Playlist createPlaylist(char *name) {
	Playlist ret = malloc(sizeof(struct playlist));
	ret->name = name;
	ret->songs = newList();
	return ret;
}

/**
 * Prende in input e alloca dinamicamente la stringa.
 * Il valore di ritorno è la stringa.
 * 
 * Il vantaggio di questa funzione è il poter prendere gli spazi.
 */
static char *inputString() {
	char *ret;
	char tmp;
	int size = 1;
	ret = malloc(size * sizeof(char));

	do {
		tmp = getchar();
		ret = realloc(ret, (++size) * sizeof(char));
		ret[size - 2] = tmp;
	} while(tmp != '\n');

	return ret;
}

/**
 * L'input viene fatto per titolo, artista e durata.
 * Tutto nella memoria heap.
 */
Song initSong() {
	Song ret;

	ret = malloc(sizeof(struct song));

	printf("Inserisci il nome dell'artista: ");
	ret->artist = inputString();

	printf("Inserisci il nome della canzone: ");
	ret->title = inputString();

	printf("Inserisci la durata della canzone: ");
	scanf("%f", &ret->duration);

	// pulisci il buffer
	getchar();

	return ret;
}

Item inputItem () {
	return initSong();
}

/**
 * Nel main utilizziamo la struct Playlist che punta a List.
 * List contiene le informazioni sulla lista.
 * Quindi referenziamo a head->songs per avere list.
 */
void addSong(Playlist head, Song data) {
	addHead(head->songs, data);
}

char *title(Song data) {
	return data->title;
}
char *artist(Song data) {
	return data->artist;
}
float duration(Song data) {
	return data->duration;
}

void outputItem(Item data){
	Song output = data;

	printf("\nNome dell'artista: %s", artist(output));
	printf("\nNome della canzone: %s", title(output));
	printf("\nDurata della canzone: %f\n\n", duration(output));
}

int cmpItem(Item data1, Item data2) {
	char *p1=((struct song *)data1)->title;
	char *p2=((struct song *)data2)->title;

	return strcmp(p1,p2);
}
