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
		return out
			<< "Foo = " << rhs.m_Foo << ", "
		;
	}

private:
	std::string m_Foo = "Foo42";
};


class State100ServerResponse : public CommandBuffer {
public:
	State100ServerResponse(const std::vector<uint8_t>& buffer = {}): CommandBuffer(buffer) {
		if(buffer.empty())
			return;
	}
	virtual ~State100ServerResponse() {
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
		return out
			<< "Bar = " << rhs.m_Bar << ", "
		;
	}

private:
	uint64_t m_Bar = 42;
};


class State101ServerResponse : public CommandBuffer {
public:
	State101ServerResponse(const std::vector<uint8_t>& buffer = {}): CommandBuffer(buffer) {
		if(buffer.empty())
			return;
	}
	virtual ~State101ServerResponse() {
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
		return out
			<< "Credits = " << rhs.m_Credits << ", "
			<< "NumberOfBalls = " << rhs.m_NumberOfBalls << ", "
			<< "GameName = " << rhs.m_GameName << ", "
			<< "State = " << rhs.m_State << ", "
			<< (
				rhs.m_State == 100 ? "State100" :
				rhs.m_State == 101 ? "State101" : 
					throw std::runtime_error("invalid command value")
			) 
			<< "Test = " << rhs.m_Test << ", "
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
		return out
		;
	}

private:
};


class SerState10ServerResponse : public CommandBuffer {
public:
	SerState10ServerResponse(const std::vector<uint8_t>& buffer = {}): CommandBuffer(buffer) {
		if(buffer.empty())
			return;
		get(m_Barmaley);
		get(m_Animal);
	}
	virtual ~SerState10ServerResponse() {
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
		return out
		;
	}

private:
};


class SerState20ServerResponse : public CommandBuffer {
public:
	SerState20ServerResponse(const std::vector<uint8_t>& buffer = {}): CommandBuffer(buffer) {
		if(buffer.empty())
			return;
		get(m_Card);
	}
	virtual ~SerState20ServerResponse() {
	}
	std::string m_Card = "qol4k21;3l452;3l4kj5;2l3k4j";
};
	


class StartServerResponse : public CommandBuffer {
public:
	StartServerResponse(const std::vector<uint8_t>& buffer = {}): CommandBuffer(buffer) {
		if(buffer.empty())
			return;
		get(m_Credits);
		get(m_State);
		m_State == 10 ? get(static_cast<CommandBuffer&>(m_SerState10)) :
		m_State == 20 ? get(static_cast<CommandBuffer&>(m_SerState20)) : 
			throw std::runtime_error("");
		get(m_Pi);
	}
	virtual ~StartServerResponse() {
	}
	uint64_t m_Credits = 0;
	uint8_t m_State = 10;
	SerState10ServerResponse m_SerState10;
	SerState20ServerResponse m_SerState20;
	double m_Pi = 3.1415926;
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
		return out
			<< "Ball = " << rhs.m_Ball << ", "
		;
	}

private:
	uint8_t m_Ball = 0;
};


class FreeServerResponse : public CommandBuffer {
public:
	FreeServerResponse(const std::vector<uint8_t>& buffer = {}): CommandBuffer(buffer) {
		if(buffer.empty())
			return;
	}
	virtual ~FreeServerResponse() {
	}
};
	
