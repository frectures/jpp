#include <assert.h>
#include <string>

class Gebiet {
    int plz;
    std::string ort;

public:

    Gebiet(int plz, std::string const& ort)
    : plz(plz)
    , ort(ort) {
        // TODO validate constructor parameters
    }

    friend bool operator==(Gebiet const& links, Gebiet const& rechts) {
        return links.plz == rechts.plz
            && links.ort == rechts.ort;
    }
};

void zeiger() {
    Gebiet* a = new Gebiet(33615, "Bielefeld");
    Gebiet* b = new Gebiet(33615, "Bielefeld");

    assert( a !=  b); // Gebiet*
    assert(*a == *b); // Gebiet
/*
        +-------------+   +-------------+
  links |  33615      |   |  33615      | rechts
     *a | "Bielefeld" |   | "Bielefeld" | *b
        +-------------+   +-------------+
                  ^         ^
                  |         |
                +-|-+     +-|-+
              a | ° +   b | ° |
                +---+     +---+
*/
    delete(a);
    a = b;
    assert( a ==  b);
    assert(*a == *b);
/*
                          +-------------+
                    links |  33615      | rechts
                       *a | "Bielefeld" | *b
                  +-----> +-------------+
                  |         ^
                  |         |
                +-|-+     +-|-+
              a | ° +   b | ° |
                +---+     +---+
*/
    delete(a);
/*
                  +----->
                  |         ^
                  |         |
                +-|-+     +-|-+
              a | ° +   b | ° |
                +---+     +---+
*/
}

void objekte() {
    Gebiet a(33615, "Bielefeld");
    Gebiet b(33615, "Bielefeld");

    assert(&a != &b);
    assert( a ==  b);
/*
        +-------------+   +-------------+
  links |  33615      |   |  33615      | rechts
      a | "Bielefeld" |   | "Bielefeld" | b
        +-------------+   +-------------+
*/
    a = b;
}

void werte() {
    assert(42 == 42);

    assert(Gebiet(33615, "Bielefeld") == Gebiet(33615, "Bielefeld"));
/*
        +-------------+   +-------------+
  links |  33615      |   |  33615      | rechts
        | "Bielefeld" |   | "Bielefeld" |
        +-------------+   +-------------+
*/
}

int main() {
    zeiger();
    objekte();
    werte();
}
