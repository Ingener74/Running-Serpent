#pragma once
#include "CommandBuffer.h"



class State100ServerRequest : public CommandBuffer {
public:
	State100ServerRequest() {
	}
	virtual ~State100ServerRequest() {
	}
	State100ServerRequest& putFoo(const std::string& Foo) {
		m_Foo = Foo;
		return *this;
	}

    virtual size_t size() const {
    	return
			1 + m_Foo.size() 
    	;
    }

	virtual std::vector<uint8_t> getBuffer() override {
		setSize(size());
		put(m_Foo);
		return _buffer;
	}

	friend std::ostream& operator<<(std::ostream& out, const State100ServerRequest& rhs) {
		return out << std::endl
			<< "Foo = " << rhs.m_Foo << std::endl
		;
	}

private:
	std::string m_Foo = "Foo42";
};

class State100ServerResponse : public CommandBuffer {
public:
	State100ServerResponse(const std::vector<uint8_t>& buffer = {}): CommandBuffer(buffer) {
		parse(buffer);
	}
	virtual ~State100ServerResponse() {
	}

    virtual void parse(const std::vector<uint8_t>& data){
		if(data.empty())
			return;
		CommandBuffer::parse(data);
    }

	friend std::ostream& operator<<(std::ostream& out, const State100ServerResponse& rhs) {
		return out << std::endl
		;
	}
};
	

class State101ServerRequest : public CommandBuffer {
public:
	State101ServerRequest() {
	}
	virtual ~State101ServerRequest() {
	}
	State101ServerRequest& putBar(uint64_t Bar) {
		m_Bar = Bar;
		return *this;
	}

    virtual size_t size() const {
    	return
			sizeof(m_Bar) 
    	;
    }

	virtual std::vector<uint8_t> getBuffer() override {
		setSize(size());
		put(m_Bar);
		return _buffer;
	}

	friend std::ostream& operator<<(std::ostream& out, const State101ServerRequest& rhs) {
		return out << std::endl
			<< "Bar = " << rhs.m_Bar << std::endl
		;
	}

private:
	uint64_t m_Bar = 42;
};

class State101ServerResponse : public CommandBuffer {
public:
	State101ServerResponse(const std::vector<uint8_t>& buffer = {}): CommandBuffer(buffer) {
		parse(buffer);
	}
	virtual ~State101ServerResponse() {
	}

    virtual void parse(const std::vector<uint8_t>& data){
		if(data.empty())
			return;
		CommandBuffer::parse(data);
    }

	friend std::ostream& operator<<(std::ostream& out, const State101ServerResponse& rhs) {
		return out << std::endl
		;
	}
};
	

class StartServerRequest : public CommandBuffer {
public:
	StartServerRequest() {
	}
	virtual ~StartServerRequest() {
	}
	StartServerRequest& putCredits(int32_t Credits) {
		m_Credits = Credits;
		return *this;
	}
	StartServerRequest& putNumberOfBalls(int8_t NumberOfBalls) {
		m_NumberOfBalls = NumberOfBalls;
		return *this;
	}
	StartServerRequest& putGameName(const std::string& GameName) {
		m_GameName = GameName;
		return *this;
	}
	StartServerRequest& putState(uint8_t State) {
		m_State = State;
		return *this;
	}
	StartServerRequest& putState100(const State100ServerRequest& State100) {
		m_State100 = State100;
		return *this;
	}
	StartServerRequest& putState101(const State101ServerRequest& State101) {
		m_State101 = State101;
		return *this;
	}
	StartServerRequest& putTest(int8_t Test) {
		m_Test = Test;
		return *this;
	}

    virtual size_t size() const {
    	return
			sizeof(m_Credits) +
			sizeof(m_NumberOfBalls) +
			1 + m_GameName.size() +
			sizeof(m_State) + 
			(
				m_State == 100 ? m_State100.size() :
				m_State == 101 ? m_State101.size() :
					throw std::runtime_error("invalid command value")
			) +
			sizeof(m_Test) 
    	;
    }

	virtual std::vector<uint8_t> getBuffer() override {
		setSize(size());
		put(m_Credits);
		put(m_NumberOfBalls);
		put(m_GameName);
		put(m_State);
		m_State == 100 ? put(static_cast<CommandBuffer&>(m_State100)) :
		m_State == 101 ? put(static_cast<CommandBuffer&>(m_State101)) : 
			throw std::runtime_error("invalid command value");
		put(m_Test);
		return _buffer;
	}

	friend std::ostream& operator<<(std::ostream& out, const StartServerRequest& rhs) {
		return out << std::endl
			<< "Credits = " << rhs.m_Credits << std::endl
			<< "NumberOfBalls = " << rhs.m_NumberOfBalls << std::endl
			<< "GameName = " << rhs.m_GameName << std::endl
			<< "State = " << rhs.m_State << std::endl
			<< (
				rhs.m_State == 100 ? "State100" :
				rhs.m_State == 101 ? "State101" : 
					throw std::runtime_error("invalid command value")
			)  << std::endl
			<< "Test = " << rhs.m_Test << std::endl
		;
	}

private:
	int32_t m_Credits = 0;
	int8_t m_NumberOfBalls = 0;
	std::string m_GameName = "Game57";
	uint8_t m_State = 100;
	State100ServerRequest m_State100;
	State101ServerRequest m_State101;
	int8_t m_Test = -3;
};



class SerState10ServerRequest : public CommandBuffer {
public:
	SerState10ServerRequest() {
	}
	virtual ~SerState10ServerRequest() {
	}

    virtual size_t size() const {
    	return
    		0
    	;
    }

	virtual std::vector<uint8_t> getBuffer() override {
		setSize(size());
		return _buffer;
	}

	friend std::ostream& operator<<(std::ostream& out, const SerState10ServerRequest& rhs) {
		return out << std::endl
		;
	}

private:
};

class SerState10ServerResponse : public CommandBuffer {
public:
	SerState10ServerResponse(const std::vector<uint8_t>& buffer = {}): CommandBuffer(buffer) {
		parse(buffer);
	}
	virtual ~SerState10ServerResponse() {
	}

    virtual void parse(const std::vector<uint8_t>& data){
		if(data.empty())
			return;
		CommandBuffer::parse(data);
		get(m_Barmaley);
		get(m_Animal);
    }

	friend std::ostream& operator<<(std::ostream& out, const SerState10ServerResponse& rhs) {
		return out << std::endl
			<< "Barmaley = " << rhs.m_Barmaley << std::endl
			<< "Animal = " << rhs.m_Animal << std::endl
		;
	}
	uint64_t m_Barmaley = 234;
	std::string m_Animal = "Dog";
};
	

class SerState20ServerRequest : public CommandBuffer {
public:
	SerState20ServerRequest() {
	}
	virtual ~SerState20ServerRequest() {
	}

    virtual size_t size() const {
    	return
    		0
    	;
    }

	virtual std::vector<uint8_t> getBuffer() override {
		setSize(size());
		return _buffer;
	}

	friend std::ostream& operator<<(std::ostream& out, const SerState20ServerRequest& rhs) {
		return out << std::endl
		;
	}

private:
};

class SerState20ServerResponse : public CommandBuffer {
public:
	SerState20ServerResponse(const std::vector<uint8_t>& buffer = {}): CommandBuffer(buffer) {
		parse(buffer);
	}
	virtual ~SerState20ServerResponse() {
	}

    virtual void parse(const std::vector<uint8_t>& data){
		if(data.empty())
			return;
		CommandBuffer::parse(data);
		get(m_Card);
    }

	friend std::ostream& operator<<(std::ostream& out, const SerState20ServerResponse& rhs) {
		return out << std::endl
			<< "Card = " << rhs.m_Card << std::endl
		;
	}
	std::string m_Card = "qol4k21;3l452;3l4kj5;2l3k4j";
};
	

class StartServerResponse : public CommandBuffer {
public:
	StartServerResponse(const std::vector<uint8_t>& buffer = {}): CommandBuffer(buffer) {
		parse(buffer);
	}
	virtual ~StartServerResponse() {
	}

    virtual void parse(const std::vector<uint8_t>& data){
		if(data.empty())
			return;
		CommandBuffer::parse(data);
		get(m_Credits);
		get(m_State);
		m_State == 10 ? get(static_cast<CommandBuffer&>(m_SerState10)) :
		m_State == 20 ? get(static_cast<CommandBuffer&>(m_SerState20)) : 
			throw std::runtime_error("");
		get(m_Pi);
    }

	friend std::ostream& operator<<(std::ostream& out, const StartServerResponse& rhs) {
		return out << std::endl
			<< "Credits = " << rhs.m_Credits << std::endl
			<< "State = " << rhs.m_State << std::endl
			<< (
				rhs.m_State == 10 ? "SerState10" :
				rhs.m_State == 20 ? "SerState20" : 
					throw std::runtime_error("invalid command value")
			)  << std::endl
			<< "Pi = " << rhs.m_Pi << std::endl
		;
	}
	uint64_t m_Credits = 0;
	uint8_t m_State = 10;
	SerState10ServerResponse m_SerState10;
	SerState20ServerResponse m_SerState20;
	double m_Pi = 3.1415926;
};



class SerState10ClientRequest : public CommandBuffer {
public:
	SerState10ClientRequest() {
	}
	virtual ~SerState10ClientRequest() {
	}
	SerState10ClientRequest& putBarmaley(uint64_t Barmaley) {
		m_Barmaley = Barmaley;
		return *this;
	}
	SerState10ClientRequest& putAnimal(const std::string& Animal) {
		m_Animal = Animal;
		return *this;
	}

    virtual size_t size() const {
    	return
			sizeof(m_Barmaley) +
			1 + m_Animal.size() 
    	;
    }

	virtual std::vector<uint8_t> getBuffer() override {
		setSize(size());
		put(m_Barmaley);
		put(m_Animal);
		return _buffer;
	}

	friend std::ostream& operator<<(std::ostream& out, const SerState10ClientRequest& rhs) {
		return out << std::endl
			<< "Barmaley = " << rhs.m_Barmaley << std::endl
			<< "Animal = " << rhs.m_Animal << std::endl
		;
	}

private:
	uint64_t m_Barmaley = 234;
	std::string m_Animal = "Dog";
};

class SerState10ClientResponse : public CommandBuffer {
public:
	SerState10ClientResponse(const std::vector<uint8_t>& buffer = {}): CommandBuffer(buffer) {
		parse(buffer);
	}
	virtual ~SerState10ClientResponse() {
	}

    virtual void parse(const std::vector<uint8_t>& data){
		if(data.empty())
			return;
		CommandBuffer::parse(data);
    }

	friend std::ostream& operator<<(std::ostream& out, const SerState10ClientResponse& rhs) {
		return out << std::endl
		;
	}
};
	

class SerState20ClientRequest : public CommandBuffer {
public:
	SerState20ClientRequest() {
	}
	virtual ~SerState20ClientRequest() {
	}
	SerState20ClientRequest& putCard(const std::string& Card) {
		m_Card = Card;
		return *this;
	}

    virtual size_t size() const {
    	return
			1 + m_Card.size() 
    	;
    }

	virtual std::vector<uint8_t> getBuffer() override {
		setSize(size());
		put(m_Card);
		return _buffer;
	}

	friend std::ostream& operator<<(std::ostream& out, const SerState20ClientRequest& rhs) {
		return out << std::endl
			<< "Card = " << rhs.m_Card << std::endl
		;
	}

private:
	std::string m_Card = "qol4k21;3l452;3l4kj5;2l3k4j";
};

class SerState20ClientResponse : public CommandBuffer {
public:
	SerState20ClientResponse(const std::vector<uint8_t>& buffer = {}): CommandBuffer(buffer) {
		parse(buffer);
	}
	virtual ~SerState20ClientResponse() {
	}

    virtual void parse(const std::vector<uint8_t>& data){
		if(data.empty())
			return;
		CommandBuffer::parse(data);
    }

	friend std::ostream& operator<<(std::ostream& out, const SerState20ClientResponse& rhs) {
		return out << std::endl
		;
	}
};
	

class StartClientRequest : public CommandBuffer {
public:
	StartClientRequest() {
	}
	virtual ~StartClientRequest() {
	}
	StartClientRequest& putCredits(uint64_t Credits) {
		m_Credits = Credits;
		return *this;
	}
	StartClientRequest& putState(uint8_t State) {
		m_State = State;
		return *this;
	}
	StartClientRequest& putSerState10(const SerState10ClientRequest& SerState10) {
		m_SerState10 = SerState10;
		return *this;
	}
	StartClientRequest& putSerState20(const SerState20ClientRequest& SerState20) {
		m_SerState20 = SerState20;
		return *this;
	}
	StartClientRequest& putPi(double Pi) {
		m_Pi = Pi;
		return *this;
	}

    virtual size_t size() const {
    	return
			sizeof(m_Credits) +
			sizeof(m_State) + 
			(
				m_State == 10 ? m_SerState10.size() :
				m_State == 20 ? m_SerState20.size() :
					throw std::runtime_error("invalid command value")
			) +
			sizeof(m_Pi) 
    	;
    }

	virtual std::vector<uint8_t> getBuffer() override {
		setSize(size());
		put(m_Credits);
		put(m_State);
		m_State == 10 ? put(static_cast<CommandBuffer&>(m_SerState10)) :
		m_State == 20 ? put(static_cast<CommandBuffer&>(m_SerState20)) : 
			throw std::runtime_error("invalid command value");
		put(m_Pi);
		return _buffer;
	}

	friend std::ostream& operator<<(std::ostream& out, const StartClientRequest& rhs) {
		return out << std::endl
			<< "Credits = " << rhs.m_Credits << std::endl
			<< "State = " << rhs.m_State << std::endl
			<< (
				rhs.m_State == 10 ? "SerState10" :
				rhs.m_State == 20 ? "SerState20" : 
					throw std::runtime_error("invalid command value")
			)  << std::endl
			<< "Pi = " << rhs.m_Pi << std::endl
		;
	}

private:
	uint64_t m_Credits = 0;
	uint8_t m_State = 10;
	SerState10ClientRequest m_SerState10;
	SerState20ClientRequest m_SerState20;
	double m_Pi = 3.1415926;
};



class State100ClientRequest : public CommandBuffer {
public:
	State100ClientRequest() {
	}
	virtual ~State100ClientRequest() {
	}

    virtual size_t size() const {
    	return
    		0
    	;
    }

	virtual std::vector<uint8_t> getBuffer() override {
		setSize(size());
		return _buffer;
	}

	friend std::ostream& operator<<(std::ostream& out, const State100ClientRequest& rhs) {
		return out << std::endl
		;
	}

private:
};

class State100ClientResponse : public CommandBuffer {
public:
	State100ClientResponse(const std::vector<uint8_t>& buffer = {}): CommandBuffer(buffer) {
		parse(buffer);
	}
	virtual ~State100ClientResponse() {
	}

    virtual void parse(const std::vector<uint8_t>& data){
		if(data.empty())
			return;
		CommandBuffer::parse(data);
		get(m_Foo);
    }

	friend std::ostream& operator<<(std::ostream& out, const State100ClientResponse& rhs) {
		return out << std::endl
			<< "Foo = " << rhs.m_Foo << std::endl
		;
	}
	std::string m_Foo = "Foo42";
};
	

class State101ClientRequest : public CommandBuffer {
public:
	State101ClientRequest() {
	}
	virtual ~State101ClientRequest() {
	}

    virtual size_t size() const {
    	return
    		0
    	;
    }

	virtual std::vector<uint8_t> getBuffer() override {
		setSize(size());
		return _buffer;
	}

	friend std::ostream& operator<<(std::ostream& out, const State101ClientRequest& rhs) {
		return out << std::endl
		;
	}

private:
};

class State101ClientResponse : public CommandBuffer {
public:
	State101ClientResponse(const std::vector<uint8_t>& buffer = {}): CommandBuffer(buffer) {
		parse(buffer);
	}
	virtual ~State101ClientResponse() {
	}

    virtual void parse(const std::vector<uint8_t>& data){
		if(data.empty())
			return;
		CommandBuffer::parse(data);
		get(m_Bar);
    }

	friend std::ostream& operator<<(std::ostream& out, const State101ClientResponse& rhs) {
		return out << std::endl
			<< "Bar = " << rhs.m_Bar << std::endl
		;
	}
	uint64_t m_Bar = 42;
};
	

class StartClientResponse : public CommandBuffer {
public:
	StartClientResponse(const std::vector<uint8_t>& buffer = {}): CommandBuffer(buffer) {
		parse(buffer);
	}
	virtual ~StartClientResponse() {
	}

    virtual void parse(const std::vector<uint8_t>& data){
		if(data.empty())
			return;
		CommandBuffer::parse(data);
		get(m_Credits);
		get(m_NumberOfBalls);
		get(m_GameName);
		get(m_State);
		m_State == 100 ? get(static_cast<CommandBuffer&>(m_State100)) :
		m_State == 101 ? get(static_cast<CommandBuffer&>(m_State101)) : 
			throw std::runtime_error("");
		get(m_Test);
    }

	friend std::ostream& operator<<(std::ostream& out, const StartClientResponse& rhs) {
		return out << std::endl
			<< "Credits = " << rhs.m_Credits << std::endl
			<< "NumberOfBalls = " << rhs.m_NumberOfBalls << std::endl
			<< "GameName = " << rhs.m_GameName << std::endl
			<< "State = " << rhs.m_State << std::endl
			<< (
				rhs.m_State == 100 ? "State100" :
				rhs.m_State == 101 ? "State101" : 
					throw std::runtime_error("invalid command value")
			)  << std::endl
			<< "Test = " << rhs.m_Test << std::endl
		;
	}
	int32_t m_Credits = 0;
	int8_t m_NumberOfBalls = 0;
	std::string m_GameName = "Game57";
	uint8_t m_State = 100;
	State100ClientResponse m_State100;
	State101ClientResponse m_State101;
	int8_t m_Test = -3;
};
	

class FreeServerRequest : public CommandBuffer {
public:
	FreeServerRequest() {
	}
	virtual ~FreeServerRequest() {
	}
	FreeServerRequest& putBall(uint8_t Ball) {
		m_Ball = Ball;
		return *this;
	}

    virtual size_t size() const {
    	return
			sizeof(m_Ball) 
    	;
    }

	virtual std::vector<uint8_t> getBuffer() override {
		setSize(size());
		put(m_Ball);
		return _buffer;
	}

	friend std::ostream& operator<<(std::ostream& out, const FreeServerRequest& rhs) {
		return out << std::endl
			<< "Ball = " << rhs.m_Ball << std::endl
		;
	}

private:
	uint8_t m_Ball = 0;
};

class FreeServerResponse : public CommandBuffer {
public:
	FreeServerResponse(const std::vector<uint8_t>& buffer = {}): CommandBuffer(buffer) {
		parse(buffer);
	}
	virtual ~FreeServerResponse() {
	}

    virtual void parse(const std::vector<uint8_t>& data){
		if(data.empty())
			return;
		CommandBuffer::parse(data);
    }

	friend std::ostream& operator<<(std::ostream& out, const FreeServerResponse& rhs) {
		return out << std::endl
		;
	}
};

class FreeClientRequest : public CommandBuffer {
public:
	FreeClientRequest() {
	}
	virtual ~FreeClientRequest() {
	}

    virtual size_t size() const {
    	return
    		0
    	;
    }

	virtual std::vector<uint8_t> getBuffer() override {
		setSize(size());
		return _buffer;
	}

	friend std::ostream& operator<<(std::ostream& out, const FreeClientRequest& rhs) {
		return out << std::endl
		;
	}

private:
};

class FreeClientResponse : public CommandBuffer {
public:
	FreeClientResponse(const std::vector<uint8_t>& buffer = {}): CommandBuffer(buffer) {
		parse(buffer);
	}
	virtual ~FreeClientResponse() {
	}

    virtual void parse(const std::vector<uint8_t>& data){
		if(data.empty())
			return;
		CommandBuffer::parse(data);
		get(m_Ball);
    }

	friend std::ostream& operator<<(std::ostream& out, const FreeClientResponse& rhs) {
		return out << std::endl
			<< "Ball = " << rhs.m_Ball << std::endl
		;
	}
	uint8_t m_Ball = 0;
};
	
