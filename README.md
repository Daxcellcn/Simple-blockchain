# Simple C++ Blockchain Implementation

This is a simple implementation of a blockchain in C++. It demonstrates the fundamental concepts of blockchain technology, including block creation, proof-of-work mining, chain validation, and integrity maintenance.

Features
Block Class: Represents individual blocks in the blockchain, each containing an index, data, timestamps, hashes, and a nonce value.
Blockchain Class: Manages a chain of blocks, allowing for the addition of new blocks and validation of the blockchain's integrity.
Proof-of-Work Mining: Blocks are mined using a proof-of-work algorithm, where miners compete to find a hash with a certain number of leading zeros.
Genesis Block: The blockchain starts with a genesis block, serving as the initial block in the chain.
Usage
To use this blockchain implementation:

Clone the repository to your local machine.
Compile the source code using a C++ compiler (e.g., g++).
Run the compiled executable to see the blockchain in action.

g++ -o blockchain simpleblockchain.cpp
./blockchain

Review the Output
Once the program is executed, it will create a blockchain with two blocks and print information about the blockchain, including whether it's valid or not. The output will look similar to the following:

Mining Genesis Block...
Mining Second Block...

Blockchain:

Block #0
Timestamp: Sat Jan  1 00:00:00 2022
Data: Genesis Block
Previous Hash: 0
Hash: 1586743937
Nonce: 28612

Block #1
Timestamp: Sat Jan  1 00:00:00 2022
Data: First Block Data
Previous Hash: 1586743937
Hash: 461794374
Nonce: 3444

Block #2
Timestamp: Sat Jan  1 00:00:00 2022
Data: Second Block Data
Previous Hash: 461794374
Hash: 1185117629
Nonce: 2270

Blockchain is valid.

Example
Here's a simple example of how to create and interact with the blockchain:

Blockchain blockchain;

// Add blocks to the blockchain
blockchain.addBlock("First Block Data");
blockchain.addBlock("Second Block Data");

// Print the entire blockchain
blockchain.printChain();

// Check if the blockchain is valid
if (blockchain.isChainValid()) {
    cout << "Blockchain is valid." << endl;
} else {
    cout << "Blockchain is not valid." << endl;
}


Contributing
Contributions are welcome! If you have ideas for improvements or find any issues, feel free to open an issue or submit a pull request.

License
This project is licensed under the MIT License - see the LICENSE file for details.

