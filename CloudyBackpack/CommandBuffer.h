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

    void get(std::string& t);

    void get(std::vector<uint8_t> &t);

    void get(CommandBuffer& t);

    void setData(const std::vector<uint8_t>& data);

    virtual void parse(const std::vector<uint8_t>& data);

    std::string hexView(const std::vector<uint8_t>& data, size_t offset, size_t size);

protected:
    std::vector<uint8_t> _buffer;
    uint8_t *_ptr = nullptr;
};
