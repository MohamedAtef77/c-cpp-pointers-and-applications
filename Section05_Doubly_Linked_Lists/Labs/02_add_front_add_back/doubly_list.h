#include <cstddef>
#include <initializer_list>
#include <utility>

/* Forward declaration or assumption of Node structure */
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

    /* --- Constructors, destructor, and special members --- */

    /*
     * @brief Constructs an empty list. (stub)
     */
    DoubleList() {}

    /*
     * @brief Constructs a list with `count` copies of `value`. (stub)
     */
    DoubleList(size_type count, const_reference value) {}

    /*
     * @brief Constructs a list from an initializer list. (stub)
     */
    DoubleList(std::initializer_list<value_type> values) {}

    /*
     * @brief Destroys the list and releases its nodes.
     */
    ~DoubleList() {
        release();
    }

    /*
     * @brief Copy constructor. (stub)
     */
    DoubleList(const DoubleList &other) {}

    /*
     * @brief Copy assignment operator. (stub)
     */
    DoubleList &operator=(const DoubleList &other) {
        return *this;
    }

    /*
     * @brief Move constructor. (stub)
     */
    DoubleList(DoubleList &&other) noexcept {}

    /*
     * @brief Move assignment operator. (stub)
     */
    DoubleList &operator=(DoubleList &&other) noexcept {
        return *this;
    }

    /* --- Public list operations --- */

    /*
     * @brief Returns the first element. (stub)
     */
    const_reference front() const {
        /* Return a dummy/stub reference or throw if required,
           using static to avoid undefined behavior in an empty stub. */
        static value_type dummy{};
        return dummy;
    }

    /*
     * @brief Returns true when the list is empty. (stub)
     */
    bool empty() const {
        return false;
    }

    /*
     * @brief Clears the list. (stub)
     */
    void clear() {}

    /*
     * @brief Adds an element to the back of the list.
     */
    void push_back(const_reference elem)
    {
        // Create a new node and make it the new tail.
        Node<value_type>* newNode = new Node<value_type>(elem, m_pTail, nullptr);
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
    void push_front(const_reference elem)
    {
        // Create a new node and make it the new head.
        Node<value_type>* newNode = new Node<value_type>(elem, nullptr, m_pHead);
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
     * @brief Inserts an element into the list. (stub)
     */
    void insert() {}

    /*
     * @brief Removes an element from the list. (stub)
     */
    void erase() {}

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
    size_type get_size() const {
        return m_Size;
    }

private:
    Node<value_type>* m_pHead{nullptr};
    Node<value_type>* m_pTail{nullptr};
    size_type m_Size{0};

    /* --- Private helper functions --- */

    /*
     * @brief Releases all owned nodes.
     */
    void release() noexcept {
        Node<value_type>* current = m_pHead;
        while (current) {
            Node<value_type>* next = current->m_pNext;
            delete current;
            current = next;
        }
        m_pHead = nullptr;
        m_pTail = nullptr;
        m_Size = 0;
    }

    /*
     * @brief Swaps contents with another list. (stub)
     */
    void swap(DoubleList &other) noexcept {}
};
