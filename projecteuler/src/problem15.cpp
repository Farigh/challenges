/*
 * Lattice paths
 *
 * Starting in the top left corner of a 2x2 grid, and only being able to move to the right and down,
 * there are exactly 6 routes to the bottom right corner :
 *
 *    *--*--*    *--*  *    *--*  *
 *          |       |          |
 *    *  *  *    *  *--*    *  *  *
 *          |          |       |
 *    *  *  *    *  *  *    *  *--*
 *
 *    *  *  *    *  *  *    *  *  *
 *    |          |          |
 *    *--*--*    *--*  *    *  *  *
 *          |       |       |
 *    *  *  *    *  *--*    *--*--*
 *
 * How many such routes are there through a 20x20 grid?
 */
/*
 * Self commentary : moves cost :
 *
 *         2x2                   3x3
 *   S = 0--1--1         S = 0--1--1--1
 *       |  |  |             |  |  |  |
 *       1--2--3             1--2--3--4
 *       |  |  |             |  |  |  |
 *       1--3--6 = E         1--3--6--10
 *                           |  |  |  |
 *                           1--4--10-20 = E
 */
#include <cstdint>
#include <iostream>

int main()
{
    static constexpr std::uint64_t gridSize = 20;

    // Lets initialize with 1s
    std::uint64_t buff[gridSize + 1 ][gridSize + 1] = { 0 };

    // put 1s on the 1st line (ignore 1st index, it always 0 as it's the strating point)
    for (std::uint64_t i = 1; i <= gridSize; ++i)
    {
        buff[0][i] = 1;
    }

    // Only solve the upper triangle since data is mirrored under the diagonal
    for (std::uint64_t h = 1; h <= gridSize; ++h)
    {
        // Start at 1, index 0 is already filled
        for (std::uint64_t v = 1; v < h; ++v)
        {
            // Current value = upper value + left value
            buff[v][h] = buff[v][h - 1] + buff[v - 1][h];
        }

        // The diagonal is always 2 times it's upper value
        buff[h][h] = 2 * buff[h - 1][h];
    }

    std::cout << buff[gridSize][gridSize] << std::endl;
}
