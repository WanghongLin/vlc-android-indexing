// Write C++ code here.
//
// Do not forget to dynamically load the C++ library into your application.
//
// For instance,
//
// In MainActivity.java:
//    static {
//       System.loadLibrary("vlc_source_code");
//    }
//
// Or, in MainActivity.kt:
//    companion object {
//      init {
//         System.loadLibrary("vlc_source_code")
//      }
//    }

#include <iostream>

#include <cstddef>
#include <cstring>
class rule3 {
    char* cstr;
    rule3(const char* s, std::size_t n) : cstr(new char[n]) {
        std::memcpy(cstr, s, n);
    }
public:
    rule3(const char* s = "") : rule3(s, std::strlen(s) + 1) {}
    ~rule3() { delete[] cstr; }
    rule3(const rule3& other) : rule3(other.cstr) {}
    rule3& operator=(const rule3& other) {
        if (this == &other) return *this;
        std::size_t n{std::strlen(other.cstr)+1};
        auto dest = new char[n];
        std::memcpy(dest, other.cstr, n);
        delete[] cstr;
        cstr = dest;
        return *this;
    }

    operator char*() const { return cstr; }
};
void foobar()
{
    rule3 o1{"abc"};
    std::cout << o1 << ' ';
    rule3 o2{o1};
    std::cout << o2 << ' ';
    rule3 o3("def");
    std::cout << o3 << ' ';
    o3 = o2;
    std::cout << o3 << '\n'
}