void swap(int& a, int& b);
void mergesort(int *arr, unsigned int left, unsigned int right);
void quicksort(int *arr, unsigned int left, unsigned int right);
void insertionsort(int *arr, unsigned int left, unsigned int right);
void selectionsort(int *arr, unsigned int left, unsigned int right);

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void mergesort(int *arr, unsigned int left, unsigned int right) {
    if (right - left <= 1) return;
    unsigned int mid = (right + left) / 2;
    mergesort(arr, left, mid);
    mergesort(arr, mid, right);
    unsigned int i = left, j = mid, k = 0;
    int* temp = new int[right - left];
    while (i < mid && j < right) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
            k++;
        } else {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i < mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j < right) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int i = left; i < right; i++) {
        arr[i] = temp[i - left];
    }
    delete[] temp;
    return;
}

void quicksort(int *arr, int size) {
    int i = 0, j = size - 1, mid = arr[size / 2];
    do {
        while(arr[i] < mid) i++;
        while(arr[j] > mid) j--;
        if (i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);

    if(j > 0) quicksort(arr, j + 1);
    if (i < size) quicksort(&arr[i], size - i);
}

void insertionsort(int *arr, unsigned int left, unsigned int right) {
    unsigned int cur = left + 1, temp;
    while (cur < right) {
        temp = cur - 1;
        while (arr[temp] > arr[temp + 1]) {
            swap(arr[temp], arr[temp + 1]);
            if (temp == left) break;
            temp--;
        }
        
        cur++;
    }
}

void selectionsort(int *arr, unsigned int left, unsigned int right) {
    unsigned int wall = left, curmin;
    while (wall < right) {
        curmin = wall;
        for (int i = wall; i < right; i++) {
            if (arr[curmin] > arr[i]) curmin = i;
        }
        swap(arr[curmin], arr[wall]);
        wall++;
    }
}