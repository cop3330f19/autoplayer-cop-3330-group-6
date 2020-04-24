#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stringstream>
#include <cmath>
#include <string>

using namespace std;

void PlaylistMenu(){
    int choice3;
    do{
        cout << "1 - Create new empty list" << endl
             << "2 - Merge 2 existing playlists" << endl
             << "3 - Intersect 2 existing playlists" << endl
             << "Selection: ";
        cin >> choice3;
        if (choice3==1){
        // create new empty list function
        }
        else if (choice3==2){
        // merge 2 playlist function
        }
        else if (choice3==3){
        // intersect 2 playlist function
        }
        else if (choice3!=4){
           cout << "Invalid Entry. Please input a valid entry." << endl << endl;
        }
    }while(choice3=!4)
}

void SongMenu(){
    int choice3;
    do{
        cout<<"You are now playing: " /*cout playlist name*/ << endl;
            <<"1 - Add a song"<<endl
            <<"2 - Delete a song"<<endl
            <<"3 - Play a song"<<endl
            <<"4 - Set the mode"<<endl
            <<"5 - Show all songs"<<endl
            <<"6 - Quit"<<endl<<endl
            <<"Selection: ";
        cin>>choice3;
        if (choice3==1){
            //run add song function
        }
        else if (choice3==2){
            //run delete song function
        }
        else if (choice3==3){
            //run play song function
        }
        else if (choice3==4){
            //run set mode function (depending on how function is written a menu may need to be created as well)
        }
        else if (choice3==5){
            //run print function for all songs in playlist
        }
        else if (choice3==6){
            //exit song menu back to main menu this if will be blank to prevent the else from printing Invalid Choice message
        }
        else{
            cout<<"Invalid Choice" << endl << endl;
        }
            
    }while(choice3!=6);
}

int main(){
    //open playlist file and store data in vectors, create a count for the vector as well
    int choice1, choice2;
    bool choice2_flag=false;
    do{
        // cout # of playlists
        cout << "1 - Open an exisiting playlist" << endl
             << "2 - Create new list" << endl
             << "3 - Exit" << endl
             << "Selection: ";
        cin >> choice1;
        
        if(choice1==1){
            //open existing playlist menu
            do{
                //display list of playlists to choose from
                cin >> choic2;
                for(int i=0; i< /*count of playlist vector*/; i++){// for loop to check to see if choice matches any playlist
                   if(/*choice == playlist*/){
                         SongMenu();//runs song menu
                         choice2_flag=true;
                    }
                }
                // validator will go here as well
            }while(choice2_flag==false);
        }
        
        else if(choice1==2){
            PlaylistMenu(); // run playlist menu
        }
        
        else if(choice1!=3){
            cout << "Invalid entry. Please enter valid option" << endl << endl;
        }
        
        
        
    }while(choice1!=3);
}
