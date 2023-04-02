#ifndef _PSD_PLAYLIST_H_
#define _PSD_PLAYLIST_H_

#include <song.h>
#include <list.h>
typedef struct playlist *Playlist;

Playlist createPlaylist(char *name);
void addSong(Playlist, Song);

List songList(Playlist data);
void *findName(List data, char *name);

#endif // _PSD_PLAYLIST_H_