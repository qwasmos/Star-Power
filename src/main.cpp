#include <iostream>


struct Song{
	std::string title;
	std::string artist;
	std::string genre;
	int length;
	int BPM;
	Song(std::string title = "", std::string artist ="",std::string genre = "", int length = 0, int BPM = 0){
		this->title = title;
		this->artist = artist;
		this->genre = genre;
		this->length = length;
		this->BPM = BPM;
	}
	
	
	
	
};



Song Search(Song& ref){
	// do get request for song name
	
	Song song;
	return song;
}

int main(){

    std::cout<<"Hello Star Power!!!!"<<std::endl;

}
