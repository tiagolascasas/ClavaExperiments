float foo(float A[100]) {
    for (int i = 0; i < 100; i++) {
        A[i] = 0;
    }
    for (int i = 0; i < 100; i++) {
        A[i] = A[i] + 1;
    }
    for (int i = 0; i < 100; i++) {
        A[i] = A[i] + 2;
        for (int j = 0; j < 100; j++) {
            A[j] = A[j] + 3;
        }
    }
#pragma clava begin_outline
    for (int i = 0; i < 100; i++) {
        A[i] = A[i] + 4;
        for (int j = 0; j < 100; j++) {
            A[j] = A[j] + 5;
            for (int k = 0; k < 100; k++) {
                A[k] = A[k] + 6;
            }
        }
    }
    for (int i = 0; i < 100; i++) {
        A[i] = A[i] + 7;
        for (int j = 0; j < 100; j++) {
            if (A[i] > 0) {
                return 2.4;
            }
            A[j] = A[j] + 8;
            for (int k = 0; k < 100; k++) {
                A[k] = A[k] + 9;
                if (A[k] > 0) {
                    return A[1];
                    }
                for (int l = 0; l < 100; l++) {
                    A[l] = A[l] + 10;
                }
            }
        }
    }
#pragma clava end_outline
    return A[0];
}

int main() {
    float A[100] = {2.0};
    foo(A);
    return 0;
}