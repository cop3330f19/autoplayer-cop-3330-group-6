/**************************************************************
 * Name of the file: Song.cpp                                 *
 * Group 6: Ra'Caria Burgess, Janei Elliston,                 *
 *          Michael Mondelice, Michael Parrish                *
 * Date last edited: 4/24/2020                                *
 * Purpose of Playlist.h: Is to manage the songs, by creating *
 all of the normal functions of a playlist.                   *                           
 **************************************************************/

#include "Playlist.h"
 
void Playlist::setName(std::string n){
    name = n;
}
 
std::string Playlist::getName(){
    return name;
}
 
void Playlist::addSong(Song song){
    playlist.push_back(song);
}
 
bool Playlist::deleteSong(Song song){
    bool has_song = false;
 
 for(int i = 0; i < playlist.size(); i++)
    if(song == playlist[i]){
       playlist.erase(playlist.begin()+i);
         has_song = true;
        }
    }
    
    return has_song;
}
 
Playlist Playlist::intersect(Playlist i_list){
    Playlist intersect_list;
 
 for(Song s: playlist){
    for(Song i: i_list.playlist){
       if(s == i){
                intersect_list.addSong(s);
                break;
            }
        }
    }
 
  return intersect_list;
}
 
Playlist Playlist::merge(Playlist m_list){
    Playlist merge_list;
 
    for(Song s: playlist){
        merge_list.addSong(s);
    }
 
    for(Song s: m_list.playlist){
        merge_list.addSong(s);
    }
 
    return merge_list;
}
 
void Playlist::play(){
 
  switch(play_mode){
   case 'N':
      if(now_playing < playlist.size()){
         std::cout << "NOW PLAYING: " << playlist[now_playing] << std::endl;
             now_playing++;
            }
            break;
   case 'R':
     std::cout << "NOW PLAYING: " << playlist[now_playing] << std::endl;
       break;
   case 'L':
     if(now_playing < playlist.size()){
        std::cout << "NOW PLAYING: " << playlist[now_playing] << std::endl;
           now_playing++;  
            }
            
        if(now_playing == playlist.size()){
              now_playing = 0;
            }
            break;
     default:
        if(now_playing < playlist.size()){
           std::cout << "NOW PLAYING: " << playlist[now_playing] << std::endl;
             now_playing++;
            }
            break;
    }
}
 
void Playlist::setMode(char mode){
    //N = Normal
    //R = Repeat
    //L = Loop
    char m = toupper(mode);
 
    if(m != 'N' && m != 'R' && m != 'L'){
        return;
    }else {
        play_mode = m;
    }
}
 
std::ostream& operator<<(std::ostream& os, const Playlist& pList){
    os << "PLAYLIST SONGS" << std::endl;
    os << "--------------------------------" << std::endl;
    for(Song s: pList.playlist){
        os << s << std::endl;
    }
    os << "--------------------------------" << std::endl;
    return os;
};
 
Playlist operator+(Playlist p1, Playlist p2){
    Playlist merge_list;
 
    for(Song s: p1.playlist){
        merge_list.addSong(s);
    }
    for(Song s: p2.playlist){
        merge_list.addSong(s);
    }
 
    return merge_list;
};
 
Playlist operator+(Playlist p, Song song){
    Playlist plus_list;
 
    for(Song s: p.playlist){
        plus_list.addSong(s);
    }
 
    plus_list.playlist.push_back(song);
    return plus_list;
};
 
Playlist operator-(Playlist p, Song song){
    Playlist d_list;
 
    for(Song s: p.playlist){
        if(!(s == song)){
            d_list = d_list+s;
        }
    }
 
    return d_list;
};
 
Playlist::Playlist(){
        name = " ";
        now_playing = 0;
        play_mode = 'N';
        playlist = {};
    }
