#include <algorithm>
#include <iostream>
#include <string>
using std::string;
#include <vector>
#include <unordered_set>
#include <set>

class Gebiet {
    int plz;
    string ort;

public:

    Gebiet(int plz, string const& ort)
    : plz(plz)
    , ort(ort) {
        // TODO validate constructor parameters
    }

    int getPlz() const {
        return plz;
    }

    string const& getOrt() const {
        return ort;
    }
};

std::ostream& operator<<(std::ostream& os, Gebiet const& gebiet) {
    os << gebiet.getPlz() << " " << gebiet.getOrt();
    return os;
}

bool operator==(Gebiet const& links, Gebiet const& rechts) {
    return links.getPlz() == rechts.getPlz()
        && links.getOrt() == rechts.getOrt();
}

template <>
struct std::hash<Gebiet> {
    std::size_t operator()(Gebiet const& gebiet) const {
        return gebiet.getPlz() * 31 + std::hash<string>()(gebiet.getOrt());
    }
};

bool operator<(Gebiet const& links, Gebiet const& rechts) {
    if (links.getPlz() < rechts.getPlz()) return true;
    if (rechts.getPlz() < links.getPlz()) return false;

    return links.getOrt() < rechts.getOrt();
}

int main() {
    std::vector<Gebiet> liste;
    liste.emplace_back(33615, "Bielefeld");
    std::cout << liste.front() << "\n";
    auto it = std::find(liste.begin(), liste.end(), Gebiet { 33615, "Bielefeld" });
    std::cout << (it != liste.end()) << "\n";

    std::unordered_set<Gebiet> menge;
    menge.emplace(33615, "Bielefeld");
    std::cout << *menge.begin() << "\n";
    std::cout << menge.contains({ 33615, "Bielefeld" }) << "\n";

    std::set<Gebiet> baum;
    baum.emplace(33615, "Bielefeld");
    std::cout << *baum.begin() << "\n";
    std::cout << baum.contains({ 33615, "Bielefeld" }) << "\n";
}
