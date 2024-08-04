#pragma once
#include <iostream>
#include <stdexcept>

class FontLoadingFailure : public std::exception
{
    public:
    const char* what() const noexcept override;
};

class AudioLoadingFailure : public std::exception
{
    public:
    const char* what() const noexcept override;
};