/**************************************************************
 * Name of the file: Song.cpp                                 *
 * Group 6: Ra'Caria Burgess, Janei Elliston,                 *
 *          Michael Mondelice, Michael Parrish                *
 * Date last edited: 4/26/2020                                *
 * Purpose of Player.cpp: allow users to create new named     8
 * playlist, view all the playlists, merge (intersect)        *
 * exisiting playlists into a new list, and play a playlist.  *                           
 **************************************************************/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include "Playlist.h"
#include "StringHelper.h"
#include "Song.h"

using namespace std;
// STATIC 
int PlayList::mode = 0;
struct songDetails
{
  string name;
  string filename;
};

void parse(vector<string>&temp,string songLine){
   string word = ""; 
   for (int x=0;x<songLine.length();x++) 
   { 
       if (songLine[x] == ',') 
       { 
          temp.push_back(word);
          // cout << word << endl; 
           word = ""; 
       } 
       else
       { 
           word = word + songLine[x]; 
       } 
   }  
   temp.push_back(word);
}
void ShowPlaylist(vector<Playlist>&list){
  for(int i = 0; i < list.size(); i++){
    cout << (i+1) << "- " << list[i].getName()<<endl;
  }
  cout << endl;
}
         
void PFileOpen(string name, vector <string> & p)
{
    string word;
    ifstream inFile;
    inFile.open(name.c_str());
    while(inFile >> word )
    {
        p.push_back(word);
       
    }

       
}

void OutputToPlaylistFileNewList(string playlist){
  ofstream f;
  f.open("Playlist.plist",ios::app);
  f << endl << playlist;
}

void createNewList(vector<Playlist>&lists, Playlist list, string file){ //accepts a vector as arguement and creates a new playlist.
   lists.push_back(list);
   string name;
   int v_size= lists.size();
   cout <<"Name of new playlist (cannot contain underscores): ";
   cin >> name;
   lists[v_size].setName(name);
   OutputToPlaylistFileNewList(name)
  
}
void loadPlayList(vector<songDetails> &Songs)
{
  int count=0;
  ifstream inFile;
  inFile.open("Playlist.list");
  string filename;
  songDetails l;
    while (getline(inFile,filename)
    {
      StringHelper::utos(filename);
      Songs.push_back(l);
      Songs[count].setName(filename);
      count++;
    }
  
  inFile.close();
}


/*void PlaylistMenu(vector<Playlist>&list){
    int count;
    int choice3, sel1, sel2;
    string playlistN;
    bool C;
    do{
       */    
void erase(vector<string> & p)
{
   sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
}
           
void SongMenu(vector<Playlist>playlist, char sel ){ // menu takes integer argument so that the specific playlist vector can be referenced by functions in this menu (example: mp3[location].addSong()) 
    Playlist List;
    Song S;
    string title, artist, album, year, len,;
    bool C;
    char m, sel;
    
    do{
        Spot:
        cout<<"You are now playing: " p.getTitle() << endl
            cout << "You are now playing: " << p.getTitle() << endl;
            cout << setw(24) << right << "A - Add a song\n";
            cout << setw(27) << right << "D - Delete a song\n";
            cout << setw(25) << right << "P - Play a song\n";
            cout << setw(24) << right << "M - Set the mode\n";
            cout << setw(28) << right << "S - Show all songs\n";
            cout << setw(18) << right << "Q - Quit" << endl;
            cout << "Selection: ";
              cin>> sel;
        sel = toupper(sel);
      
        switch(sel)
        {
            
        case 'A': {
            // RUN ADD SONG (need) 
         cout << "Song Details\n";
         cout << "Title: ";
         getline(cin,title);
         cout << "Artist: ";
         getline(cin, tisist);
         cout << "Album: ";
      a getline(cin ,album);
         cout << "Year: ";
         getline(cin ,year);      
          cout << "Length (in seconds): ";
         getline(cin,len);
         S.set(title, artist, album, year, len);
         List.AttachToFile(S);
         List.addSong(S);
        }
          break;
            
        case 'D':{
            // Delete song function (need)
             cout << "Enter to delete: ";
             cout << "Title: ";
             cin >> S;
             cout << "Artist: ";
             cin >> S;
             C = List.deleteSong(S);
              if(C == true)
                cout << "Song successfully deleted" << endl;
             else
                cout << "Song not found in playlist" << endl;
        }
          break;
            
        case 'P':{
             //play song function
             List.play();
             goto Spot;
        }
          break;
            
        case 'M':{
            //run set mode function 
            cout << "Enter Mode: \n";
            cout << "N - Normal\n";
            cout << "R - Repeat\n";
            cout << "L - Loop" << endl;
            cout << "Selection: ";
            cin >> m;
            List.setMode(toupper(m));
        }
          break;
         
        case 'S':{
            List.print();
        }
          break;
            
        case 'Q':{
          
        }
          break;
            
        default:{
            cout<< "Invalid Input! Please try again." << endl << endl;
        }
          break;
        }
            
    }while(sel != 'Q');
}

int main(){
    ifstream inF,inF2;
    vector<string> mp3;
    
    //SELCTION CONTROLS
    int choice, sel1, sel2;
    char s, mode;
  
    //PLAYLIST
    string title, artist, album, selection, newP;
    int year, length;
  
 //OPENING THE FILE

   do{
     //open playlist file and store data in vectors  
    PFileOpen("Playlist.list", mp3);
     eraseDuplicates(mp3);

   
    cout << "----------WELCOME to the AutoPlayer----------" << endl << endl;
    cout << "You currently have " << list.size() << " playlist(s)." << endl;
    cout << "1 - Open an exisiting playlist\n";
    cout << "2 - Create new list\n";
    cout << "3 - Exit\n";
    cout << "Selection: "; 
    cin >> choice1;
    cout << endl;
         
        
        if(choice1==1){
         cout << "Please select a playlist from below: " << endl;
          ShowPlaylist(list);
        do{
             cout  << "Selection: ";
              cin >> sel;
                 if(sel < 1 || sel > mp3.size())
                cout << "Invalid Choice" << endl << endl;
          
         }while(choice2 < 1 || choice2 > mp3.size());
          
          selection = list[sel-1];
          Playlist mp3(selection);
             SongMenu(mp3, sel1); //HEY
   
        }
     
        
        else if(choice1==2){
           cout << "1 - Create new empty list" << endl
                << "2 - Merge 2 existing playlists" << endl
                << "3 - Intersect 2 existing playlists" << endl
                << "Selection: ";
                cin >> choice3;

         
        switch(choice3)
        {
          case 1: {
          cout << "Name of new playlist (cannot contain underscores): ";
          cin.ignore();
          getline(cin,newP);
          OutputToPlaylistFileNewList("Playlist.list", newP)
           cout << " Your are now playing: " << list[i].getName << endl;
            SongMenu(list.size()); // opens song menu afterwards so that songs can be added to list.
            
            break;
        }
          case 2:
          {
        // merge 2 playlist function (need)
        cout << "Which of the following playlists would you like to merge" << endl;
        ShowPlaylist(list);
        Playlist mp3(playlistN);
        OutputToPlaylistFileNewList("Playlist.list", newP);
           cout << "Playlist 1: ";
           cin >> choice1;
           cout << endl;
           choice = mp3[choice1-1];
           Playlist p(choice);
           p3.merge(p);
           cout << "Playlist 2: ";
           cin >> choice2;
           cout << endl;
           choice2 = mp3[choice2-1];
           Playlist p1(choice2);
           p3.merge(p1);
           p3.merge(p);
          
      break;
        }
          case 3:
            {
         cout << "Which of the following playlists would you like to intersect? " << endl; 
           for(int i = 0; i < play.size(); i++)
           {
               cout <<  i + 1 << " " << play[i] << endl;
           }
           Playlist p3(playlistN);
          OutputToPlaylistFileNewList("Playlist.list", newP);
           cout << "Playlist 1: ";
           cin >> choice1;
           cout << endl;
           C = mp3[choice1-1];
           Playlist p(choice);
           p3  = p;
           cout << "Playlist 2: ";
           cin >> choice2;
           cout << endl;
           choice2 = mp3[choice2-1];
           Playlist p1(choice2);
           p3.intersect(p1);
        }
       break;
          default:{
           cout << "Invalid Entry. Please input a valid entry."  << endl;
           
    
        }
        
        else if(choice1!=3){
            cout << "Invalid entry. Please enter valid option" << endl << endl;
        }
        
        
        
    }while(choice1!=3);
    return 0;
}
