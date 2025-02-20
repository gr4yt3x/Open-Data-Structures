#include <iostream>
#include <vector>

template <typename T>
class ArrayDeque {
private:
    std::vector<T> a;
    int j = 0;
    int n = 0;

public:
    // Resize the deque to double its current capacity
    // observação: for use bitwise-and (&) instead of mod (%) you need to garantee that the a.length is aways power of two
    // this is often guaranteed by the way arrays are resized.
    void resize() {
        std::vector<T> b(std::max(1, 2 * n));
        for (int k = 0; k < n; k++) {
            b[k] = a[(j + k) & (a.size() - 1)];
        }
        a = b;
        j = 0;
    }

    T get(int i) {
        return a[(j + i) & (a.size() - 1)];
    }

    T set(int i, T x) {
        T y = a[(j + i) & (a.size() - 1)];
        a[(j + i) & (a.size() - 1)] = x;
        return y;
    }

    T front () {
        return a[j];    
    }

    T tail () {
        return a[(j + n - 1) & (a.size() - 1)];
    }

    void add(int i, T x) {
        if (n + 1 > a.size()) resize();
        if (i < n / 2) { 
            j = (j == 0) ? a.size() - 1 : j - 1;
            for (int k = 0; k < i; k++) {
                a[(j + k) & (a.size() - 1)] = a[(j + k + 1) & (a.size() - 1)];
            }
        } else { 
            for (int k = n - 1; k >= i; k--) {
                a[(j + k + 1) & (a.size() - 1)] = a[(j + k) & (a.size() - 1)];
            }
        }
        a[(j + i) & (a.size() - 1)] = x;
        n++;
    }

    T remove(int i) {
        T x = a[(j + i) & (a.size() - 1)];
        if (i < n / 2) { 
            for (int k = i; k > 0; k--) {
                a[(j + k) & (a.size() - 1)] = a[(j + k - 1) & (a.size() - 1)];
            }
            j = (j + 1) & (a.size() - 1);
        } else {
            for (int k = i; k < n - 1; k++) {
                a[(j + k) & (a.size() - 1)] = a[(j + k + 1) & (a.size() - 1)];
            }
        }
        n--;
        if (3 * n < a.size()) resize();
        return x;
    }
};

int main() {
    ArrayDeque<int> deque;
    deque.add(0, 1);
    deque.add(1, 2);
    deque.add(2, 3);
    deque.add(3, 4);

    deque.remove(3);

    std::cout << deque.front() << std::endl;
    std::cout << deque.tail() << std::endl;

    return 0;
}

