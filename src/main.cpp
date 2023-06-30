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

struct Node{
	Song song;
	Node* right;
	Node* left;
	int height;
	Node(Song& ref){
		this->song.title = ref.title;
		
		this->song.artist = ref.artist;
		this->genre = ref.genre;
		this->length = ref.length;
		this->BPM = ref.BPM;
		this->height =1;
		this->right = nullptr;
		this->left = nullptr;
	}
}



Song Search(Song& ref){
	// do get request for song name
	
	Song song;
	return song;
}

int main(){

    std::cout<<"Hello Star Power!!!!"<<std::endl;

}
