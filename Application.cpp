//
// Created by Denis Wagner on 1/14/19.
//

#include <SFML/Window/Event.hpp>
#include <iostream>
#include "Application.hpp"
#include "Node.hpp"

Application::Application( const std::string& windowText, float windowWidth, float windowHeight )
        : window( sf::VideoMode( windowWidth, windowHeight ), windowText ),
          windowWidth( windowWidth ),
          windowHeight( windowHeight ),
          windowWidthDefault( windowWidth ),
          windowHeightDefault( windowHeight ),
          windowText( windowText )
{
}

void Application::start()
{
    init();

    while ( window.isOpen() )
    {
        sf::Event event;

        while ( window.pollEvent( event ) )
        {
            if ( event.type == sf::Event::Closed )
                window.close();

            if ( event.type == sf::Event::Resized )
            {
                windowWidth  = window.getSize().x;
                windowHeight = window.getSize().y;
            }

            currentNode->eventHandler( event );
        }

        // redraw frame
        currentNode->draw( window );
        window.display();
    }
}

void Application::init()
{
}

void Application::addNode( const std::string& nodeID, std::shared_ptr<Node> node )
{
    nodes[nodeID] = node;
    node->initChild( this, nullptr );
}

void Application::setNode( const std::string& nodeID )
{
    try
    {
        currentNode = nodes.at( nodeID );
    }
    catch ( const std::exception& e )
    {
        std::cerr << "No node with ID \"" << nodeID << "\" found. Exiting..." << std::endl;
        exit( 1 );
    }

    currentNode->init();
}

float Application::getWindowHeight() const
{
    return windowHeight;
}

void Application::setWindowHeight( float windowHeight )
{
    window.create( sf::VideoMode( windowWidth, windowHeight ), windowText );
    Application::windowHeight = windowHeight;
    windowHeightDefault       = windowHeight;
}

float Application::getWindowWidth() const
{
    return windowWidth;
}

void Application::setWindowWidth( float windowWidth )
{
    window.create( sf::VideoMode( windowWidth, windowHeight ), windowText );
    Application::windowWidth = windowWidth;
    windowWidthDefault       = windowWidth;
}

void Application::setWindowSize( float windowWidth, float windowHeight )
{
    window.create( sf::VideoMode( windowWidth, windowHeight ), windowText );
    Application::windowWidth  = windowWidth;
    Application::windowHeight = windowHeight;
    windowWidthDefault        = windowWidth;
    windowHeightDefault       = windowHeight;
}

void Application::setFullscreen( bool value )
{
    if ( value && !isFullscreen )
        window.create( sf::VideoMode( windowWidth, windowHeight ), windowText, sf::Style::Fullscreen );
    else if ( isFullscreen )
        window.create( sf::VideoMode( windowWidthDefault, windowHeightDefault ), windowText );

    isFullscreen = value;
    windowWidth  = window.getSize().x;
    windowHeight = window.getSize().y;
}

sf::RenderWindow* Application::getWindow()
{
    return &window;
}

