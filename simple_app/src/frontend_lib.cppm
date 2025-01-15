export module simple_app:frontend_lib;

export namespace simple_app::frontend {
namespace detail {
enum class Style { light, dark };
} // namespace detail

class Frontend {
public:
    detail::Style style;
};

} // namespace simple_app::frontend