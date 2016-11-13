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
    /**
     * Lists of all sound effects.
     */
    enum soundEffect{
        sfxMenuClickBlip,   ///< Click Blip sound
        sfxMenuClonk        ///< Clonk sound
    };

    /*
     * Maps buttons to action, for easy change later.
     */
    struct Keymap{
        sf::Keyboard::Key key_up    = sf::Keyboard::W; ///< Maps key for UP action
        sf::Keyboard::Key key_left  = sf::Keyboard::A; ///< Maps key for LEFT action
        sf::Keyboard::Key key_down  = sf::Keyboard::S; ///< Maps key for DOWN action
        sf::Keyboard::Key key_right = sf::Keyboard::D; ///< Maps key for RIGHT action
    }keymap;

    /**
     * Constructor for resource loader, does nothing.
     * @return None
     */
    ResourceLoader(){};

    /**
     * Will load all resources
     * @return Boolean, True if success
     */
	bool LoadResources();

    /**
     * Play sound defined in enum \ref soundEffect defined in \ref ResourceLoader class
     * @param sfx soundEffect to be played
     */
    void playSound(ResourceLoader::soundEffect sfx);

    /**
     * Deconstructor for ResourceLoader
     */
    virtual ~ResourceLoader();

    /**
     * Getter for sf::window pointer
     * @return window pointer
     */
    sf::RenderWindow *getWindow() const;

    /**
     * Setter for window pointer variable
     * @param window
     */
    void setWindow(sf::RenderWindow *window);

    /**
     * Set width of in-game left side bar \ref ObjectLeftSideBar
     * @param left_side_bar side bar width in pixels
     */
    void setLeft_side_bar_size(int left_side_bar);

    /**
     * Set width of in-game right side bar
     * @param right_side_bar side bar width in pixels
     */
    void setRight_side_bar_size(int right_side_bar);

    /**
     * Getter for Playfair regular font
     * @return sf::Font address
     */
    const sf::Font &getPlayfair_regular() const;

    /**
     * Getter for Opensans regular font
     * @return sf::Font address
     */
    const sf::Font &getOpensans_regular() const;

    /**
     * Get width of in-game left side bar \ref ObjectLeftSideBar
     * @return side bar width in pixels
     */
    int getLeft_side_bar_size() const;

    /**
     * Get width of in-game right side bar
     * @return
     */
    int getRight_side_bar_size() const;

private:
    int left_side_bar_size = 100;
    int right_side_bar_size = 0;

    /**
     * Load fonts to memory
     * @return True if success
     */
    bool LoadFonts();

    /**
     * Load sounds to memory
     * @return True if success
     */
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
