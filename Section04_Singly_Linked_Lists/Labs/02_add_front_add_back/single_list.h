#include <cstddef>
#include <initializer_list>
#include <utility>

/* Forward declaration or assumption of Node structure */
template <typename T>
struct Node {
    T m_data;
    Node* m_pNext;
    Node(const T& data, Node* next = nullptr) : m_data(data), m_pNext(next) {}
};

/*
 * @brief Singly linked list container.
 * @tparam T Element type.
 */
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

    /*
     * @brief Constructs an empty list. (stub)
     */
    SingleList() {}

    /*
     * @brief Constructs a list with `count` copies of `value`. (stub)
     */
    SingleList(size_type count, const_reference value) {}

    /*
     * @brief Constructs a list from an initializer list. (stub)
     */
    SingleList(std::initializer_list<value_type> values) {}

    /*
     * @brief Destroys the list and releases its nodes.
     */
    ~SingleList() {
        clear();
    }

    /*
     * @brief Copy constructor. (stub)
     */
    SingleList(const SingleList &other) {}

    /*
     * @brief Copy assignment operator. (stub)
     */
    SingleList &operator=(const SingleList &other) {
        return *this;
    }

    /*
     * @brief Move constructor. (stub)
     */
    SingleList(SingleList &&other) noexcept {}

    /*
     * @brief Move assignment operator. (stub)
     */
    SingleList &operator=(SingleList &&other) noexcept {
        return *this;
    }

    /* --- Public list operations --- */

    /*
     * @brief Returns the first element. (stub)
     */
    const_reference Front() const {
        /* Return a dummy/stub reference or throw if required,
           using static to avoid undefined behavior in an empty stub. */
        static value_type dummy{};
        return dummy;
    }

    /*
     * @brief Returns true when the list is empty. (stub)
     */
    bool Empty() const {
        return false;
    }

    /*
     * @brief Clears the list. (stub)
     */
    void Clear() {}

    /*
     * @brief Adds an element to the front of the list.
     */
    void Add(const_reference elem)
    {
        // Create a new node and make it the new head.
        Node<value_type>* newNode = new Node<value_type>(elem);
        newNode->m_pNext = m_pHead;
        m_pHead = newNode;
        m_Size++;
    }

    /*
     * @brief Inserts an element into the list. (stub)
     */
    void Insert() {}

    /*
     * @brief Removes an element from the list. (stub)
     */
    void Erase() {}

    /*
     * @brief Returns a pointer to the head node, or nullptr if the list is empty.
     */
    Node<value_type>* get_head() const noexcept {
        return m_pHead;
    }

    /*
     * @brief Returns the number of elements stored. (stub)
     */
    size_type GetSize() const {
        return 0;
    }

private:
    Node<value_type>* m_pHead{nullptr};
    size_type m_Size{0};

    /* --- Private helper functions --- */

    /*
     * @brief Releases all owned nodes.
     */
    void clear() noexcept {
        Node<value_type>* current = m_pHead;
        while (current) {
            Node<value_type>* next = current->m_pNext;
            delete current;
            current = next;
        }
        m_pHead = nullptr;
        m_Size = 0;
    }

    /*
     * @brief Swaps contents with another list. (stub)
     */
    void swap(SingleList &other) noexcept {}
};
