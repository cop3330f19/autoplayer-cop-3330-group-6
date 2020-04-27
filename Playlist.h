/**************************************************************
 * Name of the file: Song.cpp                                 *
 * Group 6: Ra'Caria Burgess, Janei Elliston,                 *
 *          Michael Mondelice, Michael Parrish                *
 * Date last edited: 4/24/2020                                *
 * Purpose of Playlist.h: Is to manage the songs, by creating *
 all of the normal functions of a playlist.                   *                           
 **************************************************************/

#ifndef PLAYLIST_H
#define  PLAYLIST_H

#include <string>
#include "Song.h"
#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>

class Playlist
{
   private:
   std::string name;
   std::vector<Song> playlist;
   static int mode;
   void writeToFile();
   int songnumber;

   public:

   // Constructors
   Playlist();
   Playlist(std::string);
   Playlist(const Playlist &p2);

   friend std::ostream& operator<<(std::ostream& os, const Playlist& playlist);
   //output to file
   friend std::ofstream& operator<<(std::ofstream& os, const Playlist& playlist);

   // input the playlist in the format:
   // title
   friend std::istream& operator>>(std::istream& is, Playlist& playlist);
   //input from file
   friend std::fstream& operator>>(std::fstream& is, Playlist& playlist);

   void setTitle(std::string);

   std::string getTitle() const;
   //adds song to playlist
   void addSong(Song song);
   //deletes song from playlist
   bool deleteSong(Song & song);
   // Adds song to playlist current playlist
   Playlist friend operator+(Playlist &p ,Song &s);
   // concatenation of the two playlist objects 
   Playlist friend operator+(Playlist & playlist , Playlist & p2);
   //removing a song(s) from a playlist
   Playlist friend operator-(Playlist &p , Song & song);

   
   Playlist intersect(Playlist & Playlist);
  
   Playlist merge(Playlist & Playlist);
   
   //plays next indexed song
   void play();
   //sets the mode for play function 
   static void setMode(char);
   //pull for checking play mode
   static int getPlayingMode();

   std::vector<Song> getPlaylist();
  // prints all songs in vector
  void printPlaylist();

  void appendToFile(Song song);

};

#endif
