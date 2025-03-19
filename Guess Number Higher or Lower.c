int guess(int num); // Function declaration

int guessNumber(int n) {
    int left = 1, right = n;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int result = guess(mid);
        if (result == 0) {
            return mid; // Found the number
        } else if (result == -1) {
            right = mid - 1; // Number is higher, search in the left half
        } else {
            left = mid + 1; // Number is lower, search in the right half
        }
    }
    return -1; // Number not found
}
