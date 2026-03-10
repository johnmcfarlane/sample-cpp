import std;

auto main() -> int
{
    auto shared_state{0};
    std::jthread const thread{[&] {
        using namespace std::chrono_literals;
        constexpr auto short_time{10ms};
        std::this_thread::sleep_for(short_time);

        shared_state = 1;
    }};
    return shared_state;
}
