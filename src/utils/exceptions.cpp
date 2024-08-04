#include "exceptions.h"

const char* FontLoadingFailure::what() const noexcept
{
    return "Failure while loading font";
}

const char* AudioLoadingFailure::what() const noexcept
{
    return "Failure while loading audio";
}