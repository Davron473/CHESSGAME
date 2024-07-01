#include <iostream>
#include "board.h"
#include "coordinates.h"
#include "piece.h"

int main() {
    Coordinates **mvs_1 = nullptr; 
    int num_mvs = 0; 

    // Initialize board with pieces
    Board t1(8, "RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr");

    // Set the position index to a valid position, e.g., 11 (second row, third column)
    int positionIndex = 11;

    // Ensure the position index is within the valid range
    if (positionIndex >= 0 && positionIndex < 64) {
        Piece *piece = t1.getSquares()[positionIndex].getPiece();

        // Check if there is a piece at the specified position
        if (piece) {
            num_mvs = piece->possibleMoves(mvs_1);

            if (num_mvs > 0 && mvs_1 != nullptr) {
                std::cout << "There are " << num_mvs << " possible moves:" << std::endl;

                for (int i = 0; i < num_mvs; ++i) {
                    std::cout << "Move " << i + 1 << ": " << *mvs_1[i] << std::endl;
                }

                for (int i = 0; i < num_mvs; ++i) {
                    delete mvs_1[i];
                }
                delete[] mvs_1;
            } else {
                std::cout << "Error: Unable to retrieve moves." << std::endl;
            }
        } else {
            std::cout << "Error: No piece at the specified position." << std::endl;
        }
    } else {
        std::cout << "Error: Position index out of range." << std::endl;
    }

    return 0;
}
