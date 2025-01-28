import std;

using namespace std::literals;

void Test()
{
    // Todo
}

template <std::invocable<> Func>
void TestPerformance(Func&& func)
{
    auto const start_time{ std::chrono::high_resolution_clock::now() };

    std::invoke(std::forward<Func>(func));

    auto const end_time{ std::chrono::high_resolution_clock::now() };
    auto const elapsed_time{ std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time) };

    std::println("Elapsed time: {}", elapsed_time);
}

int main()
{
    std::wcout.imbue(std::locale{ "" }); // for Korean

    TestPerformance(&Test);
}
