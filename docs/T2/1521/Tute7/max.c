int max(int a[], int length) {
    int first_element = a[0];
    if (length == 1) {
        return first_element;
    } else {
        // find max value in rest of array
        // Recursive!
        int max_so_far = max(&a[1], length - 1);
        if (first_element > max_so_far) {
            max_so_far = first_element;
        }
        return max_so_far;
    }
}

/*
    [ 1 [2 [3 [4]]] ]
      ^  ^  ^  ^
      0  1  2  3

    Max(i, length) = max(a[i], Max(i + 1, length - 1))
    Max(i, 1) = a[i]

        L ->
    [      1  2  3  4
     i 0   1        4
     | 1   2     4  -
     v 2   3  4  -
    ]  3   4  -

    Max(0, 4) = max(1, Max(1, 3))
              = max(1, max(2, Max(2, 2)))
              = max(1, max(2, max(3, Max(3, 1))))
              = max(1, max(2, max(3, max(4))))
              
    MAXIMUM = Max(0, 4)
 */
