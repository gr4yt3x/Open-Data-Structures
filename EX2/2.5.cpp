#include <iostream>
#include <vector>

template <typename T>
class ArrayDeque {
private:
    std::vector<T> a;
    int j = 0;
    int n = 0;

public:
    int size () {
        return n;
    }

    void items () { // isso esta uma tremenda gambiarra (corrigir depois ou apagar essa função) | adicionar um counter de operations;
        int item;

        for(int i = 0; i < n + 1; ++i) {
        item = get(i);

        if(item > 0){
            std::cout << get(i) << " ";
        }
       }
    }

    void vetor () {
     for (int i = 0; i < a.size(); ++i) {
        std::cout << a[i];
     }
    }

    void resize () {
        std::vector<T> b(std::max(1, 2 * n));
        for (int k = 0; k < n; k++) {
            b[k] = this->get(k);
        }
        a = b;
        j = 0;
    }

    T get (int i) {
        return a[(j + i) % a.size()];
    }

    T set (int i, T x) {
        T y = a[(j + i) % a.size()];
        a[(j + i) % a.size()] = x;
        return y;
    }

    T front () {
        return a[j];
    }

    T tail () {
        return get(n - 1);
    }

    T add (int i, T x) {
        if (n + 1 > a.size()) resize();
        if (i < n / 2) {
            j = (j == 0) ? a.size() - 1 : j - 1;
            for (int k = 0; k < i; ++k) {
                a[(j + k) % a.size()] = a[(j + k + 1) % a.size()];
            }
        } else {
            for (int k = n - 1; k >= i; --k) {
                a[(j + k + 1) % a.size()] = a[(j + k) % a.size()];
            }
        }
        a[(j + i) % a.size()] = x;
        n++;

        return x;
    }

    void add_last (T x) {
        add(n, x);
    }

    T remove(int i) {
        T x = a[(j + i) & (a.size() - 1)];
        if (i < n / 2) {
            for (int k = i; k > 0; k--) {
                a[(j + k) % a.size()] = a[(j + k - 1) % a.size()];
            }
            j = (j + 1) % a.size();
        } else {
            for (int k = i; k < n - 1; k++) {
                a[(j + k) % a.size()] = a[(j + k + 1) % a.size()];
            }
        }
        n--;
        if (3 * n < a.size()) resize();

        return x;
    }

    void rotate(int r) {
        if (n == 0) { // If the deque is empty, do nothing
          return;
        }

        r = ((r % n) + n) % n;

        j = (j + r) % a.size();
    }

};


int main() {
    ArrayDeque<int> deque;

    // Add elements 1 through 7
    for(int i = 1; i <= 7; i++) {
        deque.add_last(i);
    }

    std::cout <<"Before rotation:" << std::endl;
    deque.items();

    deque.rotate(3);
    deque.size();

    std::cout << std::endl << "After rotation:" << std::endl;
    deque.items();

    return 0;
}
