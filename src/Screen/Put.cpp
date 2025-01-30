#include "Screen/ScreenBase.hpp"

void tform::Screen::put(tform::ScreenChar_t sch) {
    if (sch.height > this->screen_.size())
        throw std::out_of_range("Required row is higher than screen.size()");
    else if (sch.width > this->screen_[0].size())
        throw std::out_of_range("Required column is higher than screen[0].size()");
    else {
        this->latest_cursor_pos_ = {sch.height, sch.width};
        this->screen_[sch.height][sch.width] = sch;
    }
}
