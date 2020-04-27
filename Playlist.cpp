/**************************************************************
 * Name of the file: Song.cpp                                 *
 * Group 6: Ra'Caria Burgess, Janei Elliston,                 *
 *          Michael Mondelice, Michael Parrish                *
 * Date last edited: 4/24/2020                                *
 * Purpose of Playlist.cpp: Is to manage the songs, by        *
 * creating                                                   *
 all of the normal functions of a playlist.                   *                           
 **************************************************************/
#include <string>
#include "Song.h"
#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>
#include "Playlist.h"
#include "StringHelper.h"
#include <stdlib.h>  

using namespace std;

Playlist::Playlist()
{
    songnumber = 0;
}

Playlist::Playlist(string name)
{
    songnumber = 0;

    this->title = name;
    string song, artist,album, line;
    int year, songLength;

    ifstream file;
    file.open((StringHelper::stou(name) + ".playlist").c_str());
    while(getline(file,line))
    {
        Song s;
        song = StringHelper::parse(line,',')[0];
        artist = StringHelper::parse(line,',')[1];
        album = StringHelper::parse(line,',')[2];
        year = atoi(StringHelper::parse(line,',')[3].c_str());
        song_length = atoi(StringHelper::parse(line,',')[4].c_str());

        s.set(song,artist,album,song_length,year);
        addSong(s);
        writeToFile();
    }

}

void Playlist::setTitle(string songTitle)
{
    this->title = songTitle;
}

string Playlist::getTitle() const
{
    return name;
}

//will take a Song object as a parameter and insert it into list.
void Playlist::addSong(Song song)
{
    playlist.push_back(song);
}

//will take a Song object as a parameter and delete it list.
bool Playlist:: deleteSong(Song & song)
{   
    for(int i = 0; i < playlist.size(); i++)
    {
        if(song == playlist[i])
        {
          playlist.erase(playlist.begin()+i);
          return true;
        }
    }
    return false;
}

// Adds song to current playlist
Playlist operator+(Playlist & p ,Song & s)
{
    p.addSong(s);
    return p;  
}

  // concatenation of two playlist objects 
Playlist operator+(Playlist & playlist, Playlist & p)
{
    vector<Song> s = p.getPlaylist();
    Playlist p2 = playlist;

    for (int i = 0; i < s.size(); i++)
    {
        p2.addSong(s[i]);
    }  
    return p2;
}
//removing a song from a playlist
Playlist operator-(Playlist & p , Song & song)
{
    p.deleteSong(song);
    return p;  
}

vector<Song> Playlist:: getPlaylist()
{
    return playlist;
}

// Intersection of two playlists will have not have duplicate songs
Playlist Playlist::intersect(Playlist & p)
{
    vector<Song> s1 = this ->playlist;
    vector <Song> s2 = p.getPlaylist();
    Playlist p1 = this ->title;


    for (int i = 0; i < s1.size(); i++)
    {
       if(s1[i] == s2[i])
       {
           p1.appendToFile(s2[i]);
       }
    }
    return p1;  
}


//creates a playlist that is a merge of two playlists.

Playlist Playlist::merge(Playlist & p)
{
    Playlist p1 = this ->title;
    vector<Song> v = p.getPlaylist();
    for (int i = 0; i < v.size() ; i++)
    {
        p1.addSong(v[i]);
        p1.appendToFile(v[i]);
    }
    return p1;

}

//finds what play mode is selected

int Playlist::getPlayingMode()
{
    int count = 0;
    if(mode == 0)
    {
        return count;
        count++;
    }
    if(mode == 1)
    {
        return count;
    }
    if(mode == 2)
    {
        return count;
    }

    return count;
}

// play's one song from the play list starting at first index
void Playlist::play()
{
    if(mode == 0 || mode == 2)
    {
        cout << playlist[songnumber] << endl;
        songnumber++;
    }
    if(mode == 1)
         cout << playlist[songnumber] << endl;
    if (mode == 2 && songnumber == playlist.size())
    {
        songnumber = 0;
    }
    if (mode == 0 && songnumber == playlist.size())
    {
        cout << " END OF PLAYLIST" << endl;
        return;
    }
   
}


// sets player mode Normal Repeat Loop
void Playlist::setMode(char playingMode)
{
    if(playingMode == 'N')
        mode = 0;
    if(playingMode == 'R')
        mode = 1;
    if(playingMode == 'L')
        mode = 2;
}

void Playlist::appendToFile(Song song)
{
    ofstream file;
    file.open((StringHelper::stou(title) + ".playlist").c_str(), ios::app);
    file << song;
    
}
void Playlist::writeToFile()
{
    ofstream file;
    file.open((StringHelper::stou(title) + ".playlist").c_str());
    for (int i = 0; i < playlist.size(); i++)
    {
       file << playlist[i];
    }
}

ostream& operator<<(ostream& os, const Playlist& playlist)
{
    for(int i = 0; i < playlist.playlist.size(); i++)
   {
    os << playlist.playlist[i] << endl;
      
       return os;
   }
   
}

 Playlist:: Playlist(const Playlist & p) 
 {
    playlist = p.playlist;
 }

void Playlist::printPlaylist()
{
    for(int i = 0; i < playlist.size(); i++)
        cout << playlist[i] << endl;

}
 
Playlist::Playlist(){
        name = " ";
        now_playing = 0;
        play_mode = 'N';
        playlist = {};
    }
