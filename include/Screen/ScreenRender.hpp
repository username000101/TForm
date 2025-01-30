#pragma once

#include <iostream>
#include <ostream>
#include <vector>

#include "Char/CharBase.hpp"

namespace tform {
    class ScreenRender {
        friend class Screen;
    private:
        ScreenRender() = default;

        void refresh(std::vector<std::vector<ScreenChar_t>>& sv, std::ostream& stream = std::cout);
    };
}
