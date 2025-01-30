#include "Screen/ScreenBase.hpp"

#include <stdexcept>

void tform::Screen::print(std::uint16_t str, std::uint16_t col_spos, const std::string& text) {
    for (auto& sym : text)
        this->put(ScreenChar_t(sym, str, col_spos++));
    this->latest_cursor_pos_ = {str, col_spos};
    this->render_.refresh(this->screen_);
}
