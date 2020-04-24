/**************************************************************
 * Name of the file: Song.h                                   *
 * Group 6: Ra'Caria Burgess, Janei Elliston,                 *
 *          Michael Mondelice, Michael Parrish                *
 * Date last edited: 4/24/2020                                *
 * Purpose of the class: To determine that two songs are equal*
 * if they have same name and artist.                         *                           
 **************************************************************/
#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>
#include <fstream>

/***************************************************************************
 Song is a simple class that stores a title and artist as strings
 it just provides i/o operators, == operator, constructors and Set function
 ***************************************************************************/
class Song
{
	public:
		// output the song in the format:
		// title, artist, album, year, length
		// output to console
		friend std::ostream& operator<<(std::ostream& os, const Song& song);
		//output to file
		friend std::ofstream& operator<<(std::ofstream& os, const Song& song);

		// input the song in the format:
		// title, artist, album, year, length
		friend std::istream& operator>>(std::istream& is, Song& song);
		//input from file
		friend std::fstream& operator>>(std::fstream& is, Song& song);

		// compare two song objects for equality
		friend bool operator==(const Song& lhs, const Song& rhs);


		// constructors
		Song( );
		Song(std::string title, std::string artist, std::string album, int length, int year);

		// set the song
		void set(std::string title, std::string artist, std::string album, int length, int year);

	private:


		std::string title;
		std::string artist;
		std::string album;
		int length; // length in seconds
		int year;
};

#endif

