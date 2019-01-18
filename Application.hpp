//
// Created by Denis Wagner on 1/14/19.
//

#ifndef PONG_APPLICATION_HPP
#define PONG_APPLICATION_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <map>

class Node;

class Application {
    std::map<std::string, std::shared_ptr<Node>> nodes;
    std::shared_ptr<Node>                        currentNode;

    std::string windowText;
    float       windowHeight;
    float       windowWidth;
    float       windowWidthDefault;
    float       windowHeightDefault;
    bool        isFullscreen = false;

protected:
    sf::RenderWindow window;

public:
    Application( const std::string& windowText, float windowWidth, float windowHeight );

    void start();
    virtual void init();

    void addNode( const std::string& nodeID, std::shared_ptr<Node> node );
    void setNode( const std::string& nodeID );

    float getWindowHeight() const;
    void setWindowHeight( float windowHeight );
    float getWindowWidth() const;
    void setWindowWidth( float windowWidth );
    sf::RenderWindow* getWindow();
    void setWindowSize( float windowWidth, float windowHeight );
    void setFullscreen( bool value );
};

#endif //PONG_APPLICATION_HPP
