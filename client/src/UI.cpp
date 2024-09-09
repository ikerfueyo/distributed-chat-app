#include "UI.h"
#include <iostream>

void ChatUI::displayMessage(const std::string& message) {
    std::cout << "Message received: " << message << std::endl;
}

std::string ChatUI::getUserInput() {
    std::string input;
    std::cout << "Enter your message: ";
    std::getline(std::cin, input);
    return input;
}

void ChatUI::showError(const std::string& error) {
    std::cerr << "Error: " << error << std::endl;
}
