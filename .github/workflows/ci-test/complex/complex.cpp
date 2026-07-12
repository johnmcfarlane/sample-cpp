auto main() -> int
{
    auto result{0};
    constexpr auto ten{10};
    for (auto index1 = 0; index1 != ten; index1++)
    {
        for (auto index2 = 0; index2 != ten; index2++)
        {
            for (auto index3 = 0; index3 != ten; index3++)
            {
                result++;
            }
        }
    }
    return result != 1000;
}
