#include "pages.hpp"

Page currentPage = Page::LOGIN;

void viewHandleEvent(const sf::Event& event) {
    switch (currentPage) {
        case LOGIN: loginHandleEvent(event); break;
        case USER_DASHBOARD: dashboardHandleEvent(event); break;
        default: break;
    }
}

void viewRender(sf::RenderWindow& window) {
    switch (currentPage) {
        case LOGIN: loginRender(window); break;
        case USER_DASHBOARD: dashboardRender(window); break;
        default: break;
    }
}