#ifndef UI_H
#define UI_H

#include <string>

class ChatUI {
public:
    // Display a received message
    static void displayMessage(const std::string& message);

    // Get user input for sending a message
    static std::string getUserInput();

    // Display error messages
    static void showError(const std::string& error);
};

#endif // UI_H
