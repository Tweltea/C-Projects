//#ifndef CATALOG_h
#define CATALOG_h

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//a struct to hold info of a Playlist
struct Playlist {
	string name;        //name of the playlist, one word
	int num_song;       //number of songs in the playlist
	struct Song* s;     //an array that holds all songs in the playlist
	float total_len;    //total length of the playlist
};

//a struct to hold info of a Song
struct Song {
	string name;		//name of the song, one word
	string artist;		//name of the artist, one word
	int year_release;	//the year of release
	float length;		//length of the song
	string genre;		//genre of the song, one word
	string res;			//"E" or "none" for restriction level
};


/**************************************************
 * Name: playlist_file_name()
 * Description: If user enters correct file name, program will execute, else, program will terminate.
 				The code calls for an existing txt file, if the user enters the songs_playlist file,
				it exists and the code knows to store that input.
 * Parameters: 
 * Pre-conditions: none
 * Post-conditions: 
 ***********************************************/
bool playlist_file_name(ifstream& txt_file);


/**************************************************
 * Name: create_playlists()
 * Description: This function will dynamically allocate
				an array of playlists (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Playlist array of requested size is created and return
 ***********************************************/
Playlist* create_playlists(int playlist_total);
	

/**************************************************
 * Name: populate_one_list()
 * Description: This function will fill a single playlist struct 
				with information that is read in from the file
 * Parameters:  Playlist* - pointer to the Playlist array
				int - index of the Playlist in the array to be filled 
				ifstream& - input file to get the Playlist information
 * Pre-conditions: Playlist array has been allocated; 
				 provided index is less than the array size
 * Post-conditions: a Playlist at provided index is populated
 ***********************************************/
void populate_one_list(Playlist* dynarray_playlist, int index, ifstream &playlists_txt); 


/**************************************************
 * Name: create_songs()
 * Description: This function will dynamically allocate
				an array of songs (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Song array of requested size is created and return
 ***********************************************/
Song* create_songs(int song_total);


/**************************************************
 * Name: populate_one_song()
 * Description: This function will fill a single song struct 
				with information that is read in from the file
 * Parameters:  Song* - pointer to the Song array
				int - index of the Song in the array to be filled 
				ifstream& - input file to get the Song information
 * Pre-conditions: Song array has been allocated; 
				 provided index is less than the array size
 * Post-conditions: a Song at provided index is populated
 ***********************************************/
void populate_one_song(Song* dynarray_song, int index, ifstream &songs_txt); 


/**************************************************
 * Name: delete_info()
 * Description: This function will  delete all the memory that was dynamically allocated
 * Parameters: Playlist* - the Playlist array, int total - index for playlist array
 * Pre-conditions: the provided Playlist array hasn't been freed yet
 * Post-conditions: the Playlist array, with all Songs inside, is freed
 ***********************************************/
void delete_info(Playlist* arr_playlist, int total);


/*********************************************************************
** Function: int user_inputs()
** Description: this function stores the user input for the different options
** Parameters: 
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
int user_inputs();


/*********************************************************************
** Function: int age()
** Description: this function stores the users age
** Parameters: 
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
int age();    


/*********************************************************************
** Function: void option1(Playlist* dynarray_playlist, int playlist_total, int age)
** Description: This function displays all the songs in the print_to_file.txt file
** Parameters: Playlist* dynarray_playlist, int playlist_total, int age
** Pre-Conditions: 
** Post-Conditions:
*********************************************************************/ 
void option1(Playlist* dynarray_playlist, int playlist_total, int age);


/*********************************************************************
** Function: void option2(Playlist* dynarray_playlist, int playlist_total, ofstream &txt_file)
** Description: User searches for a song and can either print through screen or file
** Parameters: int user_option_choice
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void option2(Playlist* dynarray_playlist, int playlist_total, ofstream &txt_file);


/*********************************************************************
** Function: void option3(Playlist* dynarray_playlist, int playlist_total, ofstream &txt_file)
** Description: User searches for a song genre
** Parameters: Playlist* dynarray_playlist, int playlist_total, ofstream &txt_file
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void option3(Playlist* dynarray_playlist, int playlist_total, ofstream &txt_file);


/*********************************************************************
** Function: void option4(Playlist* dynarray_playlist, int playlist_total, ofstream &txt_file)
** Description: Displays length of each playlist in minutes
** Parameters: Playlist* dynarray_playlist, int playlist_total, ofstream &txt_file
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void option4(Playlist* dynarray_playlist, int playlist_total, ofstream &txt_file);


/*********************************************************************
** Function: void quit(int user_option_choice)
** Description: this function ends the program if the user chooses 5
** Parameters: int user_option_choice
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void quit(int user_option_choice);


/*********************************************************************
** Function: void print_screen(Playlist* dynarray_playlist, int playlist_total, int i, int s)
** Description: this function prints the display for the song struct in the terminal
** Parameters: Playlist* dynarray_playlist, int playlist_total, int i, int s
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void print_screen(Playlist* dynarray_playlist, int playlist_total, int i, int s);


/*********************************************************************
** Function: void print_file(Playlist* dynarray_playlist, int playlist_total, ofstream &txt_file, int i, int s)
** Description: this function prints the display for the song struct in the print_to_file.txt
** Parameters: Playlist* dynarray_playlist, int playlist_total, ofstream &txt_file, int i, int s
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void print_file(Playlist* dynarray_playlist, int playlist_total, ofstream &txt_file, int i, int s);


/*********************************************************************
** Function: int print_options()
** Description: this function gives the user the option to print to screen or print to file
** Parameters: 
** Pre-Conditions: options 1-4 must be chosen
** Post-Conditions:
*********************************************************************/ 
int print_options();