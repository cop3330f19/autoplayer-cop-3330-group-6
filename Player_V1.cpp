/**************************************************************
 * Name of the file: Song.cpp                                 *
 * Group 6: Ra'Caria Burgess, Janei Elliston,                 *
 *          Michael Mondelice, Michael Parrish                *
 * Date last edited: 4/24/2020                                *
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
void PlaylistMenu(){
    int choice3;
    do{
        cout << "1 - Create new empty list" << endl
             << "2 - Merge 2 existing playlists" << endl
             << "3 - Intersect 2 existing playlists" << endl
             << "Selection: ";
        cin >> choice3;
        if (choice3==1){
        // create new empty list function (need)
        }
        else if (choice3==2){
        // merge 2 playlist function (need) 
        }
        else if (choice3==3){
        // intersect 2 playlist function (need)
        }
        else if (choice3!=4){
           cout << "Invalid Entry. Please input a valid entry." << endl << endl;
        }
    }while(choice3!=4);
}

void SongMenu(){
    Playlist P;
    Song S;
    char m;
    int choice3;
    do{
        cout<<"You are now playing: " /*cout playlist name (need)*/ << endl
            <<"1 - Add a song"<<endl
            <<"2 - Delete a song"<<endl
            <<"3 - Play a song"<<endl
            <<"4 - Set the mode"<<endl
            <<"5 - Show all songs"<<endl
            <<"6 - Quit"<<endl<<endl
            <<"Selection: ";
        cin>>choice3;
        if (choice3==1){
            //run add song function (need)
         
          P + S;
        }
        else if (choice3==2){
            //run delete song function (need)
          P - S;
        }
        else if (choice3==3){
             //run play song function (need)
         P.play();
        }
        else if (choice3==4){
            //run set mode function (depending on how function is written a menu may need to be created as well) (nee              //run play song function (need)
           //cout << "Enter Mode: \n";
           //cout << "N - Normal\n";
           //cout << "R - Repeat\n"
           //cout << "L - Loop" << endl;
            // cin >> m;
            // P.setMode(m);
        }
        else if (choice3==5){
            //run print function for all songs in playlist (need)
            // cout << P;
        }
        else if (choice3==6){
            //exit song menu back to main menu this if will be blank to prevent the else from printing Invalid Choice message (need)
        }
        else{
            cout<<"Invalid Choice" << endl << endl;
        }
            
    }while(choice3!=6);
}

int main(){
    //open playlist file and store data in vectors, create a count for the vector as well (need)
    ifstream inF,inF2;
    int choice1, choice2;
    vector<Playlist> mp3; 
   
    string word, songLine;
    bool choice2_flag=false;
    inF.open("Playlist.list");
       while(!inF.eof()){
        inF>>word;
         
         //initilize 
         Playlist tempPlistObj;
         
          // set tempPlistObj name
         tempPlistObj.setName(word);
         cout<<word<<endl;
         word+=".playlist";
           //cout<<word<<endl<<endl;
         string temp="Country.playlist";
         inF2.open(temp.c_str());

          
        
         // display tempPlistObj name
         while(!inF2.eof()){
         
           
           getline(inF2,songLine);  
           //cout<<songLine<<endl;
           vector<string>temp(0);
          parse(temp,songLine);
          // cout<<temp[0]<<endl;
           
        /*  stringstream temp3(temp[3]);
           stringstream temp4(temp[4]);

  
            temp3 >> temp[3];
               temp4 >> temp[4];
           */

           //cout<<temp[0]<<" "<<temp[1]<<" "<<temp[2]<<" "<<temp[3]<<" "<<temp[4]<<endl;
           Song tempSong(temp[0],temp[1],temp[2],1,2);
           tempPlistObj=tempPlistObj+tempSong;
           
         // set tempPlistObj songs     by parsing the song data in each row and put it inin each playlist class object
         
         }
         //inF2.close();
         
        mp3.push_back(tempPlistObj);
         
      }
    do{
      
     
      
        // cout # of playlists (need)
        cout << "1 - Open an exisiting playlist" << endl
             << "2 - Create new list" << endl
             << "3 - Exit" << endl
             << "Selection: ";
        cin >> choice1;
        
        if(choice1==1){
            //open existing playlist menu (need)
            do{
                
                //display list of playlists to choose from (need)
                cin >> choice2;
                for(int i=0; i< /*count of playlist vector (need)*/5; i++){// for loop to check to see if choice matches any playlist
                   if(/*choice == playlist (need)*/1==1){
                         SongMenu();//runs song menu
                         choice2_flag=true;
                    }
                }
                if (choice2_flag==false){
                    cout << "Invalid Choice" << endl << endl;
                }
            }while(choice2_flag==false);
        }
        
        else if(choice1==2){
            PlaylistMenu(); // run playlist menu
        }
        
        else if(choice1!=3){
            cout << "Invalid entry. Please enter valid option" << endl << endl;
        }
        
        
        
    }while(choice1!=3);
    return 0;
}
