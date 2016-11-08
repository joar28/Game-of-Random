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

	ResourceLoader();
	bool LoadResources();
    void playSound(ResourceLoader::soundEffect sfx);

    virtual ~ResourceLoader();


    sf::RenderWindow *getWindow() const;
    void setWindow(sf::RenderWindow *window);

    const sf::Font &getPlayfair_regular() const;
    const sf::Font &getOpensans_regular() const;

private:
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
