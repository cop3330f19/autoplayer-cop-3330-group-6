#include <iostream>

#include <string>

#include <vector>

 

#include "Song.h"

 

class Playlist {

    public:

        Playlist();

        void setName(std::string);

        std::string getName();

        void addSong(Song);

        bool deleteSong(Song);

        Playlist intersect(Playlist);

        Playlist merge(Playlist);

        void play();

        void setMode(char);

    private:

        friend class Song;

        std::string name;

        int now_playing;

        char play_mode;

        std::vector<Song> playlist;

 

       

 

        friend std::ostream& operator<<(std::ostream& os, const Playlist& playlist);

        friend Playlist operator+(Playlist p1, Playlist p2);

        friend Playlist operator+(Playlist p, Song s);

        friend Playlist operator-(Playlist p, Song s);

 

   

};
