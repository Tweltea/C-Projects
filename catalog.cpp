/*********************************************************************
** Program Filename: catalog.cpp
** Date: 02/12/2024
** Description: functions .cpp file
** Input:
** Output:
*********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "catalog.h"
#include <cstdlib>

using namespace std;
Playlist* create_playlists(int playlist_total) {                //playlist total is the index
    Playlist* dynarray_playlist = new Playlist[playlist_total]; //dynarray is an array that is in the heap that is playlist_total long, new allocates memory on the heap
    return dynarray_playlist;                                   //returning the dynamic array
}

void populate_one_list(Playlist* dynarray_playlist, int index, ifstream &playlists_txt) {   //function utilizing playlist dynamic array, size of playlist array, and the songs_playlist.txt
    int amount_songs = 0;
    playlists_txt >> dynarray_playlist[index].name;                                         //finds a name data type from the .txt and stores it in the playlist array as name
    playlists_txt >> amount_songs;                                                          //finds a song total data type from the .txt and stores it in the playlist array as num song
    dynarray_playlist[index].num_song = amount_songs;                                       //uses the create_songs function to find the array of songs
    dynarray_playlist[index].s = create_songs(amount_songs);
    for (int i=0;i<amount_songs;i++) {                                                      //function below populates the song array that was just created with songs
        populate_one_song(dynarray_playlist[index].s, i, playlists_txt);
        dynarray_playlist[index].total_len += (dynarray_playlist[index].s)[i].length;
    }
}

Song* create_songs(int song_total) {                //creates dynamic array of songs
    Song* dynarray_song = new Song[song_total];
    return dynarray_song;
}

void populate_one_song(Song* dynarray_song, int index, ifstream &songs_txt) { //creates the function to populate the array of songs with information
    songs_txt >> dynarray_song[index].name; 
    songs_txt >> dynarray_song[index].artist; 
    songs_txt >> dynarray_song[index].year_release; 
    songs_txt >> dynarray_song[index].length;
    songs_txt >> dynarray_song[index].genre; 
    songs_txt >> dynarray_song[index].res; 
}

void delete_info(Playlist* arr_playlist, int total) {
    for (int i = 0;i<total;i++) {
        delete [] (arr_playlist[i].s); //needs for loop for deleting each array of songs        
    } delete [] arr_playlist;
}

bool playlist_file_name(ifstream& txt_file) {                   //function called playlist_file_name which passes txt_file by reference

    if(!(txt_file.is_open())){                                  //if the text file is not open (aka wrong file inputted), the code will give an error message then the program will termiante
        cout << "error: file not found..." << endl;
        cout << "terminating..." << endl;
        return false;                                       //terminates
        }
    return true;                                            //proceeds
}

int age() {                     //function stores an age input from the user                                           
int user_age = 0;

while(user_age < 1)	{
	cout << "Enter your age: ";
	cin >> user_age;
	cout << " " << endl;
		if(user_age < 1) {
			cout << "That is not a valid age. Please enter a positive integer." << endl;
		}
    }
return user_age;
}

int user_inputs() {             //function displays inputs for the user
    int user_option_choice = 0;
	string stringvar = " ";
    while ((user_option_choice < 1) || (user_option_choice > 5)) {
        cout << "Which option would you like to choose?" << endl;
        cout << "1. Display all songs" << endl;
        cout << "2. Search for a song to play" << endl;
        cout << "3. Search Songs by Genre" << endl;
        cout << "4. Display length of all playlists" << endl; 
        cout << "5. Quit" << endl;
        cout << "Your choice: ";
        cin >> stringvar;
        user_option_choice = stoi(stringvar); //allows code to take in strings then take in the numbers from said strings
        cout << " " << endl;	
            
        if(user_option_choice < 1 || user_option_choice > 5) {
                cout << "Invalid input. Enter a number between 1 and 5." << endl;
                cout << " " << endl;
        }
    }
return user_option_choice;
}

int print_options() {               //inner option choice after user chooses option from user_inputs function
    int user_choice = 0;
    while ((user_choice < 1) || (user_choice > 2)) {
        cout << "How would you like the information displayed?" << endl;
        cout << "1. Print to screen (Press 1)" << endl;
        cout << "2. Print to file (Press 2)" << endl;
        cout << "Your choice: \n";

        cin >> user_choice;
        if ((user_choice != 1) && (user_choice != 2)) {
            cout << "Invalid input. Enter either 1 or 2." << endl;
        }
    }
    return user_choice;
}

void print_screen(Playlist* dynarray_playlist, int playlist_total, int i, int s) {  //prints the specific data types from the structs onto the screen

    cout << "---------------------------------" << endl;
    cout << "Name: " << (dynarray_playlist[i].s)[s].name << endl;
    cout << "Artist: " << (dynarray_playlist[i].s)[s].artist << endl;
    cout << "Year Released: " << (dynarray_playlist[i].s)[s].year_release << endl;
    cout << "Length: " << (dynarray_playlist[i].s)[s].length << endl;
    cout << "Genre: " << (dynarray_playlist[i].s)[s].genre << endl;
    cout << "Restrictions: " << (dynarray_playlist[i].s)[s].res << endl;
    cout << "---------------------------------" << endl;
}
    
void print_file(Playlist* dynarray_playlist, int playlist_total, ofstream &txt_file, int i, int s) { //prints the specific data types from the structs onto the print_to_file.txt
 
    txt_file << "---------------------------------" << endl;
    txt_file << "Name: " << (dynarray_playlist[i].s)[s].name << endl;
    txt_file << "Artist: " << (dynarray_playlist[i].s)[s].artist << endl;
    txt_file << "Year Released: " << (dynarray_playlist[i].s)[s].year_release << endl;
    txt_file << "Length: " << (dynarray_playlist[i].s)[s].length << endl;
    txt_file << "Genre: " << (dynarray_playlist[i].s)[s].genre << endl;
    txt_file << "Restrictions: " << (dynarray_playlist[i].s)[s].res << endl;
    txt_file << "---------------------------------" << endl;
}

void option1(Playlist* dynarray_playlist, int playlist_total, int age) {                    //function displays all songs in the songs_playlist.txt
    for (int i=0;i<playlist_total;i++) {                                                    //for loop using index i loops for the amount of playlists
         int amount_songs = (dynarray_playlist[i].num_song);                                
        for (int s=0;s<amount_songs;s++) {                                                  //for loop using s loops for the amount of songs in the playlist (in playlist SummerVibes, will look 4 times)
            Song* songarr = dynarray_playlist[i].s;                                                       
            if(age <= 19 && (songarr)[s].res == "None"){
                cout << "---------------------------------" << endl;
                cout << "Name: " << (songarr)[s].name << endl;
                cout << "Artist: " << (songarr)[s].artist << endl;
                cout << "Year Released: " << (songarr)[s].year_release << endl;
                cout << "Length: " << (songarr)[s].length << endl;
                cout << "Genre: " << (songarr)[s].genre << endl;
                cout << "Restrictions: " << (songarr)[s].res << endl;
                cout << "---------------------------------" << endl;
            } else if (age > 19){
                cout << "---------------------------------" << endl;
                cout << "Name: " << (songarr)[s].name << endl;
                cout << "Artist: " << (songarr)[s].artist << endl;
                cout << "Year Released: " << (songarr)[s].year_release << endl;
                cout << "Length: " << (songarr)[s].length << endl;
                cout << "Genre: " << (songarr)[s].genre << endl;
                cout << "Restrictions: " << (songarr)[s].res << endl;
                cout << "---------------------------------" << endl;
            }
        }
    }
}




void option2(Playlist* dynarray_playlist, int playlist_total, ofstream &txt_file) {         //function allows user to choose a single song to list the information of
    int user_choice = print_options();
    string song_check = " ";
    cout << "Choose a song to list: ";
    cin >> song_check;
    for (int i=0;i<playlist_total;i++) {
        int amount_songs = (dynarray_playlist[i].num_song);                   
        for (int s=0;s<amount_songs;s++) {                                                
            if (song_check == (dynarray_playlist[i].s)[s].name) {
                if (user_choice == 1) {
                    print_screen(dynarray_playlist, playlist_total, i, s);
                } else {
                    print_file(dynarray_playlist, playlist_total, txt_file, i, s);                 
                }
            }  
        }

    }
}
    

void option3(Playlist* dynarray_playlist, int playlist_total, ofstream &txt_file) {         //function allows the user to choose a single genre to list the information of
int user_choice = print_options();
    string song_genre = " ";
    cout << "Choose a genre to list: ";
    cin >> song_genre;
    for (int i=0;i<playlist_total;i++) {  
        int amount_songs = (dynarray_playlist[i].num_song);                   
        for (int s=0;s<amount_songs;s++) {                                               
            if (song_genre == (dynarray_playlist[i].s)[s].genre) {
                if (user_choice == 1) {
                    print_screen(dynarray_playlist, playlist_total, i, s);
                } else {
                    print_file(dynarray_playlist, playlist_total, txt_file, i, s);                 
                }
            }  
        }

    }
}

void option4(Playlist* dynarray_playlist, int playlist_total, ofstream &txt_file) {         //function allows the user to display the total length of each playlist in minutes, either on screen or file
int user_choice = print_options();
    for (int i=0;i<playlist_total;i++) {  
        int amount_songs = (dynarray_playlist[i].num_song);                   
        if (user_choice == 1){
            cout << dynarray_playlist[i].name << " is " << dynarray_playlist[i].total_len << " minutes long." << endl;
        } else {
            txt_file << dynarray_playlist[i].name << " is " << dynarray_playlist[i].total_len << " minutes long." << endl;
        }
    }
}



void quit(int user_option_choice) {     //function ends the program
    
    if (user_option_choice == 5) {
		cout << "Bye!" << endl;
	}
}




