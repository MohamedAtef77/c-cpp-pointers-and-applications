#include <cstddef>
#include <initializer_list>
#include <utility>

template <typename T>
struct Node {
    T m_data;
    Node* m_pPrev;
    Node* m_pNext;

    explicit Node(const T& data, Node* prev = nullptr, Node* next = nullptr)
        : m_data(data), m_pPrev(prev), m_pNext(next) {}
};

template<typename T>
class DoubleList {
public:
    using size_type = size_t;
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;

    DoubleList() : m_pHead(nullptr), m_pTail(nullptr), m_Size(0) {}

    DoubleList(size_type count, const_reference value) : DoubleList() {
        for (size_type i = 0; i < count; ++i) {
            push_back(value);
        }
    }

    DoubleList(std::initializer_list<value_type> values) : DoubleList() {
        for (const auto& value : values) {
            push_back(value);
        }
    }

    ~DoubleList() {
        clear();
    }

    DoubleList(const DoubleList& other) : DoubleList() {
        for (Node<value_type>* current = other.m_pHead; current != nullptr; current = current->m_pNext) {
            push_back(current->m_data);
        }
    }

    DoubleList& operator=(const DoubleList& other) {
        if (this != &other) {
            DoubleList temp(other);
            swap(temp);
        }
        return *this;
    }

    DoubleList(DoubleList&& other) noexcept
        : m_pHead(other.m_pHead), m_pTail(other.m_pTail), m_Size(other.m_Size) {
        other.m_pHead = nullptr;
        other.m_pTail = nullptr;
        other.m_Size = 0;
    }

    DoubleList& operator=(DoubleList&& other) noexcept {
        if (this != &other) {
            clear();
            m_pHead = other.m_pHead;
            m_pTail = other.m_pTail;
            m_Size = other.m_Size;
            other.m_pHead = nullptr;
            other.m_pTail = nullptr;
            other.m_Size = 0;
        }
        return *this;
    }

    bool empty() const noexcept {
        return m_Size == 0;
    }

    void push_back(const_reference value) {
        Node<value_type>* newNode = new Node<value_type>(value, m_pTail, nullptr);
        if (m_pTail == nullptr) {
            m_pHead = newNode;
            m_pTail = newNode;
        } else {
            m_pTail->m_pNext = newNode;
            m_pTail = newNode;
        }
        ++m_Size;
    }

    Node<value_type>* get_head() const noexcept {
        return m_pHead;
    }

    Node<value_type>* get_tail() const noexcept {
        return m_pTail;
    }

    size_type get_size() const noexcept {
        return m_Size;
    }

private:
    Node<value_type>* m_pHead{nullptr};
    Node<value_type>* m_pTail{nullptr};
    size_type m_Size{0};

    void clear() noexcept {
        Node<value_type>* current = m_pHead;
        while (current != nullptr) {
            Node<value_type>* next = current->m_pNext;
            delete current;
            current = next;
        }
        m_pHead = nullptr;
        m_pTail = nullptr;
        m_Size = 0;
    }

    void swap(DoubleList& other) noexcept {
        using std::swap;
        swap(m_pHead, other.m_pHead);
        swap(m_pTail, other.m_pTail);
        swap(m_Size, other.m_Size);
    }
};