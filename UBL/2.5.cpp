#include <iostream>
#include <vector>
#include <unordered_map>

class ArrClass {
    private:
    std::unordered_map<int,int> umap;

    bool is_duplicate (int x) {
      if (umap[x])
        return true;

      umap[x] = 1;
      return false;
    }

    public:
    std::vector<int> remove_duplicates (std::vector<int> a) {
        std::vector<int> b;

        for (auto i: a) {
          if (!is_duplicate(i))
            b.push_back(i);
        }

        return b;
    }

};

int main() {
    ArrClass arrclass1;
    std::vector<int> a;

    a = {1,2,3,3,4,5,5,6,6,7,8,8};

    std::vector<int> new_a = arrclass1.remove_duplicates(a);

    for (auto i: new_a) {
        std::cout << i << std::endl; 
    }
}
