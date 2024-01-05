template <typename T> class unique_ptr
{
private:
    T* obj;
public:
    unique_ptr();
    ~unique_ptr();
    unique_ptr<T>& operator=(unique_ptr&& newPtr);
    void operator=(unique_ptr& right);
    operator bool() const;
    T& operator*();
    friend unique_ptr<T>&& move(unique_ptr<T>& right);
};

template<typename T>
unique_ptr<T>&& move(unique_ptr<T>& right)
{
    return unique_ptr<T> && right;
}


template <typename T>
unique_ptr<T>::unique_ptr()
{
    obj = new T;
}


template <typename T>
unique_ptr<T>::~unique_ptr()
{
    delete obj;
}

template <typename T>
unique_ptr<T>& unique_ptr<T>::operator=(unique_ptr&& newPtr)
{
    this->obj = newPtr.obj;
    newPtr.obj = nullptr;
    return *this;
}

template <typename T>
void unique_ptr<T>::operator=(unique_ptr& right)
{
    this->obj = right.obj;
    right.obj = nullptr;
}

template <typename T>
unique_ptr<T>::operator bool() const
{
    if (obj == nullptr)
        return false;
    return true;
}

template <typename T>
T& unique_ptr<T>::operator*()
{
    return *obj;
}