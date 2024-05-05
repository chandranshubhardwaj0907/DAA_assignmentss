#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

// A Huffman tree node
struct Node {
    char data;
    int frequency;
    Node *left, *right;

    Node(char data, int frequency) {
        this->data = data;
        this->frequency = frequency;
        left = right = nullptr;
    }
};

// Function to compare two nodes based on their frequencies
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->frequency > r->frequency;
    }
};

// Function to perform Huffman encoding
void encode(Node* root, string str, map<char, string>& huffmanCode) {
    if (root == nullptr) return;

    // If the current node is a leaf node, then it contains a character
    // Add it to the huffmanCode map
    if (!root->left && !root->right) {
        huffmanCode[root->data] = str;
    }

    // Traverse left
    encode(root->left, str + "0", huffmanCode);

    // Traverse right
    encode(root->right, str + "1", huffmanCode);
}

// Function to build the Huffman tree and perform encoding
map<char, string> buildHuffmanTree(string text) {
    // Calculate frequency of each character
    map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }

    // Create a priority queue to store nodes
    priority_queue<Node*, vector<Node*>, compare> pq;
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Build Huffman tree
    while (pq.size() != 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* newNode = new Node('$', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Perform encoding
    Node* root = pq.top();
    map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    return huffmanCode;
}

int main() {
    string text = "Huffman coding is a data compression algorithm.";
    map<char, string> huffmanCode = buildHuffmanTree(text);

    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << endl;
    }

    return 0;
}
