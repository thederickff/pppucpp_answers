#include <iostream>
#include <vector>

int main()
{
    std::vector<int> nodes = {
                                    0, 
                    1,                              2,
            3,              4,              5,               6,
        7,       8,     9,     10,      11,     12,     13,     14,
      15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30
    };

    std::vector<int> nav = {
        1, 2
    };

    int level = 0;
    int itemPerLvl = 1;
    int offset = 0;

    for (int i = 0; i < nodes.size();)
    {
        level++;

        for (int j = 0; j < itemPerLvl; ++j) {
            if (offset == j) {
                std::cout << nodes[i+j] << std::endl;
            }
        }
        
        i += itemPerLvl;

        int dir = nav[level-1];

        if (dir == 1) {
            offset = (offset * 2);
        } else if (dir == 2) {
            offset = (offset * 2) + 1;
        }

        std::cout << "Level: " << level << std::endl;
        itemPerLvl *= 2;

        int remaning = nodes.size() - i;

        if (remaning < itemPerLvl) {
            break;
        }

        if (level > nav.size()) {
            break;
        }
    }
    

    return 0;
}