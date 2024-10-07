// Name: Shukhratbek
// Subject: ADVANCED COMPUTER ARCHITECTURE (2024 Fall)
// Assignment: Project1-Part2
// Data: Oct 16 2024

class Pipeline {
private:
    BranchPredictor branchPredictor;
    std::queue<Instruction> fetchQueue;
    std::vector<Instruction> speculativeInstructions;

public:
    void speculate(Instruction& branchInst) {
        bool prediction = branchPredictor.predict(branchInst.getAddress());
        uint32_t nextPC = prediction ? branchInst.getTargetAddress() : branchInst.getAddress() + 4;
        
        // Fetch and speculatively execute instructions
        while (speculativeInstructions.size() < MAX_SPECULATIVE_DEPTH) {
            Instruction nextInst = fetchInstruction(nextPC);
            speculativeInstructions.push_back(nextInst);
            nextPC += 4;
        }
    }

    void squash() {
        speculativeInstructions.clear();
        // Flush pipeline stages as needed
    }

    void execute() {
        Instruction& inst = getCurrentInstruction();
        if (inst.isBranch()) {
            bool actualOutcome = inst.execute();
            if (actualOutcome != branchPredictor.predict(inst.getAddress())) {
                squash();
                branchPredictor.update(inst.getAddress(), actualOutcome);
            } else {
                // Commit speculative instructions
                commitSpeculativeInstructions();
            }
        } else {
            inst.execute();
        }
    }

    void commitSpeculativeInstructions() {
        for (auto& inst : speculativeInstructions) {
            commitInstruction(inst);
        }
        speculativeInstructions.clear();
    }
};