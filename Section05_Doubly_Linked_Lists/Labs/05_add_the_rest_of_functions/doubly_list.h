#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <utility>

/*
 * @brief Forward declaration or assumption of Node structure.
 */
template <typename T>
struct Node {
    T m_data;
    Node* m_pPrev;
    Node* m_pNext;

    explicit Node(const T& data, Node* prev = nullptr, Node* next = nullptr)
        : m_data(data), m_pPrev(prev), m_pNext(next) {}
};

/*
 * @brief Doubly linked list container.
 * @tparam T Element type.
 */
template<typename T>
class DoubleList {
public:
    using size_type = size_t;
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;

    /*
     * @brief Constructs an empty list.
     */
    DoubleList() : m_pHead(nullptr), m_pTail(nullptr), m_Size(0) {}

    /*
     * @brief Constructs a list with `count` copies of `value`.
     */
    DoubleList(size_type count, const_reference value) : DoubleList() {
        for (size_type i = 0; i < count; ++i) {
            push_back(value);
        }
    }

    /*
     * @brief Constructs a list from an initializer list.
     */
    DoubleList(std::initializer_list<value_type> values) : DoubleList() {
        for (const auto& value : values) {
            push_back(value);
        }
    }

    /*
     * @brief Destroys the list and releases its nodes.
     */
    ~DoubleList() {
        release();
    }

    /*
     * @brief Copy constructor. Deep-copies every node from `other`.
     */
    DoubleList(const DoubleList& other) : DoubleList() {
        for (Node<value_type>* current = other.m_pHead; current != nullptr; current = current->m_pNext) {
            push_back(current->m_data);
        }
    }

    /*
     * @brief Copy assignment operator, implemented via copy-and-swap.
     */
    DoubleList& operator=(const DoubleList& other) {
        if (this != &other) {
            DoubleList temp(other);
            swap(temp);
        }
        return *this;
    }

    /*
     * @brief Move constructor. Steals `other`'s nodes and leaves it empty.
     */
    DoubleList(DoubleList&& other) noexcept
        : m_pHead(other.m_pHead), m_pTail(other.m_pTail), m_Size(other.m_Size) {
        other.m_pHead = nullptr;
        other.m_pTail = nullptr;
        other.m_Size = 0;
    }

    /*
     * @brief Move assignment operator. Releases owned nodes, then steals `other`'s.
     */
    DoubleList& operator=(DoubleList&& other) noexcept {
        if (this != &other) {
            release();
            m_pHead = other.m_pHead;
            m_pTail = other.m_pTail;
            m_Size = other.m_Size;
            other.m_pHead = nullptr;
            other.m_pTail = nullptr;
            other.m_Size = 0;
        }
        return *this;
    }

    /*
     * @brief Returns the first element.
     * @throws std::out_of_range if the list is empty.
     */
    const_reference front() const {
        if (empty()) {
            throw std::out_of_range("DoubleList is empty");
        }
        return m_pHead->m_data;
    }

    /*
     * @brief Returns the last element.
     * @throws std::out_of_range if the list is empty.
     */
    const_reference back() const {
        if (empty()) {
            throw std::out_of_range("DoubleList is empty");
        }
        return m_pTail->m_data;
    }

    /*
     * @brief Returns true when the list is empty.
     */
    bool empty() const noexcept {
        return m_Size == 0;
    }

    /*
     * @brief Clears the list, releasing all nodes.
     */
    void clear() {
        release();
    }

    /*
     * @brief Adds an element to the back of the list.
     */
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

    /*
     * @brief Adds an element to the front of the list.
     */
    void push_front(const_reference value) {
        Node<value_type>* newNode = new Node<value_type>(value, nullptr, m_pHead);
        if (m_pHead == nullptr) {
            m_pHead = newNode;
            m_pTail = newNode;
        } else {
            m_pHead->m_pPrev = newNode;
            m_pHead = newNode;
        }
        ++m_Size;
    }

    /*
     * @brief Inserts an element at the specified index.
     * @throws std::out_of_range if index is invalid.
     */
    void insert(size_type index, const_reference value) {
        if (index > m_Size) {
            throw std::out_of_range("Insert index out of range");
        }

        if (index == 0) {
            push_front(value);
            return;
        }

        if (index == m_Size) {
            push_back(value);
            return;
        }

        Node<value_type>* current = m_pHead;
        for (size_type i = 0; i < index; ++i) {
            current = current->m_pNext;
        }

        Node<value_type>* prevNode = current->m_pPrev;
        Node<value_type>* newNode = new Node<value_type>(value, prevNode, current);
        prevNode->m_pNext = newNode;
        current->m_pPrev = newNode;
        ++m_Size;
    }

    /*
     * @brief Removes the element at the specified index.
     * @throws std::out_of_range if index is invalid.
     */
    void erase(size_type index) {
        if (empty() || index >= m_Size) {
            throw std::out_of_range("Erase index out of range");
        }

        Node<value_type>* current = m_pHead;
        for (size_type i = 0; i < index; ++i) {
            current = current->m_pNext;
        }

        if (current->m_pPrev != nullptr) {
            current->m_pPrev->m_pNext = current->m_pNext;
        } else {
            m_pHead = current->m_pNext;
        }

        if (current->m_pNext != nullptr) {
            current->m_pNext->m_pPrev = current->m_pPrev;
        } else {
            m_pTail = current->m_pPrev;
        }

        delete current;
        --m_Size;
    }

    /*
     * @brief Returns a pointer to the head node, or nullptr if the list is empty.
     */
    Node<value_type>* get_head() const noexcept {
        return m_pHead;
    }

    /*
     * @brief Returns a pointer to the tail node, or nullptr if the list is empty.
     */
    Node<value_type>* get_tail() const noexcept {
        return m_pTail;
    }

    /*
     * @brief Returns the number of elements stored.
     */
    size_type get_size() const noexcept {
        return m_Size;
    }

private:
    Node<value_type>* m_pHead{nullptr};
    Node<value_type>* m_pTail{nullptr};
    size_type m_Size{0};

    /*
     * @brief Releases all owned nodes.
     */
    void release() noexcept {
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

    /*
     * @brief Swaps contents with another list.
     */
    void swap(DoubleList& other) noexcept {
        using std::swap;
        swap(m_pHead, other.m_pHead);
        swap(m_pTail, other.m_pTail);
        swap(m_Size, other.m_Size);
    }
};
