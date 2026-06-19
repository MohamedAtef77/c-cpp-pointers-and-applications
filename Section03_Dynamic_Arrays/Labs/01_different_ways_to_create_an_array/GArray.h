#include <cstddef>
#include <initializer_list>
#include <stdexcept>

namespace Basic
{
    /*
     * @brief Copy elements from one iterator range into a destination iterator.
     * @tparam SourceT Input iterator type.
     * @tparam DestT Output iterator type.
     * @param begin Start of the source range.
     * @param end End of the source range.
     * @param dest Destination iterator.
     * @returns Destination iterator advanced past the last copied element.
     */
    template<typename SourceT, typename DestT>
    DestT Copy(SourceT begin, SourceT end, DestT dest)
    {
        for (; begin != end; ++begin, ++dest)
        {
            *dest = *begin;
        }
        return dest;
    }

    /*
     * @brief Dynamically allocated generic array container.
     * @tparam T Element type.
     */
    template<typename T>
    class GArray
    {
    private:
        T *m_pBuffer = nullptr; /* Owned element buffer. */
        int m_size = 0;         /* Number of elements currently stored. */

    public:
        using size_type = std::size_t;
        using value_type = T;
        using pointer = T*;
        using const_pointer = const T*;
        using reference = T&;
        using const_reference = const T&;

        /*
         * @brief Constructs an empty array.
         */
        GArray() = default;

        /*
         * @brief Constructs an array with count` copies of `elem`.
         */
        GArray(size_type count, const_reference elem)
            : m_pBuffer(nullptr), m_size(0)
        {
            if (count == 0)
            {
                return;
            }

            m_pBuffer = new T[count];
            for (size_type i = 0; i < count; ++i)
            {
                m_pBuffer[i] = elem;
            }
            m_size = static_cast<int>(count);
        }

        /*
         * @brief Constructs an array from an initializer list.
         */
        GArray(const std::initializer_list<value_type> &ilist)
            : m_pBuffer(nullptr), m_size(0)
        {
            size_type count = ilist.size();
            if (count == 0)
            {
                return;
            }

            m_pBuffer = new T[count];
            Copy(ilist.begin(), ilist.end(), m_pBuffer);
            m_size = static_cast<int>(count);
        }

        /*
         * @brief Adds a new element to the end of the array.
         */
        void Add(const_reference elem)
        {
            Insert(static_cast<size_type>(m_size), elem);
        }

        /*
         * @brief Inserts an element at the specified index.
         */
        void Insert(size_type index, const_reference elem)
        {
            if (index > static_cast<size_type>(m_size))
            {
                return;
            }

            size_type newSize = static_cast<size_type>(m_size) + 1;
            T *newBuffer = new T[newSize];

            Copy(m_pBuffer, m_pBuffer + index, newBuffer);
            newBuffer[index] = elem;
            Copy(m_pBuffer + index, m_pBuffer + m_size, newBuffer + index + 1);

            delete[] m_pBuffer;
            m_pBuffer = newBuffer;
            m_size = static_cast<int>(newSize);
        }

        /*
         * @brief Removes the element at the specified index.
         * @throws std::out_of_range if index is invalid.
         */
        void Erase(size_type index)
        {
            try
            {
                if (index >= static_cast<size_type>(m_size))
                {
                    throw std::out_of_range("GArray::Erase: index out of range");
                }

                if (m_size == 1)
                {
                    delete[] m_pBuffer;
                    m_pBuffer = nullptr;
                    m_size = 0;
                    return;
                }

                size_type newSize = static_cast<size_type>(m_size) - 1;
                T *newBuffer = new T[newSize];

                Copy(m_pBuffer, m_pBuffer + index, newBuffer);
                Copy(m_pBuffer + index + 1, m_pBuffer + m_size, newBuffer + index);

                delete[] m_pBuffer;
                m_pBuffer = newBuffer;
                m_size = static_cast<int>(newSize);
            }
            catch (const std::bad_alloc &)
            {
                throw std::runtime_error("GArray::Erase: allocation failed");
            }
        }

        /*
         * @brief Returns the last element.
         * @throws std::logic_error if the array is empty.
         */
        const_reference Back() const
        {
            try
            {
                if (m_size == 0)
                {
                    throw std::logic_error("GArray::Back: array is empty");
                }
                return m_pBuffer[static_cast<size_type>(m_size) - 1];
            }
            catch (const std::logic_error &)
            {
                throw;
            }
        }

        /*
         * @brief Returns the first element.
         * @throws std::logic_error if the array is empty.
         */
        const_reference Front() const
        {
            try
            {
                if (m_size == 0)
                {
                    throw std::logic_error("GArray::Front: array is empty");
                }
                return m_pBuffer[0];
            }
            catch (const std::logic_error &)
            {
                throw;
            }
        }

        /*
         * @brief Read-only element access.
         */
        const_reference operator[](size_type index) const
        {
            return m_pBuffer[index];
        }

        /*
         * @brief Mutable element access.
         */
        reference operator[](size_type index)
        {
            return m_pBuffer[index];
        }

        /*
         * @brief Returns true when the array is empty.
         */
        bool Empty() const
        {
            return m_size == 0;
        }

        /*
         * @brief Returns the number of elements stored.
         */
        size_type GetSize() const
        {
            return static_cast<size_type>(m_size);
        }

        /*
         * @brief Clears the array and releases owned storage.
         */
        void Clear()
        {
            delete[] m_pBuffer;
            m_pBuffer = nullptr;
            m_size = 0;
        }

        /*
         * @brief Finds the first occurrence of `elem`.
         * @returns The index of the element, or `size_type(-1)` if not found.
         */
        size_type Find(const_reference elem)
        {
            for (size_type i = 0; i < static_cast<size_type>(m_size); ++i)
            {
                if (m_pBuffer[i] == elem)
                {
                    return i;
                }
            }
            return static_cast<size_type>(-1);
        }

        /*
         * @brief Returns the raw buffer pointer.
         */
        pointer GetRawPointer()
        {
            return m_pBuffer;
        }

        /*
         * @brief Returns the raw buffer pointer (const overload).
         */
        const_pointer GetRawPointer() const
        {
            return m_pBuffer;
        }

        /*
         * @brief Destroys the array and frees storage.
         */
        ~GArray()
        {
            delete[] m_pBuffer;
        }

        /*
         * @brief Copy constructor.
         */
        GArray(const GArray &other)
        {
        }

        /*
         * @brief Move constructor.
         */
        GArray(GArray &&other) noexcept
        {
        }

        /*
         * @brief Copy assignment operator.
         */
        GArray& operator=(const GArray &other)
        {
        }

        /*
         * @brief Move assignment operator.
         */
        GArray& operator=(GArray &&other) noexcept
        {
        }
    };

} /* namespace Basic */
