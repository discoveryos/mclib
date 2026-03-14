/* The compiler handles the 'fs' offset for __thread variables */
__thread int __errno_val;

int *__errno_location(void) {
    return &__errno_val;
}
