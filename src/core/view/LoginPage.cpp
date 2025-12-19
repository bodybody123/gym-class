#include "pages.hpp"
#include <SFML/Graphics.hpp>

// ?
static sf::Font font("assets/fonts/Inter/Regular.ttf");
static bool initialized = false;

// ? Login button
static sf::RectangleShape loginButton;
static sf::Text loginButtonText(font);

// ? Username input
static sf::RectangleShape usernameBox;
static sf::Text usernameText(font);
static std::string usernameInput;
static bool usernameActive = false;

// ? Password input
static sf::RectangleShape passwordBox;
static sf::Text passwordText(font);
static std::string passwordInput;
static bool passwordActive = false;

static void initLoginForms()
{
    // Username box
    usernameBox.setSize({300.f, 40.f});
    usernameBox.setPosition({250.f, 200.f});
    usernameBox.setFillColor(sf::Color::Blue);
    usernameBox.setOutlineThickness(2.f);
    usernameBox.setOutlineColor(sf::Color::Black);

    usernameText.setCharacterSize(20);
    usernameText.setFillColor(sf::Color::Black);
    usernameText.setPosition({260.f, 205.f});

    // Password box
    passwordBox.setSize({300.f, 40.f});
    passwordBox.setPosition({250.f, 260.f});
    passwordBox.setFillColor(sf::Color::Red);
    passwordBox.setOutlineThickness(2.f);
    passwordBox.setOutlineColor(sf::Color::Black);

    passwordText.setCharacterSize(20);
    passwordText.setFillColor(sf::Color::Black);
    passwordText.setPosition({260.f, 265.f});

    // Submit button
    loginButton.setSize({300.f, 45.f});
    loginButton.setPosition({250.f, 330.f});
    loginButton.setFillColor(sf::Color(200, 200, 200));

    loginButtonText.setString("LOGIN");
    loginButtonText.setCharacterSize(22);
    loginButtonText.setFillColor(sf::Color::Black);

    auto bounds = loginButtonText.getLocalBounds();
    loginButtonText.setPosition({loginButton.getPosition().x + (300.f - bounds.size.x) / 2.f,
                                 loginButton.getPosition().y + (45.f - bounds.size.y) / 2.f - 5.f});

    initialized = true;
}

void loginHandleEvent(const sf::Event& event)
{
    if (!initialized)
        initLoginForms();

    // -------------------------------
    // Mouse click (focus + button)
    // -------------------------------
    if (const auto* mouse = event.getIf<sf::Event::MouseButtonPressed>())
    {
        sf::Vector2f pos(
            static_cast<float>(mouse->position.x),
            static_cast<float>(mouse->position.y)
        );

        usernameActive = usernameBox.getGlobalBounds().contains(pos);
        passwordActive = passwordBox.getGlobalBounds().contains(pos);

        usernameBox.setOutlineColor(usernameActive ? sf::Color::Blue : sf::Color::Black);
        passwordBox.setOutlineColor(passwordActive ? sf::Color::Blue : sf::Color::Black);

        // Login button click
        if (loginButton.getGlobalBounds().contains(pos))
        {
            // TODO: validate username/password
            currentPage = USER_DASHBOARD;
        }
    }

    // -------------------------------
    // Text input
    // -------------------------------
    if (const auto* textEntered = event.getIf<sf::Event::TextEntered>())
    {
        if (textEntered->unicode == 8) // Backspace
        {
            if (usernameActive && !usernameInput.empty())
                usernameInput.pop_back();

            if (passwordActive && !passwordInput.empty())
                passwordInput.pop_back();
        }
        else if (textEntered->unicode >= 32 && textEntered->unicode <= 126)
        {
            char c = static_cast<char>(textEntered->unicode);

            if (usernameActive)
                usernameInput += c;

            if (passwordActive)
                passwordInput += c;
        }

        usernameText.setString(usernameInput);
        passwordText.setString(std::string(passwordInput.size(), '*'));
    }
}

void loginRender(sf::RenderWindow &window)
{
    if (!initialized) initLoginForms;

    window.draw(loginButton);
    window.draw(usernameBox);
    window.draw(passwordBox);

    window.draw(loginButtonText);
    window.draw(usernameText);
    window.draw(passwordText);
}