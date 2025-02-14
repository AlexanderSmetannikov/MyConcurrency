#include <cstdint>

class Atomic {
private:
    volatile int64_t value;

public:
    explicit Atomic(int64_t init_value = 0) : value(init_value) {}

    void increment() {
        __asm__ __volatile__(
            "lock incq %0"
            : "+m" (value)
            :
            : "memory"
        );
    }

    int64_t load() const {
        int64_t result;
        __asm__ __volatile__(
            "movq %1, %0\n"
            "mfence\n"
            : "=r" (result)
            : "m" (value)
            : "memory"
        );
        return result;
    }

    void store(int64_t new_value) {
        __asm__ __volatile__(
            "movq %1, %0\n"
            "mfence\n"
            : "=m" (value)
            : "r" (new_value)
            : "memory"
        );
    }

    volatile int64_t* get_ptr() {
        return &value;
    }
};
