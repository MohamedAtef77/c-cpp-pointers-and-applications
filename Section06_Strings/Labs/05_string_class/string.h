#ifndef STRING_H
#define STRING_H

#include <cstddef>
#include <cstring>
#include <iostream>
#include <utility>

/*
 * @brief Owning, null-terminated dynamic string class.
 */
class String {
public:
    using size_type = size_t;

    /*
     * @brief Constructs an empty string.
     */
    String() : m_pData(new char[1]{'\0'}) {}

    /*
     * @brief Constructs a string that copies the contents of a C-style string.
     * @param str A null-terminated C-style string, or nullptr for an empty string.
     */
    String(const char* str) : m_pData(nullptr) {
        if (str == nullptr) {
            m_pData = new char[1]{'\0'};
        } else {
            size_type length = std::strlen(str);
            m_pData = new char[length + 1];
            std::strcpy(m_pData, str);
        }
    }

    /*
     * @brief Destroys the string and frees its buffer.
     */
    ~String() {
        delete[] m_pData;
    }

    /*
     * @brief Copy constructor.
     */
    String(const String& other) : String(other.m_pData) {}

    /*
     * @brief Copy assignment operator.
     */
    String& operator=(const String& other) {
        if (this != &other) {
            String temp(other);
            swap(temp);
        }
        return *this;
    }

    /*
     * @brief Move constructor.
     */
    String(String&& other) noexcept : m_pData(other.m_pData) {
        other.m_pData = nullptr;
    }

    /*
     * @brief Move assignment operator.
     */
    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] m_pData;
            m_pData = other.m_pData;
            other.m_pData = nullptr;
        }
        return *this;
    }

    /*
     * @brief Returns true when the string is empty.
     */
    bool Empty() const {
        return m_pData[0] == '\0';
    }

    /*
     * @brief Clears the string, leaving it empty.
     */
    void Clear() {
        delete[] m_pData;
        m_pData = new char[1]{'\0'};
    }

    /*
     * @brief Appends a C-style string to the end of this string.
     * @param str A null-terminated C-style string to append; nullptr is a no-op.
     */
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

    /*
     * @brief Returns the number of characters in the string, excluding the null terminator.
     */
    size_type GetSize() const {
        return std::strlen(m_pData);
    }

    /*
     * @brief Returns a read-only C-style view of the string.
     */
    const char* c_str() const {
        return m_pData;
    }

    /*
     * @brief Prints the string to standard output followed by a newline.
     */
    void Print() const {
        std::cout << m_pData << std::endl;
    }

private:
    char* m_pData;

    /*
     * @brief Swaps contents with another string.
     */
    void swap(String& other) noexcept {
        using std::swap;
        swap(m_pData, other.m_pData);
    }
};

#endif
