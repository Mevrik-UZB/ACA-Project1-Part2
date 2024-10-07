// Name: Shukhratbek
// Subject: ADVANCED COMPUTER ARCHITECTURE (2024 Fall)
// Assignment: Project1-Part2
// Data: Oct 16 2024

void Pipeline::printStatistics() {
    std::cout << "Total instructions executed: " << totalInstructions << std::endl;
    std::cout << "Branch predictions: " << branchPredictions << std::endl;
    std::cout << "Correct predictions: " << correctPredictions << std::endl;
    std::cout << "Prediction accuracy: " 
              << (float)correctPredictions / branchPredictions * 100 << "%" << std::endl;
    std::cout << "Total cycles: " << totalCycles << std::endl;
    std::cout << "IPC: " << (float)totalInstructions / totalCycles << std::endl;
}