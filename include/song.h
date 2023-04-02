#ifndef _PSD_SONG_H_
#define _PSD_SONG_H_

typedef struct song *Song;

Song initSong();
char *title(Song);
char *artist(Song);
float duration(Song);

#endif // _PSD_SONG_H_