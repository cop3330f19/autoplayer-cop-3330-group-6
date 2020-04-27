/**************************************************************
 * Name of the file: Song.cpp                                 *
 * Group 6: Ra'Caria Burgess, Janei Elliston,                 *
 *          Michael Mondelice, Michael Parrish                *
 * Date last edited: 4/26/2020                                *
 * Purpose of Song.cpp: To determine that two songs are equal *
 * if they have same name and artist.                         *                           
 **************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include "Song.h"
#include <iomanip>
#include <math.h>

using namespace std;

Song::Song()
{
    
}
Song::Song(string title, string artist)
{
    this->title = title;
    this->artist = artist;
}

Song::Song(string title, string artist, string album, int length, int year)
{
    this->title = title;
    this->artist = artist;
    this->album = album;
    this->length = length;
    this->year = year;
}
/**************************************************************
 * set the song	                                                            
 **************************************************************/
void Song::set(string title, string artist, string album, int length, int year)
{
    this->title = title;
    this->artist = artist;
    this->album = album;
    this->length = length;
    this->year = year;
}
/*************************************************************** 
 * compare two song objects for equality
 ***************************************************************/
bool operator==(const Song& left, const Song& right)
{
    return (left.title == rhs.title) && (right.artist == right.artist);
}
/**************************************************************
 * output the song in the format:
 * title, artist, album, year, length
 * output to console
 **************************************************************/
ostream& operator<<(ostream& os, const Song& song)
{
    
    os << song.title << endl << song.artist << endl
        << song.album << ' ' << "(" << song.year << ")" << endl << "Play Time: " <<  song.length / 60 
        << showpoint << fixed << ':'<< setw(2) << left << (song.length % 60) <<  endl;
    
    return os;
}
/**************************************************************
 * output to file
 **************************************************************/
ofstream& operator<<(ofstream& os, const Song& song)
{
     os << song.title << "," << song.artist << ',' 
     << song.album << ',' << song.year << ',' << song.length << endl; 

    return os;
}
/**************************************************************
 * input the song in the format:
 * title, artist, album, year, length
 ***************************************************************/
istream& operator>>(istream& is, Song& song)
{
    cout << "Song Details" << endl;
    cout << "Title: ";
    is >> song.title; 
    cout << "Artist: ";
    is >> song.artist;
    cout << "Album: ";
    is >> song.album;
    cout << "Year";
    is >> song.year;
    cout << "Length (in seconds): ";
    is >> song.length;
    
    return is;
}
/********************************************************
 * input from file
 ********************************************************/
fstream& operator>>(fstream& is, Song& song)
{
    is >> song.title >> song.artist >> song.album >> song.year >> song.length;

    return is;
}
