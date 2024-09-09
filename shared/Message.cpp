#include "Message.h"
#include <nlohmann/json.hpp>

Message::Message(const std::string& sender, const std::string& recipient, const std::string& content)
    : sender(sender), recipient(recipient), content(content) {}

std::string Message::serialize() const {
    nlohmann::json messageJson;
    messageJson["sender"] = sender;
    messageJson["recipient"] = recipient;
    messageJson["content"] = content;
    messageJson["timestamp"] = timestamp;
    return messageJson.dump();
}

Message Message::deserialize(const std::string& data) {
    nlohmann::json messageJson = nlohmann::json::parse(data);
    Message message(
        messageJson["sender"].get<std::string>(),
        messageJson["recipient"].get<std::string>(),
        messageJson["content"].get<std::string>()
    );
    message.timestamp = messageJson["timestamp"].get<std::string>();
    return message;
}

void Message::setTimestamp(const std::string& ts) {
    timestamp = ts;
}

std::string Message::getSender() const {
    return sender;
}

std::string Message::getRecipient() const {
    return recipient;
}

std::string Message::getContent() const {
    return content;
}

std::string Message::getTimestamp() const {
    return timestamp;
}
