// Name: Shukhratbek
// Subject: ADVANCED COMPUTER ARCHITECTURE (2024 Fall)
// Assignment: Project1-Part2
// Data: Oct 16 2024

class BranchPredictor {
private:
    std::unordered_map<uint32_t, uint8_t> predictorTable;

public:
    bool predict(uint32_t branchAddress) {
        uint8_t counter = predictorTable[branchAddress];
        return counter >= 2;
    }

    void update(uint32_t branchAddress, bool taken) {
        uint8_t& counter = predictorTable[branchAddress];
        if (taken && counter < 3) counter++;
        else if (!taken && counter > 0) counter--;
    }
};