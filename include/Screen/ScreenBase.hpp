#pragma once

#ifdef WIN32
#include <Windows.h>
#else
#include <sys/ioctl.h>
#include <unistd.h>
#endif

#include <chrono>
#include <concepts>
#include <cstdint>
#include <thread>
#include <utility>
#include <vector>

#include "Char/CharBase.hpp"
#include "Screen/ScreenRender.hpp"

namespace tform {
    using TSize = std::pair<std::uint16_t, std::uint16_t>;
    using ScreenVector = std::vector<std::vector<ScreenChar_t>>;
    using ScreenColumn = std::vector<ScreenChar_t>;

    static TSize get_terminal_size() {
#ifdef WIN32
    return {0,0};
#else
    winsize ws;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == 0)
        return {ws.ws_row - 1, ws.ws_col};
    else
        return {0, 0};
#endif
    }

    template <typename T> concept Writeable = requires(T var) {
        { std::cout << var };
    };

    class Screen {
    public:
        Screen(char fillch = ' ', TSize size = get_terminal_size()) : wsize_(size) {
            for (std::uint16_t row_counter = 0; row_counter < this->wsize_.first; ++row_counter) {
                ScreenColumn col;
                for (std::uint16_t column_counter = 0; column_counter < this->wsize_.second; ++ column_counter)
                    col.push_back(ScreenChar_t(fillch, row_counter, column_counter));
                this->screen_.push_back(col);
            }
            this->render_.refresh(this->screen_);
        }

        template <Writeable... ArgT> void printt(ArgT&&... args) {
            std::ostringstream stream;
            (stream << ... << args);
            this->print(stream.str());
        }
        void print(std::uint16_t str, std::uint16_t col_spos, const std::string& text);
        void print(const std::string& text) {
            return this->print(this->latest_cursor_pos_.first, this->latest_cursor_pos_.second, text);
        }

        void put(ScreenChar_t sch);

        void update(std::ostream& stream = std::cout) { this->render_.refresh(this->screen_, stream); }

        void wait(std::chrono::seconds sec) { std::this_thread::sleep_for(sec); }
        void wait(std::chrono::milliseconds msec) { std::this_thread::sleep_for(msec); }
        void wait(std::chrono::minutes mins) { std::this_thread::sleep_for(mins); }

        TSize get_screen_parameters() { return this->wsize_; }
        TSize get_latest_cursor_pos() { return this->latest_cursor_pos_; }
    private:
        ScreenVector screen_;
        ScreenRender render_;
        TSize latest_cursor_pos_;
        TSize wsize_;
    };
}
