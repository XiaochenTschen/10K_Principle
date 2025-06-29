#include <iostream>
#include <string>

// Computer can also be used as a base class
// and drives game computer
class Computer {
public:
    std::string cpu;
    std::string gpu;
    std::string ram;
    std::string storage;

    void show() const {
        std::cout << "CPU: " << cpu << "\n"
                  << "GPU: " << gpu << "\n"
                  << "RAM: " << ram << "\n"
                  << "Storage: " << storage << "\n";
    }
};

// Builder interface, virtual class
class ComputerBuilder {
public:
    virtual ~ComputerBuilder() = default;
    virtual void buildCPU() = 0;
    virtual void buildGPU() = 0;
    virtual void buildRAM() = 0;
    virtual void buildStorage() = 0;
    virtual Computer* getResult() = 0;
};

// concrete builder
class GamingComputerBuilder : public ComputerBuilder {
private:
    Computer* computer;
public:
    GamingComputerBuilder() {
        computer = new Computer();
    }

    void buildCPU() override {
        computer->cpu = "Intel i9";
    }

    void buildGPU() override {
        computer->gpu = "NVIDIA RTX 4090";
    }

    void buildRAM() override {
        computer->ram = "32GB DDR5";
    }

    void buildStorage() override {
        computer->storage = "2TB NVMe SSD";
    }

    Computer* getResult() override {
        return computer;
    }
};

// Algorithm to organize builder process is stabil
class Director {
public:
    void construct(ComputerBuilder* builder) {
        builder->buildCPU();
        builder->buildGPU();
        builder->buildRAM();
        builder->buildStorage();
    }
};


int main() {
    Director director;
    GamingComputerBuilder builder;

    director.construct(&builder);
    Computer* computer = builder.getResult();

    computer->show();

    delete computer;
    return 0;
}

    
    