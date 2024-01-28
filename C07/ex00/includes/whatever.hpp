#pragma once

template <typename Arg>
void swap(Arg& a, Arg& b)
{
    Arg temp;

    temp = a;
    a = b;
    b = temp;
}

template <typename Arg>
Arg min(Arg a, Arg b)
{
    if (b <= a)
        return b;
    else
        return a;
}

template <typename Arg>
Arg max(Arg a, Arg b)
{
    if (b >= a)
        return b;
    else
        return a;
}
