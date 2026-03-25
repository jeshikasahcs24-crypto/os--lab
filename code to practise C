#include <stdio.h>
#define MAX 100

int arr[MAX];

int insert(int n, int pos, int val) {
    if (pos > n + 1 || pos < 1) {
        printf("Invalid");
        return n;
    }

    for (int i = n - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }

    arr[pos - 1] = val;
    return n + 1;
}

int main() {
    int n, pos, val;

    printf("Enter size of array");
    scanf("%d", &n);

    printf("Enter elements:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter position and value:");
    scanf("%d %d", &pos, &val);

    n = insert(n, pos, val);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}




next :

#include <stdio.h>
#define MAX 100

int arr[MAX];

void find_min(int n) {
    int min = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[min]) {
            min = i;
        }
    }

    printf("Min element: %d", arr[min]);
    printf(" Index of min element: %d", min);

    return;
}

int main() {
    int n;

    printf("Size of array:");
    scanf("%d", &n);

    printf("Enter elements:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    find_min(n);

    return 0;
}



next:

#include <stdio.h>
#define MAX 100

int arr[MAX][MAX];

void transpose(int r, int c) {
    int trans[MAX][MAX];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            trans[j][i] = arr[i][j];
        }
    }

    printf("Transpose matrix:\n");
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            printf("%d ", trans[i][j]);
        }
        printf("\n");
    }

    return;
}

int main() {
    int rows, cols;

    printf("Enter rows & columns:");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    transpose(rows, cols);

    return 0;
}


next:

#include <stdio.h>
#define MAX 100

int arr[MAX];

bool check_duplicate(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j])
                return true;
        }
    }
    return false;
}

int main() {
    int n;

    printf("Enter size:");
    scanf("%d", &n);

    printf("Enter elements:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (check_duplicate(n))
        printf("Array has duplicate");
    else
        printf("No duplicates");

    return 0;
}
