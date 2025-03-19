#ifndef LOG_H
#define LOG_H

#include <filesystem>
#include <spdlog/fmt/ostr.h>
#include <spdlog/spdlog.h>

#include <glm/glm.hpp>

namespace Explore {

namespace Log {

    void Init();
    void Shutdown();
    spdlog::logger* GetEngineLogger();
    spdlog::logger* GetAppLogger();
}

#define EX_TRACE(...) Explore::Log::GetEngineLogger()->trace(__VA_ARGS__);
#define EX_INFO(...) Explore::Log::GetEngineLogger()->info(__VA_ARGS__);
#define EX_WARN(...) Explore::Log::GetEngineLogger()->warn(__VA_ARGS__);
#define EX_ERROR(...) Explore::Log::GetEngineLogger()->error(__VA_ARGS__);
#define EX_CRITICAL(...) Explore::Log::GetEngineLogger()->critical(__VA_ARGS__);

#define EX_APP_TRACE(...) Explore::Log::GetAppLogger()->trace(__VA_ARGS__);
#define EX_APP_INFO(...) Explore::Log::GetAppLogger()->info(__VA_ARGS__);
#define EX_APP_WARN(...) Explore::Log::GetAppLogger()->warn(__VA_ARGS__);
#define EX_APP_ERROR(...) Explore::Log::GetAppLogger()->error(__VA_ARGS__);
#define EX_APP_CRITICAL(...) Explore::Log::GetAppLogger()->critical(__VA_ARGS__);

}

template <>
struct fmt::formatter<glm::vec2> {
    char presentation = 'f';

    constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin())
    {
        auto it = ctx.begin(), end = ctx.end();
        if (it != end && (*it == 'f' || *it == 'e'))
            presentation = *it++;

        if (it != end && *it != '}')
            throw format_error("invalid format");

        return it;
    }

    template <typename FormatContext>
    auto format(const glm::vec2& vec, FormatContext& ctx) const -> decltype(ctx.out())
    {
        return presentation == 'f'
            ? format_to(ctx.out(), "({:.3f}, {:.3f})", vec.x, vec.y)
            : format_to(ctx.out(), "({:.3e}, {:.3e})", vec.x, vec.y);
    }
};

template <>
struct fmt::formatter<glm::vec3> {
    char presentation = 'f';

    constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin())
    {
        auto it = ctx.begin(), end = ctx.end();
        if (it != end && (*it == 'f' || *it == 'e'))
            presentation = *it++;

        if (it != end && *it != '}')
            throw format_error("invalid format");

        return it;
    }

    template <typename FormatContext>
    auto format(const glm::vec3& vec, FormatContext& ctx) const -> decltype(ctx.out())
    {
        return presentation == 'f'
            ? format_to(ctx.out(), "({:.3f}, {:.3f}, {:.3f})", vec.x, vec.y, vec.z)
            : format_to(ctx.out(), "({:.3e}, {:.3e}, {:.3e})", vec.x, vec.y, vec.z);
    }
};

template <>
struct fmt::formatter<glm::vec4> {
    char presentation = 'f';

    constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin())
    {
        auto it = ctx.begin(), end = ctx.end();
        if (it != end && (*it == 'f' || *it == 'e'))
            presentation = *it++;

        if (it != end && *it != '}')
            throw format_error("invalid format");

        return it;
    }

    template <typename FormatContext>
    auto format(const glm::vec4& vec, FormatContext& ctx) const -> decltype(ctx.out())
    {
        return presentation == 'f'
            ? format_to(ctx.out(), "({:.3f}, {:.3f}, {:.3f}, {:.3f})", vec.x, vec.y, vec.z, vec.w)
            : format_to(ctx.out(), "({:.3e}, {:.3e}, {:.3e}, {:.3e})", vec.x, vec.y, vec.z, vec.w);
    }
};

#endif // LOG_H
