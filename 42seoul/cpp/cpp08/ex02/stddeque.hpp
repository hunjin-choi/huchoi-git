template <class T, class Allocator = allocator<T> >
class deque {
public:
    // types:
    typedef value_type&                                         reference;
    typedef const value_type&                                   const_reference;
    typedef /*implementation-defined*/                          iterator;
    typedef /*implementation-defined*/                          const_iterator;
    typedef /*implementation-defined*/                          size_type;
    typedef /*implementation-defined*/                          difference_type;
    typedef T                                                   value_type;
    typedef Allocator                                           allocator_type;
    typedef typename allocator_traits<Allocator>::pointer       pointer;
    typedef typename allocator_traits<Allocator>::const_pointer const_pointer;
    typedef std::reverse_iterator<iterator>                     reverse_iterator;
    typedef std::reverse_iterator<const_iterator>               const_reverse_iterator;

    // construct/copy/destroy:
    explicit deque(const Allocator& = Allocator());
    explicit deque(size_type n);
    deque(size_type n, const T& value,const Allocator& = Allocator());
    template <class InputIterator>
        deque(InputIterator first, InputIterator last,const Allocator& = Allocator());
    deque(const deque<T,Allocator>& x);
    deque(deque&&);
    deque(const deque&, const Allocator&);
    deque(deque&&, const Allocator&);
    deque(initializer_list<T>, const Allocator& = Allocator());

    ~deque();
    deque<T,Allocator>& operator=(const deque<T,Allocator>& x);
    deque<T,Allocator>& operator=(deque<T,Allocator>&& x);
    deque& operator=(initializer_list<T>);
    template <class InputIterator>
    void assign(InputIterator first, InputIterator last);
    void assign(size_type n, const T& t);
    void assign(initializer_list<T>);
    allocator_type get_allocator() const noexcept;

    // iterators:
    iterator                begin() noexcept;
    const_iterator          begin() const noexcept;
    iterator                end() noexcept;
    const_iterator          end() const noexcept;

    reverse_iterator        rbegin() noexcept;
    const_reverse_iterator  rbegin() const noexcept;
    reverse_iterator        rend() noexcept;
    const_reverse_iterator  rend() const noexcept;

    const_iterator          cbegin() noexcept;
    const_iterator          cend() noexcept;
    const_reverse_iterator  crbegin() const noexcept;
    const_reverse_iterator  crend() const noexcept;

    // capacity:
    size_type size() const noexcept;
    size_type max_size() const noexcept;
    void      resize(size_type sz);
    void      resize(size_type sz, const T& c);
    void      shrink_to_fit();
    bool      empty() const noexcept;

    // element access:
    reference       operator[](size_type n);
    const_reference operator[](size_type n) const;
    reference       at(size_type n);
    const_reference at(size_type n) const;
    reference       front();
    const_reference front() const;
    reference       back();
    const_reference back() const;

    // modifiers:
    template <class... Args> void emplace_front(Args&&... args);
    template <class... Args> void emplace_back(Args&&... args);
    template <class... Args> iterator emplace(const_iterator position, Args&&... args);

    void push_front(const T& x);
    void push_front(T&& x);
    void push_back(const T& x);
    void push_back(T&& x);

    iterator insert(const_iterator position, const T& x);
    iterator insert(const_iterator position, T&& x);
    iterator insert(const_iterator position, size_type n, const T& x);
    template <class InputIterator>
        iterator insert (const_iterator position, InputIterator first,
                         InputIterator last);
    iterator insert(const_iterator position, initializer_list<T>);

    void pop_front();
    void pop_back();

    iterator erase(const_iterator position);
    iterator erase(const_iterator first, const_iterator last);
    void     swap(deque<T,Allocator>&);
    void     clear() noexcept;
};
