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
 * @brief Singly linked list container (class-shape stage).
 * @tparam T Element type.
 *
 * @details
 * At this stage the class only declares its full public interface; the
 * operations below are stubbed out and will be implemented in later labs.
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
     * @brief Destroys the list. (stub)
     */
    ~SingleList() {}

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
     * @brief Adds an element to the front of the list. (stub)
     */
    void Add(const_reference elem) {}

    /*
     * @brief Inserts an element into the list. (stub)
     */
    void Insert() {}

    /*
     * @brief Removes an element from the list. (stub)
     */
    void Erase() {}

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
     * @brief Releases all owned nodes. (stub)
     */
    void clear() noexcept {}

    /*
     * @brief Swaps contents with another list. (stub)
     */
    void swap(SingleList &other) noexcept {}
};
