bool checkAddition(unsigned int a, unsigned int b) {
    unsigned int temp = -1;
    if ((temp - a) < b) {
        return false; // Wraparound
    }
    else {
        return true;
    }
}

bool checkSubtraction(unsigned int a, unsigned int b) {
    if (a < b) {
        return false; // Wraparound
    }
    else {
        return true;
    }
}

bool checkMultiplication(unsigned int a, unsigned int b) {
    unsigned int temp = -1;
    if (a == 0 || b == 0) {
        return true;
    }
    else if ((temp / a) < b) {
        return false; // Wraparound
    }
    else {
        return true;
    }
}

int checkWrapAround(char operation, unsigned int a, unsigned int b, unsigned int *sol) {
    if (sol == nullptr) {
        return 0; // sol is null, return with failure
    }

    switch (operation) {
        case '+':
            if (checkAddition(a, b)) {
                *sol = a + b;
                return 1;
            }
            break; // Prevent fall-through
        case '-':
            if (checkSubtraction(a, b)) {
                *sol = a - b;
                return 1;
            }
            break; // Prevent fall-through
        case '*':
            if (checkMultiplication(a, b)) {
                *sol = a * b;
                return 1;
            }
            break; // Prevent fall-through
        default:
            return 0;
    }
    return 0; // In case none of the operations match
}
