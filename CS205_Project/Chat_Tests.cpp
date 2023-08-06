#include <gtest/gtest.h>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>

#include "chat.h"

// Fixture class to set up a Chat object for testing
class ChatTest : public testing::Test {
protected:
    Chat* chat;

    void SetUp() override {
        // Set up a Chat object
        chat = new Chat();
        chat->show();
    }

    void TearDown() override {
        // Delete the Chat object
        delete chat;
    }
};


// Test the setupDropdown() function
TEST_F(ChatTest, SetupDropdown) {
    // Get the QComboBox object from the Chat object
    QComboBox* userDropdown = chat->findChild<QComboBox*>("userDropdown");

    // Redirect stdout to a buffer
    std::stringstream buffer;
    std::streambuf* old_stdout = std::cout.rdbuf(buffer.rdbuf());

    // Call the setupDropdown() function
    chat->setupDropdown();

    // Restore stdout
    std::cout.rdbuf(old_stdout);

    // Check if something was printed to stdout
    std::string output = buffer.str();
    EXPECT_TRUE(output.empty());
}
