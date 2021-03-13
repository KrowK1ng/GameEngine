#include "room.h"
#include "object.h"
#include "objects/object_manager.h"
#include "game.h"

Room::Room(char* path){
	obj_manager = new ObjectManager();
	std::ifstream source;
	source.open(path);
	if (!source.is_open()){
		std::cout << "Unable to open" << path ;
		exit(1);
	}
	std::string line;
	std::getline(source, line);
	width = std::stoi(line.substr(0,line.find_first_of(' ')));
	height = std::stoi(line.substr(line.find_first_of(' '), line.length() - 2));
	Object* temp;
	std::string name;
	int x;
	int y;
	Game::self->current_room = this;			//Sets The room early for no Start create object bug;
	while (std::getline(source,line)){
		name = line.substr(0,line.find_first_of(' '));
		x = std::stoi(line.substr(line.find_first_of(' ') + 1, line.find(' ',line.find_first_of(' ') + 1)));
		y = std::stoi(line.substr(line.find(' ',line.find_first_of(' ') + 1), line.length() - 1));
		temp = object::CreateObject(name, x, y);
		obj_manager->AddObject(temp);
	}
	source.close();
	std::cout << "Created room with size " << width << " " << height << std::endl;
}

Room::Room(std::string path){
	obj_manager = new ObjectManager();
	std::ifstream source;
	source.open(path);
	if (!source.is_open()){
		std::cout << "Unable to open" << path ;
		exit(1);
	}
	std::string line;
	std::getline(source, line);
	width = std::stoi(line.substr(0,line.find_first_of(' ')));
	height = std::stoi(line.substr(line.find_first_of(' '), line.length() - 2));
	Object* temp;
	std::string name;
	int x;
	int y;
	Game::self->current_room = this;			//Sets The room early for no Start create object bug;
	while (std::getline(source,line)){
		name = line.substr(0,line.find_first_of(' '));
		x = std::stoi(line.substr(line.find_first_of(' ') + 1, line.find(' ',line.find_first_of(' ') + 1)));
		y = std::stoi(line.substr(line.find(' ',line.find_first_of(' ') + 1), line.length() - 1));
		temp = object::CreateObject(name, x, y);
		obj_manager->AddObject(temp);
	}
	source.close();
	std::cout << "Created room with size " << width << " " << height << std::endl;
}

Room::~Room(){
	//delete obj_manager;
	delete obj_manager;
}

void Room::update(){
	//obj_manager->Step();
	obj_manager->Step();
}

void Room::render(){
	//obj_manager->Draw();
	obj_manager->Draw();
}
