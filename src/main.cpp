#include <iostream>
#define Table_Size 250000
#include <cmath>

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

int Hash(std::string ref){
	int index = 0;
	for(int i =0; i < ref.size();i++){
		index+=ref[i]* std::pow(2,i);
	}
	
	return index % Table_Size;
}


struct HashTable{
	Song* songs[Table_Size];
	int size;
	public:
	HashTable(){
		for(int i = 0; i < Table_Size;i++){
			songs[i] = nullptr;
		}
		size = 0;
	}
	
	int getSize(){
		return size;
	}
	
	void Insert(Song& ref){
		int index = Hash(ref.title);
		if(songs[index]==nullptr){
			songs[index] = new Song(ref.title, ref.artist, ref.genre, ref.length, ref.BPM);
			return;
		}
		
		std::cout<<"The song can not be inserted, it already exists"<<std::endl;
	}
	
	void Search(std::string ref){
		int index = Hash(ref);
		if(songs[index] == nullptr){
			std::cout<<ref<<" does not exist"<<std::endl;
			return;
		}
		
		std::cout<<ref<<" is here"<<std::endl;
	}
	
	
};


// This will be for the hash table


int main(){

    std::cout<<"Hello Star Power!!!!"<<std::endl;
	std::cout<<"jacob ladder"<<std::endl;
	HashTable ht;
	Song song("Single Ladies", "Beyonce", "Pop", 125, 225);
	ht.Insert(song);
	ht.Search("bacon and eggs");
	ht.Search("Single Ladies");

}
