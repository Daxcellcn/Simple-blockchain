#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <functional> // For std::hash
#include <string> // Added for substr()

using std::string;
using std::cout;
using std::endl;

// Class representing a block in the blockchain
class Block {
private:
    int index;          // Index of the block in the blockchain
    string data;        // Data stored in the block
    string prevHash;    // Hash of the previous block
    string hash;        // Hash of the current block
    time_t timestamp;   // Timestamp of when the block was created
    int nonce;          // Nonce value used in mining

public:
    Block(int index, const string& data, const string& prevHash); // Constructor
    string calculateHash() const;  // Method to calculate the hash of the block
    void mineBlock(int difficulty); // Method to mine the block
    void printBlock() const;    // Method to print information about the block
    string getHash() const { return hash; } // Method to get the hash of the block
    string getPrevHash() const { return prevHash; } // Method to get the previous hash of the block
};

// Constructor for the Block class
Block::Block(int index, const string& data, const string& prevHash)
        : index(index), data(data), prevHash(prevHash), timestamp(time(0)), nonce(0) {
    hash = calculateHash(); // Calculate the hash of the block
}

// Method to calculate the hash of the block using std::hash
string Block::calculateHash() const {
    std::stringstream ss;
    ss << index << prevHash << timestamp << data << nonce;
    return std::to_string(std::hash<string>{}(ss.str())); // Hash the concatenated string
}

// Method to mine the block using Proof of Work
void Block::mineBlock(int difficulty) {
    char target = '0'; // Define the target hash with a specified number of leading zeros
    // Continue incrementing the nonce and recalculating the hash until the target is reached
    while (hash.substr(0, difficulty) != string(difficulty, target)) {
        nonce++;
        hash = calculateHash(); // Recalculate the hash
    }
}

// Method to print information about the block
void Block::printBlock() const {
    cout << "Block #" << index << endl; // Print the block index
    cout << "Timestamp: " << std::ctime(&timestamp); // Print the block timestamp
    cout << "Data: " << data << endl; // Print the block data
    cout << "Previous Hash: " << prevHash << endl; // Print the previous block's hash
    cout << "Hash: " << hash << endl; // Print the block's hash
    cout << "Nonce: " << nonce << endl << endl; // Print the nonce value
}

// Class representing the blockchain
class Blockchain {
private:
    std::vector<Block> chain; // Vector to store blocks in the blockchain
    int difficulty;      // Difficulty level for mining

public:
    Blockchain();  // Constructor
    void addBlock(const string& data); // Method to add a new block to the blockchain
    bool isChainValid() const;  // Method to validate the blockchain
    void printChain() const;    // Method to print the entire blockchain
};

// Constructor for the Blockchain class
Blockchain::Blockchain() {
    chain.emplace_back(Block(0, "Genesis Block", "0")); // Create and add the genesis block to the blockchain
    difficulty = 2; // Set the initial difficulty level for mining
}

// Method to add a new block to the blockchain
void Blockchain::addBlock(const string& data) {
    // Create a new block with the provided data and the hash of the last block in the chain
    Block newBlock(chain.size(), data, chain.back().calculateHash());
    newBlock.mineBlock(difficulty); // Mine the new block
    chain.push_back(newBlock); // Add the new block to the blockchain
}

// Method to validate the blockchain
bool Blockchain::isChainValid() const {
    // Iterate over each block in the blockchain (starting from the second block)
    for (size_t i = 1; i < chain.size(); ++i) {
        const Block& currentBlock = chain[i]; // Current block
        const Block& prevBlock = chain[i - 1]; // Previous block

        // Check if the hash of the current block is valid
        if (currentBlock.calculateHash() != currentBlock.getHash()) {
            cout << "Block #" << i << " is not valid." << endl;
            return false; // Return false if the hash is not valid
        }

        // Check if the previous hash of the current block matches the hash of the previous block
        if (currentBlock.getPrevHash() != prevBlock.getHash()) {
            cout << "Block #" << i << " has invalid previous hash." << endl;
            return false; // Return false if the previous hash is not valid
        }
    }

    return true; // Return true if the blockchain is valid
}

// Method to print the entire blockchain
void Blockchain::printChain() const {
    // Iterate over each block in the blockchain and print its information
    for (const Block& block : chain) {
        block.printBlock();
    }
}

// Main function
int main() {
    Blockchain blockchain; // Create a new blockchain

    cout << "Mining Genesis Block..." << endl;
    blockchain.addBlock("First Block Data"); // Add the first block to the blockchain
    cout << "Mining Second Block..." << endl;
    blockchain.addBlock("Second Block Data"); // Add the second block to the blockchain

    cout << endl << "Blockchain: " << endl;
    blockchain.printChain(); // Print the entire blockchain

    cout << endl << "Blockchain is " << (blockchain.isChainValid() ? "valid." : "not valid.") << endl; // Check if the blockchain is valid

    return 0;
}
