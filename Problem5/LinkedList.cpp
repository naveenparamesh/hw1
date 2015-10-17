#include <iostream>

using namespace std;

template <typename DataType>
struct Node{
    Node* nextNode;
    Node* previousNode;
    DataType data;
    Node(DataType inputData);
};

template <typename DataType>
Node<DataType>::Node(DataType inputData){
    data = inputData;
    nextNode = 0;
    previousNode = 0;
}

template <typename DataType>
class LinkedListClass{
    
    private:
    Node<DataType>* head;
    Node<DataType>* tail;
    
    public:
    LinkedListClass(){
        head = 0;
        tail = 0;
    }
    
    void Prepend(DataType inputData){
        Node<DataType>* newNode = new Node<DataType>(inputData);
        if(head == 0){
            head = newNode;
            tail = newNode;
        }
        else {
            Node<DataType>* tempNode = head;
            newNode->nextNode = head;
            head = newNode;
            tempNode->previousNode = head;
        }
    }
    
    void Append(DataType inputData){
        Node<DataType>* newNode = new Node<DataType>(inputData);
        if(tail == 0){
            head = newNode;
            tail = newNode;
        }
        else {
            Node<DataType>* tempNode = tail;
            tail->nextNode = newNode;
            tail = newNode;
            tail->previousNode = tempNode;
        }
    }
    
    void DeleteNode(DataType inputData){
        Node<DataType>* currentNode = head;
        while(true){
            if(currentNode == 0){//if there are no nodes at all nothing to delete so just break;
                cout << "Nothing to delete...\n";
                break;
            }
            if(currentNode->data == inputData){// this is the node you want to delete
                if(currentNode->previousNode == 0 && currentNode->nextNode == 0){
                    delete currentNode;
                    head = 0;
                    tail = 0;
                }
                else if(currentNode->previousNode == 0){
                    currentNode->nextNode->previousNode = 0;
                    delete currentNode;
                }
                else if(currentNode->nextNode == 0){
                    currentNode->previousNode->nextNode = 0;
                    delete currentNode;
                }
                else {
                    currentNode->previousNode->nextNode = currentNode->nextNode;
                    currentNode->nextNode->previousNode = currentNode->previousNode;
                    delete currentNode;
                }
                
                cout << "Node deleted...\n";
                break;
            }
            else if(currentNode == tail){//if it reached the end and there is no node to delete
                cout << "That node was not in the list, didn't delete anything...\n";
                break;
            }
            
            currentNode = currentNode->nextNode; // increment to the next node in the list
        }
    }
    
    bool search(DataType inputData){
        Node<DataType>* currentNode = head;
        while(true){
            if(currentNode == 0){//no nodes in the list
                cout << "Nothing to search for...\n";
                return false;
            }
            if(currentNode->data == inputData){//found the node, return true
                cout << "Found the node...\n";
                return true;
            }
            else if(currentNode == tail){
                cout << "That node was not in the list...\n";
                return false;
            }
            
            currentNode = currentNode->nextNode;
        }
    }
    
    void clearList(){
        Node<DataType>* currentNode = head;
        while(true){
            if(currentNode == 0){//no nodes in the list, thus nothing to delete
                 cout << "Finished clearing...\n";
                 break;
            }
            Node<DataType>* tempNode = currentNode;
            currentNode = currentNode->nextNode;
            delete tempNode; // gets rid of that node
        }
    }
    
};

int main(){
    
    // All of these lines were just random lines added to test and show that my LinkedListClass works
    LinkedListClass<int> myLinkedList;
    myLinkedList.search(5);
    myLinkedList.Prepend(10);
    myLinkedList.search(10);
    myLinkedList.Append(19);
    myLinkedList.search(19);
    myLinkedList.DeleteNode(19);
    myLinkedList.DeleteNode(20);
    myLinkedList.clearList();
    
    
    return 0;
}