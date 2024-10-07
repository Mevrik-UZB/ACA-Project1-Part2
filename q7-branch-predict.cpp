// Name: Shukhratbek
// Subject: ADVANCED COMPUTER ARCHITECTURE (2024 Fall)
// Assignment: Project1-Part2
// Data: Oct 16 2024

// Branch History Table (BHT)
uint16_t bht = 0; // 16-bit BHT initialized to all zeros

// Pattern History Table (PHT)
uint8_t pht[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; // 16 entries, initialized to weakly NOT-TAKEN (01)

// Branch Target Buffer (BTB)
struct BTBEntry {
    uint32_t tag;
    uint32_t target;
    bool valid;
};
BTBEntry btb[16]; // 16-entry BTB
int btb_fifo_counter = 0;

// Function to make a branch prediction
bool predict_branch(uint32_t pc) {
    uint32_t bht_index = pc & 0xF; // Last 4 bits of PC
    uint32_t xor_result = (bht & 0xF) ^ bht_index;
    uint8_t pht_entry = pht[xor_result];
    return pht_entry >= 2; // Predict taken if 10 or 11
}

// Function to update branch predictor
void update_predictor(uint32_t pc, bool taken) {
    uint32_t bht_index = pc & 0xF;
    uint32_t xor_result = (bht & 0xF) ^ bht_index;
    
    // Update PHT
    if (taken) {
        if (pht[xor_result] < 3) pht[xor_result]++;
    } else {
        if (pht[xor_result] > 0) pht[xor_result]--;
    }
    
    // Update BHT
    bht = (bht << 1) | (taken ? 1 : 0);
    bht &= 0xFFFF; // Keep only 16 bits
}

// Function to check BTB for target address
uint32_t check_btb(uint32_t pc) {
    for (int i = 0; i < 16; i++) {
        if (btb[i].valid && btb[i].tag == pc) {
            return btb[i].target;
        }
    }
    return pc + 1; // Return PC+1 if not found in BTB
}

// Function to update BTB
void update_btb(uint32_t pc, uint32_t target) {
    // Find an empty entry or use FIFO replacement
    int index = btb_fifo_counter;
    for (int i = 0; i < 16; i++) {
        if (!btb[i].valid) {
            index = i;
            break;
        }
    }
    
    btb[index].tag = pc;
    btb[index].target = target;
    btb[index].valid = true;
    
    btb_fifo_counter = (btb_fifo_counter + 1) % 16;
}

// Main prediction function
uint32_t predict_and_update(uint32_t pc, bool is_branch, bool taken, uint32_t target) {
    bool prediction = predict_branch(pc);
    uint32_t predicted_target = check_btb(pc);
    
    if (is_branch) {
        update_predictor(pc, taken);
        if (taken) {
            update_btb(pc, target);
        }
    }
    
    if (prediction && is_branch) {
        return predicted_target;
    } else {
        return pc + 1;
    }
}