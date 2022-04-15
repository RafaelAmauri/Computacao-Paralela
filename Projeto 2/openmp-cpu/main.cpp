#include <stdbool.h>

#include "headers/Blockchain.h"

bool is_string_empty(char* c) {
    return ((c != NULL) && (c[0] == '\0'));
}

int main(int argc, char** argv)
{
    int num_blocks = 3, difficulty = 2;

    if (!is_string_empty(argv[1]))
        num_blocks = atoi(argv[1]);
    if (!is_string_empty(argv[2]))
        difficulty = atoi(argv[2]);

    cout << "Num blocks: " << num_blocks << endl;
    cout << "Difficulty: " << difficulty << endl << endl;

    Blockchain bChain = Blockchain(difficulty);

    for(int i = 0; i < num_blocks; i++ ) {
        cout << "Mining block " << i + 1 << "..." << endl;
        bChain.AddBlock(Block(i+1, "Block "+std::to_string(i+1)+" Data"));
    }

    return 0;
}
