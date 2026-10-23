#include <iostream>
#include <string>

using namespace std;

struct Node {
    char data;
    Node* firstChild;
    Node* nextSibling;

    Node(char val) : data(val), firstChild(nullptr), nextSibling(nullptr) {}
};

Node* createGeneralTree();

void preOrder(Node* root);
void postOrder(Node* root);
void inOrder(Node* root);
void addChild(Node* parent, Node* child);
bool searchPreOrder(Node* root, char key);
bool searchPostOrder(Node* root, char key);
bool searchInOrder(Node* root, char key);
void findData(Node* root, string choice, char key);

int main() {
    // Task 1: Create General Tree
    Node* root = createGeneralTree();
    cout << "General Tree created with Root: " << root->data << "\n\n";

    // Task 3.2: Demonstrate Traversals
    cout << "Pre-Order Traversal: ";
    preOrder(root);
    cout << "\nIn-Order Traversal: ";
    inOrder(root);
    cout << "\nPost-Order Traversal: ";
    postOrder(root);
    cout << "\n\n";

    // Task 3.3: Demonstrate findDataS
    cout << "Searching for key 'J' using INORDER: ";
    findData(root, "INORDER", 'J');

    // Task 3.4: Add Node 'O' under Node 'G' and search
    Node* nodeO = new Node('O');
    Node* tempG = root->firstChild; 
    while (tempG && tempG->data != 'G') {
        tempG = tempG->nextSibling;
    }

    if (tempG) {
        addChild(tempG, nodeO); // Node 'O' attached under 'G'
    }

    cout << "Searching for newly added leaf 'O' using PREORDER: ";
    findData(root, "PREORDER", 'O');

    return 0;
}

void addChild(Node* parent, Node* child) {
    if (!parent->firstChild) {
        parent->firstChild = child;
    } else {
        Node* temp = parent->firstChild;
        while (temp->nextSibling) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = child;
    }
}

// Task 1: Building the General Tree structure (Nodes A through Q)
Node* createGeneralTree() {
    Node* nodeA = new Node('A');
    Node* nodeB = new Node('B');
    Node* nodeC = new Node('C');
    Node* nodeD = new Node('D');
    Node* nodeE = new Node('E');
    Node* nodeF = new Node('F');
    Node* nodeG = new Node('G');
    Node* nodeH = new Node('H');
    Node* nodeI = new Node('I');
    Node* nodeJ = new Node('J');
    Node* nodeK = new Node('K');
    Node* nodeL = new Node('L');
    Node* nodeM = new Node('M');
    Node* nodeN = new Node('N');
    Node* nodeP = new Node('P');
    Node* nodeQ = new Node('Q');

    // Root A children
    addChild(nodeA, nodeB);
    addChild(nodeA, nodeC);
    addChild(nodeA, nodeD);
    addChild(nodeA, nodeE);
    addChild(nodeA, nodeF);
    addChild(nodeA, nodeG);

    // Subtree connection
    addChild(nodeD, nodeH);

    addChild(nodeE, nodeI);
    addChild(nodeE, nodeJ);
    addChild(nodeJ, nodeP);
    addChild(nodeJ, nodeQ);

    addChild(nodeF, nodeK);
    addChild(nodeF, nodeL);
    addChild(nodeF, nodeM);

    addChild(nodeG, nodeN);

    return nodeA;
}

// Task 3.2 Traversal
void preOrder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    Node* child = root->firstChild;
    while (child) {
        preOrder(child);
        child = child->nextSibling;
    }
}

void postOrder(Node* root) {
    if (!root) return;
    Node* child = root->firstChild;
    while (child) {
        postOrder(child);
        child = child->nextSibling;
    }
    cout << root->data << " ";
}

void inOrder(Node* root) {
    if (!root) return;
    Node* child = root->firstChild;
    if (child) {
        inOrder(child);
        child = child->nextSibling;
    }
    cout << root->data << " ";
    while (child) {
        inOrder(child);
        child = child->nextSibling;
    }
}

// Task 3.3 Search Algorithms & Interface
bool searchPreOrder(Node* root, char key) {
    if (!root) return false;
    if (root->data == key) return true;
    Node* child = root->firstChild;
    while (child) {
        if (searchPreOrder(child, key)) return true;
        child = child->nextSibling;
    }
    return false;
}

bool searchPostOrder(Node* root, char key) {
    if (!root) return false;
    Node* child = root->firstChild;
    while (child) {
        if (searchPostOrder(child, key)) return true;
        child = child->nextSibling;
    }
    return (root->data == key);
}

bool searchInOrder(Node* root, char key) {
    if (!root) return false;
    Node* child = root->firstChild;
    if (child) {
        if (searchInOrder(child, key)) return true;
        child = child->nextSibling;
    }
    if (root->data == key) return true;
    while (child) {
        if (searchInOrder(child, key)) return true;
        child = child->nextSibling;
    }
    return false;
}

void findData(Node* root, string choice, char key) {
    bool found = false;
    if (choice == "PREORDER" || choice == "preorder") {
        found = searchPreOrder(root, key);
    } else if (choice == "INORDER" || choice == "inorder") {
        found = searchInOrder(root, key);
    } else if (choice == "POSTORDER" || choice == "postorder") {
        found = searchPostOrder(root, key);
    }

    if (found) {
        cout << key << " was found!" << endl;
    }
}