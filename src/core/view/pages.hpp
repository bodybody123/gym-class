#pragma once
#include <SFML/Graphics.hpp>

enum Page
{
    LOGIN,
    USER_DASHBOARD,
    USER_SEARCH,
    USER_DETAIL,
    USER_PROFILE
};

extern Page currentPage;

// router
void viewHandleEvent(const sf::Event& event);
void viewRender(sf::RenderWindow& window);

// pages
void loginHandleEvent(const sf::Event& event);
void loginRender(sf::RenderWindow& window);

void dashboardHandleEvent(const sf::Event& event);
void dashboardRender(sf::RenderWindow& window);