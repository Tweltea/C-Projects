/*********************************************************************
** Program Filename: run_catalog.cpp
** Author: Bryce Khut
** Date: 02/12/2024
** Description: Main function .cpp file
** Input:
** Output:
*********************************************************************/

#include "catalog.h"
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {

	//for playlist_file_name function, takes a string which is used to open text file or terminate program
	string file_name = " ";									//creates a string variable called file_name
	cout << "Enter the playlist info file name: " << endl;	
	cin >> file_name;
	ifstream txt_file;								//initializes txt_file reference
	txt_file.open(file_name);						//the code expects a string in the parenthesis, where the string is the name of the file we want accessed (songs_playlist.txt)
	if(!(playlist_file_name(txt_file))) {			//if this function does not recieve songs_playlist.txt, it will return 0 and terminate
	 	return 0;
	}
	
	ofstream write_file;							//initalizing the print_to_file.txt which is where the print to file will be
	write_file.open("print_to_file.txt");			//opens the file


	int playlist_num = 0;									//initializing number of playlists
	txt_file >> playlist_num;								//taking number of playlists from the text file

	Playlist* play_array = create_playlists(playlist_num);  //executes create_playlists function
	for(int i = 0;i<playlist_num;i++) {
		populate_one_list(play_array, i, txt_file);			//executes create_one_list function

	}
	
	int user_age = age();									//executes age function and initializes it as int user_age

int run_again = 1;											//start of do while loop
do {

	int inputs = user_inputs();								//executes all the option functions where if an input other than 1-5 is inputted, error message
		if (inputs == 1) {
			option1(play_array, playlist_num, user_age);
		} else if (inputs == 2) {
			option2(play_array, playlist_num, write_file);
		} else if (inputs == 3) {
			option3(play_array, playlist_num, write_file);
		} else if (inputs == 4) {
			option4(play_array, playlist_num, write_file);
		} else {
			run_again = 2;
		}

	quit(inputs);											//if run again = 2, will go to quit function
	} while (run_again == 1);

	delete_info(play_array, playlist_num);					//deletes the arrays to prevent memory leaks

	txt_file.close();										//closes both txt files
	write_file.close();

	return 0;
}