#include "Window.h"

bool Window::closing = false;
Window::Window() {
    title = "Untitled";
    shown = true;
    borderless = false;
    additionalFlags = 0;
    init();
}

Window::Window(const std::string& t) {
    title = t;
    shown = true;
    borderless = false;
    additionalFlags = 0;
    init();
}

Window::Window(const std::string& t, Vec2D<int>& res) {
    title = t;
    resolution->x() = res.x();
    resolution->y() = res.y();
    shown = true;
    borderless = false;
    additionalFlags = 0;
    init();
}
Window::Window(const std::string& t, Vec2D<int>& res, bool s) {
    title = t;
    shown = s;
    resolution->x() = res.x();
    resolution->y() = res.y();
    borderless = false;
    additionalFlags = 0;
    init();
}

Window::Window(const std::string& t, Vec2D<int>& res, Uint32 flags) {
    title = t;
    resolution->x() = res.x();
    resolution->y() = res.y();
    shown = true;
    borderless = false;
    additionalFlags = flags; 
    init();
}

Window::Window(const std::string& t, bool s, bool b) {
    title = t;
    shown = s;
    borderless = b;
    additionalFlags = 0;
    init();
}

Window::Window(const std::string& t, bool s, Uint32 flags) {
    title = t;
    shown = s;
    borderless = false;
    additionalFlags = flags; 
    init();
}

Window::Window(Vec2D<int>& res, bool s, bool b) {
    title = "Untitled";
    resolution->x() = res.x();
    resolution->y() = res.y();
    shown = s;
    borderless = b;
    additionalFlags = 0; 
    init();
}

Window::Window(Vec2D<int>& res, bool s, Uint32 flags) {
    title = "Untitled";
    resolution->x() = res.x();
    resolution->y() = res.y();
    shown = s;
    borderless = false;
    additionalFlags = flags; 
    init();
}

Window::Window(const std::string& t, Vec2D<int>& pos, Vec2D<int>& res, bool s, bool b, Uint32 flags) {
    title = t;
    position->x() = pos.x();
    position->y() = pos.y();
    resolution->x() = res.x();
    resolution->y() = res.y();
    shown = s;
    borderless = b;
    additionalFlags = flags; 
    init();
}

