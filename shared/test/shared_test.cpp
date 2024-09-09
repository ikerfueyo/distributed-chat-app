// Run with:
//      g++ -std=c++11 -I /usr/local/include -L /usr/local/lib test/shared_test.cpp -lgtest -lgtest_main -pthread -o shared_test
//      ./shared_test

#include "Message.h"
#include "Constants.h"
#include "Encryption.h"
#include <gtest/gtest.h>
#include <string>

// Test: Ensure that message serialization and deserialization work correctly
TEST(MessageTest, SerializeDeserialize) {
    // Create a sample message
    std::string sender = "Alice";
    std::string recipient = "Bob";
    std::string content = "Hello, Bob!";
    Message originalMessage(sender, recipient, content);

    // Serialize the message
    std::string serializedMessage = originalMessage.serialize();

    // Deserialize it back to a message object
    Message deserializedMessage = Message::deserialize(serializedMessage);

    // Check that the deserialized message matches the original
    ASSERT_EQ(deserializedMessage.getSender(), originalMessage.getSender());
    ASSERT_EQ(deserializedMessage.getRecipient(), originalMessage.getRecipient());
    ASSERT_EQ(deserializedMessage.getContent(), originalMessage.getContent());
}

// Test: Ensure that message serialization includes the timestamp
TEST(MessageTest, TimestampInSerialization) {
    // Create a sample message and set a timestamp
    std::string sender = "Charlie";
    std::string recipient = "Dana";
    std::string content = "Hi Dana!";
    Message originalMessage(sender, recipient, content);
    std::string timestamp = "2024-09-07 12:34:56";
    originalMessage.setTimestamp(timestamp);

    // Serialize the message
    std::string serializedMessage = originalMessage.serialize();

    // Deserialize it back to a message object
    Message deserializedMessage = Message::deserialize(serializedMessage);

    // Check that the timestamp is correctly set
    ASSERT_EQ(deserializedMessage.getTimestamp(), timestamp);
}

// Test: Validate constants (e.g., message types, port numbers, buffer sizes)
TEST(ConstantsTest, ValidateConstants) {
    ASSERT_EQ(MESSAGE_TYPE_TEXT, "text");
    ASSERT_EQ(MESSAGE_TYPE_IMAGE, "image");
    ASSERT_EQ(DEFAULT_PORT, 12345);
    ASSERT_EQ(MAX_BUFFER_SIZE, 4096);
}

// Test: Ensure that encryption and decryption work properly (placeholder encryption)
TEST(EncryptionTest, EncryptDecrypt) {
    // Create a plain text message
    std::string plainText = "This is a test message.";

    // Encrypt the message
    std::string encryptedMessage = Encryption::encryptMessage(plainText);

    // Decrypt the message
    std::string decryptedMessage = Encryption::decryptMessage(encryptedMessage);

    // The decrypted message should match the original plain text
    ASSERT_EQ(decryptedMessage, plainText);
}

// Test: Verify that encryption returns something different from plain text
TEST(EncryptionTest, EncryptionChangesMessage) {
    // Create a plain text message
    std::string plainText = "Another test message.";

    // Encrypt the message
    std::string encryptedMessage = Encryption::encryptMessage(plainText);

    // Ensure the encrypted message is different from the plain text
    ASSERT_NE(encryptedMessage, plainText);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
