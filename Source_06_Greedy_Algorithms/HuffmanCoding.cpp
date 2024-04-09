#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

// Cvor Hafmanovog stabla
struct Node {
    char data;
    int freq;
    Node* left, * right;

    Node(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// Funkcija za poredjenje cvorova u redu sa prioritetom
struct compare {
    bool operator()(Node* l, Node* r) {
        return (l->freq > r->freq);
    }
};

// Funkcija za dodelu kodnih reci
void encode(Node* root, string str, unordered_map<char, string>& huffmanCode) {
    if (root == nullptr)
        return;

    if (!root->left && !root->right) {
        huffmanCode[root->data] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

// Funkcija za konstrukciju Hafmanovog stabla
Node* buildHuffmanTree(string text) {
    // Racunanje frekvencije ulaznih karaktera
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    // Kreiranje reda sa prioritetom od cvorova
    priority_queue<Node*, vector<Node*>, compare> pq;
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Hafmanov algoritam
    while (pq.size() != 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        int sum = left->freq + right->freq;
        Node* newNode = new Node('\0', sum);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    // Reultat je koren Hafmanovog stabla
    return pq.top();
}

// Glavna funkcija za kreriranje Hafmanovog stabla i dodeljivanje kodnih reci
unordered_map<char, string> buildHuffmanCodes(string text) {
    unordered_map<char, string> huffmanCode;
    Node* root = buildHuffmanTree(text);
    encode(root, "", huffmanCode);
    return huffmanCode;
}

int Huffman_main() {
    string text = "aaaaaaaaaaeeeeeeeeeeeeeeeiiiiiiiiiiiiooouuuussssssssssssst";

    // Generisanje Hafmanovih kodnih reci
    unordered_map<char, string> huffmanCode = buildHuffmanCodes(text);

    // Ispis kodnih reci
    cout << "Huffman Codes are:\n" << endl;
    for (auto pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << "\n";
    }

    return 0;
}