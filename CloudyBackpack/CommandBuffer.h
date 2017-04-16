#pragma once

#include <cstdint>
#include <vector>
#include <stdexcept>

class CommandBuffer {
public:
    CommandBuffer(const std::vector<uint8_t> &buffer = {});

    virtual ~CommandBuffer();

    void put(void *data, size_t size);

    template<typename T>
    void put(const T &t) {
        put(const_cast<T *>(&t), sizeof(t));
    }

    void put(const std::string &t);

    void put(const std::vector<uint8_t> &t);

    void put(const CommandBuffer &t);

    virtual void setSize(size_t size = 0);

    virtual size_t size() const;

    virtual std::vector<uint8_t> getBuffer() { return {}; }

    void get(void *data, size_t size);

    template<typename T>
    void get(T &t) {
        get(&t, sizeof(t));
    }

protected:
    std::vector<uint8_t> _buffer;
    uint8_t *_ptr = nullptr;
};
