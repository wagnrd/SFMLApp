//
// Created by Denis Wagner on 1/14/19.
//

#ifndef PONG_NODE_HPP
#define PONG_NODE_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Application.hpp"

class Node {
protected:
    Application* application;
    Node       * parent;

public:
    void initChild( Application* application, Node* child );
    Node* getParent();
    virtual void init();
    virtual void eventHandler( const sf::Event& event );
    virtual void draw( sf::RenderWindow& window ) = 0;
};

#endif //PONG_NODE_HPP
