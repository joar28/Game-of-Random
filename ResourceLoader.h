//
// Created by joar on 1/2/16.
//

#ifndef BF_RESOURCELOADER_H
#define BF_RESOURCELOADER_H

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class ResourceLoader {
public:
    enum soundEffect{
        sfxMenuClickBlip,
        sfxMenuClonk
    };

    struct Keymap{
        sf::Keyboard::Key key_up    = sf::Keyboard::W;
        sf::Keyboard::Key key_left  = sf::Keyboard::A;
        sf::Keyboard::Key key_down  = sf::Keyboard::S;
        sf::Keyboard::Key key_right = sf::Keyboard::D;
    }keymap;

	ResourceLoader();
	bool LoadResources();
    void playSound(ResourceLoader::soundEffect sfx);

    virtual ~ResourceLoader();


    sf::RenderWindow *getWindow() const;
    void setWindow(sf::RenderWindow *window);
    void setLeft_side_bar_size(int left_side_bar);
    void setRight_side_bar_size(int right_side_bar);

    const sf::Font &getPlayfair_regular() const;
    const sf::Font &getOpensans_regular() const;
    int getLeft_side_bar_size() const;
    int getRight_side_bar_size() const;

private:
    int left_side_bar_size = 100;
    int right_side_bar_size = 0;

    bool LoadFonts();
    bool LoadSounds();

    sf::RenderWindow *window;

    sf::Font playfair_regular;
    sf::Font opensans_regular;


    sf::SoundBuffer bufferSoundMenuClickBlip;
    sf::Sound soundMenuClickBlip;

    sf::SoundBuffer bufferSoundClonk;
    sf::Sound soundMenuClonk;
};


#endif // BF_RESOURCELOADER_H
