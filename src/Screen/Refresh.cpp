#include "Screen/ScreenRender.hpp"

#include <cstdlib>

void tform::ScreenRender::refresh(std::vector<std::vector<tform::ScreenChar_t>>& sv, std::ostream& stream) {
#ifdef WIN32
    std::system("cls");
#else
    std::system("clear");
#endif

    for (auto& row : sv) {
        for (auto& col : row)
            stream << col.ch;
        stream << std::endl;
    }
}
