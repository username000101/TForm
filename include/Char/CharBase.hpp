#pragma once

#include <cstdint>

namespace tform {
    enum ScreenCharColor {
        WHITE = 0x0,
        BLACK = 0x1,
    };

    struct ScreenChar_t {
    public:
        ScreenChar_t(char chr, std::uint16_t hght, std::uint16_t wdth,
                     ScreenCharColor frg = WHITE, ScreenCharColor bck = BLACK)
            : width(wdth), height(hght),
              foreground_color(frg), background_color(bck),
              ch(chr) {}

        std::uint16_t width = 0;
        std::uint16_t height = 0;

        ScreenCharColor foreground_color = WHITE;
        ScreenCharColor background_color = BLACK;

        char ch;
    };
}
