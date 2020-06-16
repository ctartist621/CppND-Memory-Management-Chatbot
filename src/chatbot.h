#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <iostream>
#include "chatlogic.h"

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();                    // destructor

    // Task 2: Copy Constructor
    ChatBot(const ChatBot &source)
    {
        std::cout << "ChatBot Copy Constructor" << std::endl;

        _image = source._image;
        _chatLogic = source._chatLogic;
        _chatLogic->SetChatbotHandle(this);
        _rootNode = source._rootNode;
        _currentNode = source._currentNode;
    }

    // Task 2: Copy Assignment Operator
    ChatBot &operator=(const ChatBot &source)
    {
        std::cout << "ChatBot Copy Assignment Operator" << std::endl;
        if (this == &source)
            return *this;

        _image = source._image;
        _chatLogic = source._chatLogic;
        _chatLogic->SetChatbotHandle(this);
        _rootNode = source._rootNode;
        _currentNode = source._currentNode;

        return *this;
    }

    // Task 2: Move Constructor
    ChatBot(ChatBot &&source)
    {
        std::cout << "ChatBot Move Constructor" << std::endl;
        _image = source._image;
        _chatLogic = source._chatLogic;
        _chatLogic->SetChatbotHandle(this);
        _rootNode = source._rootNode;
        _currentNode = source._currentNode;
        source._image = nullptr;
        source._chatLogic = nullptr;
        source._rootNode = nullptr;
        source._currentNode = nullptr;
    }

    // Task 2: Move Assignment Operator
    ChatBot &operator=(ChatBot &&source)
    {
        std::cout << "ChatBot Move Assignment Operator" << std::endl;
        if (this == &source)
            return *this;

        _image = source._image;
        _chatLogic = source._chatLogic;
        _chatLogic->SetChatbotHandle(this);
        _rootNode = source._rootNode;
        _currentNode = source._currentNode;
        source._image = nullptr;
        source._chatLogic = nullptr;
        source._rootNode = nullptr;
        source._currentNode = nullptr;

        return *this;
    }

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */