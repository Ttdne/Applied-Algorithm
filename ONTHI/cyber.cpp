#include <iostream>
#include <bitset>
#include <vector>

// Function to apply the block cipher permutation e(b1b2b3b4b5) = (b1b3b2b4b5)
std::bitset<5> encrypt(std::bitset<5> block) {
    // Swap b2 and b3 (swap 2nd and 3rd bit)
    std::bitset<5> encryptedBlock;
    encryptedBlock[0] = block[0]; // b1 remains the same
    encryptedBlock[1] = block[1]; // b3 becomes b2
    encryptedBlock[2] = block[3]; // b2 becomes b3
    encryptedBlock[3] = block[2]; // b4 remains the same
    encryptedBlock[4] = block[4]; // b5 remains the same
    std::cout<<encryptedBlock<<" ";
    return encryptedBlock;
}

// Function to encrypt a message using CTR mode
std::vector<std::bitset<5>> ctrModeEncryption(const std::vector<std::bitset<5>>& plaintext, const std::bitset<5>& iv) {
    std::vector<std::bitset<5>> ciphertext;
    std::bitset<5> counter = iv;

    for (const auto& block : plaintext) {
        // Encrypt the counter
        std::bitset<5> encryptedCounter = encrypt(counter);
        std::cout<<encryptedCounter<<" ";
        // XOR the encrypted counter with the plaintext block to get the ciphertext
        std::bitset<5> encryptedBlock = block ^ encryptedCounter;
        ciphertext.push_back(encryptedBlock);

        // Increment the counter for the next block
        counter = counter.to_ulong() + 1;  // Increment the counter
    }

    return ciphertext;
}

int main() {
    // Initialize the IV (Initialization Vector)
    std::bitset<5> iv("11001");

    // Define the plaintext message in 5-bit blocks
    std::vector<std::bitset<5>> plaintext = {
        std::bitset<5>("01101"), // Block 1
        std::bitset<5>("11011"), // Block 2
        std::bitset<5>("11110"), // Block 3
        std::bitset<5>("00110")  // Block 4
    };

    // Encrypt the message using CTR mode
    std::vector<std::bitset<5>> ciphertext = ctrModeEncryption(plaintext, iv);

    // Output the ciphertext
    std::cout << "Ciphertext in binary: \n";
    for (const auto& block : ciphertext) {
        std::cout << block << std::endl;
    }

    return 0;
}
