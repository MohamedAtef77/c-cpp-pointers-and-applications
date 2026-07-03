#ifndef STRING_H
#define STRING_H

#include <cstddef>
#include <cstring>
#include <iostream>
#include <utility>

class String {
public:
    using size_type = size_t;

    String() : m_pData(new char[1]{'\0'}) {}

    String(const char* str) : m_pData(nullptr) {
        if (str == nullptr) {
            m_pData = new char[1]{'\0'};
        } else {
            size_type length = std::strlen(str);
            m_pData = new char[length + 1];
            std::strcpy(m_pData, str);
        }
    }

    ~String() {
        delete[] m_pData;
    }

    String(const String& other) : String(other.m_pData) {}

    String& operator=(const String& other) {
        if (this != &other) {
            String temp(other);
            swap(temp);
        }
        return *this;
    }

    String(String&& other) noexcept : m_pData(other.m_pData) {
        other.m_pData = nullptr;
    }

    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] m_pData;
            m_pData = other.m_pData;
            other.m_pData = nullptr;
        }
        return *this;
    }

    bool Empty() const {
        return m_pData[0] == '\0';
    }

    void Clear() {
        delete[] m_pData;
        m_pData = new char[1]{'\0'};
    }

    void Append(const char* str) {
        if (str == nullptr) {
            return;
        }

        size_type currentLength = std::strlen(m_pData);
        size_type appendLength = std::strlen(str);
        char* newBuffer = new char[currentLength + appendLength + 1];

        std::strcpy(newBuffer, m_pData);
        std::strcpy(newBuffer + currentLength, str);

        delete[] m_pData;
        m_pData = newBuffer;
    }

    size_type GetSize() const {
        return std::strlen(m_pData);
    }

    const char* c_str() const {
        return m_pData;
    }

    void Print() const {
        std::cout << m_pData << std::endl;
    }

private:
    char* m_pData;

    void swap(String& other) noexcept {
        using std::swap;
        swap(m_pData, other.m_pData);
    }
};

#endif