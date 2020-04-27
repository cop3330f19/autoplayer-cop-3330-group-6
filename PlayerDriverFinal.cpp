/**************************************************************
 * Name of the file: Song.cpp                                 *
 * Group 6: Ra'Caria Burgess, Janei Elliston,                 *
 *          Michael Mondelice, Michael Parrish                *
 * Worked with Amani group 2                                  *
 * Date last edited: 4/24/2020                                *
 * Purpose of Player.cpp: allow users to create new named     8
 * playlist, view all the playlists, merge (intersect)        *
 * exisiting playlists into a new list, and play a playlist.  *
 *  COULDN'T COMPILE AND CHECK DUE TO STRINGHELPER.O FILE     *                                                    ^
 **************************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <string>
#include "Playlist.h"
#include "StringHelper.h"
#include "Song.h"

using namespace std;
// STATIC 
int Playlist::mode = 0;
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

void OutputToNewList(string fName, string list ){
  ofstream file;
  file.open("Playlist.list",ios::app);
  file << endl << list;
}

void ShowPlaylist(vector<string>&list){
  for(int i = 0; i < list.size(); i++){
    cout << (i+1) << "- " << list[i] <<endl;
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
  
void erase(vector<string> & p)
{
   sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
}
        

int main(){
    ifstream inF,inF2;
    vector<string> mp3;
    
    Song S;
    bool v;
    //SELCTION CONTROLS
    int sel2, choice, choice1, choice2;
    string C, C2;
    char s, m, sel;
  
    //PLAYLIST
    string title, artist, album, selection, newP;
    int year, len;

   do{
     //open playlist file and store data in vectors  
    PFileOpen("Playlist.list", mp3);
       //Deletes duplicates
     erase(mp3);

   
    cout << "*********** WELCOME to the AutoPlayer **********" << endl << endl;
    cout << "You currently have " << mp3.size() << " playlist(s)." << endl;
    cout << "1 - Open an exisiting playlist\n";
    cout << "2 - Create new list\n";
    cout << "3 - Exit\n";
    cout << "Selection: "; 
    cin >> choice1;
    cout << endl;
         

     
        if(choice1==1){
         do{
         cout << "Please select a playlist from below: " << endl;
                ShowPlaylist(mp3);
                cout << "Selection: ";
                      cin >> sel2;
            
            if(sel < 1 || sel > mp3.size())
                cout << "Invalid Choice" << endl << endl;
          
         }while(sel < 1 || sel > mp3.size());
                      C = mp3[sel-1];
                      Playlist List(C);
            do{
               Spot:
                  cout << "You are now playing: " << endl;
                        cout << setw(30) << right << "A - Add a song\n";
                        cout << setw(33) << right <<"D - Delete a song\n";
                        cout << setw(31) << right <<"P - Play a song\n";
                        cout << setw(32) << right <<"M - Set the mode\n";
                        cout << setw(34) << right <<"S - Show all songs\n";
                        cout << setw(23) << right <<"Q - Quit" << endl;
                        cout << "Selection: ";
                        cin  >> sel;
                        sel = toupper(sel);
                            switch(sel)
                            {

                            case 'A': {
                                // RUN ADD SONG (need) 
                             cout << "Song Details\n";
                             cout << "Title: ";
                             getline(cin,title); //Read in Spaces
                             cout << "Artist: ";
                             getline(cin,artist);
                             cout << "Album: ";
                             getline(cin,album);
                             cout << "Year: ";
                                 cin >> year;      
                              cout << "Length (in seconds): ";
                                 cin >> len;
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
                                 v = List.deleteSong(S);
                               
                                 if(v == true)
                                    cout << "Song successfully deleted" << endl;
                                 else
                                    cout << "Song not found" << endl;
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
                            do{
                                cout << "Enter Mode: \n";
                                cout << "N - Normal\n";
                                cout << "R - Repeat\n";
                                cout << "L - Loop" << endl;
                                cout << "Selection: ";
                                cin >> m;
                            }while(m != 'N' && m != 'R' && m != 'L');
                                
                                List.setMode(toupper(m));
                                cout << "Mode is: " << m <<endl;
                            }
                              break;

                            case 'S':{
                                cout << List;
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


        else if(choice1==2){
            while(choice1 != 1 && choice1 != 2 && choice1 != 3){
           cout << "1 - Create new empty list" << endl
                << "2 - Merge 2 existing playlists" << endl
                << "3 - Intersect 2 existing playlists" << endl
                << "Selection: ";
                cin >> choice1;
            }
                   cout << "Name of new playlist (cannot contain underscores): ";
                   cin.ignore();
                   getline(cin,newP);
         
        switch(choice1)
        {
                  case 1: {

                  OutputToNewList("Playlist.list", newP);
                   cout << " Your are now playing: " << mp3[sel-1] << endl;

                  }    
                     break;

                 case 2: {
                // MERGE TWO PLAYLIST
                cout << "Which of the following playlists would you like to merge" << endl;
                ShowPlaylist(mp3);
                Playlist PL2(newP);
                OutputToNewList("Playlist.list", newP);
                   cout << "Playlist 1: ";
                   cin >> choice1;
                       cout << endl;
                       C = mp3[choice1-1];
                       Playlist p(C);
                       //PL2.merge(p);
                   cout << "Playlist 2: ";
                       cin >> choice2;
                       cout << endl;
                       C2 = mp3[choice2-1];
                       Playlist p1(C2);
                       //PL2.merge(p1);

                   }
                  break;
                
                  case 3:{
                        //INTERSECTING PLAYLIST
                 cout << "Which of the following playlists would you like to intersect? " << endl; 
                   ShowPlaylist(mp3);
                   Playlist PL2(newP);
                      OutputToNewList("Playlist.list", newP);
                       cout << "Playlist 1: ";
                           cin >> choice1;
                           cout << endl;
                           C = mp3[choice1-1];
                           Playlist p(C);
                           PL2  = p;
                       cout << "Playlist 2: ";
                           cin >> choice2;
                           cout << endl;
                           C2 = mp3[choice2-1];
                           Playlist p1(C2);
                           PL2.intersect(p1);
                }
                       break;
                  default:{
                   cout << "Invalid Entry. Please input a valid entry."  << endl;
                   }
                }
         }
        
        else if(choice1!=3){
            cout << "Thank " << endl << endl;
        }
        else 
            cout << "Invalid entry. Please enter valid option" << endl << endl;
        
        
    }while(choice1!=3);
    
    return 0;
}
