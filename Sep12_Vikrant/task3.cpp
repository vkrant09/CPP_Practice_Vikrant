// Question 3: Command Queue – Linked Execution Engine
// Introduction
// Command queues are vital in embedded actuator systems. This challenge
// involves building a linked list of commands using pointers and executing them
// via reference-to-pointer traversal.
// Scenario
// You’re designing a command queue for a robotic actuator. Each command is
// stored in a node and executed sequentially. The queue is traversed using
// reference-to-pointer logic, and global functions help manage execution and
// display.
// Class Specifications
// Command
// • Attributes:
// std::string name, int duration
// CommandNode
// • Attributes:
// Command* cmd, CommandNode* next
// CommandQueue
// • Attributes:
// CommandNode* head
// • Methods:
// void enqueue(Command* c)
// void executeNext(CommandNode*& current)
// void executeAll() → uses global function
// void clear()
// CommandExecutor
// • Method:
// void run(Command& c)
// Global Functions
// void advanceQueue(CommandNode*& current);
// void printQueue(CommandNode* head);
// Sample Data
// Command* c1 = new Command("Start Motor", 100);
// Command* c2 = new Command("Open Valve", 50);
// Command* c3 = new Command("Stop Motor", 80);
// Tasks
// • Dynamically create and enqueue 5 commands
// • Traverse queue using reference to pointer
// • Execute commands via reference
// • Use global functions to advance and print queue
// • Implement destructor logic to avoid leaks
// Concepts Reinforced
// • Reference-to-pointer traversal
// • Linked list manipulation via pointers
// • Global function-based queue control
// • Reference-based command execution
// • Manual memory cleanup

#include <iostream>
#include <string>
using namespace std;

class Command;
class CommandNode;

void advanceQueue(CommandNode*& current);
void printQueue(CommandNode* head);

class Command {
public:
    string name;
    int duration;
    Command(string n, int d) : name(n), duration(d) {}
};

class CommandNode {
public:
    Command* cmd;
    CommandNode* next;
    CommandNode(Command* c) : cmd(c), next(nullptr) {}
};

class CommandExecutor {
public:
    void run(Command& c) {
        cout << "Executing: " << c.name << " for " << c.duration << "ms" << endl;
    }
};

class CommandQueue {
public:
    CommandNode* head;
    CommandQueue() : head(nullptr) {}

    void enqueue(Command* c) {
        CommandNode* node = new CommandNode(c);
        if (!head) {
            head = node;
        } else {
            CommandNode* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = node;
        }
    }

    void executeNext(CommandNode*& current) {
        if (current) {
            CommandExecutor exec;
            exec.run(*current->cmd);
            advanceQueue(current);
        }
    }

    void executeAll() {
        CommandNode* current = head;
        while (current) {
            executeNext(current);
        }
    }

    void clear() {
        CommandNode* temp = head;
        while (temp) {
            CommandNode* nextNode = temp->next;
            delete temp->cmd;
            delete temp;
            temp = nextNode;
        }
        head = nullptr;
    }

    ~CommandQueue() {
        clear();
    }
};

void advanceQueue(CommandNode*& current) {
    if (current) current = current->next;
}

void printQueue(CommandNode* head) {
    CommandNode* temp = head;
    while (temp) {
        cout << temp->cmd->name << " (" << temp->cmd->duration << "ms)" << endl;
        temp = temp->next;
    }
}

int main() {
    CommandQueue queue;
    queue.enqueue(new Command("Start Motor", 100));
    queue.enqueue(new Command("Open Valve", 50));
    queue.enqueue(new Command("Stop Motor", 80));
    queue.enqueue(new Command("Check Pressure", 30));
    queue.enqueue(new Command("Shutdown", 60));

    cout << "Queue Status:" << endl;
    printQueue(queue.head);

    cout << "\nExecuting All Commands:" << endl;
    queue.executeAll();

    return 0;
}
