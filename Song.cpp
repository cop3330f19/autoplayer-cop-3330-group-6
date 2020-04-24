/**************************************************************
 * Name of the file: Song.cpp                                 *
 * Group 6: Ra'Caria Burgess, Janei Elliston,                 *
 *          Michael Mondelice, Michael Parrish                *
 * Date last edited: 4/24/2020                                *
 * Purpose of Song.cpp: To determine that two songs are equal *
 * if they have same name and artist.                         *                           
 **************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include "Song.h"

using namespace std;
       /**************************************************************
		output the song in the format:
		title, artist, album, year, length
		output to console
        **************************************************************/
	friend ostream& operator<<(ostream& os, const Song& song){
            os << song.title << " " << song.artist << " " << song.album <<
                " " << song.year << " " << song.length;
        }

        /**************************************************************
         output to file
         **************************************************************/
	friend ofstream& operator<<(ofstream& os, const Song& song){
            os << song.title << " " << song.artist << " " << song.album <<
                " " << song.year << " " << song.length;
        }
        /**************************************************************
		 input the song in the format:
		 title, artist, album, year, length
         ***************************************************************/
	friend istream& operator>>(istream& is, Song& song){
            is >> song.title >> song.artist >> song.album >> song.year >> song.length;
        }
            
	/***************************************************************
         input from file
         ***************************************************************/
		friend fstream& operator>>(fstream& is, Song& song){
            is >> song.title >> song.artist >> song.album >> song.year >> song.length;
        }
        /*************************************************************** 
		 compare two song objects for equality
	 ***************************************************************/
		friend bool operator==(const Song& lhs, const Song& rhs){
            if (lhs.title == rhs.title && lhs.artist == rhs.artist)
                return true;
            else 
                return false;
            }

		// constructors
		Song::Song(){}

		Song::Song(string title, string artist, string album, int length, int year){
                 this->title = title;
		 this->artist = artist;
		 this->album = album;
		 this->length = length; // length in seconds
		 this->year = year;
        }
	/**************************************************************
         set the song	                                                            
	 **************************************************************/        

		void Song::set(string title, string artist, string album, int length, int year){
                 this->title = title;
		 this->artist = artist;
		 this->album = album;
		 this->length = length; // length in seconds
		 this->year = year;            
        }
