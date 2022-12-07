#include "Floor.h"


Floor::Floor(unsigned int seed, std::map<std::string, sf::Texture>* textures, sf::RenderWindow* window)
{
	this->currentPosition = { 7,7 };
	this->seed = seed;
	this->textures = textures;
	this->window = window;
	generateFloor();
}

void Floor::generateFloor() {
	std::mt19937 gen(seed);
	std::uniform_int_distribution<> dist(1, 4);
	std::uniform_int_distribution<> dist2(0, 2000);
	int temp_num;
	bool temp_flag;
	std::vector<std::tuple<int, int>> overlay;

	// generating level template
	currentPosition = {7, 7};
	overlay.push_back(currentPosition);
	while (overlay.size() <= 7) {
		temp_num = dist(gen);
		if (temp_num % 2 == 0) {
			std::get<0>(currentPosition) += temp_num - 3;
		}
		else {
			std::get<1>(currentPosition) += temp_num - 2;
		}
		temp_flag = true;
		for (std::tuple<int, int> vec: overlay) {
			if (std::get<0>(vec) == std::get<0>(currentPosition) && std::get<1>(vec) == std::get<1>(currentPosition)) {
				temp_flag = false;
			}
		}
		if (temp_flag) {
			overlay.push_back(currentPosition);
		}
	}
	// making rooms for the map
	int seed_overlay = 0;
	for (std::tuple<int, int> vec : overlay) {
		map.insert({vec, Room(seed + seed_overlay, textures, window)});
		seed_overlay += 1;
	}
	// generating doors for them
	std::cout << "\n";
	for (auto& i : map) {
		if (map.count(std::tuple<int, int>(std::get<0>(i.first), std::get<1>(i.first) + 1)) != 0) {
			Tile temp_door(536.f, -48.f, true, "door.png", textures);
			temp_door.makeDoor(0);
			i.second.addTile(temp_door);
			std::cout << "door up for: {" << std::get<0>(i.first) << ", " << std::get<1>(i.first) << "}\n";
		}
		if (map.count(std::tuple<int, int>(std::get<0>(i.first), std::get<1>(i.first) - 1)) != 0) {
			Tile temp_door(536.f, 720.f, true, "door.png", textures);
			temp_door.makeDoor(2);
			temp_door.setRotation(2);
			i.second.addTile(temp_door);
			std::cout << "door down for: {" << std::get<0>(i.first) << ", " << std::get<1>(i.first) << "}\n";
		}
		if (map.count(std::tuple<int, int>(std::get<0>(i.first) + 1, std::get<1>(i.first))) != 0) {
			Tile temp_door(1048.f, 336.f, true, "door.png", textures);
			temp_door.makeDoor(1);
			temp_door.setRotation(1);
			i.second.addTile(temp_door);
			std::cout << "door right for: {" << std::get<0>(i.first) << ", " << std::get<1>(i.first) << "}\n";
		}
		if (map.count(std::tuple<int, int>(std::get<0>(i.first) - 1, std::get<1>(i.first))) != 0) {
			Tile temp_door(24.f, 336.f, true, "door.png", textures);
			temp_door.makeDoor(3);
			temp_door.setRotation(3);
			i.second.addTile(temp_door);
			std::cout << "door left for: {" << std::get<0>(i.first) << ", " << std::get<1>(i.first) << "}\n";
		}
		
	}
}

Room* Floor::getCurrentRoom() {
	return &map[currentPosition];
}

void Floor::changeRoomByDoor(int door)
{
	if (door == 0) {
		std::get<1>(currentPosition) += 1;
	}
	if (door == 1) {
		std::get<0>(currentPosition) += 1;
	}
	if (door == 2) {
		std::get<1>(currentPosition) -= 1;
	}
	if (door == 3) {
		std::get<0>(currentPosition) -= 1;
	}
}

std::map<std::tuple<int, int>, Room>* Floor::getMap() {
	return &map;
}


