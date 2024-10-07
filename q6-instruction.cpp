// Name: Shukhratbek
// Subject: ADVANCED COMPUTER ARCHITECTURE (2024 Fall)
// Assignment: Project1-Part2
// Data: Oct 16 2024

class Instruction {
private:
    bool isSpeculative = false;

public:
    void setSpeculative(bool spec) { isSpeculative = spec; }
    bool isSpeculative() const { return isSpeculative; }

    ExecutionResult execute() {
        // Execute instruction logic
        if (isSpeculative) {
            // Store results in temporary buffers
        } else {
            // Commit results to architectural state
        }
    }
};