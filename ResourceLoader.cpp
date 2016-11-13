//
// Created by joar on 1/2/16.
//

#include "ResourceLoader.h"
#include <iostream>



bool ResourceLoader::LoadResources() {
	if(!LoadFonts()){
		std::cout << "Error! Loading fonts. " << std::endl;
		return false;
	}
	if(!LoadSounds()){
		std::cout << "Error! Loading sounds. " << std::endl;
		return false;
	}

	return true;
}

bool ResourceLoader::LoadFonts() {
	std::string path = "resources/fonts/playfair_display/PlayfairDisplay-Regular.ttf";
//	std::string path = "recourses/fonts/playfair_display/IMMORTAL.ttf";

	if (!opensans_regular.loadFromFile("resources/fonts/open-sans/opensans-regular.ttf")) {
		std::cout << "Error loading resources/fonts/open-sans/opensans-regular.ttf" << std::endl;
		return false;
	}

	if (!playfair_regular.loadFromFile(path)) {
		std::cout << "Error! ResourceLoader: " << path << std::endl;
		return false;
	}
	return true;
}

bool ResourceLoader::LoadSounds() {

	if (!bufferSoundMenuClickBlip.loadFromFile("resources/sfx/menu_click_blip.wav")) {
		std::cout << "Error loading resources/sfx/menu_click_blip.wav" << std::endl;
		return false;
	}
    soundMenuClickBlip.setBuffer(bufferSoundMenuClickBlip);

    if (!bufferSoundClonk.loadFromFile("resources/sfx/menu_click_blip.wav")) {
        std::cout << "Error loading resources/sfx/menu_click_blip.wav" << std::endl;
		return false;
	}
    soundMenuClonk.setBuffer(bufferSoundClonk);

	return true;
}

ResourceLoader::~ResourceLoader() {

    std::cout << "ResourceLoader deconstructing" <<  std::endl;

}

sf::RenderWindow *ResourceLoader::getWindow() const {
	return window;
}

void ResourceLoader::setWindow(sf::RenderWindow *window) {
	ResourceLoader::window = window;
}

void ResourceLoader::playSound(soundEffect sfx) {
    switch (sfx){
        case sfxMenuClickBlip:
            soundMenuClickBlip.play();
            break;
        case sfxMenuClonk:
            soundMenuClonk.play();
            break;
        default:
            break;
    }
}

const sf::Font &ResourceLoader::getPlayfair_regular() const {
	return playfair_regular;
}

const sf::Font &ResourceLoader::getOpensans_regular() const {
	return opensans_regular;
}

int ResourceLoader::getLeft_side_bar_size() const {
    return left_side_bar_size;
}

void ResourceLoader::setLeft_side_bar_size(int left_side_bar) {
    ResourceLoader::left_side_bar_size = left_side_bar;
}

int ResourceLoader::getRight_side_bar_size() const {
    return right_side_bar_size;
}

void ResourceLoader::setRight_side_bar_size(int right_side_bar) {
    ResourceLoader::right_side_bar_size = right_side_bar;
}

