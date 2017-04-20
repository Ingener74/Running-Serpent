#include <cstring>
#include <string>
#include <sstream>
#include "CommandBuffer.h"

using namespace std;

CommandBuffer::CommandBuffer(const vector<uint8_t> &buffer) : _buffer(buffer),
                                                              _ptr(_buffer.empty() ? nullptr : _buffer.data()) {
}

CommandBuffer::~CommandBuffer() {
}

void CommandBuffer::put(void *data, size_t size) {
    memcpy(_ptr, data, size);
    _ptr += size;
}

void CommandBuffer::put(const std::string &t) {
    put(uint8_t(t.size()));
    put(const_cast<char *>(t.data()), t.size());
}

void CommandBuffer::put(const std::vector<uint8_t> &t) {
    put(uint8_t(t.size()));
    put(const_cast<uint8_t *>(t.data()), t.size());
}

void CommandBuffer::put(const CommandBuffer &t) {
    auto buffer = const_cast<CommandBuffer&>(t).getBuffer();
    put(const_cast<uint8_t *>(buffer.data()), buffer.size()); // TODO const_cast bad
}

void CommandBuffer::setSize(size_t size) {
    _buffer.clear();
    _buffer.resize(size);
    _ptr = _buffer.data();
}

void CommandBuffer::get(void *data, size_t size) {
    memcpy(data, _ptr, size);
    _ptr += size;
}

size_t CommandBuffer::size() const {
    return _buffer.size();
}

std::string CommandBuffer::hexView(const std::vector<uint8_t> &data, size_t offset, size_t size) {
    std::stringstream ss;
    uint8_t *ptr = const_cast<uint8_t *>(data.data()) + offset;
    for (int i = 0; i < size; ++i, ++ptr) {
        char buffer[8];
        snprintf(buffer, sizeof(buffer), "%02x ", *ptr);
        ss << buffer;
    }
    return ss.str();
}

