#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    // Removed duplicate deallocation of chatbot to resolve runtime error
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
{
    // Task 4: Push the unique pointer to the vector
    _childEdges.push_back(std::make_unique<GraphEdge>(*edge));
}

// Task 5 Move instance of ChatBot
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    // Task 5 Move instance of ChatBot
    newNode->MoveChatbotHere(_chatBot);
}

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{

    // Task 4: Get the stored pointer of the GraphEdge
    return _childEdges[index].get();
}