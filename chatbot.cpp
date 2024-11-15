#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Function to perform basic sentiment analysis
string analyzeSentiment(const string& input) {
    vector<string> positiveWords = {"good", "great", "happy", "love", "excellent", "fantastic"};
    vector<string> negativeWords = {"bad", "sad", "hate", "terrible", "awful"};

    int positiveCount = 0;
    int negativeCount = 0;

    // Convert input to lowercase for easier matching
    string lowerInput = input;
    transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);

    for (const string& word : positiveWords) {
        if (lowerInput.find(word) != string::npos) {
            positiveCount++;
        }
    }

    for (const string& word : negativeWords) {
        if (lowerInput.find(word) != string::npos) {
            negativeCount++;
        }
    }

    if (positiveCount > negativeCount) {
        return "positive";
    } else if (negativeCount > positiveCount) {
        return "negative";
    } else {
        return "neutral";
    }
}

// Function to get a response based on user input
string getResponse(const string& input) {
    if (input.find("hello") != string::npos || input.find("hi") != string::npos) {
        return "Hello! How can I assist you today?";
    } else if (input.find("how are you") != string::npos) {
        return "I'm just a program, but thanks for asking! How about you?";
    } else if (input.find("what is your name") != string::npos) {
        return "I'm a chatbot created to assist you.";
    } else if (input.find("bye") != string::npos || input.find("exit") != string::npos) {
        return "Goodbye! Have a great day!";
    } else {
        return "I'm not sure how to respond to that.";
    }
}

int main() {
    string userInput;
    cout << "Chatbot: Hello! I am an AI chatbot. Type 'bye' or 'exit' to end the conversation." << endl;

    while (true) {
        cout << "You: ";
        getline(cin, userInput);

        // Exit condition
        if (userInput == "bye" || userInput == "exit") {
            cout << "Chatbot: Goodbye! Have a great day!" << endl;
            break;
        }

        // Analyze sentiment
        string sentiment = analyzeSentiment(userInput);
        cout << "Chatbot: Your sentiment is " << sentiment << "." << endl;

        // Get response
        string response = getResponse(userInput);
        cout << "Chatbot: " << response << endl;
    }

    return 0;
}