#include <cstddef>
#include <initializer_list>
#include <ostream>
#include <stdexcept>
#include <utility>

template<typename T>
class SingleList {
public:
    using size_type = size_t;
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;

    /* --- Constructors, destructor, and special members --- */
    
    SingleList() : m_pHead(nullptr), m_Size(0) {}

    SingleList(size_type count, const_reference value) : m_pHead(nullptr), m_Size(0) {
        if (count == 0) {
            return;
        }

        Node* tail = nullptr;
        for (size_type i = 0; i < count; ++i)
        {
            Node* newNode = new Node(value, nullptr);
            if (m_pHead == nullptr)
            {
                m_pHead = newNode;
                tail = newNode;
            }
            else
            {
                tail->m_pNext = newNode;
                tail = newNode;
            }
            ++m_Size;
        }
    }

    SingleList(std::initializer_list<value_type> values) : m_pHead(nullptr), m_Size(0)
    {
        Node* tail = nullptr;
        for (const auto &value : values)
        {
            Node* newNode = new Node(value, nullptr);
            if (m_pHead == nullptr)
            {
                m_pHead = newNode;
                tail = newNode;
            }
            else
            {
                tail->m_pNext = newNode;
                tail = newNode;
            }
            ++m_Size;
        }
    }

    ~SingleList() {
        clear();
    }

    SingleList(const SingleList &other) : m_pHead(nullptr), m_Size(0) {
        Node* tail = nullptr;
        Node* current = other.m_pHead;

        while (current != nullptr) {
            Node* newNode = new Node(current->m_data, nullptr);
            if (m_pHead == nullptr) {
                m_pHead = newNode;
                tail = newNode;
            } else {
                tail->m_pNext = newNode;
                tail = newNode;
            }
            ++m_Size;
            current = current->m_pNext;
        }
    }

    SingleList &operator=(const SingleList &other) {
        if (this != &other) {
            SingleList temp(other);
            swap(temp);
        }
        return *this;
    }

    SingleList(SingleList &&other) noexcept : m_pHead(other.m_pHead), m_Size(other.m_Size) {
        other.m_pHead = nullptr;
        other.m_Size = 0;
    }

    SingleList &operator=(SingleList &&other) noexcept {
        if (this != &other) {
            clear();
            m_pHead = other.m_pHead;
            m_Size = other.m_Size;
            other.m_pHead = nullptr;
            other.m_Size = 0;
        }
        return *this;
    }

    /* --- Public list operations --- */

    const_reference Front() const {
        if (Empty()) {
            throw std::out_of_range("SingleList is empty");
        }
        return m_pHead->m_data;
    }

    bool Empty() const {
        return m_pHead == nullptr;
    }

    void Clear() {
        clear();
    }

    void Add(const_reference elem) {
        Node* newNode = new Node(elem, m_pHead);
        m_pHead = newNode;
        ++m_Size;
    }

    void Insert(size_type index, const_reference elem) {
        if (index > m_Size) {
            throw std::out_of_range("Insert index out of range");
        }

        if (index == 0) {
            Add(elem);
            return;
        }

        Node* newNode = new Node(elem, nullptr);
        Node* current = m_pHead;
        for (size_type i = 1; i < index; ++i) {
            current = current->m_pNext;
        }

        newNode->m_pNext = current->m_pNext;
        current->m_pNext = newNode;
        ++m_Size;
    }

    void Erase(size_type index) {
        if (Empty() || index >= m_Size) {
            throw std::out_of_range("Erase index out of range");
        }

        Node* current = m_pHead;
        if (index == 0) {
            m_pHead = current->m_pNext;
            delete current;
            --m_Size;
            return;
        }

        for (size_type i = 1; i < index; ++i) {
            current = current->m_pNext;
        }

        Node* toDelete = current->m_pNext;
        current->m_pNext = toDelete->m_pNext;
        delete toDelete;
        --m_Size;
    }

    reference At(size_type index) {
        if (index >= m_Size) {
            throw std::out_of_range("Index out of range");
        }

        Node* current = m_pHead;
        for (size_type i = 0; i < index; ++i) {
            current = current->m_pNext;
        }
        return current->m_data;
    }

    const_reference At(size_type index) const {
        if (index >= m_Size) {
            throw std::out_of_range("Index out of range");
        }

        Node* current = m_pHead;
        for (size_type i = 0; i < index; ++i) {
            current = current->m_pNext;
        }
        return current->m_data;
    }

    void Print(std::ostream& os) const {
        Node* current = m_pHead;
        while (current != nullptr) {
            os << current->m_data;
            if (current->m_pNext != nullptr) {
                os << " -> ";
            }
            current = current->m_pNext;
        }
    }

    size_type GetSize() const {
        return m_Size;
    }

private:
    /* Feasible in C++ 17*/
    struct Node {
        value_type m_data;
        Node* m_pNext;
        Node(const value_type& data, Node* next = nullptr) : m_data(data), m_pNext(next) {}
    };

    Node* m_pHead{nullptr};
    size_type m_Size{0};

    /* --- Private helper functions --- */
    void clear() noexcept {
        Node* current = m_pHead;
        while (current) {
            Node* next = current->m_pNext;
            delete current;
            current = next;
        }
        m_pHead = nullptr;
        m_Size = 0;
    }
    void swap(SingleList &other) noexcept {
        using std::swap;
        swap(m_pHead, other.m_pHead);
        swap(m_Size, other.m_Size);
    }
};