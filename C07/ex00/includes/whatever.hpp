#pragma once

/*
# define BLACK	"\033[0;30m"
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;34m"∏
# define WHITE	"\033[0;37m"
# define ENDC	"\033[0m"
*/

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
