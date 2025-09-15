#include <cstring>
#include <iostream>

class String {
private:
    char* data_;   // owned heap memory
    std::size_t n_;

public:
    // 1) Destructor
    ~String() {
        delete[] data_;
    }

    // Default ctor
    String() : data_(nullptr), n_(0) {}

    // Convenience ctor from C-string
    explicit String(const char* s) {
        n_ = s ? std::strlen(s) : 0;
        data_ = n_ ? new char[n_ + 1] : nullptr;
        if (data_) {
            std::memcpy(data_, s, n_ + 1);
        }
    }

    // 2) Copy constructor (deep copy)
    String(const String& other) : n_(other.n_) {
        data_ = n_ ? new char[n_ + 1] : nullptr;
        if (data_) {
            std::memcpy(data_, other.data_, n_ + 1);
        }
    }

    // 3) Copy-assignment operator (deep copy, handles self-assign)
    String& operator=(const String& other) {
        if (this == &other) return *this;          // self-assign guard
        char* newData = other.n_ ? new char[other.n_ + 1] : nullptr;
        if (newData) {
            std::memcpy(newData, other.data_, other.n_ + 1);
        }
        delete[] data_;                             // free old
        data_ = newData;                            // take new
        n_ = other.n_;
        return *this;
    }

    // Helper for printing
    const char* c_str() const { return data_ ? data_ : ""; }
    std::size_t size() const { return n_; }
};

int main() {
    String a("hello");
    String b = a;              // copy ctor
    String c;                  
    c = a;                     // copy assignment

    std::cout << a.c_str() << " (" << a.size() << ")\n";
    std::cout << b.c_str() << " (" << b.size() << ")\n";
    std::cout << c.c_str() << " (" << c.size() << ")\n";
}
