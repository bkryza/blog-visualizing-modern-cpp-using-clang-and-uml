import simple_app;

#include <memory>

namespace simple_app {
class App {
public:
    std::unique_ptr<frontend::Frontend> frontend;
    std::unique_ptr<backend::Backend> backend;

    int run() { return 0; }
};
} // namespace simple_app