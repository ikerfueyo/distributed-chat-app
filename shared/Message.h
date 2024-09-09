#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class Message {
public:
    // Constructor to initialize a message
    Message(const std::string& sender, const std::string& recipient, const std::string& content);

    // Serialize the message into a JSON string
    std::string serialize() const;

    // Deserialize a JSON string into a Message object
    static Message deserialize(const std::string& data);

    // Set and get timestamp
    void setTimestamp(const std::string& timestamp);
    std::string getTimestamp() const;

    // Getters for message properties
    std::string getSender() const;
    std::string getRecipient() const;
    std::string getContent() const;

private:
    std::string sender;
    std::string recipient;
    std::string content;
    std::string timestamp;
};

#endif // MESSAGE_H
